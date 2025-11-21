#ifndef __WIFIFW_HAL_H__
#define __WIFIFW_HAL_H__

#ifndef __ASSEMBLY__
/*--------------------------Define -------------------------------------------*/
#define CONFIG_DRFC_IC					1

//3 Basic
#define PAGESIZE_TX                 	128
#define PAGESIZE_RX                 	8 // no page size concept, only for 8 byte alignment
#define TX_PAGE_NUM		    			256
#define SIZE_RX_DESC_MAC            	24
#define SIZE_TX_DESC_MAC            	40
#define MACID_NUM                   	16
#define SIZE_CTRLINFO_ENTRY				40

//2 Common Interface for each HAL
//other
#define TSF_After(a,b)  					((s32)(b)-(s32)(a)<0)

//2 KM4/KR4/DDMA access base
//3 BB base address
#define RTL8721F_BBREG_AHB_BASE             	0x40010000
#define BBREG_AHB_BASE             				RTL8721F_BBREG_AHB_BASE
//3 RF base address
#define RTL8721F_ARFCREG_AHB_BASE             	0x40017000
#define ARFCREG_AHB_BASE             			RTL8721F_ARFCREG_AHB_BASE
#define RTL8721F_DRFCREG_AHB_BASE             	0x4001E000
#define DRFCREG_AHB_BASE             			RTL8721F_DRFCREG_AHB_BASE
//3 BT mailbox base address
#define RTL8721F_BT_MAILBOX_AHB_BASE        	0x400011A4
#define BT_MAILBOX_AHB_BASE						RTL8721F_BT_MAILBOX_AHB_BASE
//3 LLT Table base
#define RTL8721F_LLT_AHB_BASE					0x40050000//256 byte/entry
//3 TxReport Buffer base address
#define RTL8721F_RPTBUF_AHB_BASE            	0x40040000
#define RTL8721F_CtrlInfo_AHB_BASE          	(RTL8721F_RPTBUF_AHB_BASE)
#define RTL8721F_TRXRPT_AHB_BASE            	(RTL8721F_RPTBUF_AHB_BASE + TXRPT_START_OFFSET)
#define RTL8721F_CRC5_AHB_BASE              	(RTL8721F_RPTBUF_AHB_BASE + 0xA80)
#define RTL8721F_NANRPT_AHB_BASE             	(RTL8721F_RPTBUF_AHB_BASE + 0xA90)
//3 Rx packet buffer base address
#define RTL8721F_RXFF_AHB_BASE              	0x40030000
#define RXFF_AHB_BASE              				RTL8721F_RXFF_AHB_BASE
//3 Tx packet buffer base address
#define RTL8721F_TXFF_AHB_BASE              	0x40020000
#define TXFF_AHB_BASE              				RTL8721F_TXFF_AHB_BASE
//3 CAM base address
#define RTL8721F_SECCAM_AHB_BASE            	0x40050800
#define SECCAM_AHB_BASE							RTL8721F_SECCAM_AHB_BASE
#define RTL8721F_BACAM_AHB_BASE             	0x40051000
#define RTL8721F_MBIDCAM_AHB_BASE 				0x40051800
//3 address cam address
#define RTL8721F_ADDR_CAM_BASE		0x40051C00
#define ADDR_CAM_BASE				RTL8721F_ADDR_CAM_BASE
//security cam
#define SECCAM_ENTRY_NUM        		32
#define SECCAM_DIRECT_ENTRY_SIZE    	32
#define SECCAM_START_ADDR        		0x800 //not used for normal

//3 PHYSTS/CHANINFO
#define PHYSTS_AHB_BASE            	0x40054000
#define RTL8721F_CHINFO_AHB_BASE            	0x40052000
//2 sysreg access
#define SYSTEM_CTRL_BASE_LPSYS_OFFSET			0x200
//3 retention access
#define RETENTION_RAM_AHB_FW_BASE			  	0x000C0130

#define rtl_inb(offset)             				(*(volatile u8 *)((u32)(offset)))
#define rtl_inw(offset)             				(*(volatile u16 *)((u32)(offset)))
#define rtl_inl(offset)             				(*(volatile u32 *)((u32)(offset)))

#define rtl_outb(offset,val)        				do { (*(volatile u8 *)((u32)(offset)) = (val));    } while(0)
#define rtl_outw(offset,val)        				do { (*(volatile u16 *)((u32)(offset)) = (val));    } while(0)
#define rtl_outl(offset,val)        				do { (*(volatile u32 *)((u32)(offset)) = (val));    } while(0)

