#ifndef __WIFIFW_HAL_RAM_H__
#define __WIFIFW_HAL_RAM_H__

/*--------------------------Define -------------------------------------------*/
#define CONFIG_DRFC_IC						1

//3 1.) basic
#define PAGESIZE_TX                 128
#define PAGESIZE_RX                 8 // no page size concept, only for 8 byte alignment
#define TX_PAGE_NUM					256
#define SIZE_RX_DESC_MAC			24
#define SIZE_TX_DESC_MAC			40
#define MACID_NUM					16

#define SIZE_CTRLINFO_ENTRY			40


//2 KM0 access base
//3 BB base address
#define RTL8730E_BBREG_AHB_BASE             	0x43010000
#define BBREG_AHB_BASE             				RTL8730E_BBREG_AHB_BASE
//3 RF base address
#define RTL8730E_RFREG_AHB_BASE             	0x43017000
//3 DDMA control base address
#define RTL8730E_DDMA_CTRL_AHB_BASE         	0x43000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8730E_BT_MAILBOX_AHB_BASE        	0x430011A4
//3 LPSYSON local base
#define RTL8730E_LPSYSON_AHB_BASE				0x42008000
//3 LLT Table base
#define RTL8730E_LLT_AHB_BASE					0x43050000//256 byte/entry
//3 TxReport Buffer base address
#define RTL8730E_RPTBUF_AHB_BASE            	0x43040000
#define RTL8730E_CtrlInfo_AHB_BASE          	(RTL8730E_RPTBUF_AHB_BASE)
#define RTL8730E_TRXRPT_AHB_BASE            	(RTL8730E_RPTBUF_AHB_BASE + TXRPT_START_OFFSET)
#define RTL8730E_CRC5_AHB_BASE              	(RTL8730E_RPTBUF_AHB_BASE + 0xA80)
#define RTL8730E_NANRPT_AHB_BASE             	(RTL8730E_RPTBUF_AHB_BASE + 0xA90)
//3 Rx packet buffer base address
#define RTL8730E_RXFF_AHB_BASE              	0x43030000
#define RXFF_AHB_BASE              				RTL8730E_RXFF_AHB_BASE
//3 Tx packet buffer base address
#define RTL8730E_TXFF_AHB_BASE              	0x43020000
#define TXFF_AHB_BASE              				RTL8730E_TXFF_AHB_BASE
//3 CAM base address
#define RTL8730E_SECCAM_AHB_BASE            	0x43050800
#define SECCAM_AHB_BASE							RTL8730E_SECCAM_AHB_BASE
#define RTL8730E_BACAM_AHB_BASE             	0x43051000
#define RTL8730E_MBIDCAM_AHB_BASE 				0x43051800

//2 DDMA access base
//3 MAC base address
#define RTL8730E_IOREG_DDMA_AXI_BASE			0x40000000
//3 BB base address
#define RTL8730E_BBREG_DDMA_AXI_BASE            0x40010000
//3 RF base address
#define RTL8730E_RFREG_DDMA_AXI_BASE            0x40017000
//3 DDMA control base address
#define RTL8730E_DDMA_CTRL_DDMA_AXI_BASE        0x40000000 //0x4000_1200- 0x4000_12FF
//3 BT mailbox base address
#define RTL8730E_BT_MAILBOX_DDMA_AXI_BASE       0x400011A4
//3 LLT Table base
#define RTL8730E_LLT_DDMA_AXI_BASE			    0x40050000//256 byte/entry
//3 TxReport Buffer base address
#define RTL8730E_RPTBUF_DDMA_AXI_BASE     	    0x40040000
#define RTL8730E_CtrlInfo_DDMA_AXI_BASE  	    (RTL8730E_RPTBUF_AHB_BASE)
#define RTL8730E_TRXRPT_DDMA_AXI_BASE       	(RTL8730E_RPTBUF_AHB_BASE + 0x280)
#define RTL8730E_CRC5_DDMA_AXI_BASE          	(RTL8730E_RPTBUF_AHB_BASE + 0xA80)
#define RTL8730E_NANRPT_DDMA_AXI_BASE     	    (RTL8730E_RPTBUF_AHB_BASE + 0xA90)
//3 Rx packet buffer base address
#define RTL8730E_RXFF_DDMA_AXI_BASE          	0x40030000
//3 Tx packet buffer base address
#define RTL8730E_TXFF_DDMA_AXI_BASE          	0x40020000
//3 CAM base address
#define RTL8730E_SECCAM_DDMA_AXI_BASE      	    0x40050800
#define RTL8730E_BACAM_DDMA_AXI_BASE        	0x40051000
#define RTL8730E_MBIDCAM_DDMA_AXI_BASE 		    0x40051800

