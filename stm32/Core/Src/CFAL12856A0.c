#include "main.h"
#include "CFAL12856A0.h"
#include "fonts.h"

#define INIT_LENGTH 25

const uint8_t initSeq[INIT_LENGTH] = {0xFD, 0x12, // Unlock display
                                0xAE,       // Display off (sleep)
                                0xD5, 0x30, //
                                0xA8, 0x37, //
                                0xD3, 0x08, //
                                0x40,       //
                                0xA1,       //
                                0xC8,       //
                                0xDA, 0x12, //
                                0x81, 0x8F, // Set display contrast
                                0xD9, 0x25, //
                                0xDB, 0x34, //
                                0x20, 0x00, // Horizontal addressing mode
                                0xA4,       // Display follows RAM
                                0xA6,       // Non-inverted displayed
                                0xAF};      // Display on

uint8_t displayBuf[7][128];

void oled_whisperer(SPI_HandleTypeDef* hspi, uint8_t* data, uint16_t data_length, uint8_t isDATA) {

  /// Pull CS pin low
  HAL_GPIO_WritePin(n_oled_cs_GPIO_Port, n_oled_cs_Pin, GPIO_PIN_RESET);

  /// Pull D/C pin high if sent byte is data, low if command
  HAL_GPIO_WritePin(n_oled_dc_GPIO_Port, n_oled_dc_Pin, isDATA);

  /// Transmit entire passed data buffer
  HAL_SPI_Transmit(hspi, data, data_length, HAL_MAX_DELAY);

  /// Pull D/C pin high
  HAL_GPIO_WritePin(n_oled_dc_GPIO_Port, n_oled_dc_Pin, GPIO_PIN_SET);

  /// Pull CS pin high
  HAL_GPIO_WritePin(n_oled_cs_GPIO_Port, n_oled_cs_Pin, GPIO_PIN_SET);

}

void oled_init(SPI_HandleTypeDef* hspi) {

  /// Pass the pre-determined init sequence to be transmitted
  oled_whisperer(hspi, initSeq, INIT_LENGTH, 0);

  oled_blank_screen(hspi);

}

void oled_set_column(SPI_HandleTypeDef* hspi, uint8_t start, uint8_t stop) {

  /// Construct command to send. 0x00 is the lower nibble of the start address. 0x10 is the upper nibble of the start address.
  uint8_t command[3] = {0x21, start % COLUMNS, stop % COLUMNS};

  /// Pass the command to be transmitted
  oled_whisperer(hspi, command, 3, 0);

}

void oled_set_page(SPI_HandleTypeDef* hspi, uint8_t start, uint8_t stop) {

  /// Construct command to send. 0xb0 is the page address command. mod 8 is to prevent invalid inputs
  uint8_t command[3] = {0x22, start % PAGES, stop % PAGES};

  /// Set the page address
  oled_whisperer(hspi, command, 3, 0);

}

void oled_load_buffer(const uint8_t image[7][128]) {

  for(uint8_t i = 0; i < PAGES; i++) {

    for(uint8_t ii = 0; ii < COLUMNS; ii++) {

      displayBuf[i][ii] = image[i][ii];

    }

  }

}

void oled_send_buffer(SPI_HandleTypeDef* hspi) {

  /// Set the page range to [0 7]
  oled_set_page(hspi, 0, LAST_PAGE);

  /// Set the column range to [0 127]
  oled_set_column(hspi, 0, LAST_COLUMN);

  /// Loop over all 8 pages
  for(uint8_t i = 0; i < PAGES; i++) {

    /// Loop over all 128 columns
    for(uint8_t ii = 0; ii < COLUMNS; ii++) {

      /// Send current byte of display ram
      oled_whisperer(hspi, &displayBuf[i][ii], 1, 1);

    }

  }

}

void oled_blank_screen(SPI_HandleTypeDef* hspi) {

  for(uint8_t i = 0; i < PAGES; i++) {

    for(uint8_t ii = 0; ii < COLUMNS; ii++) {

      displayBuf[i][ii] = 0;

    }

  }

  oled_send_buffer(hspi);

}

void oled_send_char(SPI_HandleTypeDef* hspi, char c) {

  uint8_t index = (c - ' ') % 96;

  for(uint8_t i = 0; i < SMALL_FONT_WIDTH; i++) {

    oled_whisperer(hspi, &font_small[index][i], 1, 1);

  }

}

void oled_send_string(SPI_HandleTypeDef* hspi, char* s, size_t len, uint8_t page, uint8_t column) {

  oled_set_page(hspi, page, page);

  oled_set_column(hspi, column, 127);

  for(;*s;) {

    oled_send_char(hspi, *s++);

  }

}

void oled_font_test(SPI_HandleTypeDef* hspi) {

  oled_set_column(hspi, 0, LAST_COLUMN);

  char a = ' ';

  for(uint8_t i = 0; i < 8; i++) {
    oled_set_page(hspi, i, i);
    for(uint8_t ii = 0; ii < (128 / SMALL_FONT_WIDTH); ii++) {
      oled_send_char(hspi, a++);
    }
  }

}
