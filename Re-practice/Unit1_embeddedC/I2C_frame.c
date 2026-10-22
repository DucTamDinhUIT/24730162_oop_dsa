#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define PN532_PREAMBLE        0x00
#define PN532_STARTCODE1      0x00
#define PN532_STARTCODE2      0xFF
#define PN532_POSTAMBLE       0x00

#define PN532_HOST_TO_PN532   0xD4
#define PN532_PN532_TO_HOST   0xD5

#define PN532_MAX_FRAME_LEN   64

// LCS: Bù 2 của LEN
uint8_t Calculate_LCS(uint8_t len) {
    return (uint8_t)(0x100 - len);
}

// DCS: Bù 2 của (TFI + CMD + sum(DATA))
uint8_t Calculate_DCS(uint8_t tfi, uint8_t cmd) {
    return (uint8_t)(0x100 - (tfi + cmd));
}

uint8_t Calculate_Received_DCS(const uint8_t *frame, uint8_t len) {
    uint8_t sum = 0;
    // Payload bắt đầu từ index 5 (TFI) đến hết dữ liệu (độ dài len)
    for (size_t i = 5; i < (5 + len); i++) {
        sum += frame[i];
    }
    return (uint8_t)(0x100 - sum); // Bù 2 của tổng payload
}

/**
 * @brief Đóng gói khung lệnh GetFirmware (0x02)
 * @return Tổng số byte của toàn bộ gói tin để gửi qua I2C (luôn là 9 byte)
 */
uint8_t Build_Get_FW_Frame(uint8_t *frame, uint8_t cmd) {  
    uint8_t payload_len = 2; // Gồm: 1 byte TFI (0xD4) + 1 byte CMD (0x02)

    frame[0] = PN532_PREAMBLE;
    frame[1] = PN532_STARTCODE1;
    frame[2] = PN532_STARTCODE2;
    frame[3] = payload_len;                              // LEN = 0x02
    frame[4] = Calculate_LCS(payload_len);               // LCS = 0xFE
    frame[5] = PN532_HOST_TO_PN532;                     // TFI = 0xD4
    frame[6] = cmd;                                      // CMD = 0x02
    frame[7] = Calculate_DCS(PN532_HOST_TO_PN532, cmd); // DCS = 0x2A
    frame[8] = PN532_POSTAMBLE;                          // 0x00

    return 9; // Tổng số byte cần ghi vào I2C_DR
}

uint8_t I2C3_DR[PN532_MAX_FRAME_LEN];
    I2C3_DR[0] = PN532_PREAMBLE;
    I2C3_DR[1] = PN532_STARTCODE1;
    I2C3_DR[2] = PN532_STARTCODE2;
    I2C3_DR[3] = 0x07;
    I2C3_DR[4] = Calculate_LCS(7);
    I2C3_DR[5] = PN532_PN532_TO_HOST;
    I2C3_DR[6] = 0x03;
    I2C3_DR[7] = 0x03;  
    I2C3_DR[8] = 0x32;  
    I2C3_DR[9] = 0x01;
    I2C3_DR[10] = 0x06;  
    I2C3_DR[11] = 0x07;
    I2C3_DR[12] = Calculate_Received_DCS(PN532_PN532_TO_HOST, 0x03, &I2C3_DR);
    I2C3_DR[13] = PN532_POSTAMBLE;
    

void Received_Frame(uint8_t *frame, uint8_t len) {
    // received có dạng D5 03 IC Ver Rev Support 

    printf("Received Frame: ");
    for (int i = 0; i < len; i++) {
        printf("0x%05X ", frame[i]);
    }
    printf("\n");
}

int main() {
    uint8_t frame[PN532_MAX_FRAME_LEN];
    uint8_t cmd = 0x02;

    uint8_t total_bytes = Build_Get_FW_Frame(frame, cmd);

    printf("Frame: ");
    for (int i = 0; i < total_bytes; i++) {
        printf("0x%05X ", frame[i]);
    }
    printf("\n");



    return 0;
}