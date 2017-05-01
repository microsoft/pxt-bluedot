/**
  * Class definition for the custom MicroBit Temperature Service.
  * Provides a BLE service to remotely read the silicon temperature of the nRF51822.
  */
#include "MicroBitConfig.h"
#include "ble/UUID.h"

#include "BlueDotService.h"

/**
  * Constructor.
  * Create a representation of the BlueDotService
  * @param _ble The instance of a BLE device that we're running on.
  */
BlueDotService::BlueDotService(BLEDevice &_ble) :
        ble(_ble)
{
    // Create the data structures that represent each of our characteristics in Soft Device.
    GattCharacteristic  buttonCharacteristic(BlueDotServiceButtonUUID, 
        (uint8_t *)&buttonCharacteristicBuffer, 0,
        sizeof(buttonCharacteristicBuffer), 
        GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE_WITHOUT_RESPONSE
        | GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY);

    GattCharacteristic  positionCharacteristic(BlueDotServicePositionUUID, 
        (uint8_t *)&positionCharacteristicBuffer, 0,
        sizeof(positionCharacteristicBuffer), 
        GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE_WITHOUT_RESPONSE
        | GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY);

    // Initialise our characteristic values.
    buttonCharacteristicBuffer = 0;
    positionCharacteristicBuffer = 0;

    // Set default security requirements
    buttonCharacteristic.requireSecurity(SecurityManager::MICROBIT_BLE_SECURITY_LEVEL);
    positionCharacteristic.requireSecurity(SecurityManager::MICROBIT_BLE_SECURITY_LEVEL);

    GattCharacteristic *characteristics[] = {&buttonCharacteristic, &positionCharacteristic};
    GattService         service(BlueDotServiceUUID, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));

    ble.addService(service);

    buttonCharacteristicHandle = buttonCharacteristic.getValueHandle();
    positionCharacteristicHandle = positionCharacteristic.getValueHandle();

    ble.onDataWritten(this, &BlueDotService::onDataWritten);
}

uint8_t BlueDotService::getButton() 
{
    return buttonCharacteristicBuffer;
}

uint16_t BlueDotService::getX() 
{
    return positionCharacteristicBuffer >> 16;
}

uint16_t BlueDotService::getY() 
{
    return positionCharacteristicBuffer & 0xffff;
}

/**
  * Callback. Invoked when any of our attributes are written via BLE.
  */
void BlueDotService::onDataWritten(const GattWriteCallbackParams *params)
{
    if (params->handle == buttonCharacteristicHandle && params->len >= sizeof(buttonCharacteristicBuffer))
    {
        buttonCharacteristicBuffer = *((uint8_t *)params->data);
        if (EventModel::defaultEventBus) {
            MicroBitEvent ev(MICROBIT_ID_BLUEDOT,
                buttonCharacteristicBuffer == 0 
                    ? MICROBIT_BLUEDOT_EVT_BUTTON_UP 
                    : MICROBIT_BLUEDOT_EVT_BUTTON_DOWN);                
        }
    }
    else if (params->handle == positionCharacteristicHandle && params->len >= sizeof(positionCharacteristicBuffer))
    {
        positionCharacteristicBuffer = *((uint32_t *)params->data);
        if (EventModel::defaultEventBus) {
                MicroBitEvent ev(MICROBIT_ID_BLUEDOT, MICROBIT_BLUEDOT_EVT_POSITION_UPDATE);
        }
    }
}
