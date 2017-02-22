//
//  LinkedList.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2/22/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <stdlib.h>

#include "Link.hpp"

template <typename T>

struct LinkedList{
    
    Link<T> root;
    
    void addItem(T* item)
    {
        //TODO: We should use custom allocator here
        Link<T> *link = (Link<T>*)malloc(sizeof(Link<T>));
        link->item = item;
        
        this->root.prev = link;
        this->root.next = link;
    }
};

#endif /* LinkedList_hpp */
