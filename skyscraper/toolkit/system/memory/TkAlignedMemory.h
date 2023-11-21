#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <uint32_t liSize, uint32_t liAlignment>
class cTkAlignedBlock
{
  public:
    alignas(liAlignment) uint8_t data_[liSize];
    void *void_data() { return static_cast<void *>(data_); }
    const void *void_data() const { return static_cast<const void *>(data_); }
    template <typename Type>
    Type *data_as()
    {
        return static_cast<Type *>(void_data());
    }
    template <typename Type>
    const Type *data_as() const
    {
        return static_cast<const Type *>(void_data());
    }

  private:
    void *operator new(size_t);
    void operator delete(void *);
};

SKYSCRAPER_END