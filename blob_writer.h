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

void save_matrix(polyvecl mat[K]);

void read_mat(polyvecl mat[K]);

void read_rho_t1(uint8_t rho[SEEDBYTES],
                 polyveck *t1);


void save_pk(uint8_t pk[CRYPTO_PUBLICKEYBYTES]);

void save_sk(uint8_t sk[CRYPTO_SECRETKEYBYTES]);

void load_sk(uint8_t *sk);
void load_pk(uint8_t *pk);



#endif //DILITHIUM_SIG_CLEAN_BLOB_WRITER_H
