#!/usr/bin/python3
"""
Defines a function that calculates the minimum number of operations
needed to result in exactly n H characters in the file.
"""
def minOperations(n):
    """
    Calculate the minimum number of operations needed to result
    in exactly n H characters in the file.

    Parameters:
        n (int): The target number of H characters.

    Returns:
        int: Minimum number of operations, or 0 if impossible.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
