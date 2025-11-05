#ifndef __WIFIFW_HAL_H__
#define __WIFIFW_HAL_H__

/*--------------------------Define -------------------------------------------*/
#define CONFIG_DRFC_IC						0

//3 1.) basic
#define PAGESIZE_TX					128
#define PAGESIZE_RX                 8 // no page size,only for FW release RXBUF
#define TX_PAGE_NUM					256
#define SIZE_RX_DESC_MAC			24
#define SIZE_TX_DESC_MAC			40
#define MACID_NUM					16

#define SIZE_TXRPT_ENTRY			16
#define SIZE_CTRLINFO_ENTRY			16



//3 BB base address
#define RTL8721D_BBREG_AHB_BASE             	0x40082800 //0x40083000-0x800
#define BBREG_AHB_BASE             				RTL8721D_BBREG_AHB_BASE
//3 RF base address
#define RTL8721D_RFREG_AHB_BASE             	0x40083800
#define RFREG_AHB_BASE             				RTL8721D_RFREG_AHB_BASE
//3 BT mailbox base address
#define RTL8721D_BT_MAILBOX_AHB_BASE        	0x40081160
#define BT_MAILBOX_AHB_BASE						RTL8721D_BT_MAILBOX_AHB_BASE

//3 TxReport Buffer base address
#define RTL8721D_RPTBUF_AHB_BASE            	0x400B0000
#define RTL8721D_CCXRPT_BASE                	(RTL8721D_RPTBUF_AHB_BASE)
#define RTL8721D_BCNRPT_BASE                	(RTL8721D_RPTBUF_AHB_BASE+0x80)
#define RTL8721D_TRXRPT_BASE                 	(RTL8721D_RPTBUF_AHB_BASE+0x100)
#define RTL8721D_RAMASK_BASE               		(RTL8721D_RPTBUF_AHB_BASE+0x200)
#define RTL8721D_NANRPT_BASE                	(RTL8721D_RPTBUF_AHB_BASE+0x280)

//3 Rx packet buffer base address
#define RTL8721D_RXFF_AHB_BASE              	0x400A0000
#define RXFF_AHB_BASE              				RTL8721D_RXFF_AHB_BASE
//3 Tx packet buffer base address
#define RTL8721D_TXFF_AHB_BASE              	0x40090000
#define TXFF_AHB_BASE              				RTL8721D_TXFF_AHB_BASE
//3 CAM base address
#define RTL8721D_SECCAM_AHB_BASE            	0x40081A00
#define SECCAM_AHB_BASE							RTL8721D_SECCAM_AHB_BASE
#define RTL8721D_MBIDCAM_AHB_BASE 				0x40051800

//offset:
#define rtl_inb(offset)             (*(volatile u8 *)((u32)offset))
#define rtl_inw(offset)             (*(volatile u16 *)((u32)offset))
#define rtl_inl(offset)             (*(volatile u32 *)((u32)offset))

#define rtl_outb(offset,val)        do { (*(volatile u8 *)((u32)offset) = (val));    } while(0)
#define rtl_outw(offset,val)        do { (*(volatile u16 *)((u32)offset) = (val));    } while(0)
#define rtl_outl(offset,val)        do { (*(volatile u32 *)((u32)offset) = (val));    } while(0)


//3 BB Reg
#define WritePortBBUlong(offset, value)     rtl_outl((offset+RTL8721D_BBREG_AHB_BASE), value)
#define WritePortBBUshort(offset, value)    rtl_outw((offset+RTL8721D_BBREG_AHB_BASE), value)
#define WritePortBBUchar(offset, value)     rtl_outb((offset+RTL8721D_BBREG_AHB_BASE), value)

#define ReadPortBBUlong(offset)             (rtl_inl((offset+RTL8721D_BBREG_AHB_BASE)))
#define ReadPortBBUshort(offset)            (rtl_inw((offset+RTL8721D_BBREG_AHB_BASE)))
#define ReadPortBBUchar(offset)             (rtl_inb((offset+RTL8721D_BBREG_AHB_BASE)))

//3 RF Reg only support dword mode
#define WritePortRFUlong(offset, value)     rtl_outl((4*offset+RTL8721D_RFREG_AHB_BASE), value)
#define ReadPortRFUlong(offset)             (rtl_inl((4*offset+RTL8721D_RFREG_AHB_BASE)))

