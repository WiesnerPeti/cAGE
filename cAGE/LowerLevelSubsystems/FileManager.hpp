//
//  FileManager.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include "Manager.hpp"

class FileManager : public Manager<FileManager>{
public:
    void startUp();
    void shutDown();
};

#endif /* FileManager_hpp */
