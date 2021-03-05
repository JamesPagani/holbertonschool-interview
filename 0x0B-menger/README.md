# 0x0B. Menger sponge

## About
The challenge here is to draw a 2D menger sponge on the shell.

This merger sponge has the following properties:
- The size of the sponge is `3 ^ L`, where `L` is the level of the sponge. `L` has to be greater than or equal to zero.
- A sponge of level `L` is a 3x3 square of level `L - 1` sponges.
 - A level 0 sponge is a 1x1 square.

In this project, each grid is drawn by the character `#`.

**Jaime Andres Galvez Villamarin**
