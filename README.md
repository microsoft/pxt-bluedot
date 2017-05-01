# bluedot

### ~ hint

WORK IN PROGRESS

### ~

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

## License

MIT

## Supported targets

* for PXT/ microbit
(The metadata above is needed for package search.)

```package
bluedot=github:microsoft/pxt-bluedot
```
