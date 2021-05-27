// K4 analysis

// number known plaintext from A-Z alphabet, corresponding ciphertext from reversed Kryptos alphabet
// 
// calculate cipher minus plain, modulo 26
// count the number which are multiples of 5 - the five() function
// in original K4 ciphertext, this is 13 out of 24
// measure how common this is -- around 1 in 1,468
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int rrand(int m)
{
	          return (int)((double)m * ( lrand48() / (RAND_MAX+1.0) ));
}

#define BYTE(X) ((unsigned char *)(X))

  void
shuffle (void *obj, size_t nmemb, size_t size) 
{
  void *temp = malloc (size);
  size_t n = nmemb;
  while (n > 1)
    {
      size_t k = rrand (n--);
      memcpy (temp, BYTE (obj) + n * size, size);
      memcpy (BYTE (obj) + n * size, BYTE (obj) + k * size, size);
      memcpy (BYTE (obj) + k * size, temp, size);
    }
  free (temp);
}

 int
five (char *t) 
{
  int x = 0;
  int i;
  char k[] = "ZXWVUQNMLJIHGFEDCBASOTPYRK";
  // loc 21-34 and 63-73
  char p1[] = "EASTNORTHEAST";
  char p2[] = "BERLINCLOCK";

  for (i = 21; i <= 33; i++)
  {
	  int a = strchr(k,t[i]) - k;
	  int p = p1[i-21] - 'A';
	  int b = (52+a-p)%26;
	  if (b % 5 == 0) x++;
  }

  for (i = 63; i <= 73; i++)
  {
	  int a = strchr(k,t[i]) - k;
	  int p = p2[i-63] - 'A';
	  int b = (52+a-p)% 26;
	  if (b % 5 == 0) x++;
  }
  return x;
 }

 int
main (int argc, char **argv) 
{
  int row;
  long i;
  int pstat2, pstat3, pstat4, pcount = 0;
  long co = 1e9;		// one billion served!
  char k4[] =
    "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR";
  char k4_perm[98];
  struct timeval time;
   gettimeofday (&time, NULL);
  srand48 ((time.tv_sec * 1000) + (time.tv_usec / 1000));
  strcpy (k4_perm, k4);

  pstat2 = five (k4);
  printf("%d\n",pstat2); fflush(stdout);
   
  pcount = 0;
  for (i = 0; i < co; i++)
    
    {
      shuffle (k4_perm,97,1);
      if (five (k4_perm) >= pstat2)
	pcount++;
    }
  printf ("%d\n", co/pcount);
   return 0;
}


