# Jackpad
Jackpad is a modular slot machine macropad. Pull the lever and the slots spin and land on a set of macros for an app, either picked at random or chosen by you. Either way, you get the satisfying mechanical spin of a real slot machine.  Snap on extra slots to make it as big as you need.

Made this for https://halflife.hackclub.com/

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

# Jackpad BOM

| Item | Amount | Cost (ea.) |
|---|---|---|
| 74AHCT125 (DIP-14) + DIP-14 socket | 1 | $0.96 |
| MX126-5.0-02P screw terminal | 2 | $0.11 |
| Male pin header strip, 2.54mm (40-pin) | 1 | $0.12 |
| Female pin header strip, 2.54mm (40-pin) | 1 | $0.10 |
| Male to Female jumper wires | 1 | $0.51 |
| Female to Female jumper wires | 1 | $0.51 |
| PN532 RF-ID V3 Module | 4 | $2.68 |
| NFC Tag Sticker \| NTAG213 (pack of 10) | 3 | $1.56 |
| 0.1uF (100nF) ceramic caps | 10 | $0.10 |
| 1N5819 Schottky diodes | 6 | $0.062 |
| Electrolytic caps: 470uF x2, 100uF x1, 10uF x1 | 1 | $1.44 |
| ESP32-C3 SuperMini | 4 | $2.68 |
| Magnetic encoder sensor module AS5600 | 5 | $1.64 |
| DRV8833 motor driver breakout | 4 | $0.82 |
| N20 300 RPM Motors | 4 | $2.6975 |
| MR30 PCB connector (MR30PW-FEMALE, 3-pin) | 5 | $1.03 |
| MR30 PCB connector (MR30PW-MALE, 3-pin) | 5 | $1.14 |
| MAIN and SLOT PCB ORDER | 2 | $9.30 |
| Battery 2500mAh 2S Li-ion | 1 | $5.98 |
| WS2812B LEDs | NA | |
| XIAO S3 | 1 | |
## Schematics:

### 1) Main PCB

![Schematic 1](Images/Main_schem.png)

### 2) Slot PCB

![Schematic 2](Images/slot_schem.png)
