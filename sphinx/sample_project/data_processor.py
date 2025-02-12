# data_processor.py
"""
Data processing utilities.

This module provides functions to process and analyze data.
"""

def filter_even_numbers(numbers):
    """Filter even numbers from a list.

    :param numbers: List of integers
    :return: List of even integers
    """
    return [num for num in numbers if num % 2 == 0]

def calculate_average(numbers):
    """Calculate the average of a list of numbers.

    :param numbers: List of numbers
    :return: Average of the numbers
    :raises ValueError: If the list is empty
    """
    if not numbers:
        raise ValueError("The list of numbers is empty.")
    return sum(numbers) / len(numbers)

def find_max(numbers):
    """Find the maximum value in a list of numbers.

    :param numbers: List of numbers
    :return: Maximum value
    """
    return max(numbers)

