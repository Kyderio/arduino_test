ENTRY(Reset_Handler)

/*INCLUDE "ameba_layout.ld"*/
/* constant macro */
/*IMAGE_HEADER_LEN		=	(0x20)*/

/* layout configuration */
/*TZ_NSC_SIZE 	 		=	(4)
TZ_ENTRY_SIZE 			=	(16)
TZ_S_SIZE 				=	(1024)*/

PSRAM_BASE				=	(0x02000000);
PSRAM_END				=	(PSRAM_BASE + (4*1024*1024)); /* 4MB PSRAM */

RAM_TZ_NSC_SIZE 	 	=	(0);
RAM_TZ_ENTRY_SIZE 		=	(0);
PSRAM_KM4_IMG3_SIZE 	=	(0);

KM4_BD_RAM_NSC_START	=	(0x1007C000 - RAM_TZ_NSC_SIZE);
KM4_BD_RAM_S_START		=	(KM4_BD_RAM_NSC_START - RAM_TZ_ENTRY_SIZE);
KM4_PSRAM_S_START		=	(PSRAM_END - PSRAM_KM4_IMG3_SIZE);

MEMORY
{
	/* KM0 ROM */
	KM0_IROM (rx) :					ORIGIN = 0x00000000, LENGTH = 0x00018000 - 0x00000000	/* KM0 IROM: 96k */
	KM0_DROM (rx) :                 ORIGIN = 0x00020000, LENGTH = 0x00024000 - 0x00020000 	/* KM0 DROM: 16k */

	/* KM4 ROM */
	KM4_IROM (rx) :                 ORIGIN = 0x10100000, LENGTH = 0x1010A000 - 0x10100000	/* KM4 IROM_S: 40k */
	KM4_IROM_NS (rx) :              ORIGIN = 0x1010A000, LENGTH = 0x10140000 - 0x1010A000	/* KM4 IROM_NS: 216k */
	KM4_DROM_NS (rx) :              ORIGIN = 0x101C0000, LENGTH = 0x101D4000 - 0x101C0000	/* KM4 DROM_NS: 80k */
	KM4_DROM (rx) :                 ORIGIN = 0x101D4000, LENGTH = 0x101D8000 - 0x101D4000	/* KM4 DROM_S: 16k */

	/* KM0 RAM */
	KM0_ROMBSS_RAM (rw) :           ORIGIN = 0x00080000, LENGTH = 0x00081000 - 0x00080000	/* KM0 ROM BSS RAM: 4K */
	KM0_TIMER_IDLE_TASK_STACK (rw) : ORIGIN = 0x00081000, LENGTH = 0x00082000 - 0x00081000	/* KM0 TIMER and IDLE task stack: 4k */
	KM0_BOOTLOADER_RAM (rwx) :      ORIGIN = 0x00082000, LENGTH = 0x00083000 - 0x00082000	/* KM0 BOOT Loader RAM: 4K */
	KM0_FLOADER_RAM (rwx) :         ORIGIN = 0x00082000, LENGTH = 0x0008F000 - 0x00082000	/* KM0 ImgTool Flash Loader RAM: 52K */
	KM0_BD_RAM (rwx) :              ORIGIN = 0x00083000, LENGTH = 0x0008F000 - 0x00083000	/* KM0 MAIN RAM: 48K */
	KM0_MSP_RAM (wx) :              ORIGIN = 0x0008F000, LENGTH = 0x00090000 - 0x0008F000 	/* KM0 MSP RAM: 4k */

	/* Retention RAM */
	RETENTION_RAM (rwx) :           ORIGIN = 0x000C0000, LENGTH = 0x000C0400 - 0x000C0000	/* Retention RAM: 1K */

	/* Non-secure PSRAM */
	KM4_PSRAM_NS (rwx) :            ORIGIN = 0x02000020, LENGTH = KM4_PSRAM_S_START - 0x02000020	/* KM4 PSRAM NS: 3M */
	KM4_PSRAM_S (rwx) :             ORIGIN = KM4_PSRAM_S_START, LENGTH = PSRAM_KM4_IMG3_SIZE	/* KM4 PSRAM_S: 1M */

	/* KM4 Non-secure RAM */
	KM4_ROMBSS_RAM_COM (rw) :       ORIGIN = 0x10000000, LENGTH = 0x10001000 - 0x10000000	/* KM4 ROM BSS COMMON(S & NS both used) RAM: 4k */
	KM4_ROMBSS_RAM_NS (rw) :        ORIGIN = 0x10001000, LENGTH = 0x10002000 - 0x10001000	/* KM4 ROM BSS NS RAM: 4k */
	KM4_MSP_RAM_NS (rw) :           ORIGIN = 0x10002000, LENGTH = 0x10003000 - 0x10002000	/* KM4 MSP_NS RAM: 4K */
	KM4_BD_RAM_NS (rwx) :           ORIGIN = 0x10003000, LENGTH = KM4_BD_RAM_S_START - 0x10003000	/* KM4 MAIN RAM NS: 464K or 484k */
	KM4_BD_RAM_S (rwx) :            ORIGIN = KM4_BD_RAM_S_START, LENGTH = RAM_TZ_ENTRY_SIZE	/* KM4 MAIN RAM S: 16K */
	KM4_BD_RAM_NSC (rwx) :          ORIGIN = KM4_BD_RAM_NSC_START, LENGTH = RAM_TZ_NSC_SIZE	/* KM4 MAIN RAM NSC: 4K */

	/* KM4 Secure RAM  */
	KM4_ROMBSS_RAM_S (rw) :         ORIGIN = 0x1007C000, LENGTH = 0x1007D000 - 0x1007C000	/* KM4 ROM BSS RAM S: 4k */
	KM4_BOOTLOADER_RAM_S (rwx) :    ORIGIN = 0x1007D000, LENGTH = 0x1007EC00 - 0x1007D000	/* KM4 BOOT Loader RAM: 7k */
	KM4_MSP_RAM_S (rw) :            ORIGIN = 0x1007EC00, LENGTH = 0x1007F000 - 0x1007EC00	/* KM4 MSP_S RAM: 1k (sboot use 4k before img1 load) */
	KM4_TIMER_IDLE_TASK_STACK (rw) : ORIGIN = 0x1007F000, LENGTH = 0x10080000 - 0x1007F000	/* KM4 TIMER and IDLE task stack: 4k */

	KM4_EXTENTION_SRAM (rwx) :      ORIGIN = 0x100E0000, LENGTH = 0x10100000 - 0x100E0000	/* KM4 EXTENTION SRAM: 128k */

	/* Flash */
	KM0_BOOT_XIP (rx) :             ORIGIN = 0x08000020, LENGTH = 0x08004000 - 0x08000020	/* KM0 XIP BOOT: 16k, 32 Bytes for header*/
	KM4_BOOT_XIP (rx) :             ORIGIN = 0x08004020, LENGTH = 0x08014000 - 0x08004020	/* KM4 XIP BOOT: 64k, 32 Bytes for header*/
	KM0_IMG2_XIP (rx) :             ORIGIN = 0x0C000020, LENGTH = 0x0E000000 - 0x0C000020	/* KM0 IMG2 Virtual address: 32768k */
	KM4_IMG2_XIP (rx) :             ORIGIN = 0x0E000020, LENGTH = 0x10000000 - 0x0E000020	/* KM4 IMG2 Virtual address: 32768k */
	BTRACE (rx) :                   ORIGIN = 0x00800000, LENGTH = 0x00C00000 -0x00800000	/* Bluetooth Trace */
}

