//
//  FileManager.cpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "FileManager.hpp"
#include "LogManager.hpp"

void FileManager::startUp(){
    LogManager::sharedInstance().log("FileManager started");
}

void FileManager::shutDown(){
   LogManager::sharedInstance().log("FileManager shut down");
}
