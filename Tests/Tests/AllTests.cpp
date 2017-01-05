//
//  AllTests.cpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "AllTests.hpp"

#include "Math.hpp"
#include "Assertion.h"

#pragma mark - Vector Tests
void VectorTests::testVectorMultiplication()
{
    Vector v = {1,1,1};
    
    ASSERT(v.multiply(5).equals({5,5,5}));
}

void VectorTests::testVectorAddition(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    ASSERT(v1.add(v2).equals({3,3,3}));
}

void VectorTests::testVectorSubstraction(){
    Vector v1 = {2,2,2};
    Vector v2 = {1,1,1};
    
    ASSERT(v1.substract(v2).equals({1,1,1}));
}

void VectorTests::testVectorMagnitude(){
    
    Vector v = {1,2,3};
    
    F32 m = v.magnitudeP2();
    
    ASSERTF32Equal(m, 14);
}

void VectorTests::testVectorProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    F32 p = v1.dotProduct(v2);
    
    ASSERTF32Equal(p, 13);
}

void VectorTests::testVectorCrossProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    Vector v3 = v1.crossProduct(v2);
    
    ASSERT(v3.equals({1,-5, 2}));
}

void VectorTests::testVectorLERP(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    Vector v3 = v1.LERP(v2, 0.4);
    
    ASSERT(v3.equals({1.4, 1.4,1.4}));
}

#pragma mark - Matrix tests
void MatrixTests::testMatrixMultiplication(){
    TransMatrix m = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };
    
    TransMatrix i = TransMatrix::identity();
    
    ASSERT(m.equals(m.multiply(i)))
}

void MatrixTests::testMatrixTranspose(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,16
    };
    
    TransMatrix transposeM = m.transpose();
    
    ASSERT(transposeM.equals(
                            {1,5,9,13,
                             2,6,10,14,
                             3,6,11,15,
                             4,8,12,16
                            }));
}

void MatrixTests::testMatrixDeterminant(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,1
    };
    
    ASSERTF32Equal(m.determinant(), 120);
}

void MatrixTests::testMatrixInverse(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,1
    };
    
    TransMatrix inverseM = m.inverse();
    TransMatrix result = m.multiply(inverseM);
    
    ASSERT(result.equals(TransMatrix::identity()));
}
