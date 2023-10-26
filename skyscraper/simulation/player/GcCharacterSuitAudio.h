#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

class cGcCharacterSuitAudio
{
	struct sArmAudioAttachment
	{
		TkAudioObject mAudioObject;
		TkHandle mAttachNode;
		cTkMatrix34 mMatrix;
		long double mf64LastWhooshTime;
	};

	TkHandle mCharacterNode;
	cGcCharacterSuitAudio::sArmAudioAttachment maArmAudioAttachments[4];
	bool mabUsingHand[2];
};

SKYSCRAPER_END