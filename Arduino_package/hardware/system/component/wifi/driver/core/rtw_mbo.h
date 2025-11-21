#ifndef __RTW_MBO_H_
#define __RTW_MBO_H_

/* type + length + oui + oui type */
#define MBO_IE_HEADER 6

//#define MBO_IE_VENDOR_TYPE {0x50,0x6f,0x9a,0x16}
#define OUI_WFA 0x506f9a
#define MBO_OUI_TYPE 0x16

#define OCE_RELEASE 1
/* MBO v0.0_r19, 4.2: MBO Attributes */
/* Table 4-5: MBO Attributes */
/* OCE v0.0.10, Table 4-3: OCE Attributes */

#define MBO_OCE_ELEMENT_MAX_LEN 255

enum mbo_attr_id {
	MBO_ATTR_ID_AP_CAPA_IND = 1,
	MBO_ATTR_ID_NON_PREF_CHAN_REPORT = 2,
	MBO_ATTR_ID_CELL_DATA_CAPA = 3,
	MBO_ATTR_ID_ASSOC_DISALLOW = 4,
	MBO_ATTR_ID_CELL_DATA_PREF = 5,
	MBO_ATTR_ID_TRANSITION_REASON = 6,
	MBO_ATTR_ID_TRANSITION_REJECT_REASON = 7,
	MBO_ATTR_ID_ASSOC_RETRY_DELAY = 8,
	OCE_ATTR_ID_CAPA_IND = 101,
	OCE_ATTR_ID_RSSI_BASED_ASSOC_REJECT = 102,
	OCE_ATTR_ID_REDUCED_WAN_METRICS = 103,
	OCE_ATTR_ID_RNR_COMPLETENESS = 104,
};

/* MBO v0.0_r19, 4.2.1: MBO AP Capability Indication Attribute */
/* Table 4-7: MBO AP Capability Indication Field Values */
#define MBO_AP_CAPA_CELL_AWARE BIT(6)

/* MBO v0.0_r19, 4.2.2: Non-preferred Channel Report Attribute */
/* Table 4-10: Reason Code Field Values */
enum mbo_non_pref_chan_reason {
	MBO_NON_PREF_CHAN_REASON_UNSPECIFIED = 0,
	MBO_NON_PREF_CHAN_REASON_RSSI = 1,
	MBO_NON_PREF_CHAN_REASON_EXT_INTERFERENCE = 2,
	MBO_NON_PREF_CHAN_REASON_INT_INTERFERENCE = 3,
};

/* MBO v0.0_r19, 4.2.3: Cellular Data Capabilities Attribute */
/* Table 4-13: Cellular Data Connectivity Field */
enum mbo_cellular_capa {
	MBO_CELL_CAPA_AVAILABLE = 1,
	MBO_CELL_CAPA_NOT_AVAILABLE = 2,
	MBO_CELL_CAPA_NOT_SUPPORTED = 3,
};

/* MBO v0.0_r19, 4.2.4: Association Disallowed Attribute */
/* Table 4-15: Reason Code Field Values */
enum mbo_assoc_disallow_reason {
	MBO_ASSOC_DISALLOW_REASON_UNSPECIFIED = 1,
	MBO_ASSOC_DISALLOW_REASON_MAX_STA = 2,
	MBO_ASSOC_DISALLOW_REASON_AIR_INTERFERENCE = 3,
	MBO_ASSOC_DISALLOW_REASON_AUTH_SERVER_OVERLOAD = 4,
	MBO_ASSOC_DISALLOW_REASON_LOW_RSSI = 5,
};

/* MBO v0.0_r19, 4.2.5: Cellular Data Connection Preference Attribute */
/* Table 4-17: Cellular Preference Field Values */
enum mbo_cell_pref {
	MBO_CELL_PREF_EXCLUDED = 0,
	MBO_CELL_PREF_NO_USE = 1,
	MBO_CELL_PREF_USE = 255
};

