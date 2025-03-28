//=============================================================================
//=============================================================================
#ifndef MISC_H
#define MISC_H
//=============================================================================
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include "Arduino.h"
#include "esp_log.h"
#include "sdkconfig.h"
//=============================================================================
// esp_log_level_t esp_log_level_get(const char *tag);
// esp_log_level_set(TAG, ESP_LOG_VERBOSE);
// esp_log_level_set("[GT]", ESP_LOG_ERROR);
// esp_log_level_set("*", ESP_LOG_NONE);

#define logv(...) ESP_LOGV(TAG, __VA_ARGS__)  // Verbose
#define logd(...) ESP_LOGD(TAG, __VA_ARGS__)  // Debug
#define logi(...) ESP_LOGI(TAG, __VA_ARGS__)  // Info
#define logw(...) ESP_LOGW(TAG, __VA_ARGS__)  // Warning
#define loge(...) ESP_LOGE(TAG, __VA_ARGS__)  // Error
//=============================================================================
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             int8;
typedef signed short            int16;
typedef signed long             int32;
typedef signed long long        int64;

typedef unsigned int            uint;
//=============================================================================
#define MIN(n,m) (((n) < (m)) ? (n) : (m))
#define MAX(n,m) (((n) < (m)) ? (m) : (n))
#define ABS(n) (((n) < 0) ? -(n) : (n))

#define HIBYTE(a) (*((uint8*)&(a) + 1))
#define LOBYTE(a) (*((uint8*)&(a)))
#define HIWORD(a) (*((uint16*)&(a) + 1))
#define LOWORD(a) (*((uint16*)&(a)))

#define BYTE0(a) (*((uint8*)&(a) + 0))
#define BYTE1(a) (*((uint8*)&(a) + 1))
#define BYTE2(a) (*((uint8*)&(a) + 2))
#define BYTE3(a) (*((uint8*)&(a) + 3))
#define ARRAY_SIZE(a) ( sizeof(a)/sizeof(*(a)) )
//=============================================================================
#define Bit(bit)  (1<<(bit))
#define ClrBit(reg, bit)    reg &= (~(1<<(bit)))        //ClearBit(PORTB, 1);
#define SetBit(reg, bit)    reg |= (1<<(bit))           //SetBit(PORTB, 3);
#define InvBit(reg, bit)    reg ^= (1<<(bit))           //InvBit(PORTB, 1);
#define ClrMask(reg, mask)  reg &= (~(mask))            //ClrMask(PORTB, 0b00001111)
#define SetMask(reg, mask)  reg |= (mask)               //SetMask(PORTB, 0b11110000)
#define BitIsClr(reg, bit)  ((reg & (1<<(bit))) == 0)   //if(BitIsClear(PORTB,1)) {...}
#define BitIsSet(reg, bit)  ((reg & (1<<(bit))) != 0)   //if(BitIsSet(PORTB,2)) {...}
#define MaskIsSet(reg, mask)    ((reg & mask) == mask)  //if(MaskIsSet(USRT1->ISR, USART_ISR_TXE) {}
#define MaskIsClr(reg, mask)    ((reg & mask) == 0)     //
//=============================================================================
#define _Concat(first, second)  first##second                           //Чтобы дважды развернуть макрос
#define Concat(first, second)   _Concat(first, second)                  //пример: Concat(PORT, B) = 10 --> PORTB = 10;
#define _Concat3(first, second, third)  first##second##third            //Чтобы дважды развернуть макрос
#define Concat3(first, second, third)   _Concat3(first, second, third)  //пример: Concat(PORT, B) = 10 --> PORTB = 10;
//=============================================================================
enum
{
    b000,               /* 0 */
    b001,               /* 1 */
    b010,               /* 2 */
    b011,               /* 3 */
    b100,               /* 4 */
    b101,               /* 5 */
    b110,               /* 6 */
    b111                /* 7 */
};
enum
{
    b0000,              /* 0 */
    b0001,              /* 1 */
    b0010,              /* 2 */
    b0011,              /* 3 */
    b0100,              /* 4 */
    b0101,              /* 5 */
    b0110,              /* 6 */
    b0111,              /* 7 */
    b1000,              /* 8 */
    b1001,              /* 9 */
    b1010,              /* 10 */
    b1011,              /* 11 */
    b1100,              /* 12 */
    b1101,              /* 13 */
    b1110,              /* 14 */
    b1111               /* 15 */
};
enum
{
    b00000000,          /* 0 */
    b00000001,          /* 1 */
    b00000010,          /* 2 */
    b00000011,          /* 3 */
    b00000100,          /* 4 */
    b00000101,          /* 5 */
    b00000110,          /* 6 */
    b00000111,          /* 7 */
    b00001000,          /* 8 */
    b00001001,          /* 9 */
    b00001010,          /* 10 */
    b00001011,          /* 11 */
    b00001100,          /* 12 */
    b00001101,          /* 13 */
    b00001110,          /* 14 */
    b00001111,          /* 15 */
    b00010000,          /* 16 */
    b00010001,          /* 17 */
    b00010010,          /* 18 */
    b00010011,          /* 19 */
    b00010100,          /* 20 */
    b00010101,          /* 21 */
    b00010110,          /* 22 */
    b00010111,          /* 23 */
    b00011000,          /* 24 */
    b00011001,          /* 25 */
    b00011010,          /* 26 */
    b00011011,          /* 27 */
    b00011100,          /* 28 */
    b00011101,          /* 29 */
    b00011110,          /* 30 */
    b00011111,          /* 31 */
    b00100000,          /* 32 */
    b00100001,          /* 33 */
    b00100010,          /* 34 */
    b00100011,          /* 35 */
    b00100100,          /* 36 */
    b00100101,          /* 37 */
    b00100110,          /* 38 */
    b00100111,          /* 39 */
    b00101000,          /* 40 */
    b00101001,          /* 41 */
    b00101010,          /* 42 */
    b00101011,          /* 43 */
    b00101100,          /* 44 */
    b00101101,          /* 45 */
    b00101110,          /* 46 */
    b00101111,          /* 47 */
    b00110000,          /* 48 */
    b00110001,          /* 49 */
    b00110010,          /* 50 */
    b00110011,          /* 51 */
    b00110100,          /* 52 */
    b00110101,          /* 53 */
    b00110110,          /* 54 */
    b00110111,          /* 55 */
    b00111000,          /* 56 */
    b00111001,          /* 57 */
    b00111010,          /* 58 */
    b00111011,          /* 59 */
    b00111100,          /* 60 */
    b00111101,          /* 61 */
    b00111110,          /* 62 */
    b00111111,          /* 63 */
    b01000000,          /* 64 */
    b01000001,          /* 65 */
    b01000010,          /* 66 */
    b01000011,          /* 67 */
    b01000100,          /* 68 */
    b01000101,          /* 69 */
    b01000110,          /* 70 */
    b01000111,          /* 71 */
    b01001000,          /* 72 */
    b01001001,          /* 73 */
    b01001010,          /* 74 */
    b01001011,          /* 75 */
    b01001100,          /* 76 */
    b01001101,          /* 77 */
    b01001110,          /* 78 */
    b01001111,          /* 79 */
    b01010000,          /* 80 */
    b01010001,          /* 81 */
    b01010010,          /* 82 */
    b01010011,          /* 83 */
    b01010100,          /* 84 */
    b01010101,          /* 85 */
    b01010110,          /* 86 */
    b01010111,          /* 87 */
    b01011000,          /* 88 */
    b01011001,          /* 89 */
    b01011010,          /* 90 */
    b01011011,          /* 91 */
    b01011100,          /* 92 */
    b01011101,          /* 93 */
    b01011110,          /* 94 */
    b01011111,          /* 95 */
    b01100000,          /* 96 */
    b01100001,          /* 97 */
    b01100010,          /* 98 */
    b01100011,          /* 99 */
    b01100100,          /* 100 */
    b01100101,          /* 101 */
    b01100110,          /* 102 */
    b01100111,          /* 103 */
    b01101000,          /* 104 */
    b01101001,          /* 105 */
    b01101010,          /* 106 */
    b01101011,          /* 107 */
    b01101100,          /* 108 */
    b01101101,          /* 109 */
    b01101110,          /* 110 */
    b01101111,          /* 111 */
    b01110000,          /* 112 */
    b01110001,          /* 113 */
    b01110010,          /* 114 */
    b01110011,          /* 115 */
    b01110100,          /* 116 */
    b01110101,          /* 117 */
    b01110110,          /* 118 */
    b01110111,          /* 119 */
    b01111000,          /* 120 */
    b01111001,          /* 121 */
    b01111010,          /* 122 */
    b01111011,          /* 123 */
    b01111100,          /* 124 */
    b01111101,          /* 125 */
    b01111110,          /* 126 */
    b01111111,          /* 127 */
    b10000000,          /* 128 */
    b10000001,          /* 129 */
    b10000010,          /* 130 */
    b10000011,          /* 131 */
    b10000100,          /* 132 */
    b10000101,          /* 133 */
    b10000110,          /* 134 */
    b10000111,          /* 135 */
    b10001000,          /* 136 */
    b10001001,          /* 137 */
    b10001010,          /* 138 */
    b10001011,          /* 139 */
    b10001100,          /* 140 */
    b10001101,          /* 141 */
    b10001110,          /* 142 */
    b10001111,          /* 143 */
    b10010000,          /* 144 */
    b10010001,          /* 145 */
    b10010010,          /* 146 */
    b10010011,          /* 147 */
    b10010100,          /* 148 */
    b10010101,          /* 149 */
    b10010110,          /* 150 */
    b10010111,          /* 151 */
    b10011000,          /* 152 */
    b10011001,          /* 153 */
    b10011010,          /* 154 */
    b10011011,          /* 155 */
    b10011100,          /* 156 */
    b10011101,          /* 157 */
    b10011110,          /* 158 */
    b10011111,          /* 159 */
    b10100000,          /* 160 */
    b10100001,          /* 161 */
    b10100010,          /* 162 */
    b10100011,          /* 163 */
    b10100100,          /* 164 */
    b10100101,          /* 165 */
    b10100110,          /* 166 */
    b10100111,          /* 167 */
    b10101000,          /* 168 */
    b10101001,          /* 169 */
    b10101010,          /* 170 */
    b10101011,          /* 171 */
    b10101100,          /* 172 */
    b10101101,          /* 173 */
    b10101110,          /* 174 */
    b10101111,          /* 175 */
    b10110000,          /* 176 */
    b10110001,          /* 177 */
    b10110010,          /* 178 */
    b10110011,          /* 179 */
    b10110100,          /* 180 */
    b10110101,          /* 181 */
    b10110110,          /* 182 */
    b10110111,          /* 183 */
    b10111000,          /* 184 */
    b10111001,          /* 185 */
    b10111010,          /* 186 */
    b10111011,          /* 187 */
    b10111100,          /* 188 */
    b10111101,          /* 189 */
    b10111110,          /* 190 */
    b10111111,          /* 191 */
    b11000000,          /* 192 */
    b11000001,          /* 193 */
    b11000010,          /* 194 */
    b11000011,          /* 195 */
    b11000100,          /* 196 */
    b11000101,          /* 197 */
    b11000110,          /* 198 */
    b11000111,          /* 199 */
    b11001000,          /* 200 */
    b11001001,          /* 201 */
    b11001010,          /* 202 */
    b11001011,          /* 203 */
    b11001100,          /* 204 */
    b11001101,          /* 205 */
    b11001110,          /* 206 */
    b11001111,          /* 207 */
    b11010000,          /* 208 */
    b11010001,          /* 209 */
    b11010010,          /* 210 */
    b11010011,          /* 211 */
    b11010100,          /* 212 */
    b11010101,          /* 213 */
    b11010110,          /* 214 */
    b11010111,          /* 215 */
    b11011000,          /* 216 */
    b11011001,          /* 217 */
    b11011010,          /* 218 */
    b11011011,          /* 219 */
    b11011100,          /* 220 */
    b11011101,          /* 221 */
    b11011110,          /* 222 */
    b11011111,          /* 223 */
    b11100000,          /* 224 */
    b11100001,          /* 225 */
    b11100010,          /* 226 */
    b11100011,          /* 227 */
    b11100100,          /* 228 */
    b11100101,          /* 229 */
    b11100110,          /* 230 */
    b11100111,          /* 231 */
    b11101000,          /* 232 */
    b11101001,          /* 233 */
    b11101010,          /* 234 */
    b11101011,          /* 235 */
    b11101100,          /* 236 */
    b11101101,          /* 237 */
    b11101110,          /* 238 */
    b11101111,          /* 239 */
    b11110000,          /* 240 */
    b11110001,          /* 241 */
    b11110010,          /* 242 */
    b11110011,          /* 243 */
    b11110100,          /* 244 */
    b11110101,          /* 245 */
    b11110110,          /* 246 */
    b11110111,          /* 247 */
    b11111000,          /* 248 */
    b11111001,          /* 249 */
    b11111010,          /* 250 */
    b11111011,          /* 251 */
    b11111100,          /* 252 */
    b11111101,          /* 253 */
    b11111110,          /* 254 */
    b11111111           /* 255 */
};
//=============================================================================
#endif
