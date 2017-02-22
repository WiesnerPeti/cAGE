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

#include "Assertion.h"
#include "Link.hpp"

template <typename T>

struct LinkedList{
    
    Link<T> root;
    
    void add(T* item)
    {
        //TODO: We should use custom allocator here
        Link<T> *link = (Link<T>*)malloc(sizeof(Link<T>));
        
        link->item = item;
        
        link->next = &root;
        link->prev = root.prev ?: &root;
        root.prev = link;
        root.next = root.next ?: link;
    }
    
    Link<T>* find(T* item)
    {
        Link<T> *iterator = root.next;
        while(iterator != &root)
        {
            T *currentItem = iterator->item;
            if(*currentItem == *item)
            {
                return iterator;
            }
            iterator = iterator->next;
        }
        return NULL;
    }
    
    void remove(Link<T>* link)
    {
        ASSERT(link->prev != NULL || link->next != NULL);
        
        link->next->prev = link->prev;
        link->prev->next = link->next;
        link->prev = link->next = NULL;
    }
};

#endif /* LinkedList_hpp */
