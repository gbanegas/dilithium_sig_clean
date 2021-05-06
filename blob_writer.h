#ifndef DILITHIUM_SIG_CLEAN_BLOB_WRITER_H
#define DILITHIUM_SIG_CLEAN_BLOB_WRITER_H

#include "poly.h"
#include "params.h"
#include "polyvec.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void save(const uint8_t rho[SEEDBYTES],
          const polyveck *t1);

void read_rho_t1(uint8_t rho[SEEDBYTES],
                 polyveck *t1);

#endif //DILITHIUM_SIG_CLEAN_BLOB_WRITER_H
