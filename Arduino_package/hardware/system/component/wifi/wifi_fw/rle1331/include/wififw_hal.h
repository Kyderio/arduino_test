#ifndef __WIFIFW_HAL_H__
#define __WIFIFW_HAL_H__

#ifndef __ASSEMBLY__
/*--------------------------Define -------------------------------------------*/
#define CONFIG_DRFC_IC					0
#define MACID_NUM						MACID_HW_MAX_NUM
#define BA_MAX_NUM		                MACID_HW_MAX_NUM
#define KEY_MAX_NUM			            32
#define SECCAM_ENTRY_NUM                KEY_MAX_NUM

#define PAGESIZE_RX                 	8 // no page size concept, only for 8 byte alignment
#define SIZE_RX_DESC_MAC            	16
#define SIZE_RX_DESC_CSICHINFO			16
#define SIZE_TX_DESC_MAC            	28

#define RXBUF_DEFAULT_SIZE            	0x400// unit 8 bytes

#define SECCAM_CFG_ENTRY_SIZE         	4
#define SECCAM_KEY_ENTRY_SIZE         	32
#define SIZE_CTRLINFO_ENTRY        		16
#define BACAM_CFG_SIZE                  4
#define BACAM_BITMAP_SIZE               12

#define SCOREBOARD_BT_ON						BIT25
#define SCOREBOARD_BT_LPS						BIT26

#define TSF_After(a,b)							((s32)(b)-(s32)(a)<0)
#define RFCRegToByteAddr(x)						((x)<<2)
//BB base address
#define RLE1331_BBREG_AHB_BASE					0x40010000
#define BBREG_AHB_BASE             				RLE1331_BBREG_AHB_BASE
//RF base address
#define RLE1331_RFREG_AHB_BASE             	    0x40017000
#define RFREG_AHB_BASE             				RLE1331_RFREG_AHB_BASE
//BT mailbox base address
#define RLE1331_BT_MAILBOX_AHB_BASE				0x40001110
#define BT_MAILBOX_AHB_BASE						RLE1331_BT_MAILBOX_AHB_BASE
//1331 todo HIOECMDBUF start address not fixed
//HIOECMDBUF buffer base address
#define RLE1331_HIOEBUF_AHB_BASE              	0x40022000
#define RLE1331_HIOEBUF_SIZE            		0x1000
#define HIOEBUF_AHB_BASE              			RLE1331_TXFF_AHB_BASE
//Rx packet buffer base address
#define RLE1331_RXFF_AHB_BASE					0x40020000
#define RXFF_AHB_BASE              				RLE1331_RXFF_AHB_BASE
//RPTBUF start address need read REG
#define RLE1331_RPTRPT_AHB_BASE                  0x40023000
//CHINFO/CSI buffer base same address,chinfo/beamforming Will not be used simultaneously
#define RLE1331_CHINFO_CSI_AHB_BASE				0x40023400
//TXLLT Table base
#define RLE1331_LLT_AHB_BASE					0x40024000//256 byte/entry
//MACADDR/CTRLINFO/KEYSRCH/BACAM
#define RLE1331_MACID_CAM_AHB_BASE            	0x40023800
#define CTRLINFO_ENTRY_NUM						MACID_NUM	//byte
#define RLE1331_CRC5_A1_AHB_BASE	            RLE1331_MACID_CAM_AHB_BASE
#define RLE1331_CRC5_A2_AHB_BASE              	(RLE1331_MACID_CAM_AHB_BASE + 8 * (MACID_NUM/10 + ((MACID_NUM%10) ? 1 : 0)))
#define RLE1331_CRC5_A3_AHB_BASE                (RLE1331_MACID_CAM_AHB_BASE + 2 * 8 * (MACID_NUM/10 + ((MACID_NUM%10) ? 1 : 0)))
#define RLE1331_CtrlInfo_AHB_BASE               (RLE1331_MACID_CAM_AHB_BASE + 3 * 8 * (MACID_NUM/10 + ((MACID_NUM%10) ? 1 : 0)))
#define RLE1331_SECCAM_CFG_AHB_BASE            	(RLE1331_CtrlInfo_AHB_BASE + SIZE_CTRLINFO_ENTRY * CTRLINFO_ENTRY_NUM)
#define RLE1331_SECCAM_KEY_AHB_BASE            	(RLE1331_SECCAM_CFG_AHB_BASE + SECCAM_CFG_ENTRY_SIZE * KEY_MAX_NUM)
#define RLE1331_BACAM_AHB_BASE                  (RLE1331_SECCAM_KEY_AHB_BASE + SECCAM_KEY_ENTRY_SIZE * KEY_MAX_NUM)
#define RLE1331_BACAM_CFG_AHB_BASE             	RLE1331_BACAM_AHB_BASE
#define RLE1331_BACAM_BITMAP_AHB_BASE           (RLE1331_BACAM_AHB_BASE + BACAM_CFG_SIZE * BA_MAX_NUM)
#define RLE1331_RXFILTER_CAM_AHB_BASE 			(RLE1331_BACAM_AHB_BASE + BACAM_BITMAP_SIZE * BA_MAX_NUM)
#define ADDR_CAM_BASE                           RLE1331_RXFILTER_CAM_AHB_BASE
//access
#define rtl_inb(offset)							(*(volatile u8 *)((u32)(offset)))
#define rtl_inw(offset)							(*(volatile u16 *)((u32)(offset)))
#define rtl_inl(offset)							(*(volatile u32 *)((u32)(offset)))

