#ifndef BT_CONTROLLER_LL_LE_PERIPHERAL_H
#define BT_CONTROLLER_LL_LE_PERIPHERAL_H

void bt_controller_ll_le_peripheral_setup(uint16_t conn_handle, struct bt_ll_procedure_node *pll_le_sche_procedure, uint32_t instant, uint8_t *conn_pdu);

#endif