//3 SEC CAM
#define WriteSECCAMDWord(offset, value)  rtl_outl((offset+RTL8721D_SECCAM_AHB_BASE), value)
#define WriteSECCAMWord(offset, value)   rtl_outw((offset+RTL8721D_SECCAM_AHB_BASE), value)
#define WriteSECCAMByte(offset, value)   rtl_outb((offset+RTL8721D_SECCAM_AHB_BASE), value)

#define ReadSECCAMDWord(offset)          (rtl_inl((offset+RTL8721D_SECCAM_AHB_BASE)))
#define ReadSECCAMWord(offset)           (rtl_inw((offset+RTL8721D_SECCAM_AHB_BASE)))
#define ReadSECCAMByte(offset)           (rtl_inb((offset+RTL8721D_SECCAM_AHB_BASE)))

//3 MBID CAM
#define WriteMBIDCAMDWord(offset, value)  rtl_outl((offset+RTL8721D_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMWord(offset, value)   rtl_outw((offset+RTL8721D_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMByte(offset, value)   rtl_outb((offset+RTL8721D_MBIDCAM_AHB_BASE), value)

#define ReadMBIDCAMDWord(offset)          (rtl_inl((offset+RTL8721D_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMWord(offset)           (rtl_inw((offset+RTL8721D_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMByte(offset)           (rtl_inb((offset+RTL8721D_MBIDCAM_AHB_BASE)))

//3 ReportBUFF
#define WriteRPTBUFDWord(offset, value)  rtl_outl((offset+RTL8721D_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFWord(offset, value)   rtl_outw((offset+RTL8721D_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFByte(offset, value)   rtl_outb((offset+RTL8721D_RPTBUF_AHB_BASE), value)

#define ReadRPTBUFDWord(offset)          (rtl_inl((offset+RTL8721D_RPTBUF_AHB_BASE)))
#define ReadRPTBUFWord(offset)           (rtl_inw((offset+RTL8721D_RPTBUF_AHB_BASE)))
#define ReadRPTBUFByte(offset)           (rtl_inb((offset+RTL8721D_RPTBUF_AHB_BASE)))

//3 RXFF
#define WriteRXFFDWord(offset, value)   rtl_outl((offset+RTL8721D_RXFF_AHB_BASE), value)
#define WriteRXFFWord(offset, value)    rtl_outw((offset+RTL8721D_RXFF_AHB_BASE), value)
#define WriteRXFFByte(offset, value)    rtl_outb((offset+RTL8721D_RXFF_AHB_BASE), value)

#define ReadRXFFDWord(offset)           (rtl_inl((offset+RTL8721D_RXFF_AHB_BASE)))
#define ReadRXFFWord(offset)            (rtl_inw((offset+RTL8721D_RXFF_AHB_BASE)))
#define ReadRXFFByte(offset)            (rtl_inb((offset+RTL8721D_RXFF_AHB_BASE)))

//3 TXFF
#define GetTXFFAddr(offset)     			(u32)((offset)+RTL8721D_TXFF_AHB_BASE)
#define GetMACHeaderAddr(offset)     		(u32)((offset)+RTL8721D_TXFF_AHB_BASE+SIZE_TX_DESC_MAC)

#define WriteTXFFDWord(offset, value)     rtl_outl((offset+RTL8721D_TXFF_AHB_BASE), value)
#define WriteTXFFWord(offset, value)      rtl_outw((offset+RTL8721D_TXFF_AHB_BASE), value)
#define WriteTXFFByte(offset, value)      rtl_outb((offset+RTL8721D_TXFF_AHB_BASE), value)

#define ReadTXFFDWord(offset)             (rtl_inl((offset+RTL8721D_TXFF_AHB_BASE)))
#define ReadTXFFWord(offset)              (rtl_inw((offset+RTL8721D_TXFF_AHB_BASE)))
#define ReadTXFFByte(offset)              (rtl_inb((offset+RTL8721D_TXFF_AHB_BASE)))

#ifdef AMEBADPLUS_TODO

//3 Retention RAM
#define WriteRRamDWord(offset, value)     rtl_outl((offset+RETENTION_RAM_BASE), value)
#define WriteRRamWord(offset, value)      rtl_outw((offset+RETENTION_RAM_BASE), value)
#define WriteRRamByte(offset, value)      rtl_outb((offset+RETENTION_RAM_BASE), value)

