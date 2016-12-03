//dc land tile grid demo by GreenGianT
//tilegrids are a random idea we had, maybe they are useful..


#include <kos.h>
#include <dc_land/dc_land.h>



int main(int argc, char **argv)
{
  struct tilegrid_t *myTileGrid;   //a tilegrid
  TILE_ID player, blocks[15];      //some tiles for a "player" and some blocks
  int button = -100, i;


  v_init();
  v_clear(0,0,0);

  //create tile a new grid   //create_tilegrid (xpos, ypos, tilewidth, tileheight, gridwidth, gridheight)
  myTileGrid = create_tilegrid (110, 30, 20, 20, 21, 20);

  //add a tile which will be the player..
  player = addTile (myTileGrid, 3, 3);

  //add some other tiles for blocks
  for (i = 0; i < 5; i++)
    blocks[i] = addTile (myTileGrid, i + 2, 9);     //the horizontal blocks

  for (i = 7; i < 12; i++)
    blocks[i - 2] = addTile (myTileGrid, 10, i);    //vertical blocks in the middle

  for (i = 15; i < 20; i++)
    blocks[i - 5] = addTile (myTileGrid, i - 1, 9); //horizontal blocks

  //draw the tile grid
  draw_tilegrid (myTileGrid);


  if (pad_exists ()) {               
    while (button != btnSTART) {
      DC_sleep (50);
      button = get_button ();         //check the pad

      switch (button) {
      case dpadUP: {    //move player up
	moveTile (myTileGrid, player, tileUP);
	break;
      }
      case dpadDOWN: {  //move player down
	moveTile (myTileGrid, player, tileDOWN);
	break;
      }
      case dpadLEFT: {  //move player left
	moveTile (myTileGrid, player, tileLEFT);
	break;
      }
      case dpadRIGHT: { //move player right
	moveTile (myTileGrid, player, tileRIGHT);
	break;
      }
      }   //end of switch
    }     //end of while
  }       //end of if pad_exists()
  else {
    v_drawstring (20, 20, "no control pad connected!");
  }

  return 0;
}   


