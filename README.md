# Jackpad
Jackpad is a modular slot machine macropad. Pull the lever and the slots spin and land on a set of macros for an app, either picked at random or chosen by you. Either way, you get the satisfying mechanical spin of a real slot machine.  Snap on extra slots to make it as big as you need.

![main gif](Images/jacpad_openshot_red-ezgif.com-video-to-gif-converter.gif)

Slots detaching / attaching:

![Slot remove/add](Images/jacpad_openshot_slotchange-ezgif.com-video-to-gif-converter.gif)

## Color theme (3d prints):
Retro chrome

![Retro chrome theme](<Images/Screen Shot 2026-10-06 at 16.56.47.png>)

Classic casino

![Classic casino theme](<Images/Screen Shot 2026-10-06 at 16.56.36.png>)

## UPDATES:
1) Changed from surface mount components and individual chips to carrier board type mounts for ease of soldering.
2) Completed both main and slot pcb.
3) Week-1 completed of half-life hackclub.

## To-do:
1) Work on 3d modeling for week-2 of half-life.

## Project files:
1) Folder `kicad_jackpad` contains all the files for PCB/SCHEMATICS for main pcb and slot pcb.
2) In this folder, the first project you see is:  `Jackpad.kicad_pro`. This is my first schematic for the project. You can ignore this file as it does not serve any purpose.
3) Inside is another folder named `breakout_jackpad` which is the main folder. It contains the main pcb files (`breakout_jackpad.pro`) as well as slot pcb files (inside `slot_jackpad` folder).

## Part list:
### Main pcb:
- **Xiao s3**
- **AS5600**
- **MAX98357A + speaker**
- **74AHCT125**
- **WS2812 LEDs**

### Slot pcb:
- **ESP32 C3 SUPER MINI**
- **PN532 module (i2c) Rfid reader**
- **AS5600**
- **DRV8833**
- **N20 300rpm motor**
- **Mechanical switch**




