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

// MessageTranslator.h
/// \file 
/// Contains the wwiseErrorHandler
/// Has a static callback function that can recieved an error message from the sound engine.
/// Has a translator used to translate the message coming from the sound engine.
/// The translator can be a combination of multiple different type of translators. (See AddTranslator)
/// The translated message is then send back to the sound engine through another callback function.

#ifndef AK_OPTIMIZED

#pragma once
#include <AK/SoundEngine/Common/AkSoundEngine.h>    // Sound engine
#include <AK/SoundEngine/Common/AkSoundEngineExport.h>

class AkErrorMessageTranslator;
class AkDefaultErrorMessageTranslator;

class AkWwiseErrorHandler
{
public:
	/// ErrorHandler class destructor.
	virtual ~AkWwiseErrorHandler() {};

	/**
		On initialization, a DefaultErrorMessageTranslator is created and affected to the m_currentMessageTranslator
	*/
	static void Init();

	/**
		Set the m_currentMessageTranslator to the given translator. 
		The added translator can either override previously added translator, or attach them to itself. 
		In the case overridePreviousTranslator is true, the responsibility of deleting all the translator previously attached to
		the m_currentMessageTranslator will fall back to the class that created them.
		Also, the given translator can override all previous translator(s) except the DefaultErrorMessageTranslator, which will 
		always be attached to the given translator.
		@param[in]	in_errorMessageTranslator		The new translator that should be used by the error handler
		@param[in]	in_overridePreviousTranslator	Whether or not the given translator should override previously set translator(s)
	*/
	static void AddTranslator(AkErrorMessageTranslator* in_errorMessageTranslator, bool in_overridePreviousTranslator);

	/**
		Delete the DefaultMessageTranslator and sets the m_currentMessageTranslator pointer to nullptr
	*/
	static void Release();

	///Translate and then send back the translated message to the sound engine via it's m_funcLocalOutput
	static void Execute(
		AK::Monitor::ErrorCode in_eErrorCode,	///< Error code number value
		const AkOSChar* in_pszError,			///< Message or error string to be displayed
		AK::Monitor::ErrorLevel in_errorLevel,	///< The error level of the message
		AkPlayingID in_pID,						///< Related Playing ID if applicable, AK_INVALID_PLAYING_ID otherwise
		AkUInt64 in_gId,						///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
		AkUniqueID in_sId,						///< Related Sound ID if applicable, AK_INVALID__ID otherwise
		char* in_args,							///< Variable arguments to replace the wwise tags contained in the message or error string
		AkUInt32 in_uArgSize					///< Size of argument blob.
	);

	///Sets the localoutputfunc
	static void SetLocalOutputFunc(AkUInt32 in_uErrorLevel, AK::Monitor::LocalOutputFunc in_pMonitorFunc) { m_uLocalOutputErrorLevel = in_uErrorLevel; m_funcLocalOutput = in_pMonitorFunc;};

private:
	/// ErrorHandler class constructor.
	AkWwiseErrorHandler() {};

	static AK::Monitor::LocalOutputFunc m_funcLocalOutput;
	static AkUInt32 m_uLocalOutputErrorLevel;
	static AkDefaultErrorMessageTranslator m_defaultErrorMessageTranslator;
	static AkErrorMessageTranslator* m_currentMessageTranslator;
};

#endif // !AK_OPTIMIZED