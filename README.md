# Kryptos K4 testing by Monte Carlo sampling

## Callimahos and Lewis

Callimahos (["Military Cryptanlytics Part III", 1977](https://www.governmentattic.org/41docs/NSAmilitaryCryptalyticsPt3_1977.pdf)) and Lewis (["Solving Cipher Problems", 1992)](https://archive.org/details/solving-cipher-problems.-frank-l-lewis.-c-58_202203) describe the process of diagnosis of an unknown cipher type.

Callimahos, in a chapter entitled “Principles of Cryptodiagnosis”, sets out a process of hypothesis formulation and hypothesis testing.

This involves arrangement and rearrangement of the data to disclose nonrandom characteristics, followed by recognition and explanation of these characteristics.

The chapter headers are: manipulating the data, recognizing the phenomena, and interpreting the phenomena. 

Lewis states that the task of an analyst is finding, measuring, explaining, and exploiting a phenomenon (or phenomena). 

Writing about cipher type diagnosis, he describes the search for “something funny” or “finding the phenomena”.

## Simulation code in this repository

This repository contains code used in the ["Histocrypt 2021" paper "Cryptodiagnosis of Kryptos K4"](https://ecp.ep.liu.se/index.php/histocrypt/article/view/153).

The idea is to measure how unusual some observed phenomena of K4 are by seeing how often the phenomena occur in random permutations of K4.

If you are familiar with C, you can modify the code slightly to investigate whether any phenomena you observe might be in the realm of ["Surely, this cannot be a coincidence!"]([http://answers.codebook.org/node29.html](http://codebook.org/codebook_solution.pdf).

## The presentation file, and related videos

[Presentation file (HistoCrypt Amsterdam, June 2022)](http://elvumgar.fea.st.user.fm/presentations/2022-06-21%20cryptodiagnosis_of_k4.pdf)

I have made some videos about this subject so far ...

[UQ Lecture, April 2019](https://vimeo.com/342900905)
[Cryptodiagnosis, September 2020](https://vimeo.com/461631245)
[Gromark, October 2021](https://vimeo.com/623038634)

