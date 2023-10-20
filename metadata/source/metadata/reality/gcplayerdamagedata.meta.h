#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
enum ePlayerDamageType
{
    EPlayerDamageType_Normal = 0,
    EPlayerDamageType_Toxic = 1,
    EPlayerDamageType_Radioactive = 2,
    EPlayerDamageType_Freeze = 3,
    EPlayerDamageType_Scorch = 4,
}
#include <metadata/reality/gcbreaktechbystatdata.meta.h>

class cGcPlayerDamageData
{
    static unsigned long long muNameHash = 0x5F9BF82F9925D932;
    static unsigned long long muTemplateHash = 0x1E4BCD483220FC93;

    TkID<128> mId;
    TkID<256> mDeathMessage;
    TkID<128> mDeathStat;
    cTkTextureResource HitIcon;
    TkID<256> mHitChatMessage;
    TkID<256> mHitMessage;
    cGcAudioWwiseEvents HitMessageAudio;
    TkID<256> mCriticalHitMessage;
    cGcAudioWwiseEvents CriticalHitMessageAudio;
    float mfDamage;
    float mfPushForce;
    float mfCameraTurn;
    TkID<128> mCameraShakeShield;
    TkID<128> mCameraShakeNoShield;
    bool mbShowTrackIcon;
    bool mbForceDamageInInteraction;
    bool mbAllowDeathInInteraction;
    ePlayerDamageType PlayerDamageType;
    cTkDynamicArray<cGcBreakTechByStatData> maDamageTechWithStat;
    float mfTechDamageChance;
}