//3 LLT TABLE
#define WriteLLTTableDWord(offset, value)   rtl_outl((offset)+RTL8721F_LLT_AHB_BASE, value)
#define WriteLLTTableWord(offset, value)   	rtl_outw((offset)+RTL8721F_LLT_AHB_BASE, value)
#define WriteLLTTableByte(offset, value)   	rtl_outb((offset)+RTL8721F_LLT_AHB_BASE, value)

#define ReadLLTTableDWord(offset)           	(rtl_inl((offset)+RTL8721F_LLT_AHB_BASE))
#define ReadLLTTableWord(offset)            	(rtl_inw((offset)+RTL8721F_LLT_AHB_BASE))
#define ReadLLTTableByte(offset)            	(rtl_inb((offset)+RTL8721F_LLT_AHB_BASE))

//3 BB Reg
#define WritePortBBUlong(offset, value)		rtl_outl((offset)+RTL8721F_BBREG_AHB_BASE, value)
#define WritePortBBUshort(offset, value)  	rtl_outw((offset)+RTL8721F_BBREG_AHB_BASE, value)
#define WritePortBBUchar(offset, value)     rtl_outb((offset)+RTL8721F_BBREG_AHB_BASE, value)

#define ReadPortBBUlong(offset)             	(rtl_inl((offset)+RTL8721F_BBREG_AHB_BASE))
#define ReadPortBBUshort(offset)            	(rtl_inw((offset)+RTL8721F_BBREG_AHB_BASE))
#define ReadPortBBUchar(offset)             	(rtl_inb((offset)+RTL8721F_BBREG_AHB_BASE))

//3 SEC CAM
#define WriteSECCAMDWord(offset, value)  	rtl_outl((offset)+RTL8721F_SECCAM_AHB_BASE, value)
#define WriteSECCAMWord(offset, value)   	rtl_outw((offset)+RTL8721F_SECCAM_AHB_BASE, value)
#define WriteSECCAMByte(offset, value)   	rtl_outb((offset)+RTL8721F_SECCAM_AHB_BASE, value)

#define ReadSECCAMDWord(offset)          		(rtl_inl((offset)+RTL8721F_SECCAM_AHB_BASE))
#define ReadSECCAMWord(offset)           		(rtl_inw((offset)+RTL8721F_SECCAM_AHB_BASE))
#define ReadSECCAMByte(offset)           		(rtl_inb((offset)+RTL8721F_SECCAM_AHB_BASE))

//3 MBID CAM
#define WriteMBIDCAMDWord(offset, value)  	rtl_outl((offset)+RTL8721F_MBIDCAM_AHB_BASE, value)
#define WriteMBIDCAMWord(offset, value)   	rtl_outw((offset)+RTL8721F_MBIDCAM_AHB_BASE, value)
#define WriteMBIDCAMByte(offset, value)   	rtl_outb((offset)+RTL8721F_MBIDCAM_AHB_BASE, value)

#define ReadMBIDCAMDWord(offset)          		(rtl_inl((offset)+RTL8721F_MBIDCAM_AHB_BASE))
#define ReadMBIDCAMWord(offset)           		(rtl_inw((offset)+RTL8721F_MBIDCAM_AHB_BASE))
#define ReadMBIDCAMByte(offset)           		(rtl_inb((offset)+RTL8721F_MBIDCAM_AHB_BASE))

//3 BA CAM
#define WriteBACAMDWord(offset, value)  		rtl_outl((offset)+RTL8721F_BACAM_AHB_BASE, value)
#define WriteBACAMWord(offset, value)   		rtl_outw((offset)+RTL8721F_BACAM_AHB_BASE, value)
#define WriteBACAMByte(offset, value)   		rtl_outb((offset)+RTL8721F_BACAM_AHB_BASE, value)

#define ReadBACAMDWord(offset)          		(rtl_inl((offset)+RTL8721F_BACAM_AHB_BASE))
#define ReadBACAMWord(offset)           		(rtl_inw((offset)+RTL8721F_BACAM_AHB_BASE))
#define ReadBACAMByte(offset)           		(rtl_inb((offset)+RTL8721F_BACAM_AHB_BASE))

//3 ReportBUFF
#define WriteRPTBUFDWord(offset, value)  	rtl_outl((offset)+RTL8721F_RPTBUF_AHB_BASE, value)
#define WriteRPTBUFWord(offset, value)   	rtl_outw((offset)+RTL8721F_RPTBUF_AHB_BASE, value)
#define WriteRPTBUFByte(offset, value)   	rtl_outb((offset)+RTL8721F_RPTBUF_AHB_BASE, value)

#define ReadRPTBUFDWord(offset)          		(rtl_inl((offset)+RTL8721F_RPTBUF_AHB_BASE))
#define ReadRPTBUFWord(offset)           		(rtl_inw((offset)+RTL8721F_RPTBUF_AHB_BASE))
#define ReadRPTBUFByte(offset)           		(rtl_inb((offset)+RTL8721F_RPTBUF_AHB_BASE))

