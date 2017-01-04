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

#define ASSERTION_ENABLED 1

#if ASSERTION_ENABLED

#define debugBreak() asm { int 3 }

#define ASSERT(expr) \
    if (expr) {} \
    else \
    {   \
        std::cout << #expr << __FILE__ << __LINE__ << std::endl; \
        debugBreak(); \
    }\

#else

#define ASSERT(expr)

#endif

#endif /* Assertion_h */