/* MBO v0.0_r19, 4.2.6: Transition Reason Code Attribute */
/* Table 4-19: Transition Reason Code Field Values */
enum mbo_transition_reason {
	MBO_TRANSITION_REASON_UNSPECIFIED = 0,
	MBO_TRANSITION_REASON_FRAME_LOSS = 1,
	MBO_TRANSITION_REASON_DELAY = 2,
	MBO_TRANSITION_REASON_BANDWIDTH = 3,
	MBO_TRANSITION_REASON_LOAD_BALANCE = 4,
	MBO_TRANSITION_REASON_RSSI = 5,
	MBO_TRANSITION_REASON_RETRANSMISSIONS = 6,
	MBO_TRANSITION_REASON_INTERFERENCE = 7,
	MBO_TRANSITION_REASON_GRAY_ZONE = 8,
	MBO_TRANSITION_REASON_PREMIUM_AP = 9,
};

/* MBO v0.0_r19, 4.2.7: Transition Rejection Reason Code Attribute */
/* Table 4-21: Transition Rejection Reason Code Field Values */
enum mbo_transition_reject_reason {
	MBO_TRANSITION_REJECT_REASON_UNSPECIFIED = 0,
	MBO_TRANSITION_REJECT_REASON_FRAME_LOSS = 1,
	MBO_TRANSITION_REJECT_REASON_DELAY = 2,
	MBO_TRANSITION_REJECT_REASON_QOS_CAPACITY = 3,
	MBO_TRANSITION_REJECT_REASON_RSSI = 4,
	MBO_TRANSITION_REJECT_REASON_INTERFERENCE = 5,
	MBO_TRANSITION_REJECT_REASON_SERVICES = 6,
};

/* MBO v0.0_r27, 4.3: MBO ANQP-elements */
#define MBO_ANQP_OUI_TYPE 0x12
#define MBO_ANQP_SUBTYPE_QUERY_LIST 1
#define MBO_ANQP_SUBTYPE_CELL_CONN_PREF 2
#define MAX_MBO_ANQP_SUBTYPE MBO_ANQP_SUBTYPE_CELL_CONN_PREF

struct mbobuf {
	int size; /* total size of the allocated buffer */
	u8 used; /* length of data in the buffer */
	u8 *buf; /* pointer to the head of the buffer */
	unsigned int flags;
	/* optionally followed by the allocated buffer */
};

/* Multiband operation non-preferred channel */
struct mbo_non_pref_channel_info {
	enum mbo_non_pref_chan_reason reason;
	u8 oper_class;
	u8 chan;
	u8 preference;
};

enum default_non_pref_ch {
	DEFAULT_NO_NONE_PREF = 0,
	DEFAULT_2G_1_11 = 1,
	DEFAULT_2G_1_11_5G_44_48 = 2,
};

#define MAX_NON_PREF_CH	10
struct mbo_non_pref_ch {
	struct mbo_non_pref_channel_info non_pref_chan_info[MAX_NON_PREF_CH];

	u8 non_pref_chan_num; /* total numbers of non_pref channels. */
	u8 use_default;	/* 0: no non-pref channels, 1: use LOGO default 2G, 2: use LOGO default 2G and 5G. */
};

struct mbobuf *mbo_ie_init(int len);
u8 *mbobuf_put(struct mbobuf *buf, int len);
int init_mbo_attr(u8 id, u8 *mbo_content);
int mbo_init_ie(u8 *buf, int len, int add_oce_capa, u8 append_non_prefer);
int rtw_mbo_channel_to_opclass(int channel);
void rtw_issue_mbo_wnm_notification(u8 action);

static inline void PUT_BE24(u8 *a, u32 val)
{
	a[0] = (val >> 16) & 0xff;
	a[1] = (val >> 8) & 0xff;
	a[2] = val & 0xff;
}

static inline void mbo_put_u8(struct mbobuf *buf, u8 data)
{
	u8 *pos = mbobuf_put(buf, 1);
	*pos = data;
}

static inline void mbo_put_be24(struct mbobuf *buf, u32 data)
{
	u8 *pos = mbobuf_put(buf, 3);
	PUT_BE24(pos, data);
}

#endif
