//
//  Dictionary.hpp
//  cAGE
//
//  Created by Peti Wiesner on 3/20/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include "Types.h"
#include "AlignedAllocator.hpp"
#include "CRC.hpp"

template <typename V, U32 N>
class Dictionary{
private:
    V buckets[N];
    U32 c;
public:
    Dictionary() : c(0){
        for (U32 i = 0; i < N; i++) {
            buckets[i] = U32_MAX;
        }
    }
    
    void put(const char *key, V value)
    {
        buckets[index(key)] = value;
        if (c < N) c++;
    }
    
    void remove(const char *key){
        buckets[index(key)] = U32_MAX;
        if (c > 0) c--;
    }
    
    U32 get(const char *key)
    {
        return buckets[index(key)];
    }
    
    U32 index(const char *key){
        return CRC32C::crc32c(0, key, strlen(key)) % N;
    }
    
    U32 count(){
        return c;
    }
};

#endif /* Dictionary_hpp */
