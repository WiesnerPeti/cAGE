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
    
    Vector multiply(F32 scale){
        return {x*scale , y*scale, z *scale};
    }
    
    Vector add(Vector v){
        return {x+v.x, y+v.y, z+v.z};
    }
    
    Vector substract(Vector v){
        return {x-v.x, y-v.y, z-v.z};
    }
    
    //To avoid using too much sqrt, we return the power of two
    F32 magnitudeP2(){
        return x*x + y*y + z*z;
    }
    
    F32 dotProduct(Vector v){
        return x*v.x + y*v.y + z*v.z;
    }
    
    Vector crossProduct(Vector v){
        return {y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.y};
    }
    
    bool isCollinear(Vector v){
        return dotProduct(v) >= 1;
    }
    
    bool isCollinearOpposite(Vector v){
        return dotProduct(v) <= -1;
    }
    
    bool isSameDirection(Vector v){
        return dotProduct(v) > 0;
    }
    
    bool isOppositeDirection(Vector v){
        return dotProduct(v) < 0;
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
