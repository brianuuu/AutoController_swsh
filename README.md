# AutoController by brianuuuSonic
Based on the LUFA library's Low-Level Joystick Demo (C) Dean Camera
Based on the HORI's Pokken Tournament Pro Pad design (C) HORI

Since System Update v3.0.0, the Nintendo Switch recognizes the Pokken Tournament Pro Pad as a Pro Controller. Physical design limitations prevent the Pokken Controller from functioning at the same level as the Pro Controller. However, by default most of the descriptors are there, with the exception of Home and Capture. Descriptor modification allows us to unlock these buttons for our use.

This project implements a modified version of HORI's Pokken Tournament Pro Pad USB descriptors to allow for the creation of custom controllers for the Nintendo Switch.

# Before You Start
Please watch the following video before you start anything!!!

https://www.youtube.com/watch?v=y2xFf7e_KSU&list=PLrAfKLfOSiGFv6wjohlEXQqYjEIoBOkfX

You should watch the following timestamp of the video, you can skip the others:
* 0:00 - 3:07 Hardwares you will need to buy (Arduino/Teensy/Knockoffs)
* 3:07 - 3:47 Software required for the hardware you are using (WindAVR/Flip/TeensyLoader)
* 5:58 - 8:02 How to load .hex into your microcontroller

# How to use
Please read the manual **AutoController_Manual.pdf** for more in-depth details for each program and how to use AutoControllerHelper
