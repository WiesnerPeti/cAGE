//
//  AlignedAllocator.cpp
//  cAGE
//
//  Created by Peti Wiesner on 2/23/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#include "AlignedAllocator.hpp"
#include <stdlib.h>

void* AlignedAllocator::allocateUnaligned(size_t size_bytes)
{
    return (void*)malloc(size_bytes);
}

void AlignedAllocator::freeUnaligned(void* pMem)
{
    free(pMem);
}

void* AlignedAllocator::allocateAligned(size_t size_bytes,size_t alignment)
{
    ASSERT(alignment >= 1);
    ASSERT(alignment <= 128);
    ASSERT((alignment & (alignment - 1)) == 0);
    
    size_t expandedSize_bytes = size_bytes + alignment;
    
    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(allocateUnaligned(size_bytes));
    
    size_t mask = (alignment-1);
    uintptr_t misalignment = (rawAddress & mask);
    ptrdiff_t adjusment = alignment - misalignment;
    
    uintptr_t alignedAddress = rawAddress + adjusment;
    
    ASSERT(adjusment < 256)
    U8* pAlignedMem = reinterpret_cast<U8*>(alignedAddress);
    pAlignedMem[-1] = static_cast<U8>(adjusment);
    
    return static_cast<void*>(pAlignedMem);
}

void AlignedAllocator::freeAligned(void* pMem)
{
    const U8* pAlignedMem = reinterpret_cast<const U8*>(pMem);
    
    uintptr_t alignedAddress = reinterpret_cast<uintptr_t>(pMem);
    
    ptrdiff_t adjustment = static_cast<ptrdiff_t>(pAlignedMem[-1]);
    
    uintptr_t rawAddress = alignedAddress - adjustment;
    
    void *pRawMem = reinterpret_cast<void*>(rawAddress);
    
    freeUnaligned(pRawMem);
}
