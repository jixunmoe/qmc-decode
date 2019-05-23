#pragma once

#include <cstdint>
#include <vector>

class Crypto
{
public:
	Crypto();
	~Crypto();

	void transform(uint8_t* data, unsigned int offset, size_t size);

	uint8_t encode(unsigned int i);
};

