#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

#define TKBITARRAY_SIZE(size) (Size / 8) < 16 ? 1 : Size / 8

template <uint64_t Key, unsigned int Size>
class cTkBitArrayStorage
{
    Key mArray[TKBITARRAY_SIZE(Size)];
};

template <uint64_t Key>
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
    enum eTkStatic
    {
        eDefault,
    };

    enum eTkDynamic
    {
        eDefault,
    };

    using type = eTkStatic;

    cTkBitArrayStorage<T, Size>
};

template <typename T, unsigned int Size>
class cTkBitArray<T, true, Size>
{
  public:
    enum eTkStatic
    {
        eDefault,
    };

    enum eTkDynamic
    {
        eDefault,
    };

    using type = eTkDynamic;

    cTkBitArrayStorage<T, 0> mStorage;
};

SKYSCRAPER_END