cmake_minimum_required(VERSION 3.19)
project(dilith C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -pedantic -Werror -DFLASH )

set ( SOURCES
        testvectors.c
        fips202.c
        ntt.c
        packing.c
        poly.c
        polyvec.c
        randombytes.c
        reduce.c
        rounding.c
        sign.c
        symmetric-shake.c
        blober.h
        )

add_executable(dilith  ${SOURCES} )

