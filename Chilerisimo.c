/*
  Welcome.c
  
  Welcome to SimpleIDE, the C programming environment that makes it easy to 
  get started with the multi-core Propeller microcontroller! 
  
  To run this program:
  
    - Is this the first Parallax software you've installed on your computer?  
      If so, install USB driver's now: www.parallax.com/usbdrivers
    - Connect your Propeller board to your computer's USB.  Also connect power
      to the board if needed, and if it has a power switch, turn it on.
    - Make sure to select your COM port from the toolbar dropdown menu in the
      upper-right corner.  If you are unsure which COM port your board is 
      connected to, disconnect it and click the dropdown to check the port 
      list, then reconnect it and check again.
    - Click Program and select Run with Terminal (or click the Run with Terminal 
      button).  The SimpleIDE Terminal should appear and display the "Hello!"
      message.
      
   Next, check the Help menu for new online tutorials, software manual, and 
   reference material.
   http://learn.parallax.com/propeller-c-tutorials
*/

#include "abdrive.h"                          // Inckuir abdrive para encoders y servos
#include "ping.h"
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  while (1){
    
    drive_speed(50,50);
    pause(850);
    drive_speed(26,-25);
    pause(1000);
    if (ping_cm(8) < 15){
      drive_speed(-25,26);
      pause(1050); 
      drive_speed(0,0);
      pause(100);
      if (ping_cm(8) < 15){
        drive_speed(-25,26);
        pause(1000);
        drive_speed(0,0);
        pause(100); 
        if (ping_cm(8) < 15){
          drive_speed(-25,26);
          pause(1000); 
        }     
      }  
       
    }
    else{
      drive_speed(-25,26);
      pause(50);
    }       
  }
}