//3 RXFF
#define WriteRXFFDWord(offset, value)   		rtl_outl((offset)+RTL8721F_RXFF_AHB_BASE, value)
#define WriteRXFFWord(offset, value)    		rtl_outw((offset)+RTL8721F_RXFF_AHB_BASE, value)
#define WriteRXFFByte(offset, value)    		rtl_outb((offset)+RTL8721F_RXFF_AHB_BASE, value)

#define ReadRXFFDWord(offset)           		(rtl_inl((offset)+RTL8721F_RXFF_AHB_BASE))
#define ReadRXFFWord(offset)            			(rtl_inw((offset)+RTL8721F_RXFF_AHB_BASE))
#define ReadRXFFByte(offset)            			(rtl_inb((offset)+RTL8721F_RXFF_AHB_BASE))

//3 TXFF
#define GetTXFFAddr(offset)     			(u32)((offset)+RTL8721F_TXFF_AHB_BASE)
#define GetMACHeaderAddr(offset)     		(u32)((offset)+RTL8721F_TXFF_AHB_BASE+SIZE_TX_DESC_MAC)

#define WriteTXFFDWord(offset, value)     	rtl_outl((offset)+RTL8721F_TXFF_AHB_BASE, value)
#define WriteTXFFWord(offset, value)      	rtl_outw((offset)+RTL8721F_TXFF_AHB_BASE, value)
#define WriteTXFFByte(offset, value)      	rtl_outb((offset)+RTL8721F_TXFF_AHB_BASE, value)

#define ReadTXFFDWord(offset)             		(rtl_inl((offset)+RTL8721F_TXFF_AHB_BASE))
#define ReadTXFFWord(offset)              		(rtl_inw((offset)+RTL8721F_TXFF_AHB_BASE))
#define ReadTXFFByte(offset)              		(rtl_inb((offset)+RTL8721F_TXFF_AHB_BASE))

//3 Retention RAM
#define WriteRRamDWord(offset, value)     	rtl_outl((offset)+RETENTION_RAM_AHB_FW_BASE, value)
#define WriteRRamWord(offset, value)      	rtl_outw((offset)+RETENTION_RAM_AHB_FW_BASE, value)
#define WriteRRamByte(offset, value)     	 	rtl_outb((offset)+RETENTION_RAM_AHB_FW_BASE, value)

#define ReadRRamDWord(offset)             		(rtl_inl((offset)+RETENTION_RAM_AHB_FW_BASE))
#define ReadRRamWord(offset)              		(rtl_inw((offset)+RETENTION_RAM_AHB_FW_BASE))
#define ReadRRamByte(offset)              		(rtl_inb((offset)+RETENTION_RAM_AHB_FW_BASE))

//3 TX report buffer access
#define ReadCtrlInfoByte(macid, offset) 		rtl_inb(RTL8721F_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + (offset))    //macid range: 0~16; offset range: 0~40
#define ReadCtrlInfoDWord(macid, offset) 	rtl_inl(RTL8721F_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + (offset))    //macid range: 0~16; offset range: 0~40
#define WriteCtrlInfoByte(macid, offset, val)		rtl_outb(RTL8721F_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + (offset), val)
#define WriteCtrlInfoDWord(macid, offset, val)	rtl_outl(RTL8721F_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + (offset), val)


#define WriteTxrptByte(macid,offset,val)	rtl_outb(RTL8721F_TRXRPT_AHB_BASE + (macid<<4) + (offset), val) //macid range: 0~16; offset range: 0~15
#define WriteTxrptDWord(macid,offset,val)	rtl_outl(RTL8721F_TRXRPT_AHB_BASE + (macid<<4) + (offset), val)
#define ReadTxrptByte(macid,offset)   		rtl_inb(RTL8721F_TRXRPT_AHB_BASE + (macid<<4) + (offset))
#define ReadTxrptDWord(macid,offset)  		rtl_inl(RTL8721F_TRXRPT_AHB_BASE + (macid<<4) + (offset))

#define ReadCRC5Byte(macid, offset)  			rtl_inb(RTL8721F_CRC5_AHB_BASE + (macid) + (offset))       //rpt_idx range: 0~15; offset range: 0~1
#define WriteCRC5Byte(macid, offset, val)  	rtl_outb(RTL8721F_CRC5_AHB_BASE + (macid) + (offset), val)

#define ReadNANrptByte(offset)         			rtl_inb(RTL8721F_NANRPT_AHB_BASE  + (offset))
#define ReadNANrptDWORD(offset)        			rtl_inl(RTL8721F_NANRPT_AHB_BASE  + (offset))
#define WriteNANrptByte(offset, val)      	rtl_outb(RTL8721F_NANRPT_AHB_BASE + (offset), val)
#define WriteNANrptDWORD(offset, val)      	rtl_outl(RTL8721F_NANRPT_AHB_BASE + (offset), val)

