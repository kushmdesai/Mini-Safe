# Mini-Safe 
**A Small Cute Safe**

This safe is made using a rfid module, grove-lcd rgb backlight, and a sg90 servo motor.
This is all connected to a esp8266 using wires. Theres no PCB but it lowkey took me a really long time to make the 3d models.
How it should work is that when the correct card is tapped on the case of the safe the door pops of and after roughly 10secs the door locks again.
The display is used to show wheather or not the card was accepted, This is shown by the display turning green if accepted and red if not.
The servor motor acts as a lock preventing the door from moving and when unlocked the servo motor turn like the handle of a door allowing you to open the safe.

![Diagram](/Wiring/Diagram.png)

![vid of project](/jounally-things/images/Vid_of_project.mp4)

*Note: I am using a breadboard currently and I will solder it together when actually making the thing in IRL*

*Note: I know its not the best vid so pls don't make fun of me :(*

## BOM

| Part name         | Cost    | Use                   | URL                                         |
| ----------------- | ------- | --------------------- | ------------------------------------------- |
| PCB Manufacture   | $2.40   | Putting case together |  [Ali Express](https://www.aliexpress.com/) |
| Economic PCBA     | $1.39   | Putting case together |  [Ali Express](https://www.aliexpress.com/) |
| Total:            | $3.79   |                       |                                             |