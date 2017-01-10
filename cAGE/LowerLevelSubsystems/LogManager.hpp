//
//  LogManager.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef LogManager_hpp
#define LogManager_hpp

#include "Manager.hpp"

class LogManager : public Manager<LogManager>{
public:
    void log(const char *message);
};

#endif /* LogManager_hpp */