//3 BT mailbox
#define WriteBTMailboxDWord(offset, value)	rtl_outl((offset)+RTL8721F_BT_MAILBOX_AHB_BASE, value)
#define WriteBTMailboxWord(offset, value)	rtl_outw((offset)+RTL8721F_BT_MAILBOX_AHB_BASE, value)
#define WriteBTmailboxByte(offset, value)	rtl_outb((offset)+RTL8721F_BT_MAILBOX_AHB_BASE, value)

#define ReadBTMailboxDWord(offset)        	(rtl_inl((offset)+RTL8721F_BT_MAILBOX_AHB_BASE))
#define ReadBTMailboxWord(offset)          	(rtl_inw((offset)+RTL8721F_BT_MAILBOX_AHB_BASE))
#define ReadBTMailboxByte(offset)        		(rtl_inb((offset)+RTL8721F_BT_MAILBOX_AHB_BASE))

//3 physts
#define WritePHYSTSDWord(offset, value)     	rtl_outl((offset+PHYSTS_AHB_BASE), value)
#define WritePHYSTWord(offset, value)      	rtl_outw((offset+PHYSTS_AHB_BASE), value)
#define WritePHYSTByte(offset, value)      	rtl_outb((offset+PHYSTS_AHB_BASE), value)

#define ReadPHYSTDWord(offset)             		(rtl_inl((offset+PHYSTS_AHB_BASE)))
#define ReadPHYSTWord(offset)                	(rtl_inw((offset+PHYSTS_AHB_BASE)))
#define ReadPHYSTByte(offset)               	(rtl_inb((offset+PHYSTS_AHB_BASE)))

//3 channel info
#define WriteCHINFODWord(offset, value)     	rtl_outl((offset+RTL8721F_CHINFO_AHB_BASE), value)
#define WriteCHINFOWord(offset, value)      	rtl_outw((offset+RTL8721F_CHINFO_AHB_BASE), value)
#define WriteCHINFOByte(offset, value)      	rtl_outb((offset+RTL8721F_CHINFO_AHB_BASE), value)

#define ReadCHINFODWord(offset)             	(rtl_inl((offset+RTL8721F_CHINFO_AHB_BASE)))
#define ReadCHINFOWord(offset)                	(rtl_inw((offset+RTL8721F_CHINFO_AHB_BASE)))
#define ReadCHINFOByte(offset)               	(rtl_inb((offset+RTL8721F_CHINFO_AHB_BASE)))

//3 lpssyson
#define WriteLSONDWord(offset, value)        rtl_outl((offset)+SYSTEM_CTRL_BASE, value)
#define WriteLSONWord(offset, value)         	rtl_outw((offset)+SYSTEM_CTRL_BASE, value)
#define WriteLSONByte(offset, value)         	rtl_outb((offset)+SYSTEM_CTRL_BASE, value)

#define ReadLSONDWord(offset)                	(rtl_inl((offset)+SYSTEM_CTRL_BASE))
#define ReadLSONWord(offset)                 	(rtl_inw((offset)+SYSTEM_CTRL_BASE))
#define ReadLSONByte(offset)                 	(rtl_inb((offset)+SYSTEM_CTRL_BASE))

#define RFCRegToByteAddr(x)		((x)<<2)

//============================================================================
//       8721F Regsiter Bit and Content definition
//============================================================================
#define SCOREBOARD_BT_ON								BIT25
#define SCOREBOARD_BT_LPS								BIT26

/*------------------------COEX FW Debug GPIO------------------------------*/
//==PA25=bt_wake_sys==5=#
//==PA4=wl_pri==1=#
//==PA5=wl_rx==2=#
//==PC6=wl_tx==3=#
//==PC7=bt_pri==4=#
//==PA26=bt_rx==6=#
//==PC2=bt_tx==7=#
//==PA3=gnt_bt==0=#
#define BTC_TDMA0_3_PIN						_PA_20
#define BTC_TDMA1_4_PIN						_PA_21
#define BTC_TDMA2_5_PIN						_PB_19
#define BTC_TBTT_PIN						_PA_23
#define BTC_RF_PIN							_PB_18
#define BTC_CLK_PIN							_PB_17
#define PS_PIN_STATE2						_PC_5
#define PS_PIN_STATE1						_PC_4
#define PS_PIN_STATE0						_PA_0

/*------------------------Export global variable------------------------------*/

#endif  /* __ASSEMBLY__ */
#endif  /* __WIFIFW_HAL_H__ */
