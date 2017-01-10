/*
 *  cAGE.cpp
 *  cAGE
 *
 *  Created by Peti Wiesner on 2017. 01. 03..
 *  Copyright © 2017. Peti Wiesner. All rights reserved.
 *
 */

#include <iostream>
#include "cAGE.hpp"

void cAGE::Init(){
    logManager.startUp();
    fileManager.startUp();
    resourceManager.startUp();
    
    //Simulate
    
    resourceManager.shutDown();
    fileManager.shutDown();
    logManager.shutDown();
}

