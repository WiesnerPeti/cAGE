//
//  Math.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef Math_hpp
#define Math_hpp

#include <math.h>

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
    
    void add(Vector v){
        x += v.x;
        y += v.y;
        z += v.z;
    }
    
    void substract(Vector v){
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }
    
    bool equals(Vector v){
        return fabsf(x-v.x) < 0.0001 && fabsf(y-v.y) < 0.0001 && fabsf(z-v.z) < 0.0001;
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
