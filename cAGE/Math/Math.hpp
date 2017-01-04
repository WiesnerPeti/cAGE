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

const static F32 kF32nearZero = 0.0001;

B8 F32Equal(F32 left, F32 right){
    return fabsf(left-right) < kF32nearZero;
}

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
    
    Vector LERP(Vector v,F32 beta){
        return multiply(1-beta).add(v.multiply(beta));
    }
    
    B8 isCollinear(Vector v){
        return dotProduct(v) >= 1;
    }
    
    B8 isCollinearOpposite(Vector v){
        return dotProduct(v) <= -1;
    }
    
    B8 isSameDirection(Vector v){
        return dotProduct(v) > 0;
    }
    
    B8 isOppositeDirection(Vector v){
        return dotProduct(v) < 0;
    }
    
    B8 equals(Vector v){
        return F32Equal(x, v.x) && F32Equal(y, v.y) && F32Equal(z, v.z);
    }
    
    static Vector i(){
        return {1,0,0};
    }
    
    static Vector j(){
        return {0,1,0};
    }
    
    static Vector k(){
        return {0,0,1};
    }
};

//Using 4x3 matrixes to save memory, rightmost column is always [0, 0, 0, 1]
struct TransMatrix{
    F32 m11;
    F32 m12;
    F32 m13;
    F32 m21;
    F32 m22;
    F32 m23;
    F32 m31;
    F32 m32;
    F32 m33;
    F32 m41;
    F32 m42;
    F32 m43;
    
    static TransMatrix identity(){
        return {
            1,0,0,
            0,1,0,
            0,0,1,
            0,0,0,
        };
    }
    
    TransMatrix multiply(TransMatrix m){
        return {
                m11*m.m11 + m12*m.m21 + m13*m.m31 ,m11*m.m21 + m12*m.m22 + m13*m.m23 ,m11*m.m31 + m12*m.m32 + m13*m.m33 ,
                m21*m.m11 + m22*m.m21 + m23*m.m31 ,m21*m.m21 + m22*m.m22 + m23*m.m23 ,m21*m.m31 + m22*m.m32 + m23*m.m33 ,
                m31*m.m11 + m32*m.m21 + m33*m.m31 ,m31*m.m21 + m32*m.m22 + m33*m.m23 ,m31*m.m31 + m32*m.m32 + m33*m.m33 ,
                m41*m.m11 + m42*m.m21 + m43*m.m31 ,m41*m.m21 + m42*m.m22 + m43*m.m23 ,m41*m.m31 + m42*m.m32 + m43*m.m33
                };
    }
    
    B8 equals(TransMatrix m){
        return
        F32Equal(m11, m.m11) && F32Equal(m12, m.m12) && F32Equal(m13, m.m13) &&
        F32Equal(m21, m.m21) && F32Equal(m22, m.m22) && F32Equal(m23, m.m23) &&
        F32Equal(m31, m.m31) && F32Equal(m32, m.m32) && F32Equal(m33, m.m33) &&
        F32Equal(m41, m.m41) && F32Equal(m42, m.m42) && F32Equal(m43, m.m43);
    }
};

class Math{
    
};

#endif /* Math_hpp */
