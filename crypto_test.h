#include <snBits.h>

SN_PRIVATE_CONST(snByte) sn_crypt_test_sbox[256] = {
    // 0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F
    0x25, 0xd1, 0x84, 0xb8, 0x48, 0x35, 0x4a, 0x78, 0x79, 0x74, 0x60, 0xc7, 0x0e, 0xbc, 0x32, 0x30,
    0x91, 0x18, 0xe5, 0xdc, 0xe4, 0x90, 0x81, 0xc8, 0x65, 0x2b, 0xc3, 0x9d, 0x67, 0xa5, 0xf9, 0xdf,
    0x13, 0xf6, 0x1b, 0xd4, 0xa9, 0xb7, 0xc2, 0x5a, 0x85, 0xac, 0x41, 0x8e, 0xeb, 0x72, 0xef, 0xad,
    0x88, 0x5e, 0x1f, 0x6a, 0x52, 0x80, 0xdd, 0x16, 0xbe, 0x46, 0xf4, 0x3f, 0x94, 0x64, 0x04, 0xa8,
    0xb4, 0xc1, 0x8f, 0xee, 0x82, 0x1e, 0x8b, 0x01, 0x20, 0x11, 0xae, 0x8d, 0x17, 0x1c, 0x68, 0xab,
    0x8a, 0xfc, 0xf0, 0x50, 0xf2, 0x42, 0x0a, 0x59, 0x58, 0x6c, 0x45, 0x3e, 0x89, 0xb5, 0xa1, 0x71,
    0x73, 0x4c, 0xbd, 0xd9, 0x2f, 0x4f, 0xed, 0xdb, 0xb2, 0xaf, 0x4e, 0xff, 0x9f, 0x0b, 0x51, 0xe7,
    0x5c, 0x75, 0x53, 0x63, 0xc6, 0x6e, 0x0d, 0xf5, 0x5d, 0x47, 0x23, 0xb0, 0xda, 0xa4, 0xb6, 0x93,
    0x54, 0x19, 0x10, 0xd0, 0xfa, 0xc5, 0xd8, 0x97, 0x87, 0x3c, 0x95, 0x4b, 0xd3, 0x3d, 0xcb, 0xbb,
    0x33, 0x05, 0x0c, 0x4d, 0x08, 0x7d, 0x24, 0x5b, 0x0f, 0x3b, 0xce, 0xe3, 0xe8, 0x2e, 0xba, 0x06,
    0x57, 0xec, 0x86, 0x1d, 0x29, 0x9e, 0xa6, 0xc9, 0x31, 0x66, 0xe1, 0xfe, 0xcc, 0x7e, 0x8c, 0x1a,
    0x9a, 0x03, 0x44, 0xa7, 0xd2, 0x36, 0x2c, 0x83, 0xe2, 0x69, 0x7a, 0xe9, 0x37, 0x96, 0xb1, 0x02,
    0xea, 0x28, 0x9b, 0x21, 0xfd, 0x77, 0x3a, 0xcf, 0xf7, 0xca, 0x7b, 0x98, 0xa3, 0xc4, 0xe0, 0x6b,
    0xb9, 0xf8, 0xa2, 0x22, 0x43, 0xfb, 0xde, 0x26, 0x2d, 0xc0, 0xb3, 0xaa, 0x27, 0x7f, 0xe6, 0xbf,
    0x39, 0x9c, 0x38, 0x40, 0x09, 0x5f, 0x76, 0x34, 0xa0, 0x14, 0x49, 0x6f, 0xd5, 0xd6, 0x00, 0x12,
    0x55, 0x70, 0xf3, 0x62, 0x92, 0x56, 0x6d, 0x15, 0x2a, 0x61, 0xcd, 0x99, 0x7c, 0xf1, 0xd7, 0x07
};

