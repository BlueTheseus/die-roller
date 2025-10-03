CFLAGS = -std=c99 -Wall -O0
LDFLAGS = -lrt -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now

OBJS = die-roller.o

.PHONY: all
all: die-roller

die-roller: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) die-roller
