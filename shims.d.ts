// Auto-generated. Do not edit.
declare namespace bluedot {

    /**
     * Starts the BlueDot BLE service
     **/
    //% blockId=bluedot_start block="blue dot start" shim=bluedot::startService
    function startService(): void;

    /**
     * Registers code to run when the button is in a particular state
     */
    //% blockId=bluedot_on_button_changed block="on blue dot %state" shim=bluedot::onButton
    function onButton(state: BlueDotButtonState, handler: () => void): void;

    /**
     * Register code to run when the position has changed
     */
    //% blockId=bluedot_on_position_chaged block="on blue dot moved" shim=bluedot::onMoved
    function onMoved(handler: () => void): void;

    /**
     * Gets a value indicating if the button is pressed
     */
    //% blockId=bluedot_buttonpressed block="blue dot is pressed" shim=bluedot::isPressed
    function isPressed(): boolean;

    /**
     * Gets the position of the cursor on the bluedot, between -1023 (left) and 1023 (right)
     */
    //% shim=bluedot::x
    function x(): number;

    /**
     * Gets the position of the cursor on the bluedot, between -1023 (left) and 1023 (right)
     */
    //% shim=bluedot::y
    function y(): number;

    /**
     * Gets the position of the touch point on the blue dot
     */
    //% blockId=bluedot_position block="blue dot %name" shim=bluedot::position
    function position(dimension: BlueDotDimension): number;
}

// Auto-generated. Do not edit. Really.
