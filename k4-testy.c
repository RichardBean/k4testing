// K4 - perform five tests
  
// 1. Hannon -- width 21 -- how many bigrams are there in vertical pairs?
// 2. Materna -- for KRYPTOS letters in plaintext, what is the average of minor differences of corresponding plaintext letters?
// 3. Bean 1 -- for each repeated plaintext letter in A, C, E, L, N, O, R, T, S what is the average of the minor differences between the corresponding plaintext letters?
// 4. Bean 2 -- for each repeated plaintext letter in A, C, E, L, N, O, R, T, S how many of the minor differences between the corresponding plaintext letters are less than 5?
// 5. Double-letter -- how many permutations have at least as many double-letter bigrams as K4 ciphertext?
//
// 1 in 6750, 1 in 5520, 1 in 240, 1 in 310, 1 in 7
  
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
materna (char *t) 
{
  return md ('S', t[23]) + md ('T', t[24]) + md ('O', t[26]) + md ('R',
								       t[27])
    + md ('T', t[28]) + md ('S', t[32]) + md ('T', t[33]) + md ('R',
								    t[65]) +
    md ('O', t[71]) + md ('K', t[73]);
}

 int
bean1 (char *t) 
{
  return md (t[22], t[31]) +	// a
    md (t[69], t[72]) +		// c
    md (t[21], t[30]) +		// e1 e2
    md (t[21], t[64]) +		// e1 e3
    md (t[30], t[64]) +		// e2 e3
    md (t[66], t[70]) +		// l
    md (t[25], t[68]) +		// n
    md (t[71], t[26]) +		// o
    md (t[65], t[27]) +		// r
    md (t[23], t[32]) +		// s
    md (t[28], t[33]) +		// t1, t2
    md (t[28], t[24]) +		// t1, t3
    md (t[33], t[24]);		// t2, t3 
}
  
 int
bean2 (char *t) 
{
  int x = 5;
 return (md(t[22],t[31])<x) + 
(md(t[69],t[72])<x)+ 
(md(t[21],t[30])<x)+ 
(md(t[21],t[64])<x)+ 
(md(t[30],t[64])<x)+ 
(md(t[66],t[70])<x)+ 
(md(t[25],t[68])<x)+ 
(md(t[71],t[26])<x)+ 
(md(t[65],t[27])<x)+ 
(md(t[23],t[32])<x)+ 
(md(t[28],t[33])<x)+ 
(md(t[28],t[24])<x)+ 
(md(t[33],t[24])<x);  
 }

 int
count21 (char *s) 
{
  int row, dcount = 0, dlist[26 * 26], i;
   for (i = 0; i < 26 * 26; i++)
    dlist[i] = 0;
  for (row = 0; row < strlen (s) - 21; row++)
    
    {
      int d1, d2;
      d1 = s[row];
      d2 = s[row + 21];
      dlist[(d1 - 'A') * 26 + d2 - 'A']++;
  } for (i = 0; i < 26 * 26; i++)
    if (dlist[i] > 1)
      dcount++;
  return dcount;
}

 int
double_letter_bigrams (char *s)
{
  int double_letter_bigram_count = 0;
  int i;
  const int len = (int) strlen (s);
  for (i = 0; i < (len-1); i++)
  {
    if (s[i] == s[i+1])
    {
      double_letter_bigram_count++;
    }
  }
  return double_letter_bigram_count;
}

 int
main (int argc, char **argv) 
{
  long i, pstat2, pcount = 0, co = 1e7;
  char k4[] =
    "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR";
  char k4_perm[98];
  struct timeval time;
  pstat2 = count21 (k4);
   gettimeofday (&time, NULL);
  srand48 ((time.tv_sec * 1000) + (time.tv_usec / 1000));
  strcpy (k4_perm, k4);
   
     for (i = 0; i < co; i++)
       {
       shuffle(k4_perm,97,1);
       if (count21(k4_perm) >= pstat2) pcount++;
       }
       printf("count21 %ld\n",co/pcount); 
    pstat2 = materna (k4);
  pcount = 0;
  for (i = 0; i < co; i++)
    {
      shuffle (k4_perm,97,1);
      if (materna (k4_perm) <= pstat2)
	pcount++;
    }
  printf ("materna %ld\n", co/pcount);

  pstat2 = bean1 (k4);
  pcount = 0;
  for (i = 0; i < co; i++)
    {
      shuffle (k4_perm,97,1);
      if (bean1(k4_perm) <= pstat2)
	pcount++;
    }
  printf ("bean1 %ld\n", co/pcount);

  pstat2 = bean2 (k4);
  pcount = 0;
  for (i = 0; i < co; i++)
    {
      shuffle (k4_perm,97,1);
      if (bean2(k4_perm) >= pstat2)
	pcount++;
    }
  printf ("bean2 %ld\n", co/pcount);

  pstat2 = double_letter_bigrams (k4);
  pcount = 0;
  for (i = 0; i < co; i++)
    {
      shuffle (k4_perm,97,1);
      if (double_letter_bigrams(k4_perm) >= pstat2)
	pcount++;
    }
  printf ("double-letter %ld\n", co/pcount);

   return 0;
}


