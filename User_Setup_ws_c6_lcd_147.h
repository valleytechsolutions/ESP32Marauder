// TFT_eSPI setup for the Waveshare ESP32-C6-LCD-1.47 onboard ST7789 panel.
// Pins and driver IC confirmed directly against docs.waveshare.com and the
// board's upstream Zephyr devicetree entry (both independently agree:
// genuine ST7789, not a JD9853A-type ST7789-compatible variant -- so this
// does NOT need the BGR / inversion-off / mirror-fix workarounds a
// different 172x320 Marauder port (Seeed XIAO-S3-Plus-1.47, JD9853A) needed).
//
// WATCH ITEM, unverified: many 172-wide ST7789 panels need a GRAM column
// offset (TFT_eSPI's native ST7789 GRAM is 240 wide) or the image renders
// shifted/cut off. This vendored TFT_eSPI copy's ST7789 driver source
// wasn't available to check locally. On first boot, if the display is
// blank, offset, or shows a colored band on one edge, check this library
// version's ST7789 setup docs for the offset macro name (historically
// CGRAM_OFFSET; some newer TFT_eSPI releases compute it automatically from
// TFT_WIDTH/TFT_HEIGHT and need nothing added here).
#define ST7789_DRIVER
#define TFT_WIDTH   172
#define TFT_HEIGHT  320
#define TFT_RGB_ORDER TFT_RGB
#define TFT_INVERSION_ON

#define TFT_MOSI  6
#define TFT_SCLK  7
#define TFT_MISO  5   // shared bus; only the SD card actually uses MISO
#define TFT_CS   14
#define TFT_DC   15
#define TFT_RST  21
#define TFT_BL   22
#define TOUCH_CS -1   // no touch controller on this board

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_GFXFF
#define SMOOTH_FONT

// Conservative first-bring-up clocks; raise once the panel is verified.
#define SPI_FREQUENCY        40000000
#define SPI_READ_FREQUENCY   16000000
