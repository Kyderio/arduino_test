
#ifndef __RTW_NAN_SPEC_SDA_H_
#define __RTW_NAN_SPEC_SDA_H_

#define MAX_SDA_SRVC_INFO_LEN          (255)

#define GET_PEER_SRVC_INFO_BY_SRVC_ID  BIT(0)
#define GET_PEER_SRVC_INFO_BY_INST_ID  BIT(1)

enum ndp_generic_srvc_sub_attr_id_e {
	NAN_GEN_SRVC_TRANSPORT_PORT		= 0x0,
	NAN_GEN_SRVC_TRANSPORT_PROTOCOL	= 0x1,
	NAN_GEN_SRVC_SERVICE_NAME			= 0x2,
	NAN_GEN_SRVC_NAME_OF_SRVC_INST		= 0x3,
	NAN_GEN_SRVC_TEXT_INFO				= 0x4,
	NAN_GEN_SRVC_UUID					= 0x5,
	NAN_GEN_SRVC_BLOB					= 0x6,
	NAN_GEN_SRVC_RESERVD				= 0x7,
	NAN_GEN_SRVC_VENDOR_SPEC_INFO		= 0xDD,
};

RTW_PACK_STRUCT_BEGIN
struct sdea_ctrl_t {
	u8 sdeactrl_fsd_required : 1;
	u8 sdeactrl_fsd_with_gas : 1;
	u8 sdeactrl_datapath_req_required : 1;
	u8 sdeactrl_datapath_type : 1;
	u8 sdeactrl_mcast_type : 1;
	u8 sdeactrl_qos_required : 1;
	u8 sdeactrl_sec_required : 1;
	u8 sdeactrl_ranging_required : 1;

	u8 sdeactrl_range_limit_present : 1;
	u8 sdeactrl_srvc_update_present : 1;
	u8 sdeactrl_gtk_present : 1;
	u8 rsvd : 5;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct svcinfo_field_t {
	u8 svcinfo_oui[3];
	u8 svcinfo_protocal_type;
	u8 svcinfo_specific_info[MAX_SDA_SRVC_INFO_LEN];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* Field Control of Service Descriptor Extension attribute */
#define SERVICE_DESC_EXT_FIELD_START_OFFSET			(3)
#define SERVICE_DESC_EXT_FIELD_CONTROL_OFFSET		(4)
#define SERVICE_DESC_EXT_FIELD_CONTROL_LEN			(2)
#define SERVICE_DESC_EXT_FIELD_RANGE_LIMIT_LEN		(4)

RTW_PACK_STRUCT_BEGIN
struct sdea_attr_t {
	u8 sdea_attr_id;
	u8 sdea_attr_len[2];
	u8 sdea_attr_instanceid; //The same value as in the Instance ID field of the associated Service Descriptor attribute.
	struct sdea_ctrl_t sdea_attr_ctr;
	//u8 sdea_range_limit_present[4];
	//u8 sdea_svc_update_preset;
	//u8 sdea_svcinfo_len[2];
	//u8 sdea_svcinfo_field[0]; //struct svcinfo_field_t
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END


#define SDA_OPTIONAL_FIELD_OFFSET		(12)
#define SDA_SERVICE_ID_LEN              (6)
#define SDA_BINDING_BITMAP_LEN			(2)
#define NAN_MAX_SERVICE_INFO_LEN		(255)

/* Field offset of service descriptor attribute */
/* Service control field (SCF) of service descriptor attribute */
RTW_PACK_STRUCT_BEGIN
struct srvc_ctrl_t {
	u8 scf_type : 2;
	u8 scf_mf_present : 1;  /* Matching filter present */
	u8 scf_srf_present : 1; /* Service response filter present */
	u8 scf_si_present : 1;  /* Service info present */
	u8 scf_drl : 1;         /* Discovery Range Limited */
	u8 scf_bb_present : 1;  /* Binding bitmap present */
	u8 scf_rsvd : 1;        /* Reserved */
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct sda_attr_t {
	u8 sda_attr_id;          //0x03 Identifies the type of NAN attribute
	u8 sda_attr_len[2];     //Length of the following fields in the attribute.
	u8 sda_attr_service_id[SDA_SERVICE_ID_LEN];         //Mandatory field that contains the hash of the Service Name.
	u8 sda_attr_instance_id;           //Publish_ID or Subscribe_ID, Value of zero is reserved
	u8 sda_attr_requestor_instance_id; //Instance ID from the frame that triggered the transmission if available, otherwise set to 0x00.
	struct srvc_ctrl_t sda_attr_srvc_ctl;       //Mandatory field that defines the Service Control bitmap as defined in Table 42

	u8 sda_attr_optional_field[0];       //optional fields in the attribute.
	//binding_bitmap;           //0B or 2B 0x0000 to0xFF FF Optional field that indicates the binding of the SDA to post discovery connection attributes
	//matching_filter_length;   //0B or 1B An optional field and present if a matching service discovery filter is used
	//matching_filter;          //xB An optional field that is a sequence of length and value pairs that identify the matching service discovery filters, refer to Figure 47
	//service_response_filter_length; //0B or 1B An optional field and present if a service response filter is used.
	//Service Response Filter;  //xB An optional field that identifies the matching service response filters, refer to Table 44
	//Service Info Length;      //0B or 1B An optional field and present if service specific information is used
	//Service Info;             //struct svcinfo_field_t
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __RTW_NAN_SPEC_SDA_H_ */