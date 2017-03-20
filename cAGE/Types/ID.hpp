//
//  ID.hpp
//  cAGE
//
//  Created by Peti Wiesner on 3/21/17.
//  Copyright © 2017 Peti Wiesner. All rights reserved.
//

#ifndef ID_hpp
#define ID_hpp

#include "Dictionary.hpp"
#include "CRC.hpp"

namespace ids {
    static Dictionary<U32, 10000> g_ids;
}

#define id(STR) ({ids::g_ids.put(STR, CRC32C::crc32c(0, STR, strlen(STR)));ids::g_ids.index(STR);})

#endif /* ID_hpp */
