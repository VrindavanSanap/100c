/*
  for 32 bit implementation
    Offset basis: 2166136261 (0x811C9DC5)
    Prime: 16777619 (0x01000193)

*/
#include "fnv.h"

#define FNV_OFFSET_BASIS UINT32_C(2166136261)
#define FNV_PRIME UINT32_C(16777619)

uint32_t fnv1a_32(const void *data, size_t num_bytes) {
  const uint8_t *ptr = (const uint8_t *)data;
  uint32_t hash = FNV_OFFSET_BASIS;

  for (size_t i = 0; i < num_bytes; i++) {
    hash ^= ptr[i];
    hash *= FNV_PRIME;  // Multiply by the prime
  }
  return hash;
}