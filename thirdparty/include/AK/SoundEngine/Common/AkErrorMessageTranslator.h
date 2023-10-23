/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

  Copyright (c) 2023 Audiokinetic Inc.
*******************************************************************************/
#include <AK/SoundEngine/Common/AkSoundEngine.h>    // Sound engine
#define AK_TRANSLATOR_MAX_NAME_SIZE 150
#define AK_MAX_ERROR_LENGTH 1000

// AkErrorMessageTranslator.h
/// \file 
/// Contains the interface for a message translator
#pragma once

class AkErrorMessageTranslator
{
public:
	AkErrorMessageTranslator() :
		m_isReadyForTranslation{ false },
		m_fallBackTranslator{ nullptr }
	{}

	/// ErrorMessageTranslator class destructor.
	virtual ~AkErrorMessageTranslator() {};

	/**
	Terminate the translator
	*/
	virtual void Term() = 0;

	/**
	Sets the fallBackTranslator to the given fallback translator.
	The class that created the previously affected fallBackTranslator has
	the responsibilty to delete it.
	*/
	void SetFallBackTranslator(AkErrorMessageTranslator* in_fallBackTranslator) { m_fallBackTranslator = in_fallBackTranslator; }

	/**
	Resolve names associated to the wwise tag(s) in the error message if possible
	@param[in]	in_pszError				The error message to translate
	@param[out]	out_translatedPszError	The final result of the translation
	@param[in]	in_maxPszErrorSize		The maximum size of the translatedPszError and also the maximum size of the m_translationBuffer
	@param[in]	in_args					The variable arguments used in the tranlsation
	@param[in]	in_uArgSize				The total size of variable arguments, in bytes
	@return		bool					Whether or not the translation was successful
	*/
	virtual bool Translate(const AkOSChar* in_pszError, AkOSChar* out_translatedPszError, AkInt32 in_maxPszErrorSize, char* in_args, AkUInt32 in_uArgSize);

protected:
	struct TagInformation
	{
		const AkOSChar* m_pTag = nullptr;
		const AkOSChar* m_pStartBlock = nullptr;
		const char* m_args = nullptr;
		AkOSChar m_parsedInfo[AK_TRANSLATOR_MAX_NAME_SIZE] = { 0 };
		AkUInt32 m_argSize = 0;
		AkUInt16 m_len;
		bool m_infoIsParsed = false;
	};

	bool m_isReadyForTranslation;
	AkErrorMessageTranslator* m_fallBackTranslator;

	/**
	Copy the given string to the parsingInformation.
	@param[out]		out_parsedInfo			The modified translatedPszError
	@param[in]		in_maxSize				The maximum space in the parsedInfo buffer
	@param[in]		in_stringSize			The size of the string to print in the translatedPszError
	@param[in]		in_string				The string to print in the translatedPszError
	*/
	void CharPrintResult(AkOSChar* out_parsedInfo, AkInt32 in_maxSize, AkInt32 in_stringSize, const char* in_string);

	/**
	A translator specific function to get some informations based on the given tag.
	If the information is found, modify the translatedPszError and position
	@param[in]		in_pTagList				The list of tag to parse
	@param[in]		in_uCount				The number of tags to parse.
	@param[out]		out_uTranslated			The number of tags already translated.
	@return			bool					Whether or not all the tag were parsed
	*/
	virtual bool GetInfo(TagInformation *in_pTagList, AkUInt32 in_uCount, AkUInt32& out_uTranslated) = 0;
private:
	/**
	Extract all the tags from the pszError
	@param[in]	in_pszError				The error message to extract the tag from
	@param[in]	in_args					The variable arguments used in the parsing
	@param[in]	in_uArgSize				The size of the arguments used in the parsing
	@param[out]	out_tagList				The list of TagInformation with a standard tag
	@param[out]	out_uCount				The number of tags in out_TagsList
	@param[out]	out_uTranslated			The number of tags already translated in out_TagsList.
	@return		bool					True if we need extra translation of the tags.
	*/
	bool ExtractTags(const AkOSChar* in_pszError, char* in_args, AkUInt32 in_uArgSize, TagInformation* out_tagList, AkUInt32& out_uCount, AkUInt32& out_uTranslated);
};