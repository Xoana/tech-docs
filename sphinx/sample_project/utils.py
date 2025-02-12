# utils.py
"""
Utility functions.

This module provides general utility functions.
"""

def read_file(file_path):
    """Read the contents of a file.

    :param file_path: Path to the file
    :return: Contents of the file as a string
    """
    with open(file_path, 'r') as file:
        return file.read()

def write_file(file_path, content):
    """Write content to a file.

    :param file_path: Path to the file
    :param content: Content to write
    """
    with open(file_path, 'w') as file:
        file.write(content)

def reverse_string(s):
    """Reverse a given string.

    :param s: Input string
    :return: Reversed string
    """
    return s[::-1]
