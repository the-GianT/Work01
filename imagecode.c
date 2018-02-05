#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NUMROWS 500
#define NUMCOLS 500

int main()
{
  /*
  // for adding together to generate next fib #
  int fib0 = 0;
  int fib1 = 1;
  */

  char buf[40]; // for writing to image file (starts as image header)
  
  // int i;
  int ctr; // counts how many subpixels it has written
  int subpixelval; // integer to write
  char initchars[2]; // determines whether to put two spaces or a newline at the beginning of buf
  int fd; // descriptor for image file

  fd = open("the_image.ppm", O_CREAT | O_WRONLY, 0600);

  // image header
  sprintf(buf, "P3\n%d %d\n255\n", NUMCOLS, NUMROWS);
  write(fd, buf, strlen(buf) * sizeof(char));

  for (ctr = 0; ctr < NUMROWS * NUMCOLS; ctr++) {
    if (ctr % NUMCOLS == 0) { // if we are at the end of the row
      // endchar = "\n";
      strcpy(initchars, "\n");
    } else {
      strcpy(initchars, "  ");
    }
    subpixelval = ctr % 256;
    sprintf(buf, "%s%d %d %d", initchars, subpixelval, subpixelval, subpixelval);
    write(fd, buf, strlen(buf));
  }

  write(fd, "\n", sizeof(char));

  /*
  // fill in first two subpixels
  sprintf(buf, "%d ", fib0);
  write(fd, buf, strlen(buf) * sizeof(char));
  sprintf(buf, "%d ", fib1);
  write(fd, buf, strlen(buf) * sizeof(char));
  
  for (ctr = 2; ctr < NUMROWS * NUMCOLS; ctr++) {
    if (ctr % (NUMROWS * 3) == 0) { // if we are at the end of the row
      endchar = '\n';
    } else {
      endchar = ' ';
    }
    
    if (fib0 < fib1) {
      sprintf(buf, "%d%c", fib0 = fib0 + fib1, endchar);
    } else {
      sprintf(buf, "%d%c", fib1 = fib0 + fib1, endchar);
    }
    
    write(fd, buf, strlen(buf) * sizeof(char));
    // ctr ++;
  }
  */

  return 0;
}
