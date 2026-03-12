#ifndef FNV_H
#define FNV_H

#include <stddef.h>
#include <stdint.h>

uint32_t fnv1a_32(const void *data, size_t num_bytes);

#endif