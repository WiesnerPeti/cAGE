//
//  AlignedAllocator.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2/23/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef AlignedAllocator_hpp
#define AlignedAllocator_hpp

#include <cstddef>
#include "Assertion.h"
#include "Types.h"

class AlignedAllocator{
private:
    static void* allocateUnaligned(size_t size_bytes);
    static void freeUnaligned(void* pMem);
public:
    static void* allocateAligned(size_t size_bytes,size_t alignment);
    static void freeAligned(void* pMem);
};

#endif /* AlignedAllocator_hpp */
