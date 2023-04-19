#
# libkhepera utils Makefile
#
#
.PHONY: tests clean

SRCS	= $(wildcard *.c)
OBJS	= $(patsubst %.c,%.o,${SRCS})
INCS	= -I ../${BUILD}/include -I ..
LIBS	= -L../${BUILD}/lib -lkhepera
CFLAGS 	= -O3

TARGET	= i2ctest i2cscan

.PHONY: all clean depend

all: 	${TARGET}

i2ctest: i2ctest.o 
	@echo "Building $@"
	@$(CC) -o $@ $^ -static $(LIBS) $(INCS) $(CFLAGS)

i2cscan: i2cscan.o 
	@echo "Building $@"
	@$(CC) -o $@ $^ -static -pthread $(LIBS) $(INCS) $(CFLAGS)

clean : 
	@echo "Cleaning"
	@rm -f *.o .depend ${TARGET} *~

depend:	
	@echo "Building dependencies"
	@rm -f .depend
	@touch .depend
	@makedepend ${SYS_INCLUDES} ${INCS} -Y -f .depend ${SRCS}

%.o:	%.c
	@echo "Compiling $@"
	@$(CC) $(INCS) -c $(CFLAGS) $< -o $@

ifeq (.depend,$(wildcard .depend))
include .depend 
endif
