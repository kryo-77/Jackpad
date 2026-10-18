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

## What it is / Why i made it:
- It's a macropad but in a style of a slot machine. The reason I made this is because slot machines look cool and I wanted to combine two completely different things.

## How it works:
- Two PCBs: Main (contains XIAO S3 as the main MCU, only 1 PCB) & Slot (contains ESP32-C3 supermini as the MCU, PCB quantity depends on how many macros you want)
- XIAO S3 acts as a wireless keyboard
- The main pcb has an AS5600 magnetic sensor which is the lever you pull to send signals to the ESP32-C3 for spinning motors.
- ESP32 C3's send signals to XIAO S3 via ESP-NOW (vice-versa) for button presses, motor running etc.
- The slots also have an AS5600 sensor each for positioning the motors correctly so they line the RFID tags correctly.
- Each slot also has a PN532 rfid reader along with small rfid tags which sit on a drum which spin via the motor. A single mechanical switch is present under the drum. PN532 detects a rfid tag which is our 'macro' and as you click on the button, it sends that macro to S3.
- There are limits to how many tags a SLOT can contain (due to size), but no limits to how many SLOT PCBs you can connect with each other, and that too in any order. The slots get a numbering via a 'E-IN / E-OUT' pin on each MCU which does the ordering of slots. A MR30 connector on each pcb has 3 pins: 5v/GND/ENUM for this reason.
- There are two modes: One is just randomly selecting macros, basically a slot machine for looks (though you can set the random macros to do whatever you want). Second mode is where you group different macros together; so like you have macro for music player & 4 slots are connected to main pcb so the macros are: PLAY/PAUSE/NEXT/PREVIOUS. Other group is for FUSION-360 for Sketch/Extrude/Combine/Align tool. So the groups are selected in a sequence; once u pull the lever MUSIC group gets selected, pull lever again Fusion group gets selected and so on (loops), and this is where the AS5600 sensor is most needed.

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

## Jackpad BOM:

| Item | Amount | Cost (ea.) | Use |
|---|---|---|---|
| 74AHCT125 (DIP-14) + DIP-14 socket | 1 | $0.96 | 3.3V to 5V level shifter for LED data |
| MX126-5.0-02P screw terminal | 2 | $0.11 | External 5V input |
| Male pin header strip, 2.54mm (40-pin) | 1 | $0.12 | Headers |
| Female pin header strip, 2.54mm (40-pin) | 1 | $0.10 | Mount boards |
| Male to Female jumper wires | 1 | $0.51 | Connect boards |
| Female to Female jumper wires | 1 | $0.51 | Connect boards |
| PN532 RF-ID V3 Module | 4 | $2.68 | RFID reading for macro |
| NFC Tag Sticker \| NTAG213 (pack of 10) | 3 | $1.56 | RFID tags (macros) |
| 0.1uF (100nF) ceramic caps | 10 | $0.10 | Decoupling (1 on main pcb + 2 per slot pcb) |
| 1N5819 Schottky diodes | 6 | $0.062 | Power protection for esp32's(1 per board) |
| Electrolytic caps: 470uF x2, 100uF x1, 10uF x1 | 1 | $1.44 | Power smoothing? |
| ESP32-C3 SuperMini | 4 | $2.68 | SLOT PCB main board |
| Magnetic encoder sensor module AS5600 | 5 | $1.64 | Motor encoder for stopping at soecific points & one for lever |
| DRV8833 motor driver breakout | 4 | $0.82 | Motor control, slot board |
| N20 300 RPM Motors | 4 | $2.6975 | For spinning barrels | 
| MR30 PCB connector (MR30PW-FEMALE, 3-pin) | 5 | $1.03 | Power in/out (1 per slot pcb + 1 in main pcb) |
| MR30 PCB connector (MR30PW-MALE, 3-pin) | 5 | $1.14 | Power in/out (1 per slot pcb) |
| MAIN and SLOT PCB ORDER | 2 | $9.30 | PCB manufacture from robu.in |
| Battery 2500mAh 2S Li-ion | 1 | $5.98 | Power :3 |
| WS2812B LEDs | 6 | $0.05 USD | Lights |
| XIAO S3 | 1 | $11.99 | Main PCB main board  |

## Schematics:

### 1) Main PCB

![Schematic 1](Images/Main_schem.png)

### 2) Slot PCB

![Schematic 2](Images/slot_schem.png)
