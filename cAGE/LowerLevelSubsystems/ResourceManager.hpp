//
//  ResourceManager.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include "Manager.hpp"

class ResourceManager : public Manager<ResourceManager>{
public:
    void startUp();
    void shutDown();
};

#endif /* ResourceManager_hpp */
