#!/usr/bin/python3
"""Making Change.

Given a pile of coins of different values, determine the fewest number of coins
needed to meet a given amount total.
"""


def makeChange(coins, total):
    """makeChange.

    Return the fewest amount of coins required to reach total.

    Arguments:
    - coins: A list of integers.
    - total: An integer.
    """
    if total <= 0:
        return 0

    value = len(coins) - 1
    num_coins = 0
    coins.sort()

    while total > 0:
        while coins[value] > total and value >= 0:
            value -= 1
        total -= coins[value]
        num_coins += 1

    if total < 0:
        return -1
    return num_coins
