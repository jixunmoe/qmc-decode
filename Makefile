CC?=gcc
CFLAGS?=-Wall -std=c11

OBJS = src/main.o \
       src/qmc_crypto.o

EXT?=.exe

OUT=qmc_crypto$(EXT)

%.o: %.c
	$(CC) $(CFLAGS) -O2 -c -o $@ $<

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

strip: 
	strip $(OUT)

all: $(OUT)
release: $(OUT) strip

.PHONY: clean
clean:
	rm -f src/*.o $(OUT)
