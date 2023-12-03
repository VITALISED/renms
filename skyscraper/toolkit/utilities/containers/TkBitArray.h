#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename Key, unsigned int Size>
class cTkBitArrayStorage
{
    Key mArray[Size / 64];
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
class cTkBitArray<T, false, Size>
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