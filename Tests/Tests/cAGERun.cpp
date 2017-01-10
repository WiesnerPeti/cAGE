//
//  cAGERun.cpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "cAGERun.hpp"
#include "cAGE.hpp"

void cAGERun::runcAGE(){
    Manager<cAGE>::sharedInstance().Init();
}
