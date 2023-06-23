// We write out K4, beginning ?OBKR, into a 14 row x 7 column matrix, then permute (rewrite) the rows with two different orders which we'll call A and B.
// 
// "A" is just a KRYPTOSKRYPTOS keyed permutation, while "B" is analogous to K3. 
// 
// (A) Row reordering: 1, 4, 7, 3, 6, 2, 5, 8, 11, 14, 10, 13, 9, 12 (the equivalent of a KRYPTOS KRYPTOS permutation on the rows)
// 
// Write it out as a 98 character string, writing down the columns:
// 
//  [1,] "?"  "O"  "B"  "K"  "R"  "U"  "O" 
//  [2,] "W"  "F"  "L"  "R"  "V"  "Q"  "Q" 
//  [3,] "Q"  "S"  "S"  "E"  "K"  "Z"  "Z" 
//  [4,] "S"  "O"  "L"  "I"  "F"  "B"  "B" 
//  [5,] "O"  "T"  "W"  "T"  "Q"  "S"  "J" 
//  [6,] "X"  "O"  "G"  "H"  "U"  "L"  "B" 
//  [7,] "P"  "R"  "N"  "G"  "K"  "S"  "S" 
//  [8,] "W"  "A"  "T"  "J"  "K"  "L"  "U" 
//  [9,] "M"  "Z"  "F"  "P"  "K"  "W"  "G" 
// [10,] "A"  "U"  "E"  "K"  "C"  "A"  "R" 
// [11,] "B"  "N"  "Y"  "P"  "V"  "T"  "T" 
// [12,] "D"  "I"  "G"  "K"  "U"  "H"  "U" 
// [13,] "D"  "I"  "A"  "W"  "I"  "N"  "F" 
// [14,] "D"  "K"  "Z"  "X"  "T"  "J"  "C" 
// 
// ?WQSOXPWMABDDDOFSOTORAZUNIIKBLSLWGNTFEYGAZKREITHGJPKPKWXRVKFQUKKKCVUITUQZBSLSLWATHNJOQZBJBSUGRTUFC
// 
// (or in one of four orders, starting at one corner - this is analogous to K3)
// 
// I have tried folding this back into a 14 row x 7 col matrix and looking at Playfair down the rows, 
// or seriated Playfair as there are no doubled letters down the columns (about a 1 in 7 chance). I didn't find anything.
// 
// ?WQSOXP
// WMABDDD
// OFSOTOR
// AZUNIIK
// BLSLWGN
// TFEYGAZ
// KREITHG
// JPKPKWX
// RVKFQUK
// KKCVUIT
// UQZBSLS
// LWATHNJ
// OQZBJBS
// UGRTUFC
// 
// However, just looking at that highlighted string, we have 14 repeated digrams, 3 repeated trigrams, and 1 repeated quadgram LSLW (let's call those numbers D, T, Q).
// 
// Let's call this "Property X" -- that a given text has D >= 14 and T >= 3 and Q >= 1 simultaneously.
// 
// If we do "simulations" to see how "rare" this pattern is (I know - always dangerous to identify a pattern and then decide how rare it is - Bible Code madness lies that way) ...
// 
// ... then we can try three different approaches as in the attached C program (I used billions of iterations).
// 
// (1) Permute the 98 characters of the string randomly a large number of times, and see what proportion of those random permutations have Property X
// (2) Generate 98 random letters a large number of times and see how many have Property X
// (3) Randomly permute the 14 rows a large number of times and see how many have Property X
// 
// The results are:
// 
// (1)  1 in 89,000 
// (2)  1 in 12,000 
// (3)  1 in 8,000
// 
// (B) 1, 4, 2, 5, 3, 6, 7, 10, 8, 11, 9, 12, 13, 14 (analogous to K3 - 12 x 7 first, then the last two rows)
// 
//  [1,] "?"  "O"  "B"  "K"  "R"  "U"  "O" 
//  [2,] "W"  "F"  "L"  "R"  "V"  "Q"  "Q" 
//  [3,] "X"  "O"  "G"  "H"  "U"  "L"  "B" 
//  [4,] "P"  "R"  "N"  "G"  "K"  "S"  "S" 
//  [5,] "S"  "O"  "L"  "I"  "F"  "B"  "B" 
//  [6,] "O"  "T"  "W"  "T"  "Q"  "S"  "J" 
//  [7,] "Q"  "S"  "S"  "E"  "K"  "Z"  "Z" 
//  [8,] "B"  "N"  "Y"  "P"  "V"  "T"  "T" 
//  [9,] "W"  "A"  "T"  "J"  "K"  "L"  "U" 
// [10,] "M"  "Z"  "F"  "P"  "K"  "W"  "G" 
// [11,] "D"  "I"  "A"  "W"  "I"  "N"  "F" 
// [12,] "D"  "K"  "Z"  "X"  "T"  "J"  "C" 
// [13,] "D"  "I"  "G"  "K"  "U"  "H"  "U" 
// [14,] "A"  "U"  "E"  "K"  "C"  "A"  "R" 
// 
// This is not a normal seriated Playfair right here, because you've got a KK in rows 9/10 and a DD in rows 11/12.
// 
// We have D = 16, T = 1, Q = 0.
// 
// Let "Property Y" of a text be that D >= 16 and T >= 1 simultaneously.
// 
// The results of the simulations for the proportion of permutations of K4 that have Property Y are:
// 
// (1) 1 in 201,000
// (2) 1 in 11,000
// (3) 1 in 35,000
// 
// Basically I feel either the (A) and (B) permutations lead to preposterously "unlikely" high numbers of repeated digrams, trigrams, and quadgrams.
// 
// It seems we should pay most attention to reordering (B) -- looking at the (1) result - random permutations of the characters of K4, most of all.
// I cannot "explain away" a 1 in 201,000 result. It is not like I was looking for algorithms that produced the crib at the right location.
// (B) is more analogous to K3 cryptography.
// 
// ?WXPSOQBWMDDDAOFOROTSNAZIKIUBLGNLWSYTFAZGEKRHGITEPJPWXKKRVUKFQKVKKITUCUQLSBSZTLWNJHAOQBSBJZTUGFCUR
// 
// ?WXPSOQ
// BWMDDDA
// OFOROTS
// NAZIKIU
// BLGNLWS
// YTFAZGE
// KRHGITE
// PJPWXKK
// RVUKFQK
// VKKITUC
// UQLSBSZ
// TLWNJHA
// OQBSBJZ
// TUGFCUR 
// 
// "Only WW" in rows 1/2 is stopping this being a normal Playfair down the columns or seriated Playfair. There are lots of U, V, K in the green rows.
// Gaines mentions W.W. Rouse-Ball had a simple Playfair variant.
// 
// But, having noticed this, what is the next step? 
// "Property X" and "Property Y" describe text which already falls well within typical English statistics. 
// The really interesting property is all the repeated digrams, not just those on even and odd offsets.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
 
