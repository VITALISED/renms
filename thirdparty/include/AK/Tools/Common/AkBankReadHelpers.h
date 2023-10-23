/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2023 Audiokinetic Inc.
*******************************************************************************/

#ifndef _AK_BANKREADHELPERS_H_
#define _AK_BANKREADHELPERS_H_

#include <AK/Tools/Common/AkPlatformFuncs.h>

#include <type_traits>

namespace AK
{
	template<
		typename T,
		typename std::enable_if<std::is_fundamental<T>::value || std::is_enum<T>::value, bool>::type = true
	>
	inline T ReadUnaligned(const AkUInt8* in_pVal)
	{
#if defined(__GNUC__)
		typedef T __attribute__((aligned(1))) UnalignedT;
		return *reinterpret_cast<const UnalignedT *>(in_pVal);
#elif defined(_MSC_VER)  && !defined(AK_CPU_X86)
		return *reinterpret_cast<const T __unaligned *>(in_pVal);  // __unaligned not supported on 32-bit x86
#else
		return *reinterpret_cast<const T *>(in_pVal);
#endif
	}

	template<
		typename T,
		typename std::enable_if<std::is_class<T>::value, bool>::type = true
	>
	inline T ReadUnaligned(const AkUInt8* in_pVal)
	{
		T result;
		AKPLATFORM::AkMemCpy(&result, in_pVal, sizeof(T));
		return result;
	}

	template<
		typename T,
		typename std::enable_if<std::is_fundamental<T>::value || std::is_enum<T>::value, bool>::type = true
	>
	inline void WriteUnaligned(AkUInt8* out_pVal, const T in_val)
	{
#if defined(__GNUC__)
		typedef T __attribute__((aligned(1))) UnalignedT;
		*reinterpret_cast<UnalignedT *>(out_pVal) = in_val;
#elif defined(_MSC_VER) && !defined(AK_CPU_X86)
		*reinterpret_cast<T __unaligned *>(out_pVal) = in_val; // __unaligned not supported on 32-bit x86
#else
		*reinterpret_cast<T *>(out_pVal) = in_val;
#endif
	}

	template<
		typename T,
		typename std::enable_if<std::is_class<T>::value, bool>::type = true
	>
	inline void WriteUnaligned(AkUInt8* out_pVal, const T& in_val)
	{
		AKPLATFORM::AkMemCpy(out_pVal, &in_val, sizeof(T));
	}

	/// Read data from bank and advance pointer.
	template< typename T >
	inline T ReadBankData(
		AkUInt8*& in_rptr
#ifdef _DEBUG
		, AkUInt32& in_rSize
#endif
	)
	{
		T l_Value = ReadUnaligned<T>(in_rptr);

		in_rptr += sizeof(T);
#ifdef _DEBUG
		in_rSize -= sizeof(T);
#endif
		return l_Value;
	}

	template< typename T >
	inline T ReadVariableSizeBankData(
		AkUInt8*& in_rptr
#ifdef _DEBUG
		, AkUInt32& in_rSize
#endif
	)
	{
		AkUInt32 l_Value = 0;

		AkUInt8 currentByte = *in_rptr;
		++in_rptr;
#ifdef _DEBUG
		--in_rSize;
#endif
		l_Value = (currentByte & 0x7F);
		while (0x80 & currentByte)
		{
			currentByte = *in_rptr;
			++in_rptr;
#ifdef _DEBUG
			--in_rSize;
#endif
			l_Value = l_Value << 7;
			l_Value |= (currentByte & 0x7F);
		}

		return (T)l_Value;
	}

	inline char * ReadBankStringUtf8(
		AkUInt8*& in_rptr
#ifdef _DEBUG
		, AkUInt32& in_rSize
#endif
		, AkUInt32& out_uStringSize)
	{
		char* pString = (char *)in_rptr;
		out_uStringSize = 0;

		while (*in_rptr != 0)
		{
			++in_rptr;
#ifdef _DEBUG
			--in_rSize;
#endif
			++out_uStringSize;
		}

		++in_rptr;
#ifdef _DEBUG
		--in_rSize;
#endif

		return pString;
	}
}


#ifdef _DEBUG

/// Read and return bank data of a given type, incrementing running pointer and decrementing block size for debug tracking purposes
#define READBANKDATA( _Type, _Ptr, _Size )		\
		AK::ReadBankData<_Type>( _Ptr, _Size )

#define READVARIABLESIZEBANKDATA( _Type, _Ptr, _Size )		\
		AK::ReadVariableSizeBankData<_Type>( _Ptr, _Size )

