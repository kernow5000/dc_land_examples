//simple mandelbrot example for dc land

#include <kos.h>
#include <dc_land/dc_land.h>



int main(int argc, char **argv) {
  float rmin, rmax, imin, imax, maxsizesq, deltar, deltai, x,y, xsq, ysq, cr, ci;
  int maxsize = 2, maxit = 125, maxcol = 640, maxrow = 480, color, row, col;

  v_init ();

  rmin = -3;
  rmax = 1;
  imin = -1.25;
  imax = 1.25;
  maxit = 120; //reduce for speed
  
  maxsizesq = maxsize * maxsize;
  
  deltar = (rmax-rmin) / (maxcol-1);
  deltai = (imax-imin) / (maxrow-1);
   
  for (row = 0; row < maxrow+1; row++)
    {
      for (col = 0; col < maxcol+1; col++)
	{
	  x = 0;
	  y = 0;
	  ci = (imin+row*deltai);
	  cr = (rmin+col*deltar);
	  color = 0;
	  do {
	    color++;
	    xsq = x*x;
	    ysq = y*y;
	    if ((xsq + ysq) < maxsizesq) {
	      y = x*2*y+ci;
	      x = xsq-ysq+cr;
	    }
	  }
	  while ((color < maxit) && ((xsq + ysq) < maxsizesq));
	  if (color >= maxit) {
	    color = 0;
	  }

	  v_pixel (col, row, 0, color, color + 100);   //plot pixel
	}
    }
   
   v_drawstring(20,20,"DC_land fractal demo");  //title

   return 0;
}




