/* Knuth shuffle code from rosetta code */

int rrand(int m)
{
	  return (int)((double)m * ( lrand48() / (RAND_MAX+1.0) ));
}
 
#define BYTE(X) ((unsigned char *)(X)) 

void shuffle(void *obj, size_t nmemb, size_t size)
{
	  void *temp = malloc(size);
	    size_t n = nmemb;
	      while ( n > 1 ) {
		          size_t k = rrand(n--);
			      memcpy(temp, BYTE(obj) + n*size, size);
			          memcpy(BYTE(obj) + n*size, BYTE(obj) + k*size, size);
				      memcpy(BYTE(obj) + k*size, temp, size);
				        }
	        free(temp);
} 

int count2(char *s)
{
	int row,col,dcount = 0, dlist[26*26],i;
	int rc = 14, cc = 7;
	char t[98];

	for (i = 0; i < 26*26; i++)
		dlist[i] = 0;	
	for (row = 0; row < 14; row++)
	for (col = 0; col < 7; col++)
		t[col*14 + row] = s[row*7 + col];
	for (row = 0; row < strlen(s)-1; row++)
		{
			int d1,d2;
			d1 = t[row];
			d2 = t[row+1];
			if (d1 >= 'A' && d1 <= 'Z' && d2 >= 'A' && d2 <= 'Z')
				dlist[(d1-'A')*26+d2-'A'] ++;
		}
	for (i = 0; i < 26*26; i++)
		if (dlist[i] > 1) dcount++;
	return dcount;
}

