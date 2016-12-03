//DC_land Hello world! example
//demonstrates text and pad functions   


#include <kos.h>                   //KOS
#include <dc_land/dc_land.h>       //DC_land


int main(int argc, char **argv) {   
   int button = 0;                 //stores button press
   
   v_init ();                      //init video for 2d
   v_clear (0, 0, 0);  
   
   if (pad_exists ()) {             //if there is a pad plugged in
      v_drawstring (20, 20, "Hello World!"); 
      v_drawstring (20, 40, "Press START to end..");
      
      while(button != btnSTART)    //loop until start is pressed
	button = get_button();     //check controller status
      
      v_clear(0, 0, 0);
   }
   else {                          //no pad found
      v_clear(255, 0, 0);
      v_drawstring(20, 20, "Error! No pad connected!");  
   }
   
   return 0;
}
