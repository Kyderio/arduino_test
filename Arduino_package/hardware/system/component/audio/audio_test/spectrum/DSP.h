
#ifndef __DSP__H__
#define __DSP__H__

#define FLOATING_POINT_FIR	1
#define FLOATING_POINT_EQ	1
#define FLOATING_POINT_XTC	1

typedef	char		int8;
typedef	short		int16;
typedef	int			int32;
typedef	long long   int64;

typedef	unsigned char	uint8;
typedef	unsigned short	uint16;
typedef	unsigned int	uint32;

#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)
#define ABS(x) (x) > 0 ? (x) : (-x)

typedef float	const23_t;
typedef float	fix24_t;


#define	NEGATE_FLOAT(x)	(-x)
#define	ADD_FLOAT(x, y) ((float) x + y)
#define	SUB_FLOAT(x, y) ((float) x - y)
#define	DIV_FLOAT(x, y) ((float) x / y)

#define	ADD_INT(x, y) ((int32) x + y)
#define	SUB_INT(x, y) ((int32) x - y)

#define	MULT_FLOAT(x, y) ((float)x * y)
#define MAC_FLOAT(s, x, y)	((float)s + (float)x * y)

#define pow10f(x) expf(2.302585092994046f*x) 

#endif

