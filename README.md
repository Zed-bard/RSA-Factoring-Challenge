# RSA Factoring Challenge

## Overview

This challenge focuses on the RSA Factoring problem, which involves breaking down a given RSA number into its prime factors. The goal is to factorize as many numbers as possible into a product of two smaller numbers.

## Repository Information

- **GitHub Repository:** [RSA-Factoring-Challenge](https://github.com/your-username/RSA-Factoring-Challenge)

## File: factors

### Description

The `factors` file provides a command-line interface to factorize natural numbers into a product of two smaller numbers.

### Usage

```bash
factors <file>
```

- `<file>`: A file containing natural numbers to factor, with one number per line. All lines will be valid natural numbers greater than 1, and the file will always end with a new line.

### Output Format

The output format should be in the form of `n = p * q`, with one factorization per line. Note that p and q don’t have to be prime numbers.

### Example

```bash
factors rsa_numbers.txt
```

### Constraints

- No dependencies: The program should run without any external dependencies.
- Time limit: The program will be terminated after 5 seconds if it hasn't finished.

## File: rsa1

### Description

The `rsa1` file extends the RSA Factoring Challenge by specifying that p and q are always prime numbers, and there is only one number in the files.

### Challenge

Given an RSA number n, find the prime numbers p and q such that `n = p * q`.

### Example

```bash
factors rsa1_numbers.txt
```

### Constraints

- Prime factors: p and q must be prime numbers.
- Single number: Each file contains only one number.

## Challenge

How far can you go in less than 5 seconds? Test the efficiency of your solution within the specified time limit.
