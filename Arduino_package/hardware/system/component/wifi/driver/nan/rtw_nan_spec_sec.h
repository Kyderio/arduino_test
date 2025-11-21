
#ifndef __RTW_NAN_SPEC_SEC_H_
#define __RTW_NAN_SPEC_SEC_H_

#define MAX_KEY_NOUNCE_LEN             (32)
#define MAX_RSNA_KEY_DESC_LEN          (120)
#define MAX_RSNA_KEY_DATA_LEN          (512)
#define AUTH_TOKEN_LEN                 (16)
#define NCS_SK_128_KCK_LEN             (16)
#define NCS_SK_128_KEK_LEN             (16)
#define NCS_SK_128_TK_LEN              (16)
#define NCS_SK_128_PMK_LEN				(32)
#define REPLAY_CNT_LEN                 (8)
#define NCS_SK_128_KEY_MIC_LEN         (16)
#define WPA_GTK_LEN                    (16)
#define WPA_IGTK_LEN                   (16)
#define WPA_BIGTK_LEN                  (16)
#define WPA_NIK_LEN                    (16)
#define NAN_KEY_LIFETIME               (60*60)

#define MAX_PASSPHRASE_LEN             (64)

#define MAX_PASN_PW_LEN					16
#define MAX_PASN_RX_LEN                (512)
#define MAX_PASN_NAN_APPEND_IE_LEN     (64)


#define WPA_KCK_MAX_LEN                24
#define WPA_KEK_MAX_LEN                32
#define WPA_TK_MAX_LEN                 32
#define WPA_KDK_MAX_LEN                32

#define NCS_SK_128_MIC_LEN             16

#define WPA_GTK_MAX_LEN                32
#define WPA_IGTK_MAX_LEN               32
#define WPA_BIGTK_MAX_LEN              32

#define WPA_REPLAY_COUNTER_LEN         8
#define WPA_NONCE_LEN                  32
#define WPA_KEY_RSC_LEN                8

enum nan_cipher_suite_id {
	NAN_CIPHER_SUITE_ID_OPEN             = 0,
	NAN_CIPHER_SUITE_ID_NCS_SK_128       = 1, // NCS Secret Key, 128 bits
	NAN_CIPHER_SUITE_ID_NCS_SK_256       = 2, // NCS Secret Key, 256 bits
	NAN_CIPHER_SUITE_ID_NCS_PK_2WDH_128  = 3, // NCS Public Key, 2 Way Diffie Hellman, 128 bits
	NAN_CIPHER_SUITE_ID_NCS_PK_2WDH_256  = 4, // NCS Public Key, 2 Way Diffie Hellman, 256 bits
	NAN_CIPHER_SUITE_ID_NCS_GTK_CCMP_128 = 5,
	NAN_CIPHER_SUITE_ID_NCS_GTK_GCMP_256 = 6,
	NAN_CIPHER_SUITE_ID_NCS_PASN_128     = 7,
	NAN_CIPHER_SUITE_ID_NCS_PASN_256     = 8,
	NAN_CIPHER_SUITE_ID_MAX,
} ;

enum nan_kde_id {
	NAN_KDE_ID_GTK             = 0x1,
	NAN_KDE_ID_MAC_ADDR        = 0x3, // NCS Secret Key, 128 bits
	NAN_KDE_ID_IGTK            = 0x9, // NCS Secret Key, 256 bits
	NAN_KDE_ID_BIGTK           = 0xE, // NCS Public Key, 2 Way Diffie Hellman, 128 bits
	NAN_KDE_ID_NIK             = 0x24, // NCS Public Key, 2 Way Diffie Hellman, 256 bits
	NAN_KDE_ID_KEY_LIFETIME    = 0x25,
	NAN_KDE_ID_MAX,
} ;

/* security context information attribute */
#define MAX_PMKID_LEN           (16)
#define MAX_PMK_LEN             (32)

#define SEC_CONTXT_ATTR_OFFSET	(2)

