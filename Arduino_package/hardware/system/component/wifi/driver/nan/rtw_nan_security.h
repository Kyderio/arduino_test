#ifndef __RTW_NAN_SECURITY_H_
#define __RTW_NAN_SECURITY_H_

#define	IEEE_CRYPT_ALG_NAME_LEN			16

#define RTW_GET_LE64(a) ((((u64) (a)[7]) << 56) | (((u64) (a)[6]) << 48) | \
			 (((u64) (a)[5]) << 40) | (((u64) (a)[4]) << 32) | \
			 (((u64) (a)[3]) << 24) | (((u64) (a)[2]) << 16) | \
			 (((u64) (a)[1]) << 8) | ((u64) (a)[0]))

#define MAX_HASH_LEN 64

struct rtw_sha256_state {
	u64 length;
	u32 state[8], curlen;
	u8 buf[64];
};

struct wpa_crypt {
	u8 alg[IEEE_CRYPT_ALG_NAME_LEN];
	u8 set_tx;
	u32 err;
	u8 idx;
	u8 seq[8]; /* sequence counter (set: RX, get: TX) */
	u16 key_len;
	u8 key[0];
};

u8 rtw_nan_pmk_empty_check(u8 *pmk);
u8 rtw_nan_nmi_tk_set(struct nan_peer_info_t *ppeer_info, u8 *peer_nmi);

#endif

