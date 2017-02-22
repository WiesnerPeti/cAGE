//
//  Link.hpp
//  cAGE
//
//  Created by Peti Wiesner on 2/22/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef Link_hpp
#define Link_hpp

template <typename T>
struct Link{
    Link<T> *prev;
    Link<T> *next;
    T *item;
};

#endif /* Link_hpp */
