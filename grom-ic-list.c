// for given keys and ciphertexts, print out the index of coincidence with the output

// see https:doi.org/10.1080/0161-118991863961
// Deane R. Blackman, "The Gromark Cipher, and some relatives" (CRUX in ACA)
// Cryptologia Volume 13, 1989 - Issue 3, pp273 - 282

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ic         (char *s)
{
	/* ic calculates the index of coincidence of a string */

	int		i         , j, t[26], to = 0, l;
	l = strlen(s);

	for (i = 0; i < 26; i++)
		t[i] = 0;

	for (j = 0; j < l; j++)
		t[s[j] - 'A']++;

	for (i = 0; i < 26; i++)
		to += t[i] * (t[i] - 1);

	return to * 100000 / l / (l - 1);
}


int
main(int argc, char **argv)
{
	int		len       , ss[26][26];
	char           *out, ci[999];
	FILE           *f;

	if (argc != 3)
	{
		printf("%s intext listfile\n", argv[0]);
		exit(1);
	}
	len = strlen(argv[1]);
	strcpy(ci, argv[1]);

	f = fopen(argv[2], "r");
	if (!f)
	{
		printf("error opening %s exiting\n", argv[2]);
		exit(1);
	}
	while (1)
	{
		int		av        , co, b, c, primer[999];
		char		pr        [999];

		fscanf(f, "%s", pr);
		if (feof(f))
			break;

		for (b = 0; b < 26; b++)
			for (c = 0; c < 26; c++)
				ss[b][c] = 0;

		for (b = 0; b < len; b++)
			primer[b] = pr[b] - '0';

		for (b = 0; b < len; b++)
			ss[ci[b] - 'A'][primer[b]]++;

		av = co = 0;
		for (b = 0; b < 26; b++)
		{
			int		pt = 0;
			char		s         [999];
			for (c = 0; c < len; c++)
				if (primer[c] == b)
					s[pt++] = ci[c];
			s[pt] = 0;
			if (pt > 1)
			{
				av += ic(s);
				co++;
			}
		}

		printf("%d ", av / co);
		for (c = 0; c < len; c++)
			printf("%c", '0' + primer[c]);
		printf("\n");
	}
	fclose(f);
	return 0;
}
