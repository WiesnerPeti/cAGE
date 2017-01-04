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
    
    ASSERT(v.x == 5 && v.y == 5 && v.z == 5);
}

