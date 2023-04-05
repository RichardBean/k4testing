// Multi-threaded version of original
//
// compile with: g++ -o kperm -O3 -fopenmp kperm.cpp
// 
// Consider the known K4 plaintext "EAST NORTH EAST BERLIN CLOCK" which is 24 letters. Look at all possible pairs of letters
// for each plaintext letter where the letters are 0 or 1 apart. 
//
// What is the sum of the minor differences between the corresponding plaintext letters?
//
// Then: if we permuted the ciphertext randomly, how unusual is that pattern?
//
// That is, in what proportion of randomly permuted
// ciphertexts would we see a sum less than or equal to the original sum
// 
// depending on the value in the "if (md...)" line, with ITER = 1e9 we get
//
// 0 - sum = 47, prob = 1 in 237
// 1 - sum = 128, prob = 1 in 5031
// 2 - sum = 246, prob = 1 in 1266
// 3 - sum = 376, prob = 1 in 273
// 4 - sum = 520, prob = 1 in 82

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <omp.h>

const int ITER = 1e7;

int
md (char a, char b)
{
  int x = std::abs (a - b) % 26;
  return std::min (x, 26 - x);
}

int
bean5 (const std::string & t)
{
  std::vector < int >a
  {
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 63, 64, 65, 66, 67,
      68, 69, 70, 71, 72, 73};
  std::string pl = "EASTNORTHEASTBERLINCLOCK";
  int sum = 0;

  for (int i = 0; i < 23; ++i)
      for (int j = i + 1; j < 24; ++j)
	  if (md (pl[i], pl[j]) <= 1) // try 0-4 here
	      sum += md (t[a[i]], t[a[j]]);

  return sum;
}

void
shuffle (std::string & s, std::mt19937 & gen)
{
  std::shuffle (s.begin (), s.end (), gen);
}

int
main ()
{
  std::string k4 =
    "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR";

  auto seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
  int sum_k4 = bean5 (k4);
  std::cout << "sum: " << sum_k4 << std::endl;

  int pcount = 0;

#pragma omp parallel reduction(+:pcount)
  {
    std::mt19937 gen (seed + omp_get_thread_num ());
    std::string local_k4 = k4;

#pragma omp for
    for (int i = 0; i < ITER; ++i)
      {
	shuffle (local_k4, gen);
	pcount += bean5 (local_k4) <= sum_k4;
      }
  }

  std::cout << "probability of occurring at random: 1 in " << ITER /
    pcount << std::endl;

  return 0;
}
