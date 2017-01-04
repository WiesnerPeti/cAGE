//
//  Assertion.h
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef Assertion_h
#define Assertion_h

#include <iostream>
#include <math.h>

#define ASSERTION_ENABLED 1

#if ASSERTION_ENABLED

#define debugBreak() __asm { int 3 }

#define ASSERT(expr) \
    if (expr) {} \
    else \
    {   \
        std::cout << __FUNCTION__ << __FILE__ << __LINE__ << "  " << #expr << std::endl; \
        debugBreak(); \
    }\

#define ASSERTF32Equal(expr, value) ASSERT(fabsf(expr - value) < 0.001)

#else

#define ASSERT(expr)

#endif

#endif /* Assertion_h */
