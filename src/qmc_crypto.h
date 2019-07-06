#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(__x86_64__) || defined(_WIN64) || defined(__ppc64__) || defined(__x86_64__)
#define IS_WIN64 (true)
#else
#define IS_WIN64 (false)
#endif

#if IS_WIN64
#define BUF_SIZE (1024*1024*4)
#else
#define BUF_SIZE (1024*1024)
#endif

uint8_t qmc_crypto_encode(unsigned int i);
void qmc_crypto_transform(uint8_t* data, unsigned int offset, size_t size);
