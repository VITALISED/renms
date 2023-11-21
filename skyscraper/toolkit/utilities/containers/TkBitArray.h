#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

#define TKBITARRAY_SIZE(size) ((size / 8) < 16 ? 1 : size / 8)

template <typename Key, unsigned int Size>
class cTkBitArrayStorage
{
    constexpr int GetSize(unsigned int liSize) { return TKBITARRAY_SIZE(liSize); }

    Key mArray[GetSize(Size)];
};

template <typename Key>
class cTkBitArrayStorage<Key, 0>
{
    const int kiArraySize;
    const int kiStorageArraySize;
    Key *mArray;
};

template <typename T, bool Dynamic, unsigned int Size>
class cTkBitArray
{
  public:
    // enum eTkStatic
    // {
    //     eDefault,
    // };

    // enum eTkDynamic
    // {
    //     eDefault,
    // };

    // using type = eTkStatic;

    cTkBitArrayStorage<T, Size> mStorage;
};

template <typename T, unsigned int Size>
class cTkBitArray<T, true, Size>
{
  public:
    // enum eTkStatic
    // {
    //     eDefault,
    // };

    // enum eTkDynamic
    // {
    //     eDefault,
    // };

    // using type = eTkDynamic;

    cTkBitArrayStorage<T, 0> mStorage;
};

SKYSCRAPER_END