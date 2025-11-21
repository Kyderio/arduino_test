/******************************************************************************
 *
 * Copyright(c) 2007 - 2014 Realtek Corporation. All rights reserved.
 *
 * This is ROM code section.
 *
 *
 ******************************************************************************/
#ifndef __ROM_RTW_SAE_H_
#define __ROM_RTW_SAE_H_

#define sae_ecc_crypto ecp_group
#define sae_crypto_bignum mpi
#define sae_ecc_point ecp_point

#define SAE_KCK_LEN 		32
#define SAE_PMK_LEN 		32
#define SAE_PMKID_LEN 		16
#define SAE_GRP_SIZE 		10			/* SAE group size: 6 ECC group + 4 FFC group */
#define SAE_PWE_MAX_CNT  	40
#define SAE_MAX_PRIME_LEN	512
#define SAE_MAX_ECC_PRIME_LEN 66

extern int sae_debug_level;

#define _SAE_MSG_INFO_	2
#define _SAE_MSG_ERR_	1
#define _SAE_MSG_DISABLE_ 0

#define sae_printf(level, fmt, arg...)     \
do {\
	if(level <= sae_debug_level)	\
		DiagPrintf("\r\nSAE: " fmt, ##arg);\
}while(0)

#define SAE_BIGNUM_CHK(f) do { if( ( ret = f ) != 0 ) goto cleanup; } while( 0 )

/* Special value returned by sae_parse_commit() */
#define SAE_SILENTLY_DISCARD 65535

#ifndef MAC2STR
#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"
#endif

enum sae_type {
	_SAE_TYPE_COMMIT_,
	_SAE_TYPE_CONFIRM_
};

enum sae_state {
	SAE_NOTHING,
	SAE_COMMITTED,
	SAE_CONFIRMED,
	SAE_ACCEPTED
};

struct sae_octect_buf {
	u8 *pbuf;
	u8	length;
};

struct sae_data {
	void	*padapter;	/* pointer to padapter *//*WPA_TODO, delete this when move to AP core*/
	enum sae_state state;
	u16 sc;					/* own send-confirm counter */
	u16 rc;					/* peer send-confirm counter */
	u32 sync;	 			/* protocol instance variable: Sync */
	u16 group;				/* FCC(Finite Cyclic Cryptography) group ID */
	u32 sae_grp_idx;		/* index to the current group in the sae_groups	*/
	u16 last_peer_cmit_seq_num;	/* seq number of commit frame in wlan header */
	u16 last_peer_cfrm_seq_num;	/* seq number of confirm frame in wlan header */
	u16 last_status;		/* status code */
	u8 h2e;					/* hash to element support */
	u8 pmk[SAE_PMK_LEN];
	u8 pmkid[SAE_PMKID_LEN];
	u8 kck[SAE_KCK_LEN];

	sae_crypto_bignum order;
	u32 order_len;
	sae_crypto_bignum prime;
	u32 prime_len;

	sae_crypto_bignum rand;
	sae_crypto_bignum mask;

	sae_crypto_bignum own_commit_scalar;
	sae_crypto_bignum peer_commit_scalar;

	sae_ecc_crypto *ecc;
	sae_ecc_point pwe_ecc;
	sae_ecc_point own_commit_element_ecc;
	sae_ecc_point peer_commit_element_ecc;
	sae_ecc_point pt_ecc;

	const struct dh_group *dh;
	sae_crypto_bignum pwe_ffc;
	sae_crypto_bignum own_commit_element_ffc;
	sae_crypto_bignum peer_commit_element_ffc;
	sae_crypto_bignum pt_ffc;

	/*
	** password to generate PWE,get from wpa passphase
	** or password identifier from auth frame
	*/
	struct sae_octect_buf sae_password;
	struct sae_octect_buf anti_clogging_token;

	u8 self_mac[6];//WPA_TODO, may use the same info in wpa sta info
	u8 peer_mac[6];
	u8 port;
	u8 auth_seq;/*record auth_seq for timer to resend auth*/
	u8 reauth_count;
	u16 indicate_fail_status;
};

//ECC Alogorithm Function
void wifi_rom_dump_bignum(int debug_level, sae_crypto_bignum *bn, u32 size, char *bn_name);
void wifi_rom_dump_ecc_point(int debug_level, sae_ecc_crypto *ecc, sae_ecc_point *point, u32 size, const char *point_name);
void wifi_rom_dump_octect_string(int debug_level, u8 *pbuf, u32 len, const char *lable);
int wifi_rom_ecc_point_read_bignum(sae_ecc_crypto *ecc, sae_crypto_bignum *x, sae_crypto_bignum *y, sae_ecc_point *p);
int wifi_rom_ecc_point_write_bignum(sae_ecc_crypto *ecc, sae_crypto_bignum *x, sae_crypto_bignum *y, sae_ecc_point *p);
int wifi_rom_ecc_point_read_binary(sae_ecc_crypto *ecc, uint8_t *buf, size_t buf_len, sae_ecc_point *p);
int wifi_rom_ecc_point_write_binary(sae_ecc_point *p, unsigned int buf_len, uint8_t *x, uint8_t *y);
int wifi_rom_ecc_point_add_point(sae_ecc_crypto *ecc, sae_ecc_point *X, sae_ecc_point *A, sae_ecc_point *B);

//Big number operation and computatio Function
int wifi_rom_bignum_add_mod(sae_crypto_bignum *X, sae_crypto_bignum *A, sae_crypto_bignum *B, sae_crypto_bignum *N);
int wifi_rom_bignum_mul_mod(sae_crypto_bignum *X, sae_crypto_bignum *A, sae_crypto_bignum *B, sae_crypto_bignum *N);


/*********************************************************************************************
Function:  compare s1 and s2

Parameter: @s1: input 1
           @s2: input 2
           @n: length of input string

return:    0: if equal
           >0: if s1 > s2
           <0: if s1 < s2
*********************************************************************************************/
int wifi_rom_sae_memcmp(void *s1, void *s2, u8 n);


/*********************************************************************************************
Function:  shift buffer

Parameter: @buf: pointer of buffer to shift
           @len: the length of buffer
           @bits: bit counter of buffer

return:    void
*********************************************************************************************/
void wifi_rom_sae_buf_shift_right(u8 *buf, size_t len, size_t bits);


/*********************************************************************************************
Function:  check if sync is greater than dot11RSNASAESync

Parameter: @sae: pointer to sae data
           @dot11RSNASAESync: max Sync value

result:    1: yes; 0: no
*********************************************************************************************/
int wifi_rom_sae_check_big_sync(struct sae_data *sae, u8 dot11RSNASAESync);


/*********************************************************************************************
Function:  switch sae state

Parameter: @sae: 	   pointer to sae data
           @peer_addr: peer mac address
           @sate:  	   enum sae_state{}
           @reason:    a string for mark

result:    void
*********************************************************************************************/
void wifi_rom_sae_set_state(struct sae_data *sae, u8 *peer_addr, enum sae_state state, const char *reason);

void wifi_rom_sae_clear_data(struct sae_data *sae);
int wifi_rom_sae_check_peer_confirm(struct sae_data *sae, u8 *sae_msg, size_t sae_msg_len);
u32 wifi_rom_sae_octect_buf_alloc(struct sae_octect_buf *poctect_buf, u32 length);
void wifi_rom_sae_octect_buf_clear(struct sae_octect_buf *poctect_buf);
int wifi_rom_sae_check_group(struct sae_data *sae, const int *allowed_groups, u16 group);
int wifi_rom_sae_parse_peer_commit(struct sae_data *sae, u8 *sae_msg, u16 sae_msg_len, u8 **token, u32 *token_len);
int wifi_rom_sae_process_peer_commit(struct sae_data *sae);
void wifi_rom_sae_del_event(struct sae_data *sae, const char *reason);
int wifi_rom_sae_generate_commit_element_ecc(struct sae_data *sae);
int wifi_rom_sae_generate_commit_element_ffc(struct sae_data *sae);
int wifi_rom_sae_get_rand_mask(struct sae_data *sae, sae_crypto_bignum *rand, sae_crypto_bignum *mask);
int wifi_rom_sae_derive_pt(struct sae_data *sae, const u8 *ssid, size_t ssid_len, const u8 *password, size_t password_len, const char *identifier);
int wifi_rom_sae_blind_select_group(struct sae_data *sae);
int wifi_rom_sae_target_select_group(struct sae_data *sae, u16 group);


/*********************************************************************************************
Function:  ecc initialization of group id

Parameter: @group_id: group definition of spec, the default value is 19/20/21/25/26

return:    sae_ecc_crypto *: pointer of cryto ecc
*********************************************************************************************/
sae_ecc_crypto *wifi_rom_sae_crypto_ecc_init(unsigned char group_id);


/*********************************************************************************************
Function:  ecc clear

Parameter: @pointer of ecc group

return:    void
*********************************************************************************************/
void wifi_rom_sae_crypto_ecc_free(sae_ecc_crypto *ecc);

/*********************************************************************************************
Function:  prepare SAE commit frame

Parameter: @pframe:		   pointer to next position of left frame buffer
           @sae:		   pointer to sae data
           @available_len: available size of buffer
           @frame_len:     current size of frame
           @status: 	   status code response to peer STA

result:    pointer to position of next available memeroy
*********************************************************************************************/
u8 *wifi_rom_sae_prepare_commit(u8 *pframe,	struct sae_data *sae, u32 available_len,	u32 *frame_len, u16 status);


/*********************************************************************************************
Function:  prepare SAE confirm frame

Parameter: @pframe:		   pointer to next position of left frame buffer
           @sae:		   pointer to sae data
           @available_len: available size of buffer
           @frame_len: 	   current size of frame

result:    pointer to position of next available memeroy
*********************************************************************************************/
u8 *wifi_rom_sae_prepare_confirm(u8 *pframe, struct sae_data *sae, u32 available_len,	u32 *frame_len);


/*********************************************************************************************
Function:  derive PWE

Parameter: @sae_priv: pointer of sae_data
           @addr1: array of local mac address
           @addr2: array of peer mac address
           @password: array of password denote as ASCII
           @password_len: password size

return:    0 if successful
           -1 if failed
*********************************************************************************************/
int wifi_rom_sae_derive_pwe_ecc(struct sae_data *sae_priv, unsigned char *addr1, unsigned char *addr2,
								unsigned char *password, unsigned int password_len);


/*********************************************************************************************
Function:  derive PWE for ffc

Parameter: @sae_priv: pointer of sae_data
           @addr1: array of local mac address
           @addr2: array of peer mac address
           @password: array of password denote as ASCII
           @password_len: password size

return:    0 if successful
           -1 if failed
*********************************************************************************************/
int wifi_rom_sae_derive_pwe_ffc(struct sae_data *sae_priv, unsigned char *addr1, unsigned char *addr2,
								unsigned char *password, unsigned int password_len);


/*********************************************************************************************
Function:  derive k
		   K = scalar-op(rand, (elem-op(scalar-op(peer-commit-scalar, PWE),PEER-COMMIT-ELEMENT)))
		   If K is identity element (point-at-infinity), reject
		   k = F(K) (= x coordinate)

Parameter: @sae_priv: pointer of sae_data
           @k: output key

return:    0 if successful
           -1 if failed
*********************************************************************************************/
int wifi_rom_sae_derive_k_ecc(struct sae_data *sae_priv, unsigned char *k);


/*********************************************************************************************
Function:  derive k ffc
		   K = scalar-op(rand, (elem-op(scalar-op(peer-commit-scalar, PWE),PEER-COMMIT-ELEMENT)))
		   If K is identity element (point-at-infinity), reject
		   k = F(K) (= x coordinate)

Parameter: @sae_priv: pointer of sae_data
           @k: output key

return:    0 if successful
           -1 if failed
*********************************************************************************************/
int wifi_rom_sae_derive_k_ffc(struct sae_data *sae_priv, unsigned char *k);


/*********************************************************************************************
Function:  derive pmk,kck and pmkid
		   keyseed = H(<0>32, k)
	  	   KCK || PMK = KDF-512(keyseed, "SAE KCK and PMK",(commit-scalar + peer-commit-scalar) modulo r)
	  	   PMKID = L((commit-scalar + peer-commit-scalar) modulo r, 0, 128)

Parameter: @sae_priv: pointer of sae_data
           @k: output key

return:    0 if successful
           -1 if failed
*********************************************************************************************/
int wifi_rom_sae_derive_pmk_and_kck(struct sae_data *sae_priv, unsigned char *k, unsigned int k_len);
int wifi_rom_sae_derive_pwe_from_pt(struct sae_data *sae, u8 *addr1, u8 *addr2);
int wifi_rom_sae_derive_pt_ecc(struct sae_data *sae, const u8 *ssid, size_t ssid_len, const u8 *password, size_t password_len, const char *identifier);
int wifi_rom_is_duplicate_sae_auth(u8 *pframe, u16 *plast_peer_cmit_seq_num, u16 *plast_status, u16 *plast_peer_cfrm_seq_num);

#endif