int count3(char *s)
{
	int row,col,dcount = 0, dlist[26*26*26],i;
	int rc = 14, cc = 7;
	char t[98];

	for (i = 0; i < 26*26*26; i++)
		dlist[i] = 0;	
	for (row = 0; row < 14; row++)
	for (col = 0; col < 7; col++)
		t[col*14 + row] = s[row*7 + col];
	for (row = 0; row < strlen(s)-2; row++)
		{
			int d1,d2,d3;
			d1 = t[row];
			d2 = t[row+1];
			d3 = t[row+2];
			if (d1 >= 'A' && d1 <= 'Z' && d2 >= 'A' && d2 <= 'Z' && d3 >= 'A' && d3 <= 'Z')
				dlist[(d1-'A')*26*26+(d2-'A')*26+d3-'A'] ++;
		}
	for (i = 0; i < 26*26*26; i++)
		if (dlist[i] > 1) dcount++;
	return dcount;
}
int count4(char *s)
{
	int row,col,dcount = 0, dlist[26*26*26*26],i;
	int rc = 14, cc = 7;
	char t[98];

	for (i = 0; i < 26*26*26*26; i++)
		dlist[i] = 0;	
	for (row = 0; row < 14; row++)
	for (col = 0; col < 7; col++)
		t[col*14 + row] = s[row*7 + col];
	for (row = 0; row < strlen(s)-3; row++)
		{
			int d1,d2,d3,d4;
			d1 = t[row];
			d2 = t[(row+1)];
			d3 = t[(row+2)];
			d4 = t[(row+3)];
			if (d1 >= 'A' && d1 <= 'Z' && d2 >= 'A' && d2 <= 'Z' && d3 >= 'A' && d3 <= 'Z' && d4 >= 'A' && d4 <= 'Z')
				dlist[(d1-'A')*26*26*26+(d2-'A')*26*26+(d3-'A')*26+d4-'A'] ++;
		}
	for (i = 0; i < 26*26*26*26; i++)
		if (dlist[i] > 1) dcount++;
	return dcount;
}

int main(int argc, char **argv)
{
	int row, col; long i;
	int rc = 14, cc = 7;
	//int perm[14] = { 0,3,1,4,2,5, 6,9,7,10,8,11, 12,13}; // permutation B
	int perm[14] = { 0,3,6,2,5,1,4, 7,10,13,9,12,8,11}; // permutation A
	int pstat2,pstat3,pstat4,pcount=0;
	long co=1e8; // one billion served!
	char k4[]="?OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCARQ";
	char k4_perm[99];
	printf("%d %d %d\n",count2(k4),count3(k4),count4(k4));

	srand48(time(0));

	for (row = 0; row < rc ; row++)
		for (col = 0; col < cc; col++)
			k4_perm[row*cc+col] = k4[perm[row]*cc+col];
	k4_perm[98] = '\0';
	printf("%s\n",k4_perm);
	pstat2 = count2(k4_perm);
	pstat3 = count3(k4_perm);
	pstat4 = count4(k4_perm);
	printf("%d %d %d\n",pstat2,pstat3,pstat4);

	for (i = 0; i < co; i++)
	{
			unsigned char k[98];
			int j;
			for (j = 0; j < 98; j++)
				k[j] = j;
			shuffle(k,98,1);
			for (j = 0; j < 98; j++)
				k4_perm[j] = k4[k[j]];
			if (count2(k4_perm) >= pstat2 && count3(k4_perm) >= pstat3 && count4(k4_perm) >= pstat4) pcount++;
	}
	printf("%ld\n",co/pcount);

	pcount = 0;
	for (i = 0; i < co; i++)
	{
			int j;
			for (j = 0; j < 98; j++)
				k4_perm[j] = lrand48() % 26 + 'A'; // a little bit biased, but no problem
			if (count2(k4_perm) >= pstat2 && count3(k4_perm) >= pstat3 && count4(k4_perm) >= pstat4) pcount++;
	}
	printf("%ld\n",co/pcount);

	pcount = 0;
	for (i = 0; i < co; i++)
	{
			unsigned char k[14];
			int j;
			for (j = 0; j < 14; j++)
				k[j] = j;
			shuffle(k,14,1);
			for (row = 0; row < rc ; row++)
				for (col = 0; col < cc; col++)
					k4_perm[row*cc+col] = k4[k[row]*cc+col];
			if (count2(k4_perm) >= pstat2 && count3(k4_perm) >= pstat3 && count4(k4_perm) >= pstat4) pcount++;
	}
	printf("%ld\n",co/pcount);

	return 0;
}
