#include "pxt.h"
#include "BlueDotService.h"

enum BlueDotButtonState {
    //% block="down"
    Down = 1,
    //% block="up"
    Up = 2
};

enum BlueDotDimension {
    //% block="x"
    X,
    //% block="y"
    Y
};

namespace bluedot {
    BlueDotService* _pService = NULL;

    /**
    * Starts the BlueDot BLE service
    **/
    //% blockId=bluedot_start block="blue dot start"
    void startService() {
        if (NULL == _pService) {
            _pService = new BlueDotService(*uBit.ble);
        }
    }

    /**
    * Registers code to run when the button is in a particular state
    */
    //% blockId=bluedot_on_button_changed block="on blue dot %state"
    void onButton(BlueDotButtonState state, Action handler) {
        startService();
        registerWithDal(MICROBIT_ID_BLUEDOT, state, handler);
    }

    /**
    * Register code to run when the position has changed
    */
    //% blockId=bluedot_on_position_chaged block="on blue dot moved"
    void onMoved(Action handler) {
        startService();
        registerWithDal(MICROBIT_ID_BLUEDOT, MICROBIT_BLUEDOT_EVT_POSITION_UPDATE, handler);
    }

    /**
    * Gets a value indicating if the button is pressed
    */
    //% blockId=bluedot_buttonpressed block="blue dot is pressed"
    bool isPressed() {
        startService();
        return _pService->getButton() > 0;
    }

    /**
    * Gets the position of the cursor on the bluedot, between -1023 (left) and 1023 (right)
    */
    //% 
    int x() {
        startService();
        return (_pService->getX() - (2 << 15)) >> 5;        
    }

    /**
    * Gets the position of the cursor on the bluedot, between -1023 (left) and 1023 (right)
    */
    //% 
    int y() {
        startService();
        return (_pService->getY() - (2 << 15)) >> 5;        
    }

    /**
    * Gets the position of the touch point on the blue dot
    */
    //% blockId=bluedot_position block="blue dot %name"
    int position(BlueDotDimension dimension) {
        return dimension == BlueDotDimension::Y ? y() : x();
    }
}