//security cam
#define SECCAM_ENTRY_NUM					32
#define SECCAM_DIRECT_ENTRY_SIZE		    32
#define SECCAM_START_ADDR					0x800 //not used for normal

//2 BUS access
//3 PHYSTS/CHANINFO
#define PHYSTS_AHB_BASE            	            0x43054000
#define RTL8730E_CHINFO_AHB_BASE            	0x43052000


//offset:
#define rtl_inb(offset)             				(*(volatile u8 *)((u32)offset))
#define rtl_inw(offset)             				(*(volatile u16 *)((u32)offset))
#define rtl_inl(offset)             				(*(volatile u32 *)((u32)offset))

#define rtl_outb(offset,val)        				do { (*(volatile u8 *)((u32)offset) = (val));    } while(0)
#define rtl_outw(offset,val)        				do { (*(volatile u16 *)((u32)offset) = (val));    } while(0)
#define rtl_outl(offset,val)        				do { (*(volatile u32 *)((u32)offset) = (val));    } while(0)


//3 LLT TABLE
#define WriteLLTTableDWord(offset, value)   rtl_outl((offset+RTL8730E_LLT_AHB_BASE), value)
#define WriteLLTTableWord(offset, value)   	rtl_outw((offset+RTL8730E_LLT_AHB_BASE), value)
#define WriteLLTTableByte(offset, value)   	rtl_outb((offset+RTL8730E_LLT_AHB_BASE), value)

#define ReadLLTTableDWord(offset)           	(rtl_inl((offset+RTL8730E_LLT_AHB_BASE)))
#define ReadLLTTableWord(offset)            	(rtl_inw((offset+RTL8730E_LLT_AHB_BASE)))
#define ReadLLTTableByte(offset)            	(rtl_inb((offset+RTL8730E_LLT_AHB_BASE)))

//3 BB Reg
#define WritePortBBUlong(offset, value)		rtl_outl((offset+RTL8730E_BBREG_AHB_BASE), value)
#define WritePortBBUshort(offset, value)  	rtl_outw((offset+RTL8730E_BBREG_AHB_BASE), value)
#define WritePortBBUchar(offset, value)     rtl_outb((offset+RTL8730E_BBREG_AHB_BASE), value)

#define ReadPortBBUlong(offset)             	(rtl_inl((offset+RTL8730E_BBREG_AHB_BASE)))
#define ReadPortBBUshort(offset)            	(rtl_inw((offset+RTL8730E_BBREG_AHB_BASE)))
#define ReadPortBBUchar(offset)             	(rtl_inb((offset+RTL8730E_BBREG_AHB_BASE)))

//3 RF Reg only support dword mode
#define WritePortRFUlong(offset, value)     	rtl_outl((4*offset+RTL8730E_RFREG_AHB_BASE), value)
#define ReadPortRFUlong(offset)             	(rtl_inl((4*offset+RTL8730E_RFREG_AHB_BASE)))

//3 SEC CAM
#define WriteSECCAMDWord(offset, value)  	rtl_outl((offset+RTL8730E_SECCAM_AHB_BASE), value)
#define WriteSECCAMWord(offset, value)   	rtl_outw((offset+RTL8730E_SECCAM_AHB_BASE), value)
#define WriteSECCAMByte(offset, value)   	rtl_outb((offset+RTL8730E_SECCAM_AHB_BASE), value)

#define ReadSECCAMDWord(offset)          		(rtl_inl((offset+RTL8730E_SECCAM_AHB_BASE)))
#define ReadSECCAMWord(offset)           		(rtl_inw((offset+RTL8730E_SECCAM_AHB_BASE)))
#define ReadSECCAMByte(offset)           		(rtl_inb((offset+RTL8730E_SECCAM_AHB_BASE)))