RTW_PACK_STRUCT_BEGIN
struct scid_field_t {
	u8 scid_type_len[2];
	u8 scid_type;
	u8 scid_publishid;
	u8 scid[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct scia_attr_t {
	u8 scia_attr_id;
	u8 scia_attr_len[2];
	u8 scia_field[0]; //scid_field_t
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* cypher suite attribute */
RTW_PACK_STRUCT_BEGIN
struct cs_filed_t {
	u8 cs_id;
	u8 cs_publishid;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct csia_attr_t {
	u8 csia_attr_id;
	u8 csia_attr_len[2];
	u8 csia_attr_capbility;
	u8 csia_field[0]; //cs_filed_t
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* IEEE 802.11, 8.5.2 EAPOL-Key frames */
/* bit4..5 is used in WPA, but is reserved in IEEE 802.11i/RSN */
#define WPA_KEY_INFO_KEY_INDEX_MASK (BIT(4) | BIT(5))
#define WPA_KEY_INFO_KEY_INDEX_SHIFT 4
#define WPA_KEY_INFO_INSTALL BIT(6) /* pairwise */
#define WPA_KEY_INFO_TXRX BIT(6) /* group */
#define WPA_KEY_INFO_ACK BIT(7)
#define WPA_KEY_INFO_MIC BIT(8)
#define WPA_KEY_INFO_SECURE BIT(9)
#define WPA_KEY_INFO_ERROR BIT(10)
#define WPA_KEY_INFO_REQUEST BIT(11)
#define WPA_KEY_INFO_ENCR_KEY_DATA BIT(12) /* IEEE 802.11i/RSN only */
#define WPA_KEY_INFO_SMK_MESSAGE BIT(13)

/**
 * struct nan_wpa_ptk - WPA Pairwise Transient Key
 * IEEE Std 802.11i-2004 - 8.5.1.2 Pairwise key hierarchy
 */
struct nan_wpa_ptk {
	u8 kck[WPA_KCK_MAX_LEN]; /* EAPOL-Key Key Confirmation Key (KCK) */
	u8 kek[WPA_KEK_MAX_LEN]; /* EAPOL-Key Key Encryption Key (KEK) */
	u8 tk[WPA_TK_MAX_LEN]; /* Temporal Key (TK) */
	u8 kck2[WPA_KCK_MAX_LEN]; /* FT reasoc Key Confirmation Key (KCK2) */
	u8 kek2[WPA_KEK_MAX_LEN]; /* FT reassoc Key Encryption Key (KEK2) */
	u8 kdk[WPA_KDK_MAX_LEN]; /* Key Derivation Key */
	size_t kck_len;
	size_t kek_len;
	size_t tk_len;
	size_t kck2_len;
	size_t kek2_len;
	size_t kdk_len;
	int installed; /* 1 if key has already been installed to driver */
};

/* shared key attribute (SKA) */
/* Macro to configure EAPOL-Key frame */
#define SET_NAN_EAPOL_KEY_INFO_DESC_VER(_pStart, _val)      SET_BITS_TO_LE_2BYTE(_pStart, 0, 3, _val)
#define SET_NAN_EAPOL_KEY_INFO_KEY_TYPE(_pStart, _val)      SET_BITS_TO_LE_2BYTE(_pStart, 3, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_INSTALL(_pStart, _val)       SET_BITS_TO_LE_2BYTE(_pStart, 6, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_KEY_ACK(_pStart, _val)       SET_BITS_TO_LE_2BYTE(_pStart, 7, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_KEY_MIC(_pStart, _val)       SET_BITS_TO_LE_2BYTE(_pStart, 8, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_SECURE(_pStart, _val)        SET_BITS_TO_LE_2BYTE(_pStart, 9, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_ERROR(_pStart, _val)         SET_BITS_TO_LE_2BYTE(_pStart, 10, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_REQUEST(_pStart, _val)       SET_BITS_TO_LE_2BYTE(_pStart, 11, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_KEY_DATA(_pStart, _val)      SET_BITS_TO_LE_2BYTE(_pStart, 12, 1, _val)
#define SET_NAN_EAPOL_KEY_INFO_SMK_MESSAGE(_pStart, _val)   SET_BITS_TO_LE_2BYTE(_pStart, 13, 1, _val)

#define SET_NAN_KEY_ID_IN_KDE_GTK(_pStart, _val)            SET_BITS_TO_LE_1BYTE(_pStart, 0, 1, _val)
#define SET_NAN_TX_IN_KDE_GTK(_pStart, _val)                SET_BITS_TO_LE_1BYTE(_pStart, 2, 1, _val)
#define GET_NAN_KEY_ID_IN_KDE_GTK(_kde_start)               (*(_kde_start) & 0x03)
#define GET_NAN_TX_IN_KDE_GTK(_kde_start)                   (*(_kde_start) & BIT(2))
#define GET_NAN_CP_VER_IN_KDE_NIK(_kde_start)               (*(_kde_start))
#define GET_GROUP_KEY_CAP_IN_NDP(pndp_entry)                ((pndp_entry->sec_cipher_suite_cap >> 1) & 0x3 )

RTW_PACK_STRUCT_BEGIN
struct wpa_eapol_key {
	u8 type;	/* descriptor type */
	/* Note: key_info, key_length, and key_data_length are unaligned */
	u8 key_info[2]; /* big endian */
	u8 key_length[2]; /* big endian */
	u8 replay_counter[WPA_REPLAY_COUNTER_LEN];
	u8 key_nonce[WPA_NONCE_LEN];
	u8 key_iv[16];
	u8 key_rsc[WPA_KEY_RSC_LEN];
	u8 key_id[8]; /* Reserved in IEEE 802.11i/RSN */
	u8 key_mic[16];
	u8 key_data_length[2]; /* big endian */
	/* followed by key_data_length bytes of key_data */
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct sharedkey_attr_t {
	u8 sharedkey_attr_id;
	u8 sharedkey_attr_len[2];

	u8 sharedkey_attr_publishid;
	u8 sharedkey_attr_rsna_key[0]; //struct wpa_eapol_key
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END
#endif /* __RTW_NAN_SPEC_SEC_H_ */