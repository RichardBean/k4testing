// Gromark Key Checking for Kryptos K4 -- given a base, a primer length, and following the Lagged Fibonacci Generation key method
// of adding the first two key digits together to get the next key digit, which primers can give us EASTNORTHEAST ... BERLINCLOCK
// in the plaintext? e.g. base 8, primer length 4 -- 4 keys; base 10, primer length 5 -- 39 keys

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int
main(int argc, char **argv)
{
	long		c, i, period, pr1, BASE;
	long pow = 1,pr;
	long *primer, *primex;

        if (argc!=3) exit(1); // base length
	BASE = atoi(argv[1]);
	period = atoi(argv[2]);
	primer = malloc(sizeof(long) * MAX);
	primex = malloc(sizeof(long) * MAX);

 for (pr = 0; pr < period; pr++) pow *= BASE;
 //printf("%ld\n",pow); fflush(stdout);

	for (pr = 1; pr < pow; pr++) {
		int bad = 0;
		pr1 = pr;

		for (i = 0; i < MAX; i++)
			primer[i] = 0;
		for (c = 0; c < period; c++) {
			primex[c] = pr1 % BASE;
			pr1 = pr1 / BASE;
		}
		for (i = period - 1; i >= 0; i--)
			primer[(period - 1) - i] = primex[i];

		for (i = period; i < 98; i++)
				primer[i] = (primer[i - period] + primer[i - period + 1]) % BASE;

				if (primer[28] == primer[24]) continue; // h d
				if (primer[33] == primer[24]) continue; // d m
				if (primer[33] == primer[28]) continue; // m h

				if (primer[21] == primer[30]) continue; // a j
				if (primer[21] == primer[64]) continue; // a o
				if (primer[30] == primer[64]) continue; // j o

				if (primer[27] != primer[65]) continue; // g p

				if (primer[68] == primer[25]) continue; // s e

				if (primer[22] == primer[31]) continue; // b k
				if (primer[66] == primer[70]) continue; // q u
				if (primer[26] == primer[71]) continue; // f v
				if (primer[69] == primer[72]) continue; // t w
				if (primer[23] == primer[32]) continue; // c l

				 if (primer[71] == primer[21]) continue; 
				 if (primer[25] == primer[26]) continue; 
				 if (primer[24] == primer[66]) continue;  // 42 apart
				 if (primer[31] == primer[73]) continue; 
				 if (primer[29] == primer[63]) continue; 
				if (primer[32] == primer[33]) continue; 
				if (primer[67] == primer[68]) continue;  

				if (primer[27] == primer[72]) continue;  
				if (primer[23] == primer[28]) continue;  

				//if (primer[32] - primer[23] != primer[33] - primer[28]) continue;
				//if (primer[25] - primer[26] == primer[68] - primer[71]) continue;
				//if (primer[25] == primer[26]) continue; 

				if (primer[26] - primer[71] == primer[30] - primer[21]) continue;
				if (primer[67] - primer[68] == primer[26] - primer[25]) continue;
				if (primer[21] - primer[64] == primer[71] - primer[26]) continue;
				if (primer[26] - primer[71] == primer[25] - primer[21]) continue;
				if (primer[25] - primer[68] == primer[26] - primer[67]) continue; 
				if (primer[33] - primer[32] - primer[28] + primer[23] ) continue; 
				if (primer[25] - primer[26] - primer[68] + primer[71] == 0) continue;
				if (primer[24]- primer[28]- primer[66] + primer[70] == 0) continue;
				if (primer[24]- primer[33]- primer[66] + primer[70]==0) continue;
				if (primer[23]- primer[28]- primer[32] + primer[33]!=0) continue; // very effective!
				if (primer[24] - primer[66] - primer[28] + primer[23] == 0) continue;

				if (primer[21]- primer[25]+ primer[26] - primer[30] + primer[68] - primer[71]==0) continue;
				if (primer[25]- primer[68]- primer[26] + primer[67] + primer[71] - primer[21]==0) continue; // 36076
				if (primer[21]- primer[25]+ primer[26] - primer[64] + primer[68] - primer[71]==0) continue;
				if (primer[68] - primer[64] == primer[71] - primer[26] + primer[25] - primer[21]) continue;
				{
					int n = 0, d[26];
					for (i = 0; i < 26; i++)
						d[i] = 0;
					for (i = 0; i < 97; i++)
						d[primer[i]] ++;
					for (i = 0; i < 26; i++)
						if (d[i]) n++;
								
					printf("%ld %d ",pr,n);
					for (c = 0; c < 98; c++) printf("%c",primer[c]+'0');
					printf("\n"); fflush(stdout);
				}
	}
}