//3 MBID CAM
#define WriteMBIDCAMDWord(offset, value)  	rtl_outl((offset+RTL8730E_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMWord(offset, value)   	rtl_outw((offset+RTL8730E_MBIDCAM_AHB_BASE), value)
#define WriteMBIDCAMByte(offset, value)   	rtl_outb((offset+RTL8730E_MBIDCAM_AHB_BASE), value)

#define ReadMBIDCAMDWord(offset)          		(rtl_inl((offset+RTL8730E_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMWord(offset)           		(rtl_inw((offset+RTL8730E_MBIDCAM_AHB_BASE)))
#define ReadMBIDCAMByte(offset)           		(rtl_inb((offset+RTL8730E_MBIDCAM_AHB_BASE)))

//3 BA CAM
#define WriteBACAMDWord(offset, value)  		rtl_outl((offset+RTL8730E_BACAM_AHB_BASE), value)
#define WriteBACAMWord(offset, value)   		rtl_outw((offset+RTL8730E_BACAM_AHB_BASE), value)
#define WriteBACAMByte(offset, value)   		rtl_outb((offset+RTL8730E_BACAM_AHB_BASE), value)

#define ReadBACAMDWord(offset)          		(rtl_inl((offset+RTL8730E_BACAM_AHB_BASE)))
#define ReadBACAMWord(offset)           		(rtl_inw((offset+RTL8730E_BACAM_AHB_BASE)))
#define ReadBACAMByte(offset)           		(rtl_inb((offset+RTL8730E_BACAM_AHB_BASE)))

//3 ReportBUFF
#define WriteRPTBUFDWord(offset, value)  	rtl_outl((offset+RTL8730E_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFWord(offset, value)   	rtl_outw((offset+RTL8730E_RPTBUF_AHB_BASE), value)
#define WriteRPTBUFByte(offset, value)   	rtl_outb((offset+RTL8730E_RPTBUF_AHB_BASE), value)

#define ReadRPTBUFDWord(offset)          		(rtl_inl((offset+RTL8730E_RPTBUF_AHB_BASE)))
#define ReadRPTBUFWord(offset)           		(rtl_inw((offset+RTL8730E_RPTBUF_AHB_BASE)))
#define ReadRPTBUFByte(offset)           		(rtl_inb((offset+RTL8730E_RPTBUF_AHB_BASE)))

//3 RXFF
#define WriteRXFFDWord(offset, value)   		rtl_outl((offset+RTL8730E_RXFF_AHB_BASE), value)
#define WriteRXFFWord(offset, value)    		rtl_outw((offset+RTL8730E_RXFF_AHB_BASE), value)
#define WriteRXFFByte(offset, value)    		rtl_outb((offset+RTL8730E_RXFF_AHB_BASE), value)

#define ReadRXFFDWord(offset)           		(rtl_inl((offset+RTL8730E_RXFF_AHB_BASE)))
#define ReadRXFFWord(offset)            			(rtl_inw((offset+RTL8730E_RXFF_AHB_BASE)))
#define ReadRXFFByte(offset)            			(rtl_inb((offset+RTL8730E_RXFF_AHB_BASE)))

//3 TXFF
#define WriteTXFFDWord(offset, value)     	rtl_outl((offset+RTL8730E_TXFF_AHB_BASE), value)
#define WriteTXFFWord(offset, value)      	rtl_outw((offset+RTL8730E_TXFF_AHB_BASE), value)
#define WriteTXFFByte(offset, value)      	rtl_outb((offset+RTL8730E_TXFF_AHB_BASE), value)

#define ReadTXFFDWord(offset)             		(rtl_inl((offset+RTL8730E_TXFF_AHB_BASE)))
#define ReadTXFFWord(offset)              		(rtl_inw((offset+RTL8730E_TXFF_AHB_BASE)))
#define ReadTXFFByte(offset)              		(rtl_inb((offset+RTL8730E_TXFF_AHB_BASE)))

//3 Retention RAM
#define WriteRRamDWord(offset, value)     	rtl_outl((offset+RETENTION_RAM_BASE), value)
#define WriteRRamWord(offset, value)      	rtl_outw((offset+RETENTION_RAM_BASE), value)
#define WriteRRamByte(offset, value)     	 	rtl_outb((offset+RETENTION_RAM_BASE), value)

