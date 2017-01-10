//
//  Manager.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2017. 01. 10..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp

template <class T> class Manager {
    
public:
    Manager<T>(){}
    ~Manager<T>(){}
    
    static T& sharedInstance() {
        static T* instance = nullptr;
        if(instance == nullptr)
        {
            instance = new T();
        }
        return *instance;
    }

    
    void startUp(){}
    void shutDown(){}
};

#endif /* Manager_hpp */
