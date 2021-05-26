#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "lattice_sign_api.h"
#include "params.h"
#include "randombytes.h"

#include "blober.h"


#define MAXMLEN 2048

static void printbytes(const uint8_t *x, size_t xlen) {
    size_t i;
    for (i = 0; i < xlen; i++) {
        printf("%02x", x[i]);
    }
    printf("\n");
}

// https://stackoverflow.com/a/1489985/1711232
/*
#define PASTER(x, y) x##_##y
#define EVALUATOR(x, y) PASTER(x, y)
#define NAMESPACE(fun) EVALUATOR(PQCLEAN_NAMESPACE, fun)

#define CRYPTO_PUBLICKEYBYTES NAMESPACE(CRYPTO_PUBLICKEYBYTES)
#define CRYPTO_SECRETKEYBYTES NAMESPACE(CRYPTO_SECRETKEYBYTES)
#define CRYPTO_BYTES          NAMESPACE(CRYPTO_BYTES)

#define crypto_sign_keypair NAMESPACE(crypto_sign_keypair)
#define crypto_sign NAMESPACE(crypto_sign)
#define crypto_sign_open NAMESPACE(crypto_sign_open)
#define crypto_sign_signature NAMESPACE(crypto_sign_signature)
#define crypto_sign_verify NAMESPACE(crypto_sign_verify)
*/

