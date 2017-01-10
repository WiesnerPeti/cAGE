//
//  ResourceManager.cpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "ResourceManager.hpp"
#include "LogManager.hpp"

void ResourceManager::startUp(){
    LogManager::sharedInstance().log("ResourceManager started");
}

void ResourceManager::shutDown(){
    LogManager::sharedInstance().log("ResourceManager shut down");
}
