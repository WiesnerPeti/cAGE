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

struct TransMatrix{
    F32 m11;
    F32 m12;
    F32 m13;
    F32 m14;
    F32 m21;
    F32 m22;
    F32 m23;
    F32 m24;
    F32 m31;
    F32 m32;
    F32 m33;
    F32 m34;
    F32 m41;
    F32 m42;
    F32 m43;
    F32 m44;
    
    static TransMatrix identity(){
        return {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
    }
    
    static TransMatrix invalidTransMatrix(){
        
        static TransMatrix invalid = {
            NAN, NAN, NAN, NAN,
            NAN, NAN, NAN, NAN,
            NAN, NAN, NAN, NAN,
            NAN, NAN, NAN, NAN
        };
        return invalid;
    }
    
    TransMatrix multiply(TransMatrix m){
        return {
            m11*m.m11 + m12*m.m21 + m13*m.m31 + m14*m.m41,
                m11*m.m21 + m12*m.m22 + m13*m.m23 + m14*m.m24,
                    m11*m.m31 + m12*m.m32 + m13*m.m33 + m14*m.m34,
                        m11*m.m41 + m12*m.m42 + m13*m.m43 + m14*m.m44,
            m21*m.m11 + m22*m.m21 + m23*m.m31 + m21*m.m41,
                m21*m.m21 + m22*m.m22 + m23*m.m23 + m24*m.m24,
                    m21*m.m31 + m22*m.m32 + m23*m.m33 + m24*m.m34,
                        m21*m.m41 + m22*m.m42 + m23*m.m43 + m24*m.m44,
            m31*m.m11 + m32*m.m21 + m33*m.m31 + m31*m.m41,
                m31*m.m21 + m32*m.m22 + m33*m.m23 + m34*m.m24,
                    m31*m.m31 + m32*m.m32 + m33*m.m33 + m34*m.m34,
                        m31*m.m41 + m32*m.m42 + m33*m.m43 + m34*m.m44,
            m41*m.m11 + m42*m.m21 + m43*m.m31 + m44*m.m41,
                m41*m.m21 + m42*m.m22 + m43*m.m23 + m44*m.m24,
                    m41*m.m31 + m42*m.m32 + m43*m.m33 + m44*m.m34,
                        m41*m.m41 + m42*m.m42 + m43*m.m43 + m44*m.m44
                };
    }
    
    TransMatrix multiply(F32 scale){
        return {
            m11*scale, m12*scale, m13*scale, m14*scale,
            m21*scale, m22*scale, m23*scale, m24*scale,
            m31*scale, m32*scale, m33*scale, m34*scale,
            m41*scale, m42*scale, m43*scale, m44*scale
        };
    }
    
    TransMatrix transpose(){
        return {
                m11, m21, m31, m41,
                m12, m22, m32, m42,
                m13, m23, m33, m43,
                m14, m24, m34, m44
                };
    }
    
    TransMatrix inverse(){
        
        F32 det = determinant();
        
        if(F32Equal(det, 0))
        {
            return invalidTransMatrix();
        }
        
        return LUDecomposition().multiply(1/det);
    }
    
    F32 determinant(){
//           http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
        return
        m11*m22*m33*m44 + m11*m23*m34*m42 + m11*m24*m32*m43 +
        m12*m21*m34*m43 + m12*m23*m31*m44 + m12*m24*m33*m41 +
        m13*m21*m32*m44 + m13*m22*m34*m41 + m13*m24*m31*m42 +
        m14*m21*m33*m42 + m14*m22*m31*m43 + m14*m23*m32*m41 -
        m11*m22*m34*m43 - m11*m23*m32*m44 - m11*m24*m33*m42 -
        m12*m21*m33*m44 - m12*m23*m34*m41 - m12*m24*m31*m43 -
        m13*m21*m34*m42 - m13*m22*m31*m44 - m13*m24*m32*m41 -
        m14*m21*m32*m43 - m14*m22*m33*m41 - m14*m23*m31*m42;
    }
    
    TransMatrix LUDecomposition(){
        F32 b11 = m22*m33*m44 + m23*m34*m42 + m24*m32*m43 - m22*m34*m43 - m23*m32*m44 - m24*m33*m42;
        F32 b12 = m12*m34*m43 + m13*m32*m44 + m14*m33*m42 - m12*m33*m44 - m13*m34*m42 - m14*m32*m43;
        F32 b13 = m12*m23*m44 + m13*m24*m42 + m14*m22*m43 - m12*m24*m43 - m13*m22*m44 - m14*m23*m42;
        F32 b14 = m12*m24*m33 + m13*m22*m34 + m14*m23*m32 - m12*m23*m34 - m13*m24*m32 - m14*m22*m33;
        F32 b21 = m21*m34*m43 + m23*m31*m44 + m24*m33*m41 - m21*m33*m44 - m23*m34*m41 - m24*m31*m43;
        F32 b22 = m11*m33*m44 + m13*m34*m41 + m14*m31*m43 - m11*m34*m43 - m13*m31*m44 - m14*m33*m41;
        F32 b23 = m11*m24*m43 + m13*m21*m44 + m14*m23*m41 - m11*m23*m44 - m13*m24*m41 - m14*m21*m43;
        F32 b24 = m11*m23*m34 + m13*m24*m31 + m14*m21*m33 - m11*m24*m33 - m13*m21*m34 - m14*m23*m31;
        F32 b31 = m21*m32*m44 + m22*m34*m41 + m24*m31*m42 - m21*m34*m42 - m22*m31*m44 - m24*m32*m41;
        F32 b32 = m11*m34*m42 + m12*m31*m44 + m14*m32*m41 - m11*m32*m44 - m12*m34*m41 - m14*m31*m42;
        F32 b33 = m11*m22*m44 + m12*m24*m41 + m14*m21*m42 - m11*m24*m42 - m12*m21*m44 - m14*m22*m41;
        F32 b34 = m11*m24*m32 + m12*m21*m34 + m14*m22*m31 - m11*m22*m34 - m12*m24*m31 - m14*m21*m32;
        F32 b41 = m21*m33*m42 + m22*m31*m43 + m23*m32*m41 - m21*m32*m43 - m22*m33*m41 - m23*m31*m42;
        F32 b42 = m11*m32*m43 + m12*m33*m41 + m13*m31*m42 - m11*m33*m42 - m12*m31*m43 - m13*m32*m41;
        F32 b43 = m11*m23*m42 + m12*m21*m43 + m13*m22*m41 - m11*m22*m43 - m12*m23*m41 - m13*m21*m42;
        F32 b44 = m11*m22*m33 + m12*m23*m31 + m13*m21*m32 - m11*m23*m32 - m12*m21*m33 - m13*m22*m31;
        
        return {
            b11, b12, b13, b14,
            b21, b22, b23, b24,
            b31, b32, b33, b34,
            b41, b42, b43, b44
        };
    }
    
    TransMatrix pureRotationInverse()
    {
        return transpose();
    }
    
    TransMatrix pureScaleInverse()
    {
        return {
                1/m11 ?: 1,0,0,0,
                0,1/m22 ?: 1,0,0,
                0,0,1/m33 ?: 1,0,
                0,0,0,1
        };
    }
    
    TransMatrix pureTranslateInverse()
    {
        return {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            -m41,-m42,-m43,1
        };
    }
    
    B8 equals(TransMatrix m){
        return
        F32Equal(m11, m.m11) && F32Equal(m12, m.m12) && F32Equal(m13, m.m13) && F32Equal(m14, m.m14) &&
        F32Equal(m21, m.m21) && F32Equal(m22, m.m22) && F32Equal(m23, m.m23) && F32Equal(m24, m.m24) &&
        F32Equal(m31, m.m31) && F32Equal(m32, m.m32) && F32Equal(m33, m.m33) && F32Equal(m34, m.m34) &&
        F32Equal(m41, m.m41) && F32Equal(m42, m.m42) && F32Equal(m43, m.m43) && F32Equal(m44, m.m44);
    }
};

#endif /* Math_hpp */
