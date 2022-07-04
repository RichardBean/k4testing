// K4 - perform fifth test
  
// 4. Bean 3 -- for each plaintext letter 0 or 1 apart, how many of the minor differences between the corresponding plaintext letters are less than 5?
//
// 1 in ~5000
  
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
md (char a, char b) 
{
  int x;
  x = a - b;
  if (x < 0)
    x += 26;
  if (x > 13)
    x = 26 - x;
  return x;
}

 int
bean5 (char *t) 
{
  int i,j,to=0;
  int a[] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73};
  char *pl = "EASTNORTHEASTBERLINCLOCK";

  for (i = 0; i < 23; i++)
  for (j = i+1; j < 24; j++)
  {
	if (md(pl[i], pl[j]) <= 1)
		to += md(t[a[i]] , t[a[j]]);
  }
  return to;
}
  
 int
main (int argc, char **argv) 
{
  long i, pstat2, pcount = 0, co = 1e9;
  char k4[] =
    "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR";
  char k4_perm[98];
  struct timeval time;

  gettimeofday (&time, NULL);
  srand48 ((time.tv_sec * 1000) + (time.tv_usec / 1000));
   
  pstat2 = bean5 (k4);
  printf("pstat2: %ld\n",pstat2);

  strcpy (k4_perm, k4);

  pcount = 0;
  for (i = 0; i < co; i++)
    {
      shuffle (k4_perm,97,1);
      if (bean5(k4_perm) <= pstat2)
	pcount++;
    }
  printf ("bean5 %ld\n", co/pcount);

  return 0;
 }
