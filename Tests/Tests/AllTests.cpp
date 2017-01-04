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

void Tests::testVectorMultiplication()
{
    Vector v = {1,1,1};
    
    ASSERT(v.multiply(5).equals({5,5,5}));
}

void Tests::testVectorAddition(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    ASSERT(v1.add(v2).equals({3,3,3}));
}

void Tests::testVectorSubstraction(){
    Vector v1 = {2,2,2};
    Vector v2 = {1,1,1};
    
    ASSERT(v1.substract(v2).equals({1,1,1}));
}

void Tests::testVectorMagnitude(){
    
    Vector v = {1,2,3};
    
    F32 m = v.magnitudeP2();
    
    ASSERTF32Equal(m, 14);
}

void Tests::testVectorProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    F32 p = v1.dotProduct(v2);
    
    ASSERTF32Equal(p, 13);
}

void Tests::testVectorCrossProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    Vector v3 = v1.crossProduct(v2);
    
    ASSERT(v3.equals({1,-5, 2}));
}
