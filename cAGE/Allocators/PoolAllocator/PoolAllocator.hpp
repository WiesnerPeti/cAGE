//
//  PoolAllocator.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2/23/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef PoolAllocator_hpp
#define PoolAllocator_hpp

#include "AlignedAllocator.hpp"

template <typename T, U32 N>

class PoolAllocator{
    T* pool[N];
    int currentIndex;
    
public:
    
    PoolAllocator():currentIndex(N-1){
        for (U8 i = 0; i < N; i++) {
            pool[i] = reinterpret_cast<T*>(AlignedAllocator::allocateAligned(sizeof(T), 64));
        }
    }
    
    ~PoolAllocator(){
        for (U32 i = 0; i < N; i++) {
            AlignedAllocator::freeAligned(pool[i]);
        }
    }
    
    T* getItem()
    {
        ASSERT(currentIndex > 0);
        return pool[currentIndex--];
    }
    
    void putItem(T* item)
    {
        ASSERT((currentIndex + 1) <= N-1);
        pool[++currentIndex] = item;
    }
    
    U8 availableAmount(){
        return currentIndex+1;
    }
};

#endif /* PoolAllocator_hpp */
