#include <stdio.h>

int main (void) {
  char a = 1;
  int b  = 12365;
  long c = 0x7FFFFFFF;

  unsigned char x = 'A';
  unsigned int y  = 54321;
  unsigned long z = 0x4A6F6E00;

  float f = 10.0;
  float g = 22.95;

  char buf [] = "Test String";
  char *p = buf;

  printf ("char %d int %d long %ld\n",a,b,c);
  printf ("Uchar %u Uint %u Ulong %lu\n",x,y,z);
  printf ("xchar %x xint %x xlong %lx\n",x,y,z);
  printf ("String %s is at address %p\n",buf,p);
  printf ("%f != %g\n", f, g);
  printf ("%*f != %*g\n", 8, f, 8, g);
}