__ls_flash_text_start__ = ORIGIN(KM0_IMG2_XIP);
__hs_flash_text_start__ = ORIGIN(KM4_IMG2_XIP);

/*INCLUDE "ameba_rom_symbol_acut.ld"*/
SECTIONS
{
    PROVIDE(__rom_bss_start__ = 0x10000000);
    PROVIDE(ConfigDebugClose = 0x10000000);
    PROVIDE(ConfigDebugBuffer = 0x10000004);
    PROVIDE(ConfigDebugBufferGet = 0x10000008);
    PROVIDE(ConfigDebug = 0x1000000c);
    PROVIDE(rand_first = 0x1000001c);
    PROVIDE(rand_seed = 0x10000020);
    PROVIDE(RBSS_UDELAY_DIV = 0x10000034);
    PROVIDE(flash_init_para = 0x10000038);
    PROVIDE(GDMA_Reg = 0x10000098);
    PROVIDE(PortA_IrqHandlerTable = 0x1000009c);
    PROVIDE(PortA_IrqDataTable = 0x1000011c);
    PROVIDE(PortB_IrqHandlerTable = 0x1000019c);
    PROVIDE(PortB_IrqDataTable = 0x1000021c);
    PROVIDE(IPC_IrqHandler = 0x1000029c);
    PROVIDE(IPC_IrqData = 0x1000031c);
    PROVIDE(IS_FPGA_VERIF = 0x1000039c);
    PROVIDE(crypto_engine = 0x100003a0);
    PROVIDE(__rom_bss_end__ = 0x10000564);
    PROVIDE(__rom_bss_start_ns__ = 0x10001000);
    PROVIDE(NewVectorTable = 0x10001000);
    PROVIDE(UserIrqFunTable = 0x10001140);
    PROVIDE(UserIrqDataTable = 0x10001240);
    PROVIDE(mpu_entry_register = 0x10001340);
    PROVIDE(p_rom_ssl_ram_map = 0x10001348);
    PROVIDE(rom_ssl_ram_map = 0x1000134c);
    PROVIDE(__rom_bss_end_ns__ = 0x1000138c);
    PROVIDE(__rom_bss_start_s__ = 0x1007c000);
    PROVIDE(__ram_start_table_start__ = 0x1007d000);
    PROVIDE(STACK_TOP = 0x1007effc);
    PROVIDE(__vectors_table = 0x1010a000);
    PROVIDE(Reset_Handler = 0x1010a101);
    PROVIDE(NMI_Handler = 0x1010a111);
    PROVIDE(HardFault_Handler = 0x1010a115);
    PROVIDE(MemManage_Handler = 0x1010a119);
    PROVIDE(BusFault_Handler = 0x1010a11d);
    PROVIDE(UsageFault_Handler = 0x1010a121);
    PROVIDE(SecureFault_Handler = 0x1010a125);
    PROVIDE(DiagVSprintf = 0x1010a12d);
    PROVIDE(DiagPrintf = 0x1010a3f5);
    PROVIDE(DiagPrintfD = 0x1010a445);
    PROVIDE(DiagSPrintf = 0x1010a471);
    PROVIDE(DiagSnPrintf = 0x1010a49d);
    PROVIDE(Rand = 0x1010a765);
    PROVIDE(Rand_Arc4 = 0x1010a7f1);
    PROVIDE(RandBytes_Get = 0x1010a825);
    PROVIDE(io_assert_failed = 0x1010a871);
    PROVIDE(BKUP_Write = 0x1010a891);
    PROVIDE(BKUP_Read = 0x1010a8b5);
    PROVIDE(BKUP_Set = 0x1010a8d5);
    PROVIDE(BKUP_Clear = 0x1010a8fd);
    PROVIDE(BOOT_Reason = 0x1010a929);
    PROVIDE(DelayNop = 0x1010a939);
    PROVIDE(DelayUs = 0x1010a949);
    PROVIDE(DelayMs = 0x1010a995);
    PROVIDE(EFUSEPowerSwitch = 0x1010a9a9);
    PROVIDE(EFUSERead8 = 0x1010aa31);
    PROVIDE(EFUSEWrite8 = 0x1010ab1d);
    PROVIDE(EFUSE_PG_Packet = 0x1010ac21);
    PROVIDE(_EFUSE_LogicalMap_Read = 0x1010ae99);
    PROVIDE(_EFUSE_LogicalMap_Write = 0x1010afad);
    PROVIDE(FLASH_RxData = 0x1010b195);
    PROVIDE(FLASH_TxCmd = 0x1010b29d);
    PROVIDE(FLASH_SW_CS_Control = 0x1010b329);
    PROVIDE(FLASH_SetSpiMode = 0x1010b37d);
    PROVIDE(FLASH_RxCmd = 0x1010b415);
    PROVIDE(FLASH_WaitBusy = 0x1010b479);
    PROVIDE(FLASH_WriteEn = 0x1010b4f9);
    PROVIDE(FLASH_TxData256B = 0x1010b51d);
    PROVIDE(FLASH_TxData12B = 0x1010b60d);
    PROVIDE(FLASH_SetStatus = 0x1010b6ed);
    PROVIDE(FLASH_Erase = 0x1010b70d);
    PROVIDE(FLASH_DeepPowerDown = 0x1010b7b9);
    PROVIDE(FLASH_SetStatusBits = 0x1010b809);
    PROVIDE(FLASH_StructInit_Micron = 0x1010b8dd);
    PROVIDE(FLASH_StructInit_MXIC = 0x1010b98d);
    PROVIDE(FLASH_StructInit_GD = 0x1010ba39);
    PROVIDE(FLASH_StructInit = 0x1010baed);
    PROVIDE(FLASH_Init = 0x1010bba1);
    PROVIDE(GDMA_StructInit = 0x1010bc25);
    PROVIDE(GDMA_SetLLP = 0x1010bc45);
    PROVIDE(GDMA_ClearINTPendingBit = 0x1010bcd9);
    PROVIDE(GDMA_ClearINT = 0x1010bda5);
    PROVIDE(GDMA_INTConfig = 0x1010be75);
    PROVIDE(GDMA_Cmd = 0x1010bf91);
    PROVIDE(GDMA_Init = 0x1010bff9);
    PROVIDE(GDMA_ChCleanAutoReload = 0x1010c14d);
    PROVIDE(GDMA_SetSrcAddr = 0x1010c1d1);
    PROVIDE(GDMA_GetSrcAddr = 0x1010c221);
    PROVIDE(GDMA_GetDstAddr = 0x1010c26d);
    PROVIDE(GDMA_SetDstAddr = 0x1010c2b9);
    PROVIDE(GDMA_SetBlkSize = 0x1010c309);
    PROVIDE(GDMA_GetBlkSize = 0x1010c369);
    PROVIDE(GDMA_ChnlRegister = 0x1010c3b9);
    PROVIDE(GDMA_ChnlUnRegister = 0x1010c401);
    PROVIDE(GDMA_ChnlAlloc = 0x1010c43d);
    PROVIDE(GDMA_ChnlFree = 0x1010c4d9);
    PROVIDE(GDMA_GetIrqNum = 0x1010c565);
    PROVIDE(GPIO_INTMode = 0x1010c5a9);
    PROVIDE(GPIO_INTConfig = 0x1010c641);
    PROVIDE(GPIO_INTHandler = 0x1010c679);
    PROVIDE(GPIO_Direction = 0x1010c721);
    PROVIDE(GPIO_Init = 0x1010c755);
    PROVIDE(GPIO_DeInit = 0x1010c7e1);
    PROVIDE(GPIO_ReadDataBit = 0x1010c84d);
    PROVIDE(GPIO_WriteBit = 0x1010c871);
    PROVIDE(GPIO_PortDirection = 0x1010c8a1);
    PROVIDE(GPIO_PortRead = 0x1010c8c5);
    PROVIDE(GPIO_PortWrite = 0x1010c8d5);
    PROVIDE(GPIO_UserRegIrq = 0x1010c8ed);
    PROVIDE(IPC_INTConfig = 0x1010c925);
    PROVIDE(IPC_IERSet = 0x1010c939);
    PROVIDE(IPC_IERGet = 0x1010c93d);
    PROVIDE(IPC_INTRequest = 0x1010c941);
    PROVIDE(IPC_INTClear = 0x1010c94d);
    PROVIDE(IPC_INTGet = 0x1010c959);
    PROVIDE(IPC_CPUID = 0x1010c95d);
    PROVIDE(IPC_SEMGet = 0x1010c969);
    PROVIDE(IPC_SEMFree = 0x1010c9b9);
    PROVIDE(IPC_INTHandler = 0x1010ca21);
    PROVIDE(IPC_INTUserHandler = 0x1010ca61);
    PROVIDE(LOGUART_StructInit = 0x1010ca9d);
    PROVIDE(LOGUART_Init = 0x1010cab5);
    PROVIDE(LOGUART_PutChar = 0x1010caf5);
    PROVIDE(LOGUART_GetChar = 0x1010cb29);
    PROVIDE(LOGUART_Readable = 0x1010cb45);
    PROVIDE(LOGUART_GetIMR = 0x1010cb59);
    PROVIDE(LOGUART_SetIMR = 0x1010cb65);
    PROVIDE(LOGUART_WaitBusy = 0x1010cb71);
    PROVIDE(LOGUART_SetBaud = 0x1010cb91);
    PROVIDE(mpu_enable = 0x1010cbd5);
    PROVIDE(mpu_disable = 0x1010cbed);
    PROVIDE(mpu_init = 0x1010cc01);
    PROVIDE(mpu_set_mem_attr = 0x1010cc3d);
    PROVIDE(mpu_region_cfg = 0x1010ccb1);
    PROVIDE(mpu_entry_free = 0x1010cdb5);
    PROVIDE(mpu_entry_alloc = 0x1010cdc1);
    PROVIDE(RSIP_Cmd = 0x1010cde9);
    PROVIDE(RSIP_OTF_init = 0x1010ce05);
    PROVIDE(RSIP_OTF_Cmd = 0x1010ce6d);
    PROVIDE(RSIP_OTF_Mask = 0x1010ce81);
    PROVIDE(RSIP_KEY_Request = 0x1010cec9);
    PROVIDE(RSIP_MMU_Config = 0x1010cf0d);
    PROVIDE(RSIP_MMU_Cmd = 0x1010cf31);
    PROVIDE(PAD_DrvStrength = 0x1010cf51);
    PROVIDE(PAD_PullCtrl = 0x1010cf6d);
    PROVIDE(PAD_CMD = 0x1010cf99);
    PROVIDE(Pinmux_Config = 0x1010cfb9);
    PROVIDE(Pinmux_ConfigGet = 0x1010cfd9);
    PROVIDE(Pinmux_UartLogCtrl = 0x1010cfe9);
    PROVIDE(Pinmux_SpicCtrl = 0x1010d03d);
    PROVIDE(simulation_bit_index = 0x1010d181);
    PROVIDE(simulation_stage_set = 0x1010d199);
    PROVIDE(SYSTIMER_Init = 0x1010d1c5);
    PROVIDE(SYSTIMER_TickGet = 0x1010d215);
    PROVIDE(SYSTIMER_GetPassTime = 0x1010d225);
    PROVIDE(RTIM_TimeBaseStructInit = 0x1010d255);
    PROVIDE(RTIM_Cmd = 0x1010d26d);
    PROVIDE(RTIM_GetCount = 0x1010d2f5);
    PROVIDE(RTIM_INTConfig = 0x1010d361);
    PROVIDE(RTIM_INTClear = 0x1010d3f1);
    PROVIDE(RTIM_TimeBaseInit = 0x1010d45d);
    PROVIDE(RTIM_DeInit = 0x1010d595);
    PROVIDE(RTIM_INTClearPendingBit = 0x1010d611);
    PROVIDE(RTIM_GetFlagStatus = 0x1010d685);
    PROVIDE(RTIM_GetINTStatus = 0x1010d75d);
    PROVIDE(UART_DeInit = 0x1010d83d);
    PROVIDE(UART_StructInit = 0x1010d845);
    PROVIDE(UART_BaudParaGetFull = 0x1010d861);
    PROVIDE(UART_BaudParaGet = 0x1010d899);
    PROVIDE(UART_SetBaud = 0x1010d8bd);
    PROVIDE(UART_SetBaudExt = 0x1010d955);
    PROVIDE(UART_SetRxLevel = 0x1010d9cd);
    PROVIDE(UART_RxCmd = 0x1010d9f5);
    PROVIDE(UART_Writable = 0x1010da09);
    PROVIDE(UART_Readable = 0x1010da11);
    PROVIDE(UART_CharPut = 0x1010da19);
    PROVIDE(UART_CharGet = 0x1010da1d);
    PROVIDE(UART_ReceiveData = 0x1010da25);
    PROVIDE(UART_SendData = 0x1010da4d);
    PROVIDE(UART_ReceiveDataTO = 0x1010da75);
    PROVIDE(UART_SendDataTO = 0x1010dab5);
    PROVIDE(UART_RxByteCntClear = 0x1010daf5);
    PROVIDE(UART_RxByteCntGet = 0x1010db01);
    PROVIDE(UART_BreakCtl = 0x1010db09);
    PROVIDE(UART_ClearRxFifo = 0x1010db1d);
    PROVIDE(UART_Init = 0x1010db3d);
    PROVIDE(UART_ClearTxFifo = 0x1010dbe5);
    PROVIDE(UART_INTConfig = 0x1010dbf1);
    PROVIDE(UART_IntStatus = 0x1010dc01);
    PROVIDE(UART_ModemStatusGet = 0x1010dc05);
    PROVIDE(UART_LineStatusGet = 0x1010dc09);
    PROVIDE(UART_WaitBusy = 0x1010dc0d);
    PROVIDE(rtl_crypto_aes_cbc_init = 0x1010dc31);
    PROVIDE(rtl_crypto_aes_cbc_encrypt = 0x1010dc81);
    PROVIDE(rtl_crypto_aes_cbc_decrypt = 0x1010dccd);
    PROVIDE(rtl_crypto_aes_ecb_init = 0x1010dd19);
    PROVIDE(rtl_crypto_aes_ecb_encrypt = 0x1010dd69);
    PROVIDE(rtl_crypto_aes_ecb_decrypt = 0x1010dda1);
    PROVIDE(rtl_crypto_aes_ctr_init = 0x1010ddd9);
    PROVIDE(rtl_crypto_aes_ctr_encrypt = 0x1010de29);
    PROVIDE(rtl_crypto_aes_ctr_decrypt = 0x1010de6d);
    PROVIDE(rtl_crypto_aes_cfb_init = 0x1010deb1);
    PROVIDE(rtl_crypto_aes_cfb_encrypt = 0x1010df01);
    PROVIDE(rtl_crypto_aes_cfb_decrypt = 0x1010df45);
    PROVIDE(rtl_crypto_aes_ofb_init = 0x1010df89);
    PROVIDE(rtl_crypto_aes_ofb_encrypt = 0x1010dfdd);
    PROVIDE(rtl_crypto_aes_ofb_decrypt = 0x1010e021);
    PROVIDE(rtl_crypto_aes_gcm_init = 0x1010e065);
    PROVIDE(rtl_crypto_aes_gcm_encrypt = 0x1010e0b9);
    PROVIDE(rtl_crypto_aes_gcm_decrypt = 0x1010e131);
    PROVIDE(BOOT_ROM_SignatureCheck = 0x1010e1a9);
    PROVIDE(BOOT_ROM_FromFlash = 0x1010e281);
    PROVIDE(BOOT_ROM_InitDebugFlg = 0x1010e38d);
    PROVIDE(BOOT_ROM_ResetVsr = 0x1010e3a9);
    PROVIDE(EXT32K_Cmd = 0x1010e4c9);
    PROVIDE(XTAL_ClkGet = 0x1010e4e9);
    PROVIDE(CPU_ClkSet = 0x1010e501);
    PROVIDE(CPU_ClkGet = 0x1010e515);
    PROVIDE(CRYPTO_MemDump = 0x1010e539);
    PROVIDE(CRYPTO_RegDump = 0x1010e601);
    PROVIDE(CRYPTO_CleanCmdOk = 0x1010e7c1);
    PROVIDE(CRYPTO_ClearAllINT = 0x1010e7f9);
    PROVIDE(CRYPTO_Reset = 0x1010e829);
    PROVIDE(CRYPTO_SetSecurityModeAD = 0x1010e86d);
    PROVIDE(CRYPTO_Init = 0x1010ea49);
    PROVIDE(CRYPTO_ProcessAD = 0x1010ea6d);
    PROVIDE(CRYPTO_SendSeqBuf = 0x1010f681);
    PROVIDE(CRYPTO_CipherInit = 0x1010f799);
    PROVIDE(CRYPTO_CipherEncryptAD = 0x1010f7b9);
    PROVIDE(CRYPTO_CipherDecryptAD = 0x1010f7e9);
    PROVIDE(rtl_crypto_3des_cbc_init = 0x1010f819);
    PROVIDE(rtl_crypto_3des_cbc_encrypt = 0x1010f869);
    PROVIDE(rtl_crypto_3des_cbc_decrypt = 0x1010f8b5);
    PROVIDE(rtl_crypto_3des_ecb_init = 0x1010f901);
    PROVIDE(rtl_crypto_3des_ecb_encrypt = 0x1010f951);
    PROVIDE(rtl_crypto_3des_ecb_decrypt = 0x1010f989);
    PROVIDE(rtl_crypto_3des_cfb_init = 0x1010f9c1);
    PROVIDE(rtl_crypto_3des_cfb_encrypt = 0x1010fa11);
    PROVIDE(rtl_crypto_3des_cfb_decrypt = 0x1010fa49);
    PROVIDE(rtl_crypto_3des_ofb_init = 0x1010fa81);
    PROVIDE(rtl_crypto_3des_ofb_encrypt = 0x1010fad1);
    PROVIDE(rtl_crypto_3des_ofb_decrypt = 0x1010fb09);
    PROVIDE(rtl_crypto_3des_ctr_init = 0x1010fb41);
    PROVIDE(rtl_crypto_3des_ctr_encrypt = 0x1010fb95);
    PROVIDE(rtl_crypto_3des_ctr_decrypt = 0x1010fbcd);
    PROVIDE(rtl_crypto_des_cbc_init = 0x1010fc05);
    PROVIDE(rtl_crypto_des_cbc_encrypt = 0x1010fc59);
    PROVIDE(rtl_crypto_des_cbc_decrypt = 0x1010fcb5);
    PROVIDE(rtl_crypto_des_ecb_init = 0x1010fd11);
    PROVIDE(rtl_crypto_des_ecb_encrypt = 0x1010fd65);
    PROVIDE(rtl_crypto_des_ecb_decrypt = 0x1010fd9d);
    PROVIDE(rtl_crypto_des_cfb_init = 0x1010fdd5);
    PROVIDE(rtl_crypto_des_cfb_encrypt = 0x1010fe29);
    PROVIDE(rtl_crypto_des_cfb_decrypt = 0x1010fe61);
    PROVIDE(rtl_crypto_des_ofb_init = 0x1010fe99);
    PROVIDE(rtl_crypto_des_ofb_encrypt = 0x1010feed);
    PROVIDE(rtl_crypto_des_ofb_decrypt = 0x1010ff25);
    PROVIDE(rtl_crypto_des_ctr_init = 0x1010ff5d);
    PROVIDE(rtl_crypto_des_ctr_encrypt = 0x1010ffb1);
    PROVIDE(rtl_crypto_des_ctr_decrypt = 0x1010ffe9);
    PROVIDE(clear_ns_rom_bss = 0x10110021);
    PROVIDE(RCC_PeriphClockCmd = 0x10110039);
    PROVIDE(RCC_PeriphClockSource_RTC = 0x101100d1);
    PROVIDE(RCC_PeriphClockSource_I2C = 0x1011011d);
    PROVIDE(RCC_PeriphClockSource_QDEC = 0x1011013d);
    PROVIDE(RCC_PeriphClockSource_UART = 0x1011015d);
    PROVIDE(SYSCFG_GetChipInfo = 0x101101d1);
    PROVIDE(INT_HardFault = 0x101101dd);
    PROVIDE(INT_MemManage = 0x101101fd);
    PROVIDE(INT_BusFault = 0x1011021d);
    PROVIDE(INT_UsageFault = 0x1011023d);
    PROVIDE(INT_SecureFault = 0x1011025d);
    PROVIDE(INT_HardFault_C = 0x1011027d);
    PROVIDE(INT_NMI = 0x1011064d);
    PROVIDE(irq_table_init = 0x10110795);
    PROVIDE(irq_enable = 0x101109d1);
    PROVIDE(irq_disable = 0x101109ed);
    PROVIDE(irq_set_priority = 0x10110a11);
    PROVIDE(irq_get_priority = 0x10110a3d);
    PROVIDE(irq_set_pending = 0x10110a65);
    PROVIDE(irq_get_pending = 0x10110a81);
    PROVIDE(irq_clear_pending = 0x10110aa5);
    PROVIDE(irq_register = 0x10110ac1);
    PROVIDE(irq_unregister = 0x10110b0d);
    PROVIDE(_char2num = 0x10110b2d);
    PROVIDE(_2char2dec = 0x10110b5d);
    PROVIDE(_2char2hex = 0x10110bd1);
    PROVIDE(_memchr = 0x10110c39);
    PROVIDE(_memcmp = 0x10110cc9);
    PROVIDE(_memcpy = 0x10110d2d);
    PROVIDE(_memmove = 0x10110dd9);
    PROVIDE(_memset = 0x10110ea1);
    PROVIDE(_vsscanf = 0x10110ffd);
    PROVIDE(_sscanf = 0x101115c1);
    PROVIDE(_stratoi = 0x101115e1);
    PROVIDE(_strcat = 0x10111635);
    PROVIDE(_strchr = 0x10111675);
    PROVIDE(_strcmp = 0x10111745);
    PROVIDE(_strcpy = 0x101117b9);
    PROVIDE(_stricmp = 0x10111805);
    PROVIDE(_strlen = 0x10111839);
    PROVIDE(_strncat = 0x1011189d);
    PROVIDE(_strncmp = 0x101118f9);
    PROVIDE(_strncpy = 0x1011199d);
    PROVIDE(_strnlen = 0x10111a05);
    PROVIDE(_strpbrk = 0x10111a39);
    PROVIDE(_strsep = 0x10111a65);
    PROVIDE(_strstr = 0x10111d25);
    PROVIDE(_strtoull = 0x10111f3d);
    PROVIDE(_strtoll = 0x10111ffd);
    PROVIDE(_strtok = 0x1011201d);
    PROVIDE(__strtok_r = 0x10112029);
    PROVIDE(_strtok_r = 0x1011208d);
    PROVIDE(_strtol_r = 0x10112095);
    PROVIDE(_strtol = 0x101121b1);
    PROVIDE(_strtoul_r = 0x101121b5);
    PROVIDE(_strtoul = 0x101122e9);
    PROVIDE(_strupr = 0x101122ed);
    PROVIDE(__wrap_memchr = 0x10110c39);
    PROVIDE(__wrap_memcmp = 0x10110cc9);
    PROVIDE(__wrap_memcpy = 0x10110d2d);
    PROVIDE(__wrap_memmove = 0x10110dd9);
    PROVIDE(__wrap_memset = 0x10110ea1);
    PROVIDE(__wrap_stratoi = 0x101115e1);
    PROVIDE(__wrap_strcat = 0x10111635);
    PROVIDE(__wrap_strchr = 0x10111675);
    PROVIDE(__wrap_strcmp = 0x10111745);
    PROVIDE(__wrap_strcpy = 0x101117b9);
    PROVIDE(__wrap_stricmp = 0x10111805);
    PROVIDE(__wrap_strlen = 0x10111839);
    PROVIDE(__wrap_strncat = 0x1011189d);
    PROVIDE(__wrap_strncmp = 0x101118f9);
    PROVIDE(__wrap_strncpy = 0x1011199d);
    PROVIDE(__wrap_strnlen = 0x10111a05);
    PROVIDE(__wrap_strpbrk = 0x10111a39);
    PROVIDE(__wrap_strsep = 0x10111a65);
    PROVIDE(__wrap_strstr = 0x10111d25);
    PROVIDE(__wrap_strtoull = 0x10111f3d);
    PROVIDE(__wrap_strtoll = 0x10111ffd);
    PROVIDE(__wrap_strtok = 0x1011201d);
    PROVIDE(__wrap_strtol = 0x101121b1);
    PROVIDE(__wrap_strtoul = 0x101122e9);
    PROVIDE(__wrap_strupr = 0x101122ed);
    PROVIDE(CRYPTO_chacha_20 = 0x10112309);
    PROVIDE(rom_ed25519_gen_keypair = 0x101125c5);
    PROVIDE(rom_ed25519_gen_signature = 0x101125c9);
    PROVIDE(rom_ed25519_verify_signature = 0x101125df);
    PROVIDE(rom_ed25519_ge_double_scalarmult_vartime = 0x10113e89);
    PROVIDE(rom_ed25519_ge_frombytes_negate_vartime = 0x10114195);
    PROVIDE(rom_ed25519_ge_p3_tobytes = 0x10114695);
    PROVIDE(rom_ed25519_ge_scalarmult_base = 0x101146df);
    PROVIDE(rom_ed25519_ge_tobytes = 0x10114807);
    PROVIDE(rom_ed25519_crypto_sign_seed_keypair = 0x10114851);
    PROVIDE(rom_ed25519_crypto_sign_verify_detached = 0x101148a9);
    PROVIDE(rom_ed25519_sc_muladd = 0x10114ad5);
    PROVIDE(rom_ed25519_sc_reduce = 0x1011b265);
    PROVIDE(rom_ed25519_crypto_sign_detached = 0x1011c6dd);
    PROVIDE(CRYPTO_poly1305_init = 0x1011ca99);
    PROVIDE(CRYPTO_poly1305_update = 0x1011cb31);
    PROVIDE(CRYPTO_poly1305_finish = 0x1011cba7);
    PROVIDE(rom_sha512_starts = 0x1011cd4d);
    PROVIDE(rom_sha512_update = 0x1011cd51);
    PROVIDE(rom_sha512_finish = 0x1011cd55);
    PROVIDE(rom_sha512 = 0x1011cd59);
    PROVIDE(rom_sha512_hmac_starts = 0x1011cd5d);
    PROVIDE(rom_sha512_hmac_update = 0x1011cdf1);
    PROVIDE(rom_sha512_hmac_finish = 0x1011cdf5);
    PROVIDE(rom_sha512_hmac_reset = 0x1011ce49);
    PROVIDE(rom_sha512_hmac = 0x1011ce65);
    PROVIDE(rom_sha512_hkdf = 0x1011cea1);
    PROVIDE(curve25519_donna = 0x1011dce5);
    PROVIDE(__rom_entry_ns_start__ = 0x101c0000);
    PROVIDE(rom_sec_call_ns_entry = 0x101c0000);
    PROVIDE(__rom_entry_ns_end__ = 0x101c0008);
    PROVIDE(SPIC_CALIB_PATTERN = 0x101c0008);
    PROVIDE(PORT_AB = 0x101c0024);
    PROVIDE(armBitRevIndexTable1024 = 0x101c004c);
    PROVIDE(twiddleCoef_1024 = 0x101c0e5c);
    PROVIDE(__rom_bss_end_s__ = 0x200f9000);
}


