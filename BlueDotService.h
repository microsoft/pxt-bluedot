#ifndef BLUEDOT_SERVICE_H
#define BLUEDOT_SERVICE_H

#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitThermometer.h"
#include "EventModel.h"

// used to raise events
#define MICROBIT_ID_BLUEDOT 9601
#define MICROBIT_BLUEDOT_EVT_BUTTON_DOWN 1
#define MICROBIT_BLUEDOT_EVT_BUTTON_UP 2
#define MICROBIT_BLUEDOT_EVT_POSITION_UPDATE 16

// cf638d8f-ea58-4015-90a6-76f1f11aaa4f
const uint8_t  BlueDotServiceUUID[] = {
    0xCF, 0x63, 0x8D, 0x8F, 0xEA, 0x58, 0x40, 0x15, 0x90, 0xA6, 0x76, 0xF1, 0xF1, 0x1A, 0xAA, 0x4F
};

// cf6363c2-ea58-4015-90a6-76f1f11aaa4f
const uint8_t  BlueDotServiceButtonUUID[] = {
    0xCF, 0x63, 0x63, 0xC2, 0xEA, 0x58, 0x40, 0x15, 0x90, 0xA6, 0x76, 0xF1, 0xF1, 0x1A, 0xAA, 0x4F
};

// cf63f012-ea58-4015-90a6-76f1f11aaa4f
const uint8_t  BlueDotServicePositionUUID[] = {
    0xCF, 0x63, 0xF0, 0x12, 0xEA, 0x58, 0x40, 0x15, 0x90, 0xA6, 0x76, 0xF1, 0xF1, 0x1A, 0xAA, 0x4F
};

/**
  * Class definition for the BlueDot service.
  * Provides a BLE service to receive BlueDotMessages
  */
class BlueDotService
{
    public:

    /**
      * Constructor.
      * Create a representation of the BlueDotService
      * @param _ble The instance of a BLE device that we're running on.
      */
    BlueDotService(BLEDevice &_ble);

    /**
      * Callback. Invoked when any of our attributes are written via BLE.
      */
    void onDataWritten(const GattWriteCallbackParams *params);

    /**
    * Reads the button pressed
    */
    uint8_t getButton();

    /**
    * Reads the x position, as an unsigned short
    */
    uint16_t getX();

    /**
    * Reads the y position, as an unsigned short
    */
    uint16_t getY();

    private:

    // Temperature update callback
    void buttonPressureUpdate(MicroBitEvent e);

    void positionUpdate(int value);

    // Bluetooth stack we're running on.
    BLEDevice           	&ble;

    // characteristics
    uint8_t             buttonCharacteristicBuffer;
    int32_t           positionCharacteristicBuffer;

    // Handles to access each characteristic when they are held by Soft Device.
    GattAttribute::Handle_t buttonCharacteristicHandle;
    GattAttribute::Handle_t positionCharacteristicHandle;
};


#endif