// 用于将通过置换盒的数据还原的逆置换盒
SN_PRIVATE_CONST(snByte) sn_crypt_test_rsbox[256] = {
    // 0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F
    0xee, 0x47, 0xbf, 0xb1, 0x3e, 0x91, 0x9f, 0xff, 0x94, 0xe4, 0x56, 0x6d, 0x92, 0x76, 0x0c, 0x98,
    0x82, 0x49, 0xef, 0x20, 0xe9, 0xf7, 0x37, 0x4c, 0x11, 0x81, 0xaf, 0x22, 0x4d, 0xa3, 0x45, 0x32,
    0x48, 0xc3, 0xd3, 0x7a, 0x96, 0x00, 0xd7, 0xdc, 0xc1, 0xa4, 0xf8, 0x19, 0xb6, 0xd8, 0x9d, 0x64,
    0x0f, 0xa8, 0x0e, 0x90, 0xe7, 0x05, 0xb5, 0xbc, 0xe2, 0xe0, 0xc6, 0x99, 0x89, 0x8d, 0x5b, 0x3b,
    0xe3, 0x2a, 0x55, 0xd4, 0xb2, 0x5a, 0x39, 0x79, 0x04, 0xea, 0x06, 0x8b, 0x61, 0x93, 0x6a, 0x65,
    0x53, 0x6e, 0x34, 0x72, 0x80, 0xf0, 0xf5, 0xa0, 0x58, 0x57, 0x27, 0x97, 0x70, 0x78, 0x31, 0xe5,
    0x0a, 0xf9, 0xf3, 0x73, 0x3d, 0x18, 0xa9, 0x1c, 0x4e, 0xb9, 0x33, 0xcf, 0x59, 0xf6, 0x75, 0xeb,
    0xf1, 0x5f, 0x2d, 0x60, 0x09, 0x71, 0xe6, 0xc5, 0x07, 0x08, 0xba, 0xca, 0xfc, 0x95, 0xad, 0xdd,
    0x35, 0x16, 0x44, 0xb7, 0x02, 0x28, 0xa2, 0x88, 0x30, 0x5c, 0x50, 0x46, 0xae, 0x4b, 0x2b, 0x42,
    0x15, 0x10, 0xf4, 0x7f, 0x3c, 0x8a, 0xbd, 0x87, 0xcb, 0xfb, 0xb0, 0xc2, 0xe1, 0x1b, 0xa5, 0x6c,
    0xe8, 0x5e, 0xd2, 0xcc, 0x7d, 0x1d, 0xa6, 0xb3, 0x3f, 0x24, 0xdb, 0x4f, 0x29, 0x2f, 0x4a, 0x69,
    0x7b, 0xbe, 0x68, 0xda, 0x40, 0x5d, 0x7e, 0x25, 0x03, 0xd0, 0x9e, 0x8f, 0x0d, 0x62, 0x38, 0xdf,
    0xd9, 0x41, 0x26, 0x1a, 0xcd, 0x85, 0x74, 0x0b, 0x17, 0xa7, 0xc9, 0x8e, 0xac, 0xfa, 0x9a, 0xc7,
    0x83, 0x01, 0xb4, 0x8c, 0x23, 0xec, 0xed, 0xfe, 0x86, 0x63, 0x7c, 0x67, 0x13, 0x36, 0xd6, 0x1f,
    0xce, 0xaa, 0xb8, 0x9b, 0x14, 0x12, 0xde, 0x6f, 0x9c, 0xbb, 0xc0, 0x2c, 0xa1, 0x66, 0x43, 0x2e,
    0x52, 0xfd, 0x54, 0xf2, 0x3a, 0x77, 0x21, 0xc8, 0xd1, 0x1e, 0x84, 0xd5, 0x51, 0xc4, 0xab, 0x6b
};

#define SN_CRYPT_TEST_BLOCKLEN (16)
#define SN_CRYPT_TEST_NB 4
#define SN_CRYPT_TEST_NK 4

#define SN_CRYPT_TEST_SBOX(x) (sn_crypt_test_sbox[(x)])
#define SN_CRYPT_TEST_RSBOX(x) (sn_crypt_test_rsbox[(x)])

typedef snByte state[SN_CRYPT_TEST_NB][SN_CRYPT_TEST_NK];
typedef struct {
    snByte iv[SN_CRYPT_TEST_BLOCKLEN];
    snByte key[SN_CRYPT_TEST_BLOCKLEN];
} snCBC_ctx;

static snVoid sn_crypt_test_XorWithIV(state *buf, state *iv)
{
    sn_u32 x, y;
    for(x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        for(y = 0; y < SN_CRYPT_TEST_NK; ++y) {
            (*buf)[x][y] ^= (*iv)[x][y];
        }
    }
}

static snVoid sn_crypt_test_SubBytes(state *buf)
{
    sn_u32 x, y;
    for(x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        for(y = 0; y < SN_CRYPT_TEST_NK; ++y) {
            (*buf)[x][y] = SN_CRYPT_TEST_SBOX((*buf)[x][y]);
        }
    }
}

static snVoid sn_crypt_test_InvSubBytes(state *buf)
{
    sn_u32 x, y;
    for(x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        for(y = 0; y < SN_CRYPT_TEST_NK; ++y) {
            (*buf)[x][y] = SN_CRYPT_TEST_RSBOX((*buf)[x][y]);
        }
    }
}

static snVoid sn_crypt_test_ShiftRows(state *buf)
{
    uint8_t temp;

    temp = (*buf)[0][1];
    (*buf)[0][1] = (*buf)[1][1];
    (*buf)[1][1] = (*buf)[2][1];
    (*buf)[2][1] = (*buf)[3][1];
    (*buf)[3][1] = temp;

    temp = (*buf)[0][2];
    (*buf)[0][2] = (*buf)[2][2];
    (*buf)[2][2] = temp;
    temp = (*buf)[1][2];
    (*buf)[1][2] = (*buf)[3][2];
    (*buf)[3][2] = temp;

    temp = (*buf)[0][3];
    (*buf)[0][3] = (*buf)[3][3];
    (*buf)[3][3] = (*buf)[2][3];
    (*buf)[2][3] = (*buf)[1][3];
    (*buf)[1][3] = temp;
}