#define rtl_outb(offset,val)					do { (*(volatile u8 *)((u32)(offset)) = (val));    } while(0)
#define rtl_outw(offset,val)					do { (*(volatile u16 *)((u32)(offset)) = (val));    } while(0)
#define rtl_outl(offset,val)					do { (*(volatile u32 *)((u32)(offset)) = (val));    } while(0)

//IO ACCESS
//LLT TABLE only read
#define ReadLLTTableDWord(offset)           	(rtl_inl((offset)+RLE1331_LLT_AHB_BASE))
#define ReadLLTTableWord(offset)            	(rtl_inw((offset)+RLE1331_LLT_AHB_BASE))
#define ReadLLTTableByte(offset)            	(rtl_inb((offset)+RLE1331_LLT_AHB_BASE))

//BB Reg
#define WritePortBBUlong(offset, value)			rtl_outl((offset)+RLE1331_BBREG_AHB_BASE, value)
#define WritePortBBUshort(offset, value)		rtl_outw((offset)+RLE1331_BBREG_AHB_BASE, value)
#define WritePortBBUchar(offset, value)			rtl_outb((offset)+RLE1331_BBREG_AHB_BASE, value)

#define ReadPortBBUlong(offset)             	(rtl_inl((offset)+RLE1331_BBREG_AHB_BASE))
#define ReadPortBBUshort(offset)            	(rtl_inw((offset)+RLE1331_BBREG_AHB_BASE))
#define ReadPortBBUchar(offset)             	(rtl_inb((offset)+RLE1331_BBREG_AHB_BASE))

#define WritePortRFCUlong(offset, value)		rtl_outl((offset)+RLE1331_RFREG_AHB_BASE, value)
#define WritePortRFCUshort(offset, value)		rtl_outw((offset)+RLE1331_RFREG_AHB_BASE, value)
#define WritePortRFCUchar(offset, value)		rtl_outb((offset)+RLE1331_RFREG_AHB_BASE, value)

#define ReadPortRFCUlong(offset)             	(rtl_inl((offset)+RLE1331_RFREG_AHB_BASE))
#define ReadPortRFCUshort(offset)            	(rtl_inw((offset)+RLE1331_RFREG_AHB_BASE))
#define ReadPortRFCUchar(offset)             	(rtl_inb((offset)+RLE1331_RFREG_AHB_BASE))

//BT mailbox
#define WriteBTMailboxDWord(offset, value)		rtl_outl((offset)+RLE1331_BT_MAILBOX_AHB_BASE, value)
#define WriteBTMailboxWord(offset, value)		rtl_outw((offset)+RLE1331_BT_MAILBOX_AHB_BASE, value)
#define WriteBTmailboxByte(offset, value)		rtl_outb((offset)+RLE1331_BT_MAILBOX_AHB_BASE, value)

#define ReadBTMailboxDWord(offset)				(rtl_inl((offset)+RLE1331_BT_MAILBOX_AHB_BASE))
#define ReadBTMailboxWord(offset)				(rtl_inw((offset)+RLE1331_BT_MAILBOX_AHB_BASE))
#define ReadBTMailboxByte(offset)        		(rtl_inb((offset)+RLE1331_BT_MAILBOX_AHB_BASE))

//chinfo_buf + csibuf (1k)
#define WriteCHINFOCSIBUFDWord(offset, value)	rtl_outl((offset)+RLE1331_CHINFO_CSI_AHB_BASE, value)
#define WriteCHINFOCSIBUFWord(offset, value)	rtl_outw((offset)+RLE1331_CHINFO_CSI_AHB_BASE, value)
#define WriteCHINFOCSIBUFByte(offset, value)	rtl_outb((offset)+RLE1331_CHINFO_CSI_AHB_BASE, value)

