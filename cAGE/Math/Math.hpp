//
//  Math.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef Math_hpp
#define Math_hpp

#include "Types.h"

struct Point{
    F32 x;
    F32 y;
    F32 z;
};

struct Vector{
    F32 x;
    F32 y;
    F32 z;
    
    void multiply(F32 scale){
        x *= scale;
        y *= scale;
        z *= scale;
    }
};

//Using 4x3 matrixes to save memory, rightmost column is always [0, 0, 0, 1]
struct TransformationMatrix{
    F32 m11;
    F32 m12;
    F32 m13;
    F32 m21;
    F32 m22;
    F32 m23;
    F32 m31;
    F32 m32;
    F32 m33;
};

class Math{
    
};

#endif /* Math_hpp */
