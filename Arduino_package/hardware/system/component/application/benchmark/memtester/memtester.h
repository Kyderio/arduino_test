
#define rand32() ((unsigned int) rand() | ( (unsigned int) rand() << 16))

#if (ULONG_MAX == 4294967295UL)
	#define rand_ul() rand32()
	#define UL_ONEBITS 0xffffffff
	#define UL_LEN 32
	#define CHECKERBOARD1 0x55555555
	#define CHECKERBOARD2 0xaaaaaaaa
	#define UL_BYTE(x) ((x | x << 8 | x << 16 | x << 24))
#elif (ULONG_MAX == 18446744073709551615ULL)
	#define rand64() (((ul) rand32()) << 32 | ((ul) rand32()))
	#define rand_ul() rand64()
	#define UL_ONEBITS 0xffffffffffffffffUL
	#define UL_LEN 64
	#define CHECKERBOARD1 0x5555555555555555
	#define CHECKERBOARD2 0xaaaaaaaaaaaaaaaa
	#define UL_BYTE(x) (((ul)x | (ul)x<<8 | (ul)x<<16 | (ul)x<<24 | (ul)x<<32 | (ul)x<<40 | (ul)x<<48 | (ul)x<<56))
#else
	#error long on this platform is not 32 or 64 bits
#endif

typedef unsigned long ul;
typedef unsigned long long ull;
typedef unsigned long volatile ulv;
typedef unsigned char volatile u8v;
typedef unsigned short volatile u16v;

struct test {
	const char *name;
	int (*fp)(ulv*, ulv*, size_t);
};


static int compare_regions(ulv *bufa, ulv *bufb, size_t count);
static int test_random_value(ulv *bufa, ulv *bufb, size_t count);
static int test_xor_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_sub_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_mul_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_div_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_or_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_and_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_seqinc_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_solidbits_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_checkerboard_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_blockseq_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_bitspread_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_bitflip_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_walkbits1_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_walkbits0_comparison(ulv *bufa, ulv *bufb, size_t count);
static int test_8bit_wide_random(ulv* bufa, ulv* bufb, size_t count);
static int test_16bit_wide_random(ulv* bufa, ulv* bufb, size_t count);
static int test_stuck_address(ulv *bufa, size_t count);
int memtest_entry(volatile void *buf, size_t size, unsigned long loop_cnt);