#define ReadRRamDWord(offset)             (rtl_inl((offset+RETENTION_RAM_BASE)))
#define ReadRRamWord(offset)              (rtl_inw((offset+RETENTION_RAM_BASE)))
#define ReadRRamByte(offset)              (rtl_inb((offset+RETENTION_RAM_BASE)))
#endif

//3 TX report buffer access
#define ReadCtrlInfoByte(macid, offset)         rtl_inb(RTL8721D_TRXRPT_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset)    //macid range: 0~16; offset range: 0~40
#define ReadCtrlInfoDWord(macid, offset)        rtl_inl(RTL8721D_TRXRPT_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset)    //macid range: 0~16; offset range: 0~40
#define WriteCtrlInfoByte(macid, offset, val)   rtl_outb(RTL8721D_TRXRPT_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset, val)
#define WriteCtrlInfoDWord(macid, offset, val)  rtl_outl(RTL8721D_TRXRPT_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset, val)


#define WriteTxrptByte(macid,offset,val)        rtl_outb(RTL8721D_TRXRPT_BASE + (macid<<4) + offset, val) //macid range: 0~16; offset range: 0~15
#define WriteTxrptDWord(macid,offset,val)       rtl_outl(RTL8721D_TRXRPT_BASE + (macid<<4) + offset, val)
#define ReadTxrptByte(macid,offset)             rtl_inb(RTL8721D_TRXRPT_BASE + (macid<<4) + offset)
#define ReadTxrptDWord(macid,offset)            rtl_inl(RTL8721D_TRXRPT_BASE + (macid<<4) + offset)

#define ReadCRC5Byte(macid, offset)         	rtl_inb(CRC5_BASE + (macid) + offset)       //rpt_idx range: 0~15; offset range: 0~1
#define WriteCRC5Byte(macid, offset, val)   	rtl_outb(CRC5_BASE + (macid) + offset, val)

#define ReadNANrptByte(offset)                  rtl_inb(RTL8721D_NANRPT_BASE  + offset)
#define ReadNANrptDWORD(offset)                 rtl_inl(RTL8721D_NANRPT_BASE  + offset)
#define WriteNANrptByte(offset, val)            rtl_outb(RTL8721D_NANRPT_BASE + offset, val)
#define WriteNANrptDWORD(offset, val)           rtl_outl(RTL8721D_NANRPT_BASE + offset, val)

//3 BT mailbox
#define WriteBTMailboxDWord(offset, value)      rtl_outl((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)
#define WriteBTMailboxWord(offset, value)       rtl_outw((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)
#define WriteBTmailboxByte(offset, value)       rtl_outb((offset+RTL8721D_BT_MAILBOX_AHB_BASE), value)

#define ReadBTMailboxDWord(offset)             (rtl_inl((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxWord(offset)              (rtl_inw((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxByte(offset)              (rtl_inb((offset+RTL8721D_BT_MAILBOX_AHB_BASE)))

#define TSF_After(a,b)  ((s32)(b)-(s32)(a)<0)
//============================================================================
//       8721DA Regsiter Bit and Content definition
//============================================================================
#define SCOREBOARD_BT_ON								BIT25
#define SCOREBOARD_BT_LPS								BIT26

/*------------------------COEX FW Debug GPIO------------------------------*/
//==PB30==bt_wake_host=0=#
//==PA30==wl_pri=2=#
//==PA31==wl_rx=3=#
//==PB20==wl_tx=4=#
//==PB21==bt_pri=5=#
//==PB17==bt_rx=6=#
//==PB18==bt_tx=7=#
//==PB31==gnt_bt_pta=1=#
#define BTC_TDMA0_3_PIN						_PA_19
#define BTC_TDMA1_4_PIN						_PA_20
#define BTC_TDMA2_5_PIN						_PA_21
#define BTC_TBTT_PIN						_PA_22
#define BTC_RF_PIN							_PA_23
#define BTC_CLK_PIN							_PA_27
#define PS_PIN_STATE2						_PB_0
#define PS_PIN_STATE1						_PB_1
#define PS_PIN_STATE0						_PB_2

/*------------------------------Define Struct---------------------------------*/

#endif  //__WIFIFW_HAL_H__