static snVoid sn_crypt_test_InvShiftRows(state *buf)
{
    uint8_t temp;

    temp = (*buf)[3][1];
    (*buf)[3][1] = (*buf)[2][1];
    (*buf)[2][1] = (*buf)[1][1];
    (*buf)[1][1] = (*buf)[0][1];
    (*buf)[0][1] = temp;

    temp = (*buf)[0][2];
    (*buf)[0][2] = (*buf)[2][2];
    (*buf)[2][2] = temp;
    temp = (*buf)[1][2];
    (*buf)[1][2] = (*buf)[3][2];
    (*buf)[3][2] = temp;

    temp = (*buf)[0][3];
    (*buf)[0][3] = (*buf)[1][3];
    (*buf)[1][3] = (*buf)[2][3];
    (*buf)[2][3] = (*buf)[3][3];
    (*buf)[3][3] = temp;
}

static snVoid sn_crypt_test_MixColumns(state *buf)
{
    for(sn_u32 x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        (*buf)[0][x] = (*buf)[0][x] ^ (*buf)[1][x] ^ (*buf)[2][x];
        (*buf)[1][x] = (*buf)[1][x] ^ (*buf)[2][x] ^ (*buf)[3][x];
        (*buf)[2][x] = (*buf)[2][x] ^ (*buf)[3][x] ^ (*buf)[0][x];
        (*buf)[3][x] = (*buf)[3][x] ^ (*buf)[0][x] ^ (*buf)[1][x];
    }
}

static snVoid sn_crypt_test_InvMixColumns(state *buf)
{
    for(sn_u32 x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        (*buf)[3][x] = (*buf)[3][x] ^ (*buf)[0][x] ^ (*buf)[1][x];
        (*buf)[2][x] = (*buf)[2][x] ^ (*buf)[3][x] ^ (*buf)[0][x];
        (*buf)[1][x] = (*buf)[1][x] ^ (*buf)[2][x] ^ (*buf)[3][x];
        (*buf)[0][x] = (*buf)[0][x] ^ (*buf)[1][x] ^ (*buf)[2][x];
    }
}

static snVoid sn_crypt_test_Cipher(state *buf, state *key)
{
    sn_u32 x, y;
    sn_crypt_test_SubBytes(buf);
    for(x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        for(y = 0; y < SN_CRYPT_TEST_NK; ++y) {
            (*buf)[x][y] ^= (*key)[x][y];
        }
    }
    sn_crypt_test_ShiftRows(buf);
    sn_crypt_test_MixColumns(buf);
}

static snVoid sn_crypt_test_InvCipher(state *buf, state *key)
{
    sn_u32 x, y;
    sn_crypt_test_InvMixColumns(buf);
    sn_crypt_test_InvShiftRows(buf);
    for(x = 0; x < SN_CRYPT_TEST_NB; ++x) {
        for(y = 0; y < SN_CRYPT_TEST_NK; ++y) {
            (*buf)[x][y] ^= (*key)[x][y];
        }
    }
    sn_crypt_test_InvSubBytes(buf);
}

static snVoid sn_crypt_test_cbc_encrypt(snCBC_ctx obj, snByte *src, snSize srcSize)
{
    if(srcSize % SN_CRYPT_TEST_BLOCKLEN) {
        printf("错误，长度不是%u的倍数！\n", SN_CRYPT_TEST_BLOCKLEN);
        return;
    }
    static snSize x;
    static snByte round_iv[SN_CRYPT_TEST_BLOCKLEN];

    memcpy(round_iv, obj.iv, SN_CRYPT_TEST_BLOCKLEN);
    for(x = 0; x < srcSize; x += SN_CRYPT_TEST_BLOCKLEN) {
        sn_crypt_test_XorWithIV((state *)(src + x), (state *)round_iv);
        sn_crypt_test_Cipher((state *)(src + x), (state *)obj.key);
        memcpy(round_iv, (state *)(src + x), SN_CRYPT_TEST_BLOCKLEN);
    }
}

static snVoid sn_crypt_test_cbc_decrypt(snCBC_ctx obj, snByte *src, snSize srcSize)
{
    if(srcSize % SN_CRYPT_TEST_BLOCKLEN) {
        printf("错误，长度不是%u的倍数！\n", SN_CRYPT_TEST_BLOCKLEN);
        return;
    }
    static snSize x;
    static snByte round_buf[SN_CRYPT_TEST_BLOCKLEN];

    for(x = 0; x < srcSize; x += SN_CRYPT_TEST_BLOCKLEN) {
        memcpy(round_buf, (src + x), SN_CRYPT_TEST_BLOCKLEN);
        sn_crypt_test_InvCipher((state *)(src + x), (state *)obj.key);
        sn_crypt_test_XorWithIV((state *)(src + x), (state *)obj.iv);
        memcpy(obj.iv, round_buf, SN_CRYPT_TEST_BLOCKLEN);
    }
}


