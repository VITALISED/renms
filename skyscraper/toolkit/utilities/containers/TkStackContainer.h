/**
 * @file TkStackContainer.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// this is taken straight from Chromium, as it seems NMS' is also a literally copy of this

#pragma once

#include <skyscraper.h>

#include <toolkit/system/memory/TkAlignedMemory.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

#include <memory>

SKYSCRAPER_BEGIN

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator=(const TypeName &)

template <typename T, size_t stack_capacity>
class StackAllocator : public std::allocator<T>
{
  public:
    typedef T *pointer; // this differs due to chromium being on old cpp standards
    typedef typename std::allocator<T>::size_type size_type;
    // Backing store for the allocator. The container owner is responsible for
    // maintaining this for as long as any containers using this allocator are
    // live.
    struct Source
    {
        Source() : used_stack_buffer_(false) {}
        // Casts the buffer in its right type.
        T *stack_buffer() { return stack_buffer_.template data_as<T>(); }
        const T *stack_buffer() const { return stack_buffer_.template data_as<T>(); }
        // The buffer itself. It is not of type T because we don't want the
        // constructors and destructors to be automatically called. Define a POD
        // buffer of the right size instead.
        cTkAlignedBlock<sizeof(T[stack_capacity]), alignof(T)> stack_buffer_;

        // Set when the stack buffer is used for an allocation. We do not track
        // how much of the buffer is used, only that somebody is using it.
        bool used_stack_buffer_;
    };
    // Used by containers when they want to refer to an allocator of type U.
    template <typename U>
    struct rebind
    {
        typedef StackAllocator<U, stack_capacity> other;
    };
    // For the straight up copy c-tor, we can share storage.
    StackAllocator(const StackAllocator<T, stack_capacity> &rhs) : std::allocator<T>(), source_(rhs.source_) {}
    // ISO C++ requires the following constructor to be defined,
    // and std::vector in VC++2008SP1 Release fails with an error
    // in the class _Container_base_aux_alloc_real (from <xutility>)
    // if the constructor does not exist.
    // For this constructor, we cannot share storage; there's
    // no guarantee that the Source buffer of Ts is large enough
    // for Us.
    // TODO: If we were fancy pants, perhaps we could share storage
    // iff sizeof(T) == sizeof(U).
    template <typename U, size_t other_capacity>
    StackAllocator(const StackAllocator<U, other_capacity> &other) : source_(NULL)
    {}
    explicit StackAllocator(Source *source) : source_(source) {}
    // Actually do the allocation. Use the stack buffer if nobody has used it yet
    // and the size requested fits. Otherwise, fall through to the standard
    // allocator.
    pointer allocate(size_type n, void *hint = 0)
    {
        if (source_ != NULL && !source_->used_stack_buffer_ && n <= stack_capacity)
        {
            source_->used_stack_buffer_ = true;
            return source_->stack_buffer();
        }
        else { return std::allocator<T>::allocate(n, hint); }
    }
    // Free: when trying to free the stack buffer, just mark it as free. For
    // non-stack-buffer pointers, just fall though to the standard allocator.
    void deallocate(pointer p, size_type n)
    {
        if (source_ != NULL && p == source_->stack_buffer())
            source_->used_stack_buffer_ = false;
        else
            std::allocator<T>::deallocate(p, n);
    }

  private:
    Source *source_;
};
// A wrapper around STL containers that maintains a stack-sized buffer that the
// initial capacity of the vector is based on. Growing the container beyond the
// stack capacity will transparently overflow onto the heap. The container must
// support reserve().
//
// WATCH OUT: the ContainerType MUST use the proper StackAllocator for this
// type. This object is really intended to be used only internally. You'll want
// to use the wrappers below for different types.
template <typename TContainerType, int stack_capacity>
class StackContainer
{
  public:
    typedef TContainerType ContainerType;
    typedef typename ContainerType::value_type ContainedType;
    typedef StackAllocator<ContainedType, stack_capacity> Allocator;
    // Allocator must be constructed before the container!
    StackContainer() : allocator_(&stack_data_), container_(allocator_)
    {
        // Make the container use the stack allocation by reserving our buffer size
        // before doing anything else.
        container_.reserve(stack_capacity);
    }
    // Getters for the actual container.
    //
    // Danger: any copies of this made using the copy constructor must have
    // shorter lifetimes than the source. The copy will share the same allocator
    // and therefore the same stack buffer as the original. Use std::copy to
    // copy into a "real" container for longer-lived objects.
    ContainerType &container() { return container_; }
    const ContainerType &container() const { return container_; }
    // Support operator-> to get to the container. This allows nicer syntax like:
    //   StackContainer<...> foo;
    //   std::sort(foo->begin(), foo->end());
    ContainerType *operator->() { return &container_; }
    const ContainerType *operator->() const { return &container_; }

  protected:
    typename Allocator::Source stack_data_;
    Allocator allocator_;
    ContainerType container_;
    DISALLOW_COPY_AND_ASSIGN(StackContainer);
};
// StackString
template <size_t stack_capacity>
class StackString
    : public StackContainer<
          std::basic_string<char, std::char_traits<char>, StackAllocator<char, stack_capacity>>, stack_capacity>
{
  public:
    StackString()
        : StackContainer<
              std::basic_string<char, std::char_traits<char>, StackAllocator<char, stack_capacity>>, stack_capacity>()
    {}

  private:
    DISALLOW_COPY_AND_ASSIGN(StackString);
};
// StackWString
template <size_t stack_capacity>
class StackWString : public StackContainer<
                         std::basic_string<wchar_t, std::char_traits<wchar_t>, StackAllocator<wchar_t, stack_capacity>>,
                         stack_capacity>
{
  public:
    StackWString()
        : StackContainer<
              std::basic_string<wchar_t, std::char_traits<wchar_t>, StackAllocator<wchar_t, stack_capacity>>,
              stack_capacity>()
    {}

  private:
    DISALLOW_COPY_AND_ASSIGN(StackWString);
};

/**
 * @brief Mostly 1:1 copy of Chromium's stack vector. See
 * https://chromium.googlesource.com/chromium/chromium/+/master/base/stack_container.h
 */
template <typename T, size_t stack_capacity>
class cTkStackVector : public StackContainer<std::vector<T, StackAllocator<T, stack_capacity>>, stack_capacity>
{
  public:
    cTkStackVector() : cTkStackVector<std::vector<T, StackAllocator<T, stack_capacity>>, stack_capacity>() {}
    // We need to put this in STL containers sometimes, which requires a copy
    // constructor. We can't call the regular copy constructor because that will
    // take the stack buffer from the original. Here, we create an empty object
    // and make a stack buffer of its own.
    cTkStackVector(const cTkStackVector<T, stack_capacity> &other)
        : cTkStackVector<std::vector<T, StackAllocator<T, stack_capacity>>, stack_capacity>()
    {
        this->container().assign(other->begin(), other->end());
    }
    cTkStackVector<T, stack_capacity> &operator=(const cTkStackVector<T, stack_capacity> &other)
    {
        this->container().assign(other->begin(), other->end());
        return *this;
    }
    // Vectors are commonly indexed, which isn't very convenient even with
    // operator-> (using "->at()" does exception stuff we don't want).
    T &operator[](size_t i) { return this->container().operator[](i); }
    const T &operator[](size_t i) const { return this->container().operator[](i); }
};

SKYSCRAPER_END