#ifndef __RTW_NAN_EAPOL_H_
#define __RTW_NAN_EAPOL_H_

/**
 * nan_eapol_inc_byte_array - Increment arbitrary length byte array by one
 * @counter: Pointer to byte array
 * @len: Length of the counter in bytes
 *
 * This function increments the last byte of the counter by one and continues
 * rolling over to more significant bytes if the byte was incremented from
 * 0xff to 0x00.
 */
inline void nan_eapol_inc_byte_array(u8 *counter, u8 len)
{
	int pos = len - 1;
	while (pos >= 0) {
		counter[pos]++;
		if (counter[pos] != 0) {
			break;
		}
		pos--;
	}
}

int rtw_nan_eapol_pmk_to_ptk(u8 cipher_suite, u8 *pmk, size_t pmk_len, char *label, u8 *i_addr, u8 *r_addr, u8 *i_nonce, u8 *r_nonce, struct nan_wpa_ptk *ptk);
u8 rtw_nan_eapol_kck_calculate(u8 cipher_suite, u8 *key, u8 *auth_token, u32 auth_token_len, u8 *data, u32 data_len, u8 *mic);
u8 rtw_nan_ndp_preserve_m1_info(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 *pframe_body, u32 frbody_len);
void rtw_nan_ndp_security_setup_rx(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 ndp_type_rx, u8 ndp_status_rx, u8 *pframe_body,
								   u32 frbody_len);

#endif /* __RTW_NAN_EAPOL_H_ */