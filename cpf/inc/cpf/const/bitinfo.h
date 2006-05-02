
// #include <cpf/basetype.h>

typedef unsigned char u8_t;
typedef unsigned int u32_t;

extern u8_t bitinfo_bits[256];
extern u8_t bitinfo_zeros[256];
extern u8_t bitinfo_ones[256];
extern u8_t bitinfo_leading_zeros[256];
extern u8_t bitinfo_leading_ones[256];
extern u8_t bitinfo_trailing_zeros[256];
extern u8_t bitinfo_trailing_ones[256];

extern u8_t bitinfo_msb_mask_u8[8];
extern u32_t bitinfo_msb_mask_u32[32];
