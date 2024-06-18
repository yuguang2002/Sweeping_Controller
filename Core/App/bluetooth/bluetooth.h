/**
 * @file 蓝牙通信模块驱动
 */

#ifndef VET6_BLUETOOTH_H
#define VET6_BLUETOOTH_H

#include "main.h"

extern uint8_t receivedData;

void bluetooth();
int parse_packet(uint8_t *packet, size_t length);
uint8_t calculate_checksum(uint8_t *data, size_t length);

#endif //VET6_BLUETOOTH_H
