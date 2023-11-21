#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

template <typename K, typename V>
class cTkKeyPairCompareLess
{};

template <typename K, typename V, typename KeyPairCompare = cTkKeyPairCompareLess<K, V>>
class cTkFlatMap
{
    cTkVector<std::pair<K, V>> mVector;
    bool mbDirty;
};

SKYSCRAPER_END