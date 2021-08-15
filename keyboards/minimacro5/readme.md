# miniMACRO5

A 5 key Macropad based on Arduino Pro Micro with support for a combination of rotary encoders and mechanical switches.

![](https://i.imgur.com/lxA8DSCl.jpg)

* Keyboard Maintainer: [LeafCutterLabs](https://github.com/LeafCutterLabs)
* Hardware Supported: Pro Micro 5V/16MHz and compatible.
* Hardware availability: PCB Files are available [here](https://github.com/LeafCutterLabs/miniMACRO5), which you can get produced.

## Customized to manage LED effects

Key combos allow alteration of the LED effects:

* Hold Prev+Stop and turn knob to select animation more
* Hold Next+Stop and turn know to select color
* Tap Prev+Next to toggle LED strip on and off
* Tap Mute+Stop to store animation mode and color in eeprom

## Flash firmware

```
qmk flash -kb minimacro5 -km media
```

## Build Environament Instructions

Make example for this keyboard (after setting up your build environment):

    make minimacro5:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
