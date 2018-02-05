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
  char buf[40]; // for writing to image file (starts as image header)
  
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
      strcpy(initchars, "\n");
    } else {
      strcpy(initchars, "  ");
    }
    subpixelval = ctr % 256;
    sprintf(buf, "%s%d %d %d", initchars, subpixelval, subpixelval, subpixelval);
    write(fd, buf, strlen(buf));
  }

  write(fd, "\n", sizeof(char));
  close(fd);
  return 0;
}
