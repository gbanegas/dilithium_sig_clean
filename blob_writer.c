
#include "blob_writer.h"

void save(const uint8_t rho[SEEDBYTES],
          const polyveck *t1){
    int i;
    FILE *frho;
    FILE *ft1;


    frho = fopen("rho.key","w");
    ft1 = fopen("t1.key","w");
    for (i = 0; i < SEEDBYTES; ++i) {
        fprintf(frho,"%hhu ",rho[i]);

    }

    for (i = 0; i < K; ++i) {
        for (int j = 0; j < N / 4; ++j) {
            uint8_t a = (uint8_t) (t1->vec[i].coeffs[4 * j + 0] >> 0);
            uint8_t b = (uint8_t) ((t1->vec[i].coeffs[4 * j + 0] >> 8) | (t1->vec[i].coeffs[4 * j + 1] << 2));
            uint8_t c = (uint8_t) ((t1->vec[i].coeffs[4 * j + 1] >> 6) | (t1->vec[i].coeffs[4 * j + 2] << 4));
            uint8_t d = (uint8_t) ((t1->vec[i].coeffs[4 * j + 2] >> 4) | (t1->vec[i].coeffs[4 * j + 3] << 6));
            uint8_t e = (uint8_t) (t1->vec[i].coeffs[4 * j + 3] >> 2);
            fprintf(ft1,"%hhu ",a);
            fprintf(ft1,"%hhu ",b);
            fprintf(ft1,"%hhu ",c);
            fprintf(ft1,"%hhu ",d);
            fprintf(ft1,"%hhu ",e);


        }
    }



    fclose(frho);
    fclose(ft1);
}

void save_matrix(polyvecl mat[K]){


    FILE *frho;
    frho = fopen("matrix_flash.key","w");

    for(int i = 0; i < K; i++){
        for(int j  = 0 ; j < L;j++){
            poly p = mat[i].vec[j];
            for(int k = 0; k < N; k++){
               // printf("coeff: %d\n", p.coeffs[k]);
                fprintf(frho,"%d ", p.coeffs[k]);
               // fprintf(f_mat,"%d ",p.coeffs[k]);
            }
        }
    }
    //printf("\n--------------------\n");

    fclose(frho);



}

void read_mat(polyvecl mat[K]){
    FILE *fp = fopen("mat.key", "r");
    int i,l,k;
    for (i = 0; i < K; i++) {
        for (l = 0; l < L; l++) {
            poly p;
            for (k = 0; k < N; k++) {
                int32_t tmp = 0;
                fscanf(fp, "%d", &tmp);
                p.coeffs[k] = tmp;
              //  printf("%d, ", tmp);
            }
            mat[i].vec[l] = p;
        }
    }
   // printf("\n");


}

void read_rho_t1(uint8_t rho[SEEDBYTES],
                 polyveck *t1){

    FILE *frho;
    FILE *ft1;
    int i,j;

    frho = fopen("rho.key","r");
    ft1 = fopen("t1.key","r");

    for (i = 0; i < SEEDBYTES; ++i) {
        fscanf(frho,"%hhu", &rho[i]);
    }

    for (i = 0; i < K; ++i) {
       for (j = 0; j < N / 4; ++j) {
            uint8_t a,b,c,d,e;
            fscanf(ft1,"%hhu",&a);
            fscanf(ft1,"%hhu",&b);
            fscanf(ft1,"%hhu",&c);
            fscanf(ft1,"%hhu",&d);
            fscanf(ft1,"%hhu",&e);
            t1->vec[i].coeffs[4 * j + 0] = ((a >> 0) | ((uint32_t)b << 8)) & 0x3FF;
            t1->vec[i].coeffs[4 * j + 1] = ((b >> 2) | ((uint32_t)c << 6)) & 0x3FF;
            t1->vec[i].coeffs[4 * j + 2] = ((c >> 4) | ((uint32_t)d << 4)) & 0x3FF;
            t1->vec[i].coeffs[4 * j + 3] = ((d >> 6) | ((uint32_t)e << 2)) & 0x3FF;
        }
    }

}

void save_pk(uint8_t pk[CRYPTO_PUBLICKEYBYTES]){
    FILE *fp = fopen("pk.key", "w");
    for(int i =0; i < CRYPTO_PUBLICKEYBYTES;i++){
        fprintf(fp,"%hhu ",pk[i]);
    }
    fclose(fp);
}

void save_sk(uint8_t sk[CRYPTO_SECRETKEYBYTES]){

    FILE *fp = fopen("sk.key", "w");
    for(int i =0; i < CRYPTO_SECRETKEYBYTES;i++){
        fprintf(fp,"%hhu ",sk[i]);
    }

    fclose(fp);
}

void load_sk(uint8_t *sk){
    FILE *fp = fopen("sk.key", "r");
    for(int i =0; i < CRYPTO_SECRETKEYBYTES;i++){
        fscanf(fp,"%hhu", &sk[i]);
    }

    fclose(fp);
}

void load_pk(uint8_t *pk){
    FILE *fp = fopen("pk.key", "r");
    for(int i =0; i < CRYPTO_PUBLICKEYBYTES;i++){
        fscanf(fp,"%hhu", &pk[i]);
    }

    fclose(fp);
}