#define ReadCHINFOCSIBUFDWord(offset)          	(rtl_inl((offset)+RLE1331_CHINFO_CSI_AHB_BASE))
#define ReadCHINFOCSIBUFWord(offset)           	(rtl_inw((offset)+RLE1331_CHINFO_CSI_AHB_BASE))
#define ReadCHINFOCSIBUFByte(offset)           	(rtl_inb((offset)+RLE1331_CHINFO_CSI_AHB_BASE))

//HIOECMD BUFF
#define WriteHIOEBUFDWord(offset, value)		rtl_outl((offset)+RLE1331_HIOEBUF_AHB_BASE, value)
#define WriteHIOEBUFWord(offset, value)			rtl_outw((offset)+RLE1331_HIOEBUF_AHB_BASE, value)
#define WriteHIOEBUFByte(offset, value)			rtl_outb((offset)+RLE1331_HIOEBUF_AHB_BASE, value)

#define ReadHIOEBUFDWord(offset)          		(rtl_inl((offset)+RLE1331_HIOEBUF_AHB_BASE))
#define ReadHIOEBUFWord(offset)           		(rtl_inw((offset)+RLE1331_HIOEBUF_AHB_BASE))
#define ReadHIOEBUFByte(offset)           		(rtl_inb((offset)+RLE1331_HIOEBUF_AHB_BASE))

#define WriteTXFFDWord(offset, value)           WriteHIOEBUFDWord(offset, value)
#define WriteTXFFWord(offset, value)            WriteHIOEBUFWord(offset, value)
#define WriteTXFFByte(offset, value)            WriteHIOEBUFByte(offset, value)

#define ReadTXFFDWord(offset)                   ReadHIOEBUFDWord(offset)
#define ReadTXFFWord(offset)                    ReadHIOEBUFWord(offset)
#define ReadTXFFByte(offset)                    ReadHIOEBUFByte(offset)

//TRxReportBUFF,read only
#define ReadRPTBUFDWord(offset)          		(rtl_inl((offset)+RLE1331_RPTRPT_AHB_BASE))
#define ReadRPTBUFWord(offset)           		(rtl_inw((offset)+RLE1331_RPTRPT_AHB_BASE))
#define ReadRPTBUFByte(offset)           		(rtl_inb((offset)+RLE1331_RPTRPT_AHB_BASE))

#define WriteRPTBUFDWord(offset, value)		    rtl_outl((offset)+RLE1331_RPTRPT_AHB_BASE, value)
#define WriteRPTBUFWord(offset, value)			rtl_outw((offset)+RLE1331_RPTRPT_AHB_BASE, value)
#define WriteRPTBUFByte(offset, value)			rtl_outb((offset)+RLE1331_RPTRPT_AHB_BASE, value)

//RXFF
#define WriteRXFFDWord(offset, value)   		rtl_outl((offset)+RLE1331_RXFF_AHB_BASE, value)
#define WriteRXFFWord(offset, value)    		rtl_outw((offset)+RLE1331_RXFF_AHB_BASE, value)
#define WriteRXFFByte(offset, value)    		rtl_outb((offset)+RLE1331_RXFF_AHB_BASE, value)

#define ReadRXFFDWord(offset)           		(rtl_inl((offset)+RLE1331_RXFF_AHB_BASE))
#define ReadRXFFWord(offset)					(rtl_inw((offset)+RLE1331_RXFF_AHB_BASE))
#define ReadRXFFByte(offset)					(rtl_inb((offset)+RLE1331_RXFF_AHB_BASE))

//MACID CAM direct access
#define WriteMACIDCAMDWord(offset, val)		    rtl_outl(RLE1331_MACID_CAM_AHB_BASE + offset, val)
#define WriteMACIDCAMByte(offset, val)		    rtl_outb(RLE1331_MACID_CAM_AHB_BASE + offset, val)

#define ReadMACIDCAMDWord(offset)			    (rtl_inl(RLE1331_MACID_CAM_AHB_BASE + offset))
#define ReadMACIDCAMByte(offset)			    (rtl_inb(RLE1331_MACID_CAM_AHB_BASE + offset))

//CRC5 entry:0-29 ,every 6bit
#define ReadCRC5Byte(offset)					rtl_inb(RLE1331_CRC5_AHB_BASE + (offset))       //entry range: 0~30; 4 byte 10 entry
#define ReadCRC5DWord(offset)					rtl_inl(RLE1331_CRC5_AHB_BASE + (offset))

