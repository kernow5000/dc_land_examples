//dcland menu example by GreenGianT   


#include <kos.h>                   //KOS
#include <dc_land/dc_land.h>       //DC_land


int main(int argc, char **argv) {
  struct a_menu *my_menu;
  int selection;
  char output[20];


  v_init ();                       //init video for 2d
  v_clear (0, 0, 0);  
  
  if (pad_exists ()) {                    //if there is a pad plugged in
    my_menu = new_menu ("menu title");    //create menu to get number of points in 2d profile
    add_option (my_menu, "option 1");     //add menu options
    add_option (my_menu, "option 2");
    add_option (my_menu, "option 3");
    add_option (my_menu, "option 4");
    add_option (my_menu, "option 5");
    add_option (my_menu, "option 6");
    add_option (my_menu, "option 7");
    
    selection = display_menu (my_menu, 100, 50, 0);  //display menu and wait for selection

    v_clear (0, 0, 0);
    strcpy (output, "You selected:");
    strcat (output, itoa (selection + 1));
    v_drawstring (40, 230, output);            //output the selection
  }
  else {                                       //if there was no pad found
    v_clear(255, 0, 0);
    v_drawstring(20, 20, "Error! No pad connected!");  
  }
  
  return 0;
}
