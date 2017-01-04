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
    
    v.multiply(5);
    
    ASSERT(v.equals({5,5,5}));
}

void Tests::testVectorAddition(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    v1.add(v2);
    
    ASSERT(v1.equals({3,3,3}));
}

void Tests::testVectorSubstraction(){
    Vector v1 = {2,2,2};
    Vector v2 = {1,1,1};
    
    v1.substract(v2);
    
    ASSERT(v1.equals({1,1,1}));
}

