#ifndef __RTL8721DA_UTIL_H__
#define __RTL8721DA_UTIL_H__

/*--------------------Define --------------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/
#define WAIT_BBRW_STABLE_BREAK_CNT      (5000)
#define WAIT_BBRW_STABLE_CNT            (100)
#define WAIT_BBRW_STABLE_ONCE_TIME      (20)

/*--------------------Define Struct---------------------------------------*/

/*--------------------Export global variable-------------------------------*/

/*--------------------Function declaration---------------------------------*/

#ifndef __ASSEMBLY__


extern bool CheckBBRWIsStable(
	void
);

extern u32 PHY_QueryBBReg(
	u16         RegAddr
);   //access delay 20us

extern void PHY_SetBBReg(
	u16         RegAddr,
	u32         Data
);    //access delay 20us

extern void ReadSECCAM(
	u16 Addr,
	u8 *Data
);

extern void WriteSECCAM(
	u16 Addr,
	u8 *Data
);

extern void ReadBACAM(
	u8 Addr,
	u8 *Data
);

extern void WriteBACAM(
	u8 Addr,
	u8 *Data
);

extern void ReadMBIDCAM(
	u8 Addr,
	u8 *Data
);

extern void WriteMBIDCAM(
	u8 Addr,
	u8 *Data
);

#endif  //#ifndef __ASSEMBLY__

#endif  //__RTL8721DA_UTIL_H__

