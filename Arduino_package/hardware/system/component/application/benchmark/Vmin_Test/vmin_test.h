#define SMP_MAX_CPUS 2
typedef enum PatIdx {
	cpuburn,
	max_power_l2,
} pat_idx;

typedef struct PatArg {
	pat_idx pat;
	unsigned long IN_L;
	unsigned long OUT_L;
} pat_arg;

typedef int (*PatFunc)(pat_arg vmin_arg);

extern int max_power_l2_start(pat_arg vmin_arg);
extern int cpuburn_start(pat_arg vmin_arg);

static PatFunc patterns[2] = {
	cpuburn_start,
	max_power_l2_start,
};

typedef long long int64;
