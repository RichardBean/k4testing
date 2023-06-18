// Edward Hannon, one of the original NSA solvers of Kryptos 1-3 in 1992
// joined the Yahoo Kryptos group in June 2010.

// His consistent theory since then to date (June 2023) has been that
// ALWHSEPBMXITFQCNYJUGRDOZKV
// is a special alphabet related to K4.

// This alphabet can obtained by beginning with A-Z and "unwinding" an incomplete columnar transposition
// with keyword KRYPTOS

// June 2010:
// therefore, two conclusions can be reached regarding k4
//
// 1. there is a strong width 21 property 
// 2. that the cipher alphabet is related to letters which are 11 apart in the standard alphabet. 

// in summary, the cipher is first a substitution for the cipher alphabet  
// followed by another substitution for the cipher to plain mapping. 
// the text almost certainly contain two 'reports', each of which has 4 data points in two subsets with headers. 

// we can look at the "1 aparts" in his alphabet versus the "21 aparts" in K4, with and without wrapping
// to see how "special" this alphabet might be

// we do this by randomly permuting (1) the alphabet (2) the ciphertext and (3) both
// and counting the number of "1 aparts" vs the original alphabet + ciphertext
// and seeing for what proportion of permutations we get at least the original count

// results: 1 in 112, 248, 195 (without wrap); 1 in 163, 456, 338 (with wrap)

// "antipodes" alphabet with wrap is best (17)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int rrand(int m)
{
return (int)((double)m * ( lrand48() / (RAND_MAX+1.0) ));
}

#define byte(x) ((unsigned char *)(x))

  void
shuffle (void *obj, size_t nmemb, size_t size) 
{
  void *temp = malloc (size);
  size_t n = nmemb;
  while (n > 1)
    {
      size_t k = rrand (n--);
      memcpy (temp, byte (obj) + n * size, size);
      memcpy (byte (obj) + n * size, byte (obj) + k * size, size);
      memcpy (byte (obj) + k * size, temp, size);
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

 double
han (char *a, char *k) 
{
int x = 0;
int i;

// find all letters which are 21 letters apart in K4
// are they "one apart" in the Hannon alphabet?

for (i = 0; i < 97; i++)  // or 97 with wrapping
{
	int p,q;

	p = strchr(a,k[i])-a;
	q = strchr(a,k[(i+21)%97])-a;

//printf("%c%c %d\n",k[i],k[i+21],md(p,q));
if (md(p,q) == 1) x++; 
}
return x;
}
  
 int
main (int argc, char **argv) 
{
  long i, pcount = 0, co = 1e8;
  double pstat2;
  int m;
char a[] = "alwhsepbmxitfqcnyjugrdozkv"; // hannon
//char a[] = "aslewpibtmfxqjcungyrkdvohz"; // reverse perm i.e. wind rather than unwind
//char a[] = "alwhsdozkvgrcnyjufqbmxitep"; // decimation
//char a[] = "antipodesbcfghjklmqruvwxyz"; // antipodes
//char a[] = "amybnzcodpeqfrgshtiujvkwlx"; // amy
  
char k[] = "obkruoxoghulbsolifbbwflrvqqprngkssotwtqsjqssekzzwatjkludiawinfbnypvttmzfpkwgdkzxtjcdigkuhuauekcar";
  char k_perm[98], a_perm[27];

  srand48 (time(0));
   

  pstat2 = han (a,k);
  printf("pstat2: %lf\n",pstat2);

  for (m=1; m <= 3; m++)
  {
  pcount = 0;
  strcpy(k_perm,k);
  strcpy(a_perm,a);

   for (i = 0; i < co; i++)
    {
      if (m & 1) shuffle (a_perm,26,1);
      if (m & 2) shuffle (k_perm,97,1);

      if (han(a_perm,k_perm) >= pstat2)
	pcount++;
    }
  printf ("m=%d cp %ld\n", m,co/pcount); fflush(stdout); 
  }

  return 0;
}
