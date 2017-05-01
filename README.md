# bluedot

### ~ hint

WORK IN PROGRESS

### ~

A sample of Bluetooth Low Energy port of the [BlueDot](https://github.com/martinohanlon/BlueDot/) protocol
for the micro:bit.

## Bluetooth Low Energy Service

The BlueDot service contains 2 characteristic for the button pressure and the position.

* Service UUID: ``cf638d8f-ea58-4015-90a6-76f1f11aaa4f``

### Button Characteristic

An unsigned byte that represents the button pressure. ``0`` means not pressed, positive values means pressed.

* Mandatory
* UUID: ``cf6363c2-ea58-4015-90a6-76f1f11aaa4f``
* Access: write wo response, notify

### Position Characteristic

An ``unsigned int`` which contains the X and Y positions.

* Mandatory
* UUID: ``cf63f012-ea58-4015-90a6-76f1f11aaa4f``
* Access: write wo response, notify

Each values is mapped onto an ``unsigned short`` where ``0`` is the left or bottom position.

## Usage

```blocks
bluedot.startService();
bluedot.onButton(BlueDotButtonState.Down, () => {
    led.unplot(0, 2);
})
bluedot.onButton(BlueDotButtonState.Up, () => {
    led.plot(0, 2);
})
```

## License

MIT

# Contributing
 
This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Supported targets

* for PXT/ microbit
(The metadata above is needed for package search.)

```package
bluedot=github:microsoft/pxt-bluedot
```
