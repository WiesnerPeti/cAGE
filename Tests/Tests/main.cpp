//
//  main.cpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include <iostream>
#include "AllTests.hpp"

int main(int argc, const char * argv[]) {
    
    Tests::testVectorMultiplication();
    Tests::testVectorAddition();
    Tests::testVectorSubstraction();
    Tests::testVectorMagnitude();
    Tests::testVectorProduct();
    
    return 0;
}
