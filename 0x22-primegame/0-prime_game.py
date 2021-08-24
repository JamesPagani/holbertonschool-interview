#!/usr/bin/python3
"""0x22-prime_game.

Maria and Ben are playing a game. Given a set of consecutive integers starting
from 1 up to and including n, they take turns choosing a prime number from the
set and removing that number and its multiples from the set. The player that
cannot make a move loses the game.

They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally, determine who
the winner of each game is.
"""


def isPrime(n):
    """isPrime.

    Determine if n is a prime number.

    Args:
        - n: Number to inspect.

    Return: True if n is a prime number, False if otherwise.
    """
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def isWinner(x, nums):
    """isWinner.

    Play x amount of games and determine who wins the most rounds.

    Args:
        - x: Amount of games to play.
        - nums: The maximum number of game number x.

    Return: Name of the overall winner (Maria or Ben) or None if there's a tie.
    """
    turn = 1  # Maria = 1; Ben = -1
    scores = [0, 0]  # 0: Maria; 1: Ben
    num_set = []

    for game in range(0, x):
        # Create the game's (prime) number set
        num_set.clear()
        for n in range(1, nums[game] + 1):
            if isPrime(n):
                num_set.append(n)
        # Begin the game
        turn = 1
        for i in range(len(num_set)):
            turn *= -1
        # Determine game's winner
        if turn == 1:
            scores[1] += 1
        else:
            scores[0] += 1
    return "Maria" if scores[0] > scores[1] else "Ben"