SECTIONS
{
	/* image2: normal image start */
	.ram_image2.entry :
	{
		__ram_image2_text_start__ = .;
		__image2_entry_func__ = .;
		KEEP(*(SORT(.image2.entry.data*)))

		__image2_validate_code__ = .;
		KEEP(*(.image2.validate.rodata*))
	} > KM4_BD_RAM_NS

	/* space for TIMER and IDLE task stack: 4k */
	.sram_timer_idle_task_stack.bss (NOLOAD):
	{
		*port.o(*.uxIdleTaskStack*)
		*port.o(*.uxTimerTaskStack*)
	} > KM4_TIMER_IDLE_TASK_STACK

	.ram_image2.text :
	{
		__sram_image2_start__ = .;
		*(.image2.ram.text*)
		*(.image2.net.ram.text*)
		*(.sramdram.only.text*)
		__sram_image2_end__ = .;
	} > KM4_BD_RAM_NS

	.ram_image2.data :
	{
		*(.data*)
		. = ALIGN(32);
	} > KM4_BD_RAM_NS

	.ram_image2.bss (NOLOAD):
	{
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		__bss_end__ = .;
	} > KM4_BD_RAM_NS

	.ram_image2.nocache.data (NOLOAD):
	{
		. = ALIGN (32);
		__ram_nocache_start__ = .;
		*(.nocache.data*)
		. = ALIGN (32);
		__ram_nocache_end__ = .;
	} > KM4_BD_RAM_NS

	.ram_heap.data (NOLOAD):
	{
		. = ALIGN (32);
		end = .;
		*(.heap.stdlib*)
		. = . + 4096;
		__bdram_heap_buffer_start__ = .;
	} > KM4_BD_RAM_NS

	.xip_image2.text :
	{
		__flash_text_start__ = .;

		*(.text*)
		*(.rodata*)

		/* Add This for C++ support */
		. = ALIGN(4);
		__preinit_array_start = .;
		KEEP(*(.preinit_array))
		__preinit_array_end = .;
		. = ALIGN(4);
		__init_array_start = .;
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		__init_array_end = .;
		. = ALIGN(4);
		__fini_array_start = .;
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		__fini_array_end = .;
		/*-----------------*/

		. = ALIGN (4);
		__cmd_table_start__ = .;
		KEEP(*(.cmd.table.data*))
		__cmd_table_end__ = .;
		. = ALIGN (4);
		__ipc_table_start__ = .;
		KEEP(*(*.ipc.table.data*))
		__ipc_table_end__ = .;
		. = ALIGN (4);
		__git_ver_table_start__ = .;
		KEEP(*(.git.ver.data))
		__git_ver_table_end__ = .;

		__flash_text_end__ = .;

		. = ALIGN (32);
	} > KM4_IMG2_XIP

	/* C++ .ARM.extb/.ARM.exidx address shall same as *(.text*) */
	.ARM.extab  :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > KM4_IMG2_XIP

	.ARM.exidx :
	{
		__exidx_start = .;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
		__exidx_end = .;
	} > KM4_IMG2_XIP

	.bluetooth_trace.text :
	{
		__btrace_start__ = .;
		*(.BTTRACE)
		__btrace_end__ = .;
	} > BTRACE

	/* KM4_PSRAM_NS image start */
	.psram_image2.text :
	{
		__psram_image2_start__ = .;
		__psram_image2_text_start__ = .;
		*(.psram.text*)
		__psram_image2_text_end__ = .;
	} > KM4_PSRAM_NS

	.psram_image2.data :
	{
		. = ALIGN (32);
		*(.psram.data*)
		. = ALIGN (32);
		*(.psram.rodata*)
	} > KM4_PSRAM_NS

	.psram_image2.bss (NOLOAD):
	{
		. = ALIGN (32);
		__psram_bss_start__ = .;
		*(.psram.bss*)
		__psram_bss_end__ = .;
	} > KM4_PSRAM_NS

	.psram_heap.data :
	{
		. = ALIGN (32);
		*(.psram.heap*)
		*(.image2.net.ram.psram.heap*)
	} > KM4_PSRAM_NS
}


__bdram_heap_buffer_size__ = ORIGIN(KM4_BD_RAM_NS) + LENGTH(KM4_BD_RAM_NS) - __bdram_heap_buffer_start__;

__psram_heap_buffer_start__ = .;
__psram_heap_buffer_size__ = 0;

__psram_heap_extend_start__ = .;
__psram_heap_extend_size__ = 0;