#define WriteCRC5Byte(offset, val)				rtl_outb(RLE1331_CRC5_AHB_BASE  + (offset), val)
#define WriteCRC5DWord(offset, val)				rtl_outl(RLE1331_CRC5_AHB_BASE  + (offset), val)

//CtrlInfo
#define ReadCtrlInfoByte(entry, offset) 		rtl_inb(RLE1331_CtrlInfo_AHB_BASE + (entry<<4) + (offset))    //entry range: 0~30; offset range: 0~16
#define ReadCtrlInfoDWord(entry, offset)		rtl_inl(RLE1331_CtrlInfo_AHB_BASE + (entry<<4) + (offset))

#define WriteCtrlInfoByte(entry, offset, val)		rtl_outb(RLE1331_CtrlInfo_AHB_BASE + (entry<<4) + (offset), val)
#define WriteCtrlInfoDWord(entry, offset, val)		rtl_outl(RLE1331_CtrlInfo_AHB_BASE + (entry<<4) + (offset), val)

//SEC CAM CFG,every 4 byte
#define WriteSECCAMCFGDWord(offset, val)		    rtl_outl(RLE1331_SECCAM_CFG_AHB_BASE + offset, val)
#define WriteSECCAMCFGByte(offset, val)		        rtl_outb(RLE1331_SECCAM_CFG_AHB_BASE + offset, val)

#define ReadSECCAMCFGDWord(offset)			        (rtl_inl(RLE1331_SECCAM_CFG_AHB_BASE + offset))
#define ReadSECCAMCFGByte(offset)			        (rtl_inb(RLE1331_SECCAM_CFG_AHB_BASE + offset))

//SEC CAM KEY,every max 32byte
#define WriteSECCAMKeyDWord(offset, val)		    rtl_outl(RLE1331_SECCAM_KEY_AHB_BASE + offset, val)
#define WriteSECCAMKeyByte(offset, val)		        rtl_outb(RLE1331_SECCAM_KEY_AHB_BASE + offset, val)

#define ReadSECCAMKeyDWord(offset)			        (rtl_inl(RLE1331_SECCAM_KEY_AHB_BASE + offset))
#define ReadSECCAMKeyByte(offset)			        (rtl_inb(RLE1331_SECCAM_KEY_AHB_BASE + offset))

//BA CAM CFG
#define WriteBACAMCFGDWord(entry, offset, val)		rtl_outl(RLE1331_BACAM_CFG_AHB_BASE + (entry<<2) + (offset), val)
#define WriteBACAMCFGByte(entry, offset, val)		rtl_outb(RLE1331_BACAM_CFG_AHB_BASE + (entry<<2) + (offset), val)

#define ReadBACAMCFGDWord(entry, offset)			(rtl_inl(RLE1331_BACAM_CFG_AHB_BASE + (entry<<2) + (offset)))
#define ReadBACAMCFGByte(entry, offset)				(rtl_inb(RLE1331_BACAM_CFG_AHB_BASE + (entry<<2) + (offset)))

//BA CAM BITMAP
#define WriteBACAMBitmapDWord(entry, offset, val)	rtl_outl(RLE1331_BACAM_BITMAP_AHB_BASE + (entry<<3) + (offset), val)
#define WriteBACAMBitmapByte(entry, offset, val)	rtl_outb(RLE1331_BACAM_BITMAP_AHB_BASE + (entry<<3) + (offset), val)

#define ReadBACAMBitmapDWord(entry, offset)			(rtl_inl(RLE1331_BACAM_BITMAP_AHB_BASE + (entry<<3) + (offset)))
#define ReadBACAMBitmapByte(entry, offset)			(rtl_inb(RLE1331_BACAM_BITMAP_AHB_BASE + (entry<<3) + (offset)))

//RX filter
#define WriteRxFilterCFGDWord(entry, offset, val)	rtl_outl(RLE1331_RXFILTER_CAM_AHB_BASE + (entry<<2) + (offset), val)
#define WriteRxFilterCFGByte(entry, offset, val)	rtl_outb(RLE1331_RXFILTER_CAM_AHB_BASE + (entry<<2) + (offset), val)

#define ReadRxFilterCFGDWord(entry, offset)			(rtl_inl(RLE1331_RXFILTER_CAM_AHB_BASE + (entry<<2) + (offset)))
#define ReadRxFilterCFGByte(entry, offset)			(rtl_inb(RLE1331_RXFILTER_CAM_AHB_BASE + (entry<<2) + (offset)))

#endif  /* __ASSEMBLY__ */
#endif  /* __WIFIFW_HAL_H__ */
