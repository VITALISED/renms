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

// AkErrorMessageTranslator.h
/// \file 
/// Contains the error message translator that use the WAAPI
///	This message translator require the AkAutobahn.lib to be included in the project (Linker->Input)
#pragma once
#include <AK/SoundEngine/Common/AkSoundEngine.h>    // Sound engine
#include <AK/SoundEngine/Common/AkSoundEngineExport.h>
#include <AK/SoundEngine/Common/AkErrorMessageTranslator.h>
#include <AK/Tools/Common/AkObject.h>
#include "AK/WwiseAuthoringAPI/AkAutobahn/Client.h"
#ifndef WAAPITranslator
#define WAAPITranslator
#endif // !WAAPITranslator
class AkWAAPIErrorMessageTranslator : public AkErrorMessageTranslator
{
public:
	/// WAAPIErrorMessageTranslator class constructor.	
	AkWAAPIErrorMessageTranslator(const char* connectionIP = "127.0.0.1", const AkUInt32 port = 8080, AkUInt32 in_msTimeout = 10 /*10ms default*/);

	/// WAAPIErrorMessageTranslator class destructor.
	~AkWAAPIErrorMessageTranslator();
	
	virtual void Term() override;

	void SetConnectionIP(const char* connectionIP = "127.0.0.1", const AkUInt32 port = 8080, AkUInt32 in_msTimeout = 10 /*10ms default*/);
protected:
	
	/**
	Call the external source and parse the tag is possible
	@param[in]		in_tagList				The list of tag to parse
	@param[out]		out_parsedInformation	The list of information gathered by the parsing
	@return			bool					Whether or not all the tag were parsed
	*/
	virtual bool GetInfo(TagInformation* in_pTagList, AkUInt32 in_uCount, AkUInt32& io_uTranslated) override;
private:
	char m_connectionIP[20];
	AkUInt32 m_port;
	AkUInt32 m_msTimeout;
	AK::WwiseAuthoringAPI::Client m_Client;
	bool m_bConnectFailed;
	bool m_connectionSettingChanged;

	AKRESULT Setup();
	bool WAAPIGet(const char* in_waqlQuery, TagInformation & io_tags, AkUInt32 in_arg);
	bool WAAPIGetFromTypes(TagInformation& io_tags, AkUInt32 in_typeId);
	bool WAAPIGetFromGameObject(TagInformation& io_tags, AkUInt64 in_gId);
};
