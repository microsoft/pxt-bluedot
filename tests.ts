// tests go here; this will not be compiled when this package is used as a library
led.plot(0, 0);
bluetooth.onBluetoothConnected(() => {
    led.plot(0, 1);
})
bluetooth.onBluetoothDisconnected(() => {
    led.unplot(0, 1);
})
bluedot.startService();
bluedot.onButton(BlueDotButtonState.Down, () => {
    led.unplot(0, 2);
    serial.writeValue("b", bluedot.isPressed() ? 1 : 0)
})
bluedot.onButton(BlueDotButtonState.Up, () => {
    led.plot(0, 2);
    serial.writeValue("b", bluedot.isPressed() ? 1 : 0)
})
bluedot.onMoved(() => {
    led.toggle(0, 3);
    serial.writeValue("x", bluedot.x())
    serial.writeValue("y", bluedot.y())
    let x = pins.map(bluedot.x(), -1023, 1023, 1, 4);
    let y = pins.map(bluedot.y(), -1023, 1023, 1, 4);
    for (let i = 1; i < 5; ++i) {
        for (let j = 1; j < 5; ++j) {
            led.unplot(i, j);
        }
    }
    led.plot(x, y);
})
