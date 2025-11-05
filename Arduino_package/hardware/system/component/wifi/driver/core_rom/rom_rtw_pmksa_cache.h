#ifndef _ROM_RTW_PMKSA_CACHE_H_
#define _ROM_RTW_PMKSA_CACHE_H_


/*********************************************************************************************
Function:  used to encrypt the mac address by take password as key.

Parameter:	@passphase:	password
			@mac_addr:	mac address
			@out_addr:	the encrpyted mac_addr

result:    none
*********************************************************************************************/
void wifi_rom_pmksa_cache_encrypt_macaddr(u8 *passphrase, u8 *mac_addr, u8 *out_addr);

/*********************************************************************************************
Function:  append pmkid to RSN IE
			Check the RSN IE length
			If the RSN IE length <= 20, the RSN IE didn't include the PMKID information
			0-11th element in the array are the fixed IE
			12th element in the array is the RSNE ID
			13th element in the array is the RSNE length

Parameter: @pmkid: pmkid cached
		   @ie: pointer to RSNIE
		   @ie_len: length of RSNIE

result:    ie length
*********************************************************************************************/
u32 wifi_rom_pmksa_append_pmkid(u8 *pmkid, u8 *ie, u32 *ie_len, u8 is_80211w);

#endif
