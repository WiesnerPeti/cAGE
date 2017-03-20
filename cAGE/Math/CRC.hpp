#include "Types.h"
#include <stdlib.h>

/* CRC-32C (iSCSI) polynomial in reversed bit order. */
#define POLY 0x82f63b78

/* CRC-32 (Ethernet, ZIP, etc.) polynomial in reversed bit order. */
/* #define POLY 0xedb88320 */

class CRC32C {
public:
    static U32 crc32c(uint32_t crc, const char *buf, size_t len)
    {
        int k;
        
        crc = ~crc;
        while (len--) {
            crc ^= *buf++;
            for (k = 0; k < 8; k++)
                crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        }
        return ~crc;
    }
};