#define ReadRRamDWord(offset)             		(rtl_inl((offset+RETENTION_RAM_BASE)))
#define ReadRRamWord(offset)              		(rtl_inw((offset+RETENTION_RAM_BASE)))
#define ReadRRamByte(offset)              		(rtl_inb((offset+RETENTION_RAM_BASE)))

//3 TX report buffer access

#define ReadCtrlInfoByte(macid, offset) 		rtl_inb(RTL8730E_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset)    //macid range: 0~16; offset range: 0~40
#define ReadCtrlInfoDWord(macid, offset) 	rtl_inl(RTL8730E_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset)    //macid range: 0~16; offset range: 0~40
#define WriteCtrlInfoByte(macid, offset, val)		rtl_outb(RTL8730E_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset, val)
#define WriteCtrlInfoDWord(macid, offset, val)	rtl_outl(RTL8730E_CtrlInfo_AHB_BASE + (macid*SIZE_CTRLINFO_ENTRY) + offset, val)


#define WriteTxrptByte(macid,offset,val)	rtl_outb(RTL8730E_TRXRPT_AHB_BASE + (macid<<4) + offset, val) //macid range: 0~16; offset range: 0~15
#define WriteTxrptDWord(macid,offset,val)	rtl_outl(RTL8730E_TRXRPT_AHB_BASE + (macid<<4) + offset, val)
#define ReadTxrptByte(macid,offset)   		rtl_inb(RTL8730E_TRXRPT_AHB_BASE + (macid<<4) + offset)
#define ReadTxrptDWord(macid,offset)  		rtl_inl(RTL8730E_TRXRPT_AHB_BASE + (macid<<4) + offset)

#define ReadCRC5Byte(macid, offset)  			rtl_inb(RTL8730E_CRC5_AHB_BASE + (macid) + offset)       //rpt_idx range: 0~15; offset range: 0~1
#define WriteCRC5Byte(macid, offset, val)  	rtl_outb(RTL8730E_CRC5_AHB_BASE + (macid) + offset, val)

#define ReadNANrptByte(offset)         			rtl_inb(RTL8730E_NANRPT_AHB_BASE  + offset)
#define ReadNANrptDWORD(offset)        			rtl_inl(RTL8730E_NANRPT_AHB_BASE  + offset)
#define WriteNANrptByte(offset, val)      	rtl_outb(RTL8730E_NANRPT_AHB_BASE + offset, val)
#define WriteNANrptDWORD(offset, val)      	rtl_outl(RTL8730E_NANRPT_AHB_BASE + offset, val)

//3 BT mailbox
#define WriteBTMailboxDWord(offset, value)	rtl_outl((offset+RTL8730E_BT_MAILBOX_AHB_BASE), value)
#define WriteBTMailboxWord(offset, value)	rtl_outw((offset+RTL8730E_BT_MAILBOX_AHB_BASE), value)
#define WriteBTmailboxByte(offset, value)	rtl_outb((offset+RTL8730E_BT_MAILBOX_AHB_BASE), value)

#define ReadBTMailboxDWord(offset)        	(rtl_inl((offset+RTL8730E_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxWord(offset)          	(rtl_inw((offset+RTL8730E_BT_MAILBOX_AHB_BASE)))
#define ReadBTMailboxByte(offset)        		(rtl_inb((offset+RTL8730E_BT_MAILBOX_AHB_BASE)))

//3 DDMA
#define WriteDDMADWord(offset, value)     	rtl_outl((offset+RTL8730E_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAWord(offset, value)      	rtl_outw((offset+RTL8730E_DDMA_CTRL_AHB_BASE), value)
#define WriteDDMAByte(offset, value)      	rtl_outb((offset+RTL8730E_DDMA_CTRL_AHB_BASE), value)

#define ReadDDMADWord(offset)             		(rtl_inl((offset+RTL8730E_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAWord(offset)                		(rtl_inw((offset+RTL8730E_DDMA_CTRL_AHB_BASE)))
#define ReadDDMAByte(offset)               		(rtl_inb((offset+RTL8730E_DDMA_CTRL_AHB_BASE)))

//3 lpssyson
#define WriteLSONDWord(offset, value)        rtl_outl((offset+RTL8730E_LPSYSON_AHB_BASE), value)
#define WriteLSONWord(offset, value)         	rtl_outw((offset+RTL8730E_LPSYSON_AHB_BASE), value)
#define WriteLSONByte(offset, value)         	rtl_outb((offset+RTL8730E_LPSYSON_AHB_BASE), value)

