# calculator.py
"""
A simple calculator module.

This module provides basic arithmetic operations.
"""

def add(a, b):
    """Add two numbers.

    :param a: First number
    :param b: Second number
    :return: Sum of a and b
    """
    return a + b

def subtract(a, b):
    """Subtract one number from another.

    :param a: First number
    :param b: Second number
    :return: Difference of a and b
    """
    return a - b

def multiply(a, b):
    """Multiply two numbers.

    :param a: First number
    :param b: Second number
    :return: Product of a and b
    """
    return a * b

def divide(a, b):
    """Divide one number by another.

    :param a: First number (numerator)
    :param b: Second number (denominator)
    :return: Quotient of a and b
    :raises ZeroDivisionError: If b is zero
    """
    if b == 0:
        raise ZeroDivisionError("Cannot divide by zero.")
    return a / b

