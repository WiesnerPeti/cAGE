/*
 *  cAGE.hpp
 *  cAGE
 *
 *  Created by Peti Wiesner on 2017. 01. 03..
 *  Copyright © 2017. Peti Wiesner. All rights reserved.
 *
 */

#ifndef cAGE_
#define cAGE_

/* The classes below are exported */
#pragma GCC visibility push(default)

#import "Manager.hpp"

#import "LogManager.hpp"
#import "FileManager.hpp"
#import "ResourceManager.hpp"

class cAGE : public Manager<cAGE>
{
private:
    LogManager logManager;
    FileManager fileManager;
    ResourceManager resourceManager;
public:
    cAGE():fileManager(),resourceManager(),logManager(){}
    ~cAGE(){}
    
    void Init();
};

#pragma GCC visibility pop
#endif
