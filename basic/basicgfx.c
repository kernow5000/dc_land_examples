// hey its my first dcland example, demonstrating DC_land's powerful 2d funcs

#include <kos.h>
#include <dc_land/dc_land.h>


int main(int argc, char **argv) {
  
  int x=400, y=0, r=0, g=0, b=0;
 
  v_init();
  v_clear(0,0,0);


  v_drawstring_ctr (320, 15, "DC_land 2d video example"); //centered text

  v_drawstring_ctr (320, 240, "320, 240");                //center

  v_drawstring (403, 126, "403, 126");                    //text                    
  v_drawstring (403, 352, "403, 352");
   
  v_box (50, 50, 540, 380, 0, 0, 255);                    //big blue box
   
  v_circle (320, 240, 80, 255, 0, 0);                     //red circle
  v_circle (320, 240, 70, 0, 255, 0);                     //green circle
  v_circle (320, 240, 65, 255, 255, 0);                   //yellow circle

  v_line (50, 50, 590, 430, 0, 255, 0);                   //green lines
  v_line (50, 430, 590, 50, 0, 255, 0);  
   
  while (y <= 100)
    v_line (80, 135, x-=5, y+=5, 0,g +=7, b);             //random
   
  return 0;
}




