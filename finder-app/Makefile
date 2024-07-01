
CC=gcc
CFLAGS=

ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
CC=aarch64-none-linux-gnu-gcc
CFLAGS=
endif


SRCS=writer.c
BINS=writer

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BINS)