#define ReadLSONDWord(offset)                	(rtl_inl((offset+RTL8730E_LPSYSON_AHB_BASE)))
#define ReadLSONWord(offset)                 	(rtl_inw((offset+RTL8730E_LPSYSON_AHB_BASE)))
#define ReadLSONByte(offset)                 	(rtl_inb((offset+RTL8730E_LPSYSON_AHB_BASE)))

//3 physts
#define WritePHYSTDWord(offset, value)     	rtl_outl((offset+PHYSTS_AHB_BASE), value)
#define WritePHYSTWord(offset, value)      	rtl_outw((offset+PHYSTS_AHB_BASE), value)
#define WritePHYSTByte(offset, value)      	rtl_outb((offset+PHYSTS_AHB_BASE), value)

#define ReadPHYSTDWord(offset)             		(rtl_inl((offset+PHYSTS_AHB_BASE)))
#define ReadPHYSTWord(offset)                	(rtl_inw((offset+PHYSTS_AHB_BASE)))
#define ReadPHYSTByte(offset)               	(rtl_inb((offset+PHYSTS_AHB_BASE)))

//3 channel info
#define WriteCHINFODWord(offset, value)     	rtl_outl((offset+RTL8730E_CHINFO_AHB_BASE), value)
#define WriteCHINFOWord(offset, value)      	rtl_outw((offset+RTL8730E_CHINFO_AHB_BASE), value)
#define WriteCHINFOByte(offset, value)      	rtl_outb((offset+RTL8730E_CHINFO_AHB_BASE), value)

#define ReadCHINFODWord(offset)             	(rtl_inl((offset+RTL8730E_CHINFO_AHB_BASE)))
#define ReadCHINFOWord(offset)                	(rtl_inw((offset+RTL8730E_CHINFO_AHB_BASE)))
#define ReadCHINFOByte(offset)               	(rtl_inb((offset+RTL8730E_CHINFO_AHB_BASE)))

//3 RF base address
#define RTL8730E_ARFCREG_AHB_BASE             	0x43017000
#define ARFCREG_AHB_BASE             			RTL8730E_ARFCREG_AHB_BASE
#define RTL8730E_DRFCREG_AHB_BASE             	0x4301E000
#define DRFCREG_AHB_BASE             			RTL8730E_DRFCREG_AHB_BASE
#define BT_MAILBOX_AHB_BASE						RTL8730E_BT_MAILBOX_AHB_BASE

//3 TXFF
#define GetTXFFAddr(offset)     			(u32)((offset)+RTL8730E_TXFF_AHB_BASE)
#define GetMACHeaderAddr(offset)     		(u32)((offset)+RTL8730E_TXFF_AHB_BASE+SIZE_TX_DESC_MAC)

//other
#define TSF_After(a,b)  					((s32)(b)-(s32)(a)<0)
#define SCOREBOARD_BT_ON								BIT1
#define SCOREBOARD_BT_LPS								BIT7
#define RFCRegToByteAddr(x)		((x)<<2)

/*------------------------COEX FW Debug GPIO------------------------------*/
//#==PA2==wl_pri=0=#
//#==PA3==wl_rx=1=#
//#==PA4==wl_tx=2=#
//#==PA5==bt_pri=3=#
//#==PA15==bt_rx=4=#
//#==PA16==bt_tx=5=#
//#==PB26==gnt_bt==#
//#==PB25==gnt_wl==#
//#==PA6==gnt_bt_pta==#
//#==PC0==gnt_wl_pta==#
#define BTC_TDMA0_3_PIN						_PB_7
#define BTC_TDMA1_4_PIN						_PB_8
#define BTC_TDMA2_5_PIN						_PB_9
#define BTC_TBTT_PIN						_PB_12
#define BTC_RF_PIN							_PB_13
#define BTC_CLK_PIN							_PA_9
#define PS_PIN_STATE2						_PA_7
#define PS_PIN_STATE1						_PA_8
#define PS_PIN_STATE0						_PA_12
#define BTC_TDMA_MAILBOX					_PA_14

/*------------------------------Define Struct---------------------------------*/

#endif  /* __WIFIFW_HAL_RAM_H__ */