/// Read and return a null-terminated UTF-8 string, written with the DataWriter of \ref AK::Wwise::Plugin::CustomData::GetPluginData or
/// \ref AK::Wwise::Plugin::AudioPlugin::GetBankParameters, and stored in bank, and its size.
/// \ref wwiseplugin_bank
#define READBANKSTRING( _Ptr, _Size, _out_StringSize )		\
		AK::ReadBankStringUtf8( _Ptr, _Size, _out_StringSize )

/// Skip over some bank data of a given type, incrementing running pointer and decrementing block size for debug tracking purposes
#define SKIPBANKDATA( _Type, _Ptr, _Size )		\
		( _Ptr ) += sizeof( _Type );	\
		( _Size ) -= sizeof( _Type )

/// Skip over some bank data by a given size in bytes, incrementing running pointer and decrementing block size for debug tracking purposes
#define SKIPBANKBYTES( _NumBytes, _Ptr, _Size )	\
		( _Size ) -= _NumBytes;		\
		( _Ptr ) += _NumBytes

/// Read and copy to a null-terminated UTF-8 string conversion from string stored in bank.
#define COPYBANKSTRING_CHAR( _Ptr, _Size, _OutPtr, _MaxOutPtrSize )		\
		AKPLATFORM::SafeStrCpy( _OutPtr, ((const char*)_Ptr), (_MaxOutPtrSize) );		\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr) + 1, _Ptr, _Size )

/// Read and copy to a null-terminated OSChar string conversion from string stored in bank.
#define COPYBANKSTRING_OSCHAR( _Ptr, _Size, _OutPtr, _MaxOutPtrSize )		\
		AK_UTF8_TO_OSCHAR( _OutPtr, ((const char*)_Ptr), (_MaxOutPtrSize) );		\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr) + 1, _Ptr, _Size )

/// Read and copy to a null-terminated wchar_t string conversion from string stored in bank.
#define COPYBANKSTRING_WCHAR( _Ptr, _Size, OutPtr, _MaxOutPtrSize )		\
		AK_CHAR_TO_UTF16( _OutPtr, ((const char*)_Ptr), (_MaxOutPtrSize) );		\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr) + 1, _Ptr, _Size )


#else

/// Read and return bank data of a given type, incrementing running pointer and decrementing block size for debug tracking purposes
#define READBANKDATA( _Type, _Ptr, _Size )		\
		AK::ReadBankData<_Type>( _Ptr )

#define READVARIABLESIZEBANKDATA( _Type, _Ptr, _Size )		\
		AK::ReadVariableSizeBankData<_Type>( _Ptr )

#define READBANKSTRING( _Ptr, _Size, _out_StringSize )		\
		AK::ReadBankStringUtf8( _Ptr, _out_StringSize )

/// Skip over some bank data  of a given type, incrementing running pointer and decrementing block size for debug tracking purposes
#define SKIPBANKDATA( _Type, _Ptr, _Size )		\
		( _Ptr ) += sizeof( _Type )

/// Skip over some bank data by a given size in bytes, incrementing running pointer and decrementing block size for debug tracking purposes
#define SKIPBANKBYTES( _NumBytes, _Ptr, _Size )	\
		( _Ptr ) += _NumBytes;

/// Read and copy to a null-terminated UTF-8 string conversion from string stored in bank.
#define COPYBANKSTRING_CHAR( _Ptr, _Size, _OutPtr, _MaxPtrSize )		\
		AKPLATFORM::SafeStrCpy( _OutPtr, (const char*)_Ptr, _MaxPtrSize );		\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr)+1, _Ptr, _Size )

/// Read and copy to a null-terminated OSChar string conversion from string stored in bank.
#define COPYBANKSTRING_OSCHAR( _Ptr, _Size, _OutPtr, _MaxPtrSize )		\
		AK_UTF8_TO_OSCHAR( _OutPtr, (const char*)_Ptr, _MaxPtrSize );	\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr)+1, _Ptr, _Size )

/// Read and copy to a null-terminated wchar_t string conversion from string stored in bank.
#define COPYBANKSTRING_WCHAR( _Ptr, _Size, OutPtr, _MaxPtrSize )		\
		AK_CHAR_TO_UTF16( _OutPtr, (const char*)_Ptr, _MaxPtrSize );	\
		SKIPBANKBYTES( (AkUInt32)strlen((const char*)_Ptr)+1, _Ptr, _Size )

#endif

#define GETBANKDATABIT( _Data, _Shift )	\
	(((_Data) >> (_Shift)) & 0x1)

/// Helper macro to determine whether the full content of a block of memory was properly parsed
#ifdef _DEBUG
	#define CHECKBANKDATASIZE( _DATASIZE_, _ERESULT_ ) AKASSERT( _DATASIZE_ == 0 || _ERESULT_ != AK_Success );
#else
	#define CHECKBANKDATASIZE(_DATASIZE_, _ERESULT_ )
#endif

#endif //_AK_BANKREADHELPERS_H_
