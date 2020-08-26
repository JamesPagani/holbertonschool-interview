# Linked list palindrome

## Information
- Language: C (Compiled in gcc 4.8.4)
- OS: Ubuntu 14.04 LTS (Trusty Thar)

## The challenge
Write a function in C that checks if a singly linked list is a palindrome.
- Prototype: int is_palindrome(listint_t **head);
- Return: 0 if it is not a palindrome, 1 if it is a palindrome
- An empty list is considered a palindrome

### Additional explaination
Normally, a palindrome is a word that is read the same when read fowards (left to right) and backwards (right to left). In this case, a palindrome linked list should be the same if we read if from head to tail as well as tail to head.

## Files
- 0-is_palindrome.c: Contains `is_palindrome` and `listint_t_length`. Checks if a linked list is a palindrome or not.
- lists.h: Contains the prototypes and standard libraries used by 0-is_palindrome.

To avoid giving spoliers, the main file will not be submitted.
