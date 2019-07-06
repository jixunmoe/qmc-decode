#include "qmc_crypto.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 1M buf size
// Check windows
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

int main(int argc, char** argv)
{
	printf("QMC decoder (cli) v1.0 by Jixun\n");
	printf("\n");

	if (argc < 3)
	{
		printf("usage: %s <input> <output> [ignored]\n", argv[0]);
		return 1;
	}

	FILE* fIn = fopen(argv[1], "rb");
	FILE* fOut = fopen(argv[2], "wb");
	fseek(fIn , 0 , SEEK_SET);

	uint8_t* buf = (uint8_t*)malloc(BUF_SIZE * sizeof(uint8_t));
	unsigned int offset = 0;

	while (!feof(fIn))
	{
	    size_t bytesRead = fread ((char*)buf, sizeof(char), BUF_SIZE, fIn);

		if (bytesRead > 0)
		{
			qmc_crypto_transform(buf, offset, bytesRead);
			// output.write((char*)buf, bytesRead);
			fwrite((char*)buf, sizeof(char), bytesRead, fOut);
			offset += bytesRead;
		}
	}
	printf("ok: %u bytes processed.\n", offset);
	return 0;
}
