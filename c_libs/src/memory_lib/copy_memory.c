#include "macros.h"
#include "memory.h"
#include <unistd.h>

void *copy_memory(void *dest, const void *src, size_t n)
{
    if (dest == NULL_POINTER || src == NULL_POINTER) return NULL_POINTER;
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return dest;
}