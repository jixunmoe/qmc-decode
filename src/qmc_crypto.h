#pragma once

#include <stdint.h>

uint8_t qmc_crypto_encode(unsigned int i);
void qmc_crypto_transform(uint8_t* data, unsigned int offset, size_t size);
