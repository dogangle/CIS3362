# CIS 3362: Cryptography and Information Security - Fall 2020

## Assignments: 
This course provides an introduction to cryptography and primarily focuses on the algorithms that are used in classical and modern cryptosystems, as well as the mathematics necessary to understand the underpinnings of those algorithms. Security issues outside of the mathematics of the cryptosystems is not emphasized.

- hill.c - brute-force decryption program to decipher hill cipher
- hw5.c - reads an integer entered by user (between 2 and 1000) and determines if the integer is prime. if it is not prime, report a the least proper divisor. If the number is prime, list out each primitive root of the prime number between 2 and n-1, in numerical order.
- hw6.py - implementation of RSA protocol using given public keys. mesage sent is in radix-64 format. the message encrypted using this program was sent as the solution to a problem, to determine if the program functioned.
- vigenereGuesser.c - helpful program to assist in guessing a vigenere cipher's keyword. user enters the ciphertext and their keyword guess, and the program attempts to decrypt to ciphertext using that keyword.
