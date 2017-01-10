//
//  LogManager.cpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "LogManager.hpp"
#import <iostream>

void LogManager::log(const char *message){

    std::cout << message << std::endl;
}
