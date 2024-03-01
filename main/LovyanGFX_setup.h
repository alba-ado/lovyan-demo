#ifndef __ILI9488_TFT_LCD_LovyanGFX_LIBRARY_SETUP__
#define __ILI9488_TFT_LCD_LovyanGFX_LIBRARY_SETUP__

#include <LovyanGFX.hpp>

#define PIN_LCD_D0              15
#define PIN_LCD_D1              16
#define PIN_LCD_D2              17
#define PIN_LCD_D3              18
#define PIN_LCD_D4              12
#define PIN_LCD_D5              11
#define PIN_LCD_D6              10
#define PIN_LCD_D7              9

#define PIN_LCD_RST             4
#define PIN_LCD_DC              5
#define PIN_LCD_WR              6
#define PIN_LCD_RD              7

class LGFX : public lgfx::LGFX_Device {
    // Prepare an instance that matches the type of panel to be connected.
    lgfx::Panel_ILI9488 _panel_instance;

    // Prepare an instance that matches the type of bus that connects the panel.
    lgfx::Bus_Parallel8 _bus_instance;

   public:
    // Create a constructor and configure various settings here.
    LGFX(void) {
        {                                       // Configure bus control settings.
            auto cfg = _bus_instance.config();  // Get the bus configuration structure.

            // 8-bit parallel bus settings
            //cfg.port = 0;   //LCD_CAM peripheral number. No need to change (only 0 for ESP32-S3.)
            //cfg.freq_write = 16000000;  // Transmission clock (maximum 20MHz, rounded to 80MHz divided by an integer)
            //cfg.freq_read = 8000000;
            cfg.pin_wr = PIN_LCD_WR;    // Pin number connecting WR
            cfg.pin_rd = PIN_LCD_RD;    // Pin number connecting RD
            cfg.pin_rs = PIN_LCD_DC;    // Pin number connecting RS(D/C)
            
            cfg.pin_d0 = PIN_LCD_D0;    // Pin number connecting D0
            cfg.pin_d1 = PIN_LCD_D1;    // Pin number connecting D1
            cfg.pin_d2 = PIN_LCD_D2;    // Pin number connecting D2
            cfg.pin_d3 = PIN_LCD_D3;    // Pin number connecting D3
            cfg.pin_d4 = PIN_LCD_D4;    // Pin number connecting D4
            cfg.pin_d5 = PIN_LCD_D5;    // Pin number connecting D5
            cfg.pin_d6 = PIN_LCD_D6;    // Pin number connecting D6
            cfg.pin_d7 = PIN_LCD_D7;    // Pin number connecting D7

            _bus_instance.config(cfg);               // Apply the settings to the bus.
            _panel_instance.setBus(&_bus_instance);  // Set the bus to the panel.
        }

        {                                         // Set display panel control.
            auto cfg = _panel_instance.config();  // Get the structure for display panel settings.

            cfg.pin_cs = -1;            // Pin number to which CS is connected (-1 = disable)
            cfg.pin_rst = PIN_LCD_RST;  // Pin number to which RST is connected (-1 = disable)
            cfg.pin_busy = -1;          // Pin number to which BUSY is connected (-1 = disable)

            cfg.panel_width = 320;     // Actual display width
            cfg.panel_height = 480;    // Actual display height
            cfg.offset_x = 0;          // Panel X direction offset amount
            cfg.offset_y = 0;          // Panel Y direction offset amount
            cfg.offset_rotation = 0;   // Offset of rotation direction value 0~7 (4~7 are upside down)
            cfg.dummy_read_pixel = 8;  // Number of bits for dummy read before pixel reading
            cfg.dummy_read_bits = 1;   // Number of bits for dummy read before reading data other than pixels
            cfg.readable = true;       // Set to true if data can be read
            cfg.invert = false;        // Set to true if the brightness of the panel is inverted
            cfg.rgb_order = false;     // Set to true if the red and blue colors of the panel are swapped
            cfg.dlen_16bit = false;    // Set to true for panels that transmit data length in 16-bit units using 16-bit parallel or SPI
            cfg.bus_shared = false;     // Set to true if the bus is shared with the SD card (control the bus with drawJpgFile, etc.)

            _panel_instance.config(cfg);
        }

        setPanel(&_panel_instance);  // Set the panel to use.
    }
};

#endif