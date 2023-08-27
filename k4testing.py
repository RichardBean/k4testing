import random

ITERATIONS = 10**6
DISTANCE = 1

def minor_difference(letter1, letter2):
    difference = abs(ord(letter1) - ord(letter2))
    return min(difference, 26 - difference)

def sum_minor_differences(text):
    known_plaintext_positions = list(range(21, 34)) + list(range(63, 74))
    known_plaintext = "EASTNORTHEASTBERLINCLOCK"
    
    sum_values = sum(
        minor_difference(text[known_plaintext_positions[i]], text[known_plaintext_positions[j]])
        for i in range(len(known_plaintext) - 1)
        for j in range(i+1, len(known_plaintext))
        if minor_difference(known_plaintext[i], known_plaintext[j]) <= DISTANCE
    )
    
    return sum_values

ciphertext = "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR"
sum_ciphertext = sum_minor_differences(ciphertext)
print(f"Sum of minor diffs of CT letters where PT minor diff <= {DISTANCE}: {sum_ciphertext}")

count = sum(
    1 for _ in range(ITERATIONS)
    if sum_minor_differences(''.join(random.sample(ciphertext, len(ciphertext)))) <= sum_ciphertext
)
print(f"probability of occurring at random: 1 in {ITERATIONS/count}")

# 24 August 2023
#
# "Please explain what this program does" ...
# 
# Claude
# 
# This Python code appears to be implementing a statistical analysis on a ciphertext to determine if it has the expected characteristics of being encrypted with a simple substitution cipher.
# 
# The key aspects are:
# 
#     It defines a function minor_difference that calculates the minor difference between two letters, which is the smallest difference between their ASCII values (either forwards or backwards through the alphabet).
#     It defines a function sum_minor_differences that calculates the sum of minor differences between letters in the ciphertext at known plaintext positions, but only where the corresponding letters in the known plaintext have a minor difference less than or equal to a specified distance.
#     It calculates this sum for the given ciphertext.
#     It then randomly shuffles the letters of the ciphertext repeatedly, calculating the sum each time.
#     It counts how many times the random sum is less than or equal to the actual ciphertext's sum.
#     From this it estimates the probability that a random ciphertext would have a sum less than or equal to the actual ciphertext's sum.
# 
# So in summary, it is using the known plaintext to pick out letters in the ciphertext that should have low minor differences based on the plaintext. It summarizes this in a single numeric value. It then checks if a random shuffling of letters is likely to produce a similar summary value. If the probability is low, it suggests the ciphertext is not random and has the expected characteristics of being a simple substitution cipher.
# 
# GPT-4, Aug 3 version
# 
# 
# This program seems to be trying to determine whether a particular arrangement of letters in a given ciphertext, "OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCAR", has a statistically significant relationship to a known plaintext, "EASTNORTHEASTBERLINCLOCK", based on a certain measure of letter "closeness".
# 
# Let's break it down step by step:
# 
#     minor_difference(letter1, letter2):
#         This function calculates the "minor" difference between two letters. The difference is defined as the absolute difference in their Unicode (or ASCII) code points. However, since letters wrap around (i.e., after 'Z' comes 'A'), the function considers the smaller of the two possible differences. For example, the difference between 'A' and 'Z' is 1 (i.e., 'Z' to 'A').
# 
#     sum_minor_differences(text):
#         This function calculates the cumulative "minor difference" between each pair of letters in the known_plaintext ("EASTNORTHEASTBERLINCLOCK") which have a minor difference less than or equal to DISTANCE (which is 1), and compares that to the equivalent pair of letters in the text input.
#         known_plaintext_positions are the positions of the known plaintext in the ciphertext. The ranges 21 to 34 and 63 to 74 seem to correspond to the positions of "EASTNORTHEAST" and "BERLINCLOCK" respectively.
# 
#     Calculation of sum_ciphertext:
#         This calculates the cumulative minor difference of the given ciphertext based on the known plaintext and its positions. The result is printed out.
# 
#     Simulation:
#         The program then randomizes the ciphertext (i.e., shuffles the letters) ITERATIONS times (which is 10^6 or 1 million times) and checks how often the sum of minor differences of this randomized text is less than or equal to that of the original ciphertext. This simulation gives an idea of how often the given minor difference in the original ciphertext might occur by pure chance (assuming the given ciphertext was indeed randomized).
# 
#     Calculation of probability:
#         The program prints out the likelihood of the sum of minor differences of the original ciphertext occurring by pure chance, given by the ratio: (number of times the randomized sum was less than or equal to the original sum) / ITERATIONS.
# 
# In essence, the program seems to be trying to ascertain the likelihood that the particular arrangement of letters in the given ciphertext has a meaningful relation to the known plaintext, based on the metric of "minor difference" between letters. If the probability is very low, it might indicate that the ciphertext was derived in some meaningful way from the plaintext.
