#!/usr/bin/python3
#import pdb; pdb.set_trace()

import math
import sys

def factorize(number):
    factors = []
    divisor = 2

    while divisor <= math.isqrt(number):
        if number % divisor == 0:
            factors.append(divisor)
            number //= divisor
        else:
            divisor += 1

    if number > 1:
        factors.append(number)

    return factors

def main(file_path):
    with open(file_path, 'r') as file:
        numbers = [int(line.strip()) for line in file]

    for number in numbers:
        factors = factorize(number)
        print(f"{number}={'*'.join(map(str, factors))}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    
    try:
        main(file_path)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)
