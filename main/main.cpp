#include <LovyanGFX.hpp>
#include "LovyanGFX_setup.h"

//Display Instance (LovyanGFX)
static LGFX tft = LGFX();

void lovyanTest (void) {
    Serial.begin(115200);

    tft.init();
    tft.setRotation(2);
    tft.setColorDepth(16);
    tft.fillScreen(TFT_BLACK);
}

extern "C" void app_main() {
    lovyanTest();
}