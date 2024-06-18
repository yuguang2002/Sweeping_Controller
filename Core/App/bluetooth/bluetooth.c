/**
 * @file 蓝牙通信模块驱动
 */

#include "bluetooth.h"

#define PACKET_LENGTH 7

uint8_t receivedData;
uint8_t packet[PACKET_LENGTH];
size_t flag = 0;
int8_t rx_ok = -1;

/**
 * @brief 数据解析及模式切换
 */
void bluetooth()
{
    if(rx_ok)
    {
        switch (packet[3])
        {
            case 0x53:
                vTaskResume(AutoSweepTaskHandle);
                printf("%d \r\n",packet[3]);
                break;
            case 0x54:
                //执行其他任务
                printf("%d \r\n",packet[3]);
                break;
            default:
                break;
        }
    }

}

/**
 * @brief 蓝牙数据接受
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART3)
    {
        // 存储接收到的字节
        packet[flag++] = receivedData;

        // 检查是否接收到完整的数据包
        if (flag == PACKET_LENGTH)
        {
            // 解析数据包
            if (parse_packet(packet, PACKET_LENGTH) == 0)
            {
                rx_ok = 1;
                printf("Packet parsed successfully\n");
            }
            else
            {
                rx_ok = 0;
                printf("Packet parsing failed\n");
            }
            // 重置索引以接收下一个数据包
            flag = 0;
        }

        // 再次启用接收中断
        HAL_UART_Receive_IT(&huart3, &receivedData, 1);
    }
}

/**
 * @brief 蓝牙数据
 */
int parse_packet(uint8_t *packet, size_t length)
{
    if (length != PACKET_LENGTH)
    {
        printf("Invalid packet length\n");
        return -1;
    }

    uint8_t header = packet[0];
    uint8_t command = packet[1];
    uint8_t data_length = packet[2];
    uint8_t data[2] = { packet[3], packet[4] };
    uint8_t received_checksum = packet[6];

    // 计算校验和（不包括校验和字节）
    uint8_t calculated_checksum = calculate_checksum(packet, 6);

    // 验证校验和
    if (calculated_checksum != received_checksum)
    {
        printf("Checksum mismatch\n");
        return -1;
    }

    else if ((calculated_checksum == received_checksum) && (received_checksum != 0))
    {
//        // 输出解析结果
//        printf("Header: 0x%02X\n", header);
//        printf("Command: 0x%02X\n", command);
//        printf("Data Length: 0x%02X\n", data_length);
//        printf("Data: 0x%02X 0x%02X\n", data[0], data[1]);
//        printf("Checksum: 0x%02X\n", received_checksum);

        return 0;
    }

    return -1;
}

/**
 * @brief 计算校验和
 */
uint8_t calculate_checksum(uint8_t *data, size_t length)
{
    uint8_t checksum = 0;
    for (size_t i = 0; i < length; i++)
    {
        checksum += data[i];
    }
    return checksum;
}
