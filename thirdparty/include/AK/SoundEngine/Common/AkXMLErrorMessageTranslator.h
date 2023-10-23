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
/// Contains the error message translator that use an xml file
/// This translator use the AkFileHelper

#pragma once
#include <AK/SoundEngine/Common/AkSoundEngine.h>    // Sound engine
#include <AK/SoundEngine/Common/AkSoundEngineExport.h>
#include <AK/Tools/Common/AkArray.h>
#include <AK/SoundEngine/Common/AkErrorMessageTranslator.h>

struct SearchInfo;

class AkXMLErrorMessageTranslator : public AkErrorMessageTranslator
{
public:
	/// MessageTranslator class constructor.
	AkXMLErrorMessageTranslator();

	AkXMLErrorMessageTranslator(const AkOSChar* in_filePath, AkUInt32 in_msTimeout = 10 /*Default timeout, 10ms*/);

	~AkXMLErrorMessageTranslator();

	virtual void Term() override;

	/**
	Sets the file path to SoundBanksInfo.xml (or its equivalent). Note that the path is always with respect to the Base Path, as set with AK::SoundEngine::SetBasePath()
	@param[in]		in_filePath				The file path to SoundBanksInfo.xml, relative to the Base Path, must include the filename and the extension.
	@param[out]		in_msTimeout			Maximum time that can be spent resolving the error parameters. Set to INT_MAX to wait infinitely or 0 to disable XML translation entirely.
	@return			AKRESULT				Ak_Success if the parameters are ok. AK_InvalidParameter if in_filePath is null. AK_InsufficientMemory if there was a memory allocaiton issue.
	*/
	AKRESULT SetFileName(const AkOSChar* in_filePath, AkUInt32 in_msTimeout = 10 /*Default timeout, 10ms*/);

protected:
	/**
	Call the external source and parse the tag if possible
	@param[in]		in_pTagList				The list of tag to parse
	@param[in]		in_uCount				The number of tag to parse
	@param[in,out]	io_uTranslated			The list of information gathered by the parsing
	@return			bool					Whether or not all the tag were parsed
	*/
	virtual bool GetInfo(TagInformation* in_pTagList, AkUInt32 in_uCount, AkUInt32& io_uTranslated) override;
private:

	AKRESULT Setup();

	/**
	Read the xml file and try to search for all the pattern stored inside the SearchInfo
	When a pattern is found, the index where it was found is stored inside the SearchInfo 
	If the parsedInformation isn't a null pointer, search a bit further to find the string matching the id and print it inside the parsedInformation
	@param[in,out]	io_searchInfo			List of all the pattern to find
	@param[in]		in_patternCount			The amount of pattern to find
	@param[in]		in_longestDefaultTag	Refers to the longest startTag / endTag stored in the in_SearchInfo. Since multiple search info can have the same startTag / endTag the longest one is sent instead of checking all the searchInfo one by one to find the longest one
	@param[in]		in_uPos					The index where the search should begin. By default start at 0 (the begining)
	@return			AkInt32					The amount of pattern that were successfully found
	*/
	AkInt32 ReadXmlFile(SearchInfo* io_searchInfo, const AkInt32& in_patternCount, AkInt32 in_longestDefaultTag, AkUInt32 in_uPos = 0);

	/**
	A sligthly edited BooyerMoore search algorithm that allows to search for multiple pattern at the same time
	If the parsedInformation isn't a null pointer, then an ID search is carried out
	The search stretch a bit further to find the string matching the id stored inside the searchInfo and print it inside the parsedInformation
	@param[in]		in_data					The buffer in which we're searching the pattern.
	@param[in]		in_dataSize				The length of the buffer in which we're making the search.
	@param[in,out]	io_searchInfo			The information about the pattern to find.
	@param[in]		in_patternCount			The amount of pattern to find.
	@return			int						The amount of pattern found.
	*/
	AkInt32 BoyerMooreSearch(char* in_data, AkUInt32 in_dataSize, SearchInfo* io_searchInfo, AkUInt32 in_patternCount);
	
	/**
	A continuation of the BooyerMoore search algorithm that happens during an ID search
	It searches for the starting point of the ID based on SearchInfo.idStartingPoint
	@param[in]		in_data					The buffer in which we're searching the pattern.
	@param[in]		in_dataSize				The length of the buffer in which we're making the search.
	@param[in,out]	io_searchInfo			The information about the pattern to find.
	*/
	void BooyerMooreSearchIdStartingPoint(char* in_data, AkInt32 in_dataSize, SearchInfo& io_searchInfo);
	
	/**
	Extract the ID from the xml file and store it inside the parsedInformation
	@param[in]		in_data					The buffer in which we're searching the pattern.
	@param[in]		in_dataSize				The length of the buffer in which we are making the search.
	@param[in,out]	io_searchInfo			The information about the pattern to find.
	*/
	void ExtractId(char* in_data, AkInt32 in_dataSize, SearchInfo& io_searchInfo);

	/**
	Creates the bad heuristic array used in the BoyerMoore string search algorithm
	@param[in]	in_pattern			The pattern we're looking for
	@param[in]	in_size				The size of the pattern string	
	@param[out]	out_badChar			The bad char array that will be used later on in the algorithm
	*/
	void BoyerMooreBadHeuristic(const char* in_pattern, AkInt32 in_size, AkInt8 out_badChar[]);

	AkOSChar m_fileName[AK_MAX_PATH];

	bool m_bFileOpeningFailed;
	AkUInt32 m_msTimeout;

	enum class xmlTag
	{
		StreamedFiles = 0,
		SoundBanks,

		// ALWAYS ADD NEW TAGS AT THE END !!!!!!!
		// Otherwise it may break comm compatibility in a patch

		NUM_XML_TAG // THIS STAYS AT END OF ENUM
	};

	AkUInt32 m_tagIndex[(AkInt32) AkXMLErrorMessageTranslator::xmlTag::NUM_XML_TAG];

	const char* s_xmlTag[(AkInt32)AkXMLErrorMessageTranslator::xmlTag::NUM_XML_TAG] =
	{
		"<StreamedFiles>",
		"<SoundBanks>"
		// When adding tags, make sure they are all shorter than MAX_XML_SEARCH_LEN.
	};
};
