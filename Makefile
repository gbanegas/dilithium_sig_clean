CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O3 
AR     = gcc

TIDY   = clang-tidy
CFLAGS_TIDY ?= -std=c99

LIB=libdilithium2_clean.a
HEADERS=api.h ntt.h packing.h params.h poly.h polyvec.h reduce.h rounding.h sign.h symmetric.h 
OBJECTS=ntt.o packing.o poly.o polyvec.o reduce.o rounding.o sign.o symmetric-shake.o 

TIDYCHECKS ?= -checks=*,-readability-isolate-declaration,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers,-cppcoreguidelines-init-variables
TIDYFLAGS ?= $(TIDYCHECKS) -warnings-as-errors=*
TIDYSRCS = $(OBJECTS:.o=.c)

#CFLAGS=-O3 -Wall -Wextra -Wpedantic -Werror -Wmissing-prototypes -Wredundant-decls -std=c99  $(EXTRAFLAGS)

clang-tidy:
	$(TIDY) $(TIDYFLAGS) $(TIDYSRCS) -- $(CFLAGS) $(CFLAGS_TIDY)

all: $(LIB)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIB)

.PHONY: clang-tidy
