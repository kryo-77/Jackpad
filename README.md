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

## Updates:
- V1.5
Custom surface-mount PCB layout required full PCBA manufacturing, which was going out of my budget as the shipping cost was already high. I spent over 6 hours working on `kicad_jackpad`, but I forgot to take a look at costs. I will now have to redesign everything from scratch again in the pcb, but this time it'll be simpler as I am using full module boards in the pcb.

- V1
The project is split into two pcbs:

Main pcb and slot pcb.

1) For main pcb, I decided to use ESP32 S3 Wroom 01 chip as it has many gpio pins and is a cheap module too. I went with ESP32 as I wanted to use it as a wireless macropad, as wireless makes more sense for the design of the Jackpad. 