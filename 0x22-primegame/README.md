# 0x22. Prime Game

## The Problem
Two people, *Maria* and *Ben* play a game with a set of numbers (from `1` to `n`):

1. Take a prime number
2. Remove that number and its multiples
3. End turn

The player who can't make a move loses.

With this in mind, create an algorithm where this game is played `x` times, with a different `n` value, and determine who wins most of the games.

### Considerations
- The answer file is a ***Python 3.4** script*.
- (Main) function prototype: `def isWinner(x, nums)`
    - `x` is the amount of games to play.
    - `nums` is a list of `n` values for each game.
    - **Return:** The name of the overall winner, or `None` if the winner can't be determined.
    - `x` and `n` will not be larger than 10000.
- *Marie* goes first each game.
- Each game is played optimally (both players pick the next prime number available).

***

***Jaime Andrés Gálvez Villamarin***
