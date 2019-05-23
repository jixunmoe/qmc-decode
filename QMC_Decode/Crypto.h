#pragma once

#include <cstdint>
#include <vector>

class Crypto
{
public:
	Crypto();
	~Crypto();

	void encrypt(std::vector<uint8_t>& data, unsigned int offset, size_t size);

	uint8_t encode(uint8_t c, unsigned int i);
};