int main(void) {
#ifdef LATTICE_MATRIX_IN_FLASH
    printf("USING STATIC KEYS..\n");
    const  uint8_t sk[] = {
            97,82,224,196,160,235,189,168,248,201,241,136,92,89,145,216,6,198,191,231,158,238,178,9,223,105,88,48,106,201,172,9,121,218,48,152,126,1,21,21,160,110,48,14,90,230,32,246,48,217,56,32,105,1,140,99,175,63,236,97,216,193,222,146,22,152,253,240,29,130,145,140,178,236,12,65,218,148,211,43,118,128,97,248,188,144,203,23,220,4,175,40,53,65,208,155,18,35,78,1,164,69,152,34,4,204,192,5,66,70,133,90,36,144,216,54,49,89,22,72,35,36,133,20,185,136,34,57,142,160,34,17,11,52,137,156,132,101,210,8,68,36,3,36,35,0,136,25,39,76,216,144,97,25,57,102,26,55,100,145,0,41,66,68,114,18,23,13,67,66,41,34,18,1,68,144,49,228,50,102,1,7,36,148,36,6,0,73,65,17,73,74,136,66,68,100,184,40,32,20,10,25,9,137,192,200,32,27,57,146,17,53,133,34,152,144,4,71,104,25,51,4,96,8,66,83,72,8,17,38,132,204,160,68,82,22,146,155,0,68,4,51,98,10,20,46,90,0,65,20,38,44,88,6,33,16,39,37,24,18,130,216,34,102,227,38,8,32,1,66,90,20,104,36,147,69,90,166,81,227,20,98,81,146,17,18,40,8,226,18,106,16,130,13,35,6,34,9,200,113,201,182,73,156,196,8,1,7,104,83,8,5,137,144,40,130,2,6,192,72,81,96,56,102,129,48,10,208,36,81,10,137,132,129,70,134,196,132,68,100,182,141,144,162,140,148,24,69,32,8,101,97,176,101,28,169,97,136,132,73,162,40,12,36,8,70,65,52,80,91,52,4,131,196,76,224,130,145,195,32,13,33,65,134,27,22,18,153,196,108,80,22,2,12,183,72,3,180,69,17,9,1,152,16,81,0,38,112,11,135,108,75,68,38,9,147,5,75,24,142,10,35,132,131,64,77,72,22,136,212,56,73,202,18,4,12,130,101,35,72,108,33,52,144,216,48,136,10,167,145,17,153,68,163,32,70,3,52,106,164,144,16,68,2,105,76,144,97,154,182,13,195,32,69,139,20,1,82,40,37,11,128,77,145,68,98,68,180,44,195,24,129,148,6,129,16,57,114,0,0,132,140,198,104,89,16,48,27,3,69,100,16,18,146,68,12,147,70,138,12,5,101,35,135,17,28,40,112,154,56,109,9,38,100,89,16,128,132,66,16,216,50,146,139,146,9,88,180,41,76,36,100,194,194,105,36,134,76,139,66,14,9,195,101,220,40,44,18,182,132,220,50,133,27,25,0,212,40,13,28,167,1,27,198,12,68,0,132,224,2,73,138,48,130,0,36,2,204,144,40,35,24,10,148,38,34,196,176,136,17,57,42,20,32,66,80,70,37,99,132,45,145,50,81,160,64,128,219,184,1,220,66,4,66,24,1,209,54,136,34,179,13,204,4,8,3,67,106,74,22,137,83,0,33,34,152,73,26,160,12,3,164,104,137,40,9,34,70,36,28,153,32,164,22,10,18,16,137,67,176,40,203,64,2,3,168,16,32,25,98,16,18,72,33,18,73,1,32,132,146,152,1,73,36,32,19,183,73,8,21,44,97,18,36,25,192,137,131,32,44,132,134,144,2,192,141,18,8,42,36,163,65,25,161,105,227,34,70,72,196,100,84,16,46,3,35,9,34,67,33,3,192,140,27,2,100,0,183,9,80,8,97,19,198,112,19,8,10,160,18,12,132,200,133,153,40,32,139,132,76,164,132,17,3,56,134,137,8,42,156,36,146,9,24,16,65,194,48,152,192,100,2,24,4,97,36,109,219,0,18,136,48,146,140,0,106,25,176,69,25,136,140,131,4,10,20,57,50,228,38,97,138,132,72,220,54,130,147,34,36,80,8,9,11,36,98,8,51,72,73,132,48,90,184,81,91,68,101,202,4,18,2,17,97,202,191,64,196,22,27,118,0,246,41,99,244,66,89,83,230,212,95,53,86,44,189,246,142,11,0,47,159,59,46,75,148,54,97,57,9,51,21,162,60,128,9,63,254,31,150,137,181,0,214,29,222,67,1,29,113,36,100,141,45,36,45,101,22,16,189,94,231,59,100,210,13,245,203,8,139,119,45,104,27,25,58,228,182,170,174,129,75,96,97,227,235,129,126,154,152,248,34,81,41,47,5,146,93,248,162,116,66,189,28,239,61,5,171,138,2,177,160,5,148,151,115,241,118,93,149,91,243,103,213,51,11,229,189,62,95,11,179,104,45,115,129,87,75,3,151,131,198,127,178,239,117,230,78,93,186,54,253,75,10,114,28,207,211,21,29,18,60,206,13,167,235,149,212,205,244,206,240,98,118,176,231,142,215,143,235,64,24,12,7,248,28,111,139,37,95,152,143,195,89,95,64,113,211,163,152,175,28,133,108,157,229,248,123,137,255,121,163,84,96,13,155,179,182,166,155,59,113,223,27,62,40,45,110,53,68,109,152,208,57,122,134,222,47,132,180,172,83,93,100,95,67,181,32,254,56,2,208,178,152,11,33,37,217,222,104,87,72,61,60,108,223,165,20,248,220,46,221,177,71,162,24,165,56,29,102,73,141,158,138,242,238,214,0,246,6,198,66,77,243,78,194,18,58,224,153,28,17,149,144,71,192,166,158,192,15,212,171,240,118,199,151,18,154,59,176,207,76,152,97,143,23,46,47,188,143,171,44,115,126,208,54,147,66,109,36,175,198,248,238,92,161,243,167,39,209,145,201,137,29,48,99,5,133,118,41,140,169,30,21,218,222,194,101,134,13,160,118,178,194,124,124,30,21,38,251,26,197,229,61,32,80,29,96,193,71,102,242,165,136,117,37,87,227,252,133,11,227,168,108,207,66,225,152,228,92,84,116,121,17,49,180,57,249,218,75,9,186,91,23,110,117,237,158,100,208,63,6,88,135,126,182,224,123,160,42,97,189,78,98,244,67,67,210,139,139,137,107,22,5,125,5,83,64,138,164,233,40,66,55,74,75,24,235,76,64,96,98,17,161,1,49,22,229,129,241,136,241,45,110,122,250,165,237,61,112,192,129,110,34,168,20,37,94,111,152,157,231,59,193,166,236,4,131,47,150,186,38,28,224,231,121,97,108,2,250,202,24,232,66,254,208,253,83,205,31,122,6,53,251,210,193,69,167,34,75,216,170,185,140,38,255,108,9,185,186,89,117,161,147,91,229,158,71,151,106,198,133,81,76,203,246,133,237,255,106,233,218,231,149,192,65,33,159,110,160,9,207,212,44,76,92,33,157,113,0,25,148,94,86,158,199,93,97,4,212,28,110,213,112,30,81,197,112,218,28,245,184,1,136,246,208,69,172,65,67,222,181,121,245,98,97,0,169,102,36,235,172,105,187,29,202,52,192,146,198,221,118,247,140,65,152,221,70,176,114,130,144,53,130,100,195,108,141,11,98,124,246,9,224,42,137,59,187,240,46,203,134,174,170,211,131,225,209,109,224,191,48,212,236,67,145,155,252,35,146,251,59,159,30,57,166,53,153,60,121,212,108,35,184,18,166,88,231,247,25,16,157,226,111,32,143,176,73,148,141,135,129,228,85,31,230,118,133,54,255,235,8,21,67,195,133,106,128,167,227,195,193,153,152,178,240,246,120,94,136,78,184,207,176,135,134,131,79,157,176,21,73,24,9,49,94,200,133,25,208,22,44,123,9,121,253,54,230,224,200,0,154,17,22,147,44,222,53,102,128,221,40,72,214,188,223,51,225,117,66,220,82,79,203,102,167,157,134,91,68,12,193,158,190,198,143,127,151,243,169,234,148,156,249,19,61,10,61,98,252,154,8,9,59,174,122,163,183,201,234,215,76,213,221,162,59,92,242,27,178,111,61,239,150,111,225,65,252,87,210,99,102,153,68,226,65,7,156,136,70,230,124,82,13,53,43,139,251,130,117,117,74,223,255,63,194,18,188,212,198,146,122,181,107,227,172,185,189,236,229,211,33,204,159,18,158,225,185,19,221,215,171,226,205,86,63,109,134,130,119,7,121,15,57,32,244,253,166,29,130,33,223,26,56,160,178,131,199,83,70,67,2,90,236,146,0,157,214,137,156,149,149,154,157,225,2,175,160,237,87,197,138,196,228,162,148,100,237,223,220,190,11,34,41,86,138,8,43,218,89,196,11,179,235,91,238,187,81,130,223,178,38,140,171,130,253,121,38,205,148,227,66,159,213,18,78,19,253,255,118,103,196,255,185,44,154,155,59,71,119,170,94,30,183,29,38,156,70,135,53,84,8,93,91,22,97,135,244,148,139,246,43,188,240,125,146,209,208,250,63,150,57,55,45,119,30,168,247,71,121,183,210,21,32,64,42,142,187,84,136,139,18,240,206,134,30,7,108,166,15,207,233,3,208,31,192,177,121,81,75,241,165,235,26,205,47,169,11,72,222,38,171,55,201,87,254,40,16,47,5,119,6,115,236,194,158,246,95,14,119,208,49,224,255,31,168,181,69,50,143,225,118,148,49,30,5,30,73,142,2,90,122,39,219,138,238,40,6,236,107,44,175,172,165,3,254,91,146,8,126,243,68,188,108,115,107,40,101,3,89,59,209,174,212,239,156,112,79,189,247,72,205,253,129,80,38,64,129,162,85,193,28,250,70,118,152,204,37,52,130,146,115,78,216,173,75,243,26,15,161,81,243,251,100,32,233,44,79,144,98,63,103,188,174,154,65,244,220,136,88,198,198,195,14,252,165,85,126,224,245,64,16,67,92,47,4,248,79,212,35,119,161,99,6,61,227,65,131,196,17,134,236,106,225,155,44,147,183,84,96,36,105,168,8,126,220,150,12,166,224,51,209,88,136,82,4,91,250,202,4,194,213,185,114,141,44,85,214,76,11,97,128,73,219,145,104,252,125,225,238,101,85,24,80,134,164,12,85,201,189,68,211,131,209,102,26,167,248,218,201,78,172,223,216,150,164,193,180,33,195,152,168,69,101,104,126,23,182,91,100,16,184,26,168,238,31,220,140,129,109,123,53,30,122,159,125,87,222,162,182,234,163,180,71,202,180,177,105,98,68,46,185,47,126,17,237,38,74,169,129,246,130,177,36,133,95,111,32,73,44,94,184,8,123,169,9,218,8,31,239,41,218,224,127,78,97,194,232,248,90,181,20,40,151,252,12,159,108,185,99,178,60,163,30,97,40,136,22,185,146,112,90,80,91,56,120,246,41,236,141,208,145,100,98,235,198,75,252,204,118,38,45,164,80,246,201,53,121,189,19,176,67,104,204,170,18,245,204,21,185,73,126,208,54,149,224,71,8,75,114,197,167,22,138,230,224,33,251,72,15,16,22,41,223,106,98,113,123,242,133,117,25,71,92,189,224,190,222,88,171,22,152,176,125,162,101,215,145,180,216,81,102,167,46,21,14,221,126,166,230,123,170,88,229,60,61,227,92,232,171,9,134,50,242,145,249,244,59,30,139,61,106,153,213,123,139,44,55,64,69,60,96,28,82,187,243,75,140,221,252,251,229,62,226,163,84,96,127,20,11,133,29,90,156,242,121,107,105,171,98,138,239,4,235,144,202,62,58,198,8,32,173,230,122,129,161,68,181,115,128,145,31,91,186,249,243,218,163,70,18,106,155,191,204,186,89,241,97,163,107,230,109,108,154,5,27,135,85,95,118,231,218,134,4,9,6,150,71
    };
    const  uint8_t pk[] = {
            97,82,224,196,160,235,189,168,248,201,241,136,92,89,145,216,6,198,191,231,158,238,178,9,223,105,88,48,106,201,172,9,15,99,33,223,150,251,237,104,193,28,100,205,151,205,3,3,238,251,73,239,49,252,189,118,107,184,107,170,114,172,162,204,196,33,65,181,125,236,122,6,129,181,4,97,39,12,190,27,20,162,190,251,221,157,134,195,142,95,195,42,17,141,106,153,115,244,59,249,134,67,33,24,85,248,155,149,137,45,111,225,196,165,81,144,94,108,107,142,240,47,180,245,53,105,9,250,163,96,195,206,182,39,114,133,186,183,126,245,98,208,235,242,56,158,147,72,233,47,114,63,223,55,243,97,6,201,177,218,228,37,197,40,205,2,116,92,21,252,180,112,125,125,8,104,162,200,189,71,89,18,209,114,247,224,220,18,71,5,50,37,37,241,224,33,124,171,57,200,186,116,104,198,143,26,63,31,225,77,219,107,38,211,33,188,143,233,89,112,138,100,85,106,72,160,203,86,171,152,221,124,114,252,147,253,173,179,204,32,213,215,194,245,51,28,83,130,25,181,173,195,59,18,213,24,53,237,145,173,251,64,64,137,226,211,117,161,89,198,26,1,134,187,15,221,17,27,157,207,223,62,254,221,248,240,35,19,223,115,247,140,33,217,226,15,61,241,227,233,133,255,166,146,100,252,250,169,110,93,28,93,158,167,80,137,110,93,183,118,87,198,156,113,149,158,21,153,121,197,186,214,202,11,44,11,46,119,119,138,27,73,236,179,239,132,94,124,124,198,90,228,137,103,135,159,234,171,5,81,186,144,52,117,103,187,197,137,127,213,122,249,170,117,185,4,198,30,38,81,241,252,246,123,25,56,91,240,193,185,65,167,33,247,110,108,121,179,245,98,249,44,20,22,26,237,222,167,242,178,108,190,45,173,86,128,169,15,69,50,194,111,50,180,177,52,205,136,2,180,130,64,207,8,83,69,244,67,241,114,192,14,198,156,213,138,95,235,34,118,237,23,166,155,169,228,56,0,254,247,82,99,183,12,45,246,183,132,201,227,157,37,132,217,126,100,70,137,7,216,97,121,6,175,204,159,138,246,71,143,75,75,154,72,160,196,119,120,83,9,135,201,13,179,85,94,51,17,147,70,183,216,179,204,12,242,173,199,189,178,3,186,52,15,209,108,197,18,184,18,211,115,195,138,83,209,16,45,67,212,188,202,252,137,35,96,156,19,79,68,94,124,1,124,111,127,116,12,202,230,108,19,140,91,148,89,173,45,198,209,198,59,242,215,117,121,189,233,100,114,212,1,230,74,7,223,242,109,107,52,16,127,132,240,93,54,155,66,177,122,102,94,215,235,112,76,128,146,121,62,21,19,177,166,201,143,28,44,250,77,222,217,34,186,85,152,69,156,153,230,176,198,219,177,188,56,130,146,137,102,179,251,29,148,198,155,144,194,122,243,104,17,177,208,88,101,126,49,156,54,189,99,241,248,148,4,3,88,157,135,111,10,48,187,174,230,157,95,243,106,225,226,216,18,84,86,106,0,221,199,14,58,108,106,204,177,244,221,75,192,123,248,183,73,189,165,23,101,62,114,117,153,73,125,77,13,88,75,236,105,85,196,113,255,133,93,238,172,27,74,16,213,153,27,20,196,46,250,248,32,19,116,183,216,184,137,148,25,67,181,74,19,77,207,214,241,23,106,186,190,209,93,18,82,248,98,11,29,160,56,237,164,182,201,219,31,165,197,26,160,131,135,236,181,84,97,167,164,98,213,193,91,7,180,195,189,2,45,69,224,230,222,244,55,5,95,85,184,206,170,75,153,190,21,96,184,50,42,109,211,134,45,92,10,139,136,139,80,248,144,30,185,132,51,208,245,201,108,32,246,70,80,160,183,47,79,137,13,248,19,112,178,31,242,22,98,56,90,14,2,100,103,159,149,207,49,161,223,1,241,233,146,27,178,142,235,35,65,159,124,17,11,246,50,79,100,44,158,161,63,53,252,141,106,38,215,87,195,255,83,110,216,222,156,25,172,54,136,217,110,78,49,41,190,76,159,94,172,169,65,222,212,216,120,107,25,41,190,113,165,49,224,69,154,111,198,115,250,37,232,110,229,83,30,224,137,68,108,167,166,61,142,185,109,60,198,226,16,13,111,110,230,247,187,118,69,8,224,135,101,141,93,49,62,68,200,233,152,216,121,153,47,42,76,89,120,122,159,111,177,214,171,185,181,236,192,32,58,55,7,85,23,115,183,176,138,23,40,107,143,243,174,230,102,136,154,11,202,16,157,88,4,120,36,128,16,137,255,56,167,113,252,164,144,189,88,4,32,162,134,249,133,196,50,107,150,181,103,80,150,39,3,196,196,64,104,46,198,133,202,9,190,115,91,184,199,172,40,212,193,159,182,109,253,29,109,247,228,202,124,84,144,100,225,8,208,70,208,78,233,104,218,37,193,126,158,238,45,41,1,11,164,71,91,63,60,75,238,245,211,127,203,165,238,195,53,231,186,155,163,213,45,237,99,193,83,89,254,218,31,179,96,101,126,191,242,127,122,159,124,136,152,49,84,210,37,82,33,148,116,215,226,99,27,182,60,3,242,209,38,208,101,83,44,125,168,233,237,111,215,180,42,105,72,165,31,227,3,178,20,31,55,172,23,222,42,244,129,43,250,13,218,97,229,177,75,134,41,146,86,154,77,225,66,134,246,218,4,112,60,0,12,23,61,6,209,204,241,74,138,245,1,90,136,18,212,150,242,41,33,151,104,167,150,71,165,153,38,248,252,66,19,222,18,71,132,216,123,198,91,35,155,152,29,196,122,206,89,25,107,175,236,119,232,218,116,107,141,214,81,157,27,66,252,62,46,19,190,1,222,38,220,132,97,120,68,47,25,179,143,8,68,147,207,138,89,115,13,36,225,141,21,215,152,163,176,254,84,110,29,47,104
    };
#else
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
#endif

    uint8_t mi[MAXMLEN];
    uint8_t sm[MAXMLEN + CRYPTO_BYTES];
    uint8_t sig[CRYPTO_BYTES];

    size_t smlen;
    size_t siglen;
    size_t mlen;

    int r;
    size_t i, k;



    /* i = 0, 1, 4, 16, 64, 256, 1024 */

   /*load_sk(sk);
    load_pk(pk);*/


  /* printf("pk: \n");
   for(i = 0; i < CRYPTO_PUBLICKEYBYTES;i++){
       printf("%" PRId8 ",", pk[i]);
   }
   printf("\n\n");
    printf("sk: \n");
    for(i = 0; i < CRYPTO_SECRETKEYBYTES;i++){
        printf("%" PRId8 ",", sk[i]);
    }
    printf("\n\n");*/


    for (i = 0; i < MAXMLEN; i = (i == 0) ? i + 1 : i << 2) {
#ifdef LATTICE_MATRIX_IN_FLASH
#else
        crypto_sign_keypair(pk, sk);
#endif
        randombytes(mi, i);


        //printbytes(pk, CRYPTO_PUBLICKEYBYTES);
        //printbytes(sk, CRYPTO_SECRETKEYBYTES);

        crypto_sign(sm, &smlen, mi, i, sk);
        crypto_sign_signature(sig, &siglen, mi, i, sk);

        //printbytes(sm, smlen);
        printbytes(sig, siglen);

        // By relying on m == sm we prevent having to allocate CRYPTO_BYTES
        // twice
        r = crypto_sign_open(sm, &mlen, sm, smlen, pk);
        r |= crypto_sign_verify(sig, siglen, mi, i, pk);

        if (r) {
            printf("ERROR: signature verification failed\n");
            return -1;
        }
        for (k = 0; k < i; k++) {
            if (sm[k] != mi[k]) {
                printf("ERROR: message recovery failed\n");
                return -1;
            }
        }
    }
    printf("PASS: all tests passed\n");

    printf("CRYPTO_PUBLICKEYBYTES: %d\n", CRYPTO_PUBLICKEYBYTES);
    printf("CRYPTO_SECRETKEYBYTES: %d\n", CRYPTO_SECRETKEYBYTES);
    printf("CRYPTO_BYTES: %d\n", CRYPTO_BYTES);
    return 0;
}
