#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkLockFreeQueue
{
    std::atomic<int> miQueueMarkers;
    T *mpEntries;
    std::atomic<int> *maEntryValid;
    int miMaxNumEntries;
};

template <typename T, int Size>
class cTkInplaceLockFreeQueue : public cTkLockFreeQueue<T>
{
    T maEntryBuffer[Size + 1];
    std::atomic<int> maEntryValidBuffer[Size + 1];
};

SKYSCRAPER_END