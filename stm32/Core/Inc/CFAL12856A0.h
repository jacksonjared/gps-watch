
#ifndef CFAL12856A0_H_
#define CFAL12856A0_H_

#include "stm32f1xx_hal.h"

#define PAGES 7
#define COLUMNS 128

#define LAST_PAGE 6
#define LAST_COLUMN 127

void oled_whisperer(SPI_HandleTypeDef* hspi, uint8_t* data, uint16_t data_length, uint8_t isDATA);
void oled_init(SPI_HandleTypeDef* hspi);
void oled_blank_screen(SPI_HandleTypeDef* hspi);
void oled_set_column(SPI_HandleTypeDef* hspi, uint8_t start, uint8_t stop);
void oled_set_page(SPI_HandleTypeDef* hspi, uint8_t start, uint8_t stop);
void oled_load_buffer(const uint8_t image[7][128]);
void oled_send_buffer(SPI_HandleTypeDef* hspi);
void oled_send_char(SPI_HandleTypeDef* hspi, char c);
void oled_send_string(SPI_HandleTypeDef* hspi, char* s, size_t len, uint8_t page, uint8_t column);
void oled_font_test(SPI_HandleTypeDef* hspi);

#endif /* CFAL12856A0_H_ */
