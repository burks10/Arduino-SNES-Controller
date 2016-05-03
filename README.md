# Arduino-SNES-Controller
A small Arduino sketch which creates an HID compliant joystick out of Nintendo's Super Nintendo (SNES) Controller.
You can now play any joystick compatible game using your old SNES controller and any Arduino based microcontroller.
Check out this quick video for a demo and tutorial: https://www.youtube.com/watch?v=93oCS9nF_y0

## Hardware Setup

SNES Controller Pinout
<pre>
 -----------------\
| 1 2 3 4 | 5 6 7  |
 -----------------/</pre>
 <ul>
  <li>Pin 1: 5V</li>
  <li>Pin 2: Data_Clock (Arduino: Pin 6)</li>
  <li>Pin 3: Data_Latch (Arduino: Pin 7)</li>
  <li>Pin 4: Data_Serial (Arduino: Pin 12)</li>
  <li>Pin 5: N/A</li>
  <li>Pin 6: N/A</li>
  <li>Pin 7: GND</li>
 </ul>
 
## Software Setup
<ol>
  <li>Install the Drivers by running to UnoJoy/UnoJoyDriverInstaller.bat</li>
  <li>Open the code located under snes/snes.ino and upload it to your Arduino.</li>
  <li>The Arduino UNO R3 uses a MEGA16u2 chip to upload sketches to memory. In order to be recognized as an HID USB device,
  we must flash the 16u2 chip with some custom firmware. To do this on the Arduino R3, short the 2 pins closest to the USB port to enter
  DFU mode. From there, run UnoJoy/TurnIntoAJoystick.bat. Now that you have reflashed the Arduino, unplug it from the USB and re-plug it
  back in. You are now running the arduino as a joystick.</li>
  
</ol>

Be sure to checkout UnoJoy (https://github.com/AlanChatham/UnoJoy) for their awesome library/drivers that made this project possible.
