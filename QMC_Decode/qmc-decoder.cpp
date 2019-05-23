#include "Crypto.h"

#include <cstdio>
#include <cstdint>

#include <iostream>
#include <fstream>

// 1M buf size
// Check windows
#if defined(__x86_64__) || defined(_WIN64) || defined(__ppc64__)
#define IS_WIN64 (true)
#else
#define IS_WIN64 (false)
#endif

#if IS_WIN64
#define BUF_SIZE (1024*1024*4)
#else
#define BUF_SIZE (1024*1024)
#endif

int main(int argc, char** argv)
{
	printf("QMC decoder (cli) v1.0 by Jixun\n");
	printf("\n");

	if (argc < 3)
	{
		printf("usage: %s <input> <output> [ignored]\n", argv[0]);
		return 1;
	}

	std::ifstream input = std::ifstream(argv[1], std::ifstream::binary);
	std::ofstream output = std::ofstream(argv[2], std::ifstream::binary);

	input.seekg(0, std::istream::beg);

	Crypto* crypto = new Crypto();
	uint8_t* buf = new uint8_t[BUF_SIZE];
	unsigned int offset = 0;

	while (!input.eof())
	{
		input.read((char*)buf, BUF_SIZE);
		std::size_t bytesRead = static_cast<std::size_t>(input.gcount());

		if (bytesRead > 0)
		{
			crypto->transform(buf, offset, bytesRead);
			output.write((char*)buf, bytesRead);
			offset += bytesRead;
		}
	}
	printf("ok: %ud bytes processed.\n", offset);
	return 0;
}