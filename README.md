# Kryptos K4 testing by Monte Carlo sampling

## Callimahos and Lewis on cryptanalytic diagnosis

_Callimahos_ (["Military Cryptanalytics Part III", 1977](https://www.governmentattic.org/41docs/NSAmilitaryCryptalyticsPt3_1977.pdf)) and _Lewis_ (["Solving Cipher Problems", 1992](https://archive.org/details/solving-cipher-problems.-frank-l-lewis.-c-58_202203)) describe the process of diagnosis of an unknown cipher type.

_Callimahos_, in a chapter entitled “Principles of Cryptodiagnosis”, sets out a process of hypothesis formulation and hypothesis testing.

This involves arrangement and rearrangement of the data to disclose nonrandom characteristics, followed by recognition and explanation of these characteristics.

The chapter headers are: manipulating the data, recognizing the phenomena, and interpreting the phenomena. 

_Lewis_ states that the task of an analyst is finding, measuring, explaining, and exploiting a phenomenon (or phenomena). 

Writing about cipher type diagnosis, he describes the search for “something funny” or “finding the phenomena”.

## Simulation code in this repository

This repository contains code used in my ["Histocrypt 2021" paper "Cryptodiagnosis of Kryptos K4"](https://ecp.ep.liu.se/index.php/histocrypt/article/view/153).

The idea is to measure how unusual some observed phenomena of K4 are by seeing how often the phenomena occur in random permutations of K4.

If you are familiar with C, you can modify the code slightly to investigate whether any phenomena you observe might be in the realm of ["Surely, this cannot be a coincidence!"](http://codebook.org/codebook_solution.pdf).

One of the possible explanations for the observed phenomena is the use of the ["Gromark" cipher](https://www.cryptogram.org/downloads/aca.info/ciphers/Gromark.pdf). 

The program "gt.c" provides code to find all possible Gromark primers of base 10, length 5 which could produce the known plaintext "EASTNORTHEAST" and "BERLINCLOCK" at the given positions in the plaintext, with some plain and cipher alphabet. The standard ACA "Gromark" cipher limits the plain alphabet to be the "standard" A-Z alphabet. 

You can execute it e.g. with "./gt 10 5" and it displays 39 possibilities, one per line: the primer, the number of different digits in the expansion, and the expanded primer (i.e. key).

"grom-ic-list" performs index of coincidence calculations for a given ciphertext as described in Blackman's 1989 paper ["The Gromark Cipher, and some relatives"](https://doi.org/10.1080/0161-118991863961).

## Presentation file, and related videos

[Presentation file (HistoCrypt Amsterdam, June 2022)](https://richardbean.id.au/presentations/2022-06-21%20cryptodiagnosis_of_k4.pdf)

I wrote about the Callimahos book and the cryptodiagnosis chapter at [The Conversation in 2021](https://theconversation.com/declassified-cold-war-code-breaking-manual-has-lessons-for-solving-impossible-puzzles-161595).

I have made three videos about this subject from 2019-2021.

[UQ Lecture, April 2019](https://vimeo.com/342900905)

[Cryptodiagnosis, September 2020](https://vimeo.com/461631245)

[Gromark, October 2021](https://vimeo.com/623038634)

