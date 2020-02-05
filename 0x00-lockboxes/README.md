# Lockboxes
There are n number of lockboxes. Each box is labeled from 0 - (n-1).
Each box may contain the key to another box. Boxes are lists of numbers.
The numbers in a box correspond with the index of another box. For example,
if box 0 contains a list with the numbers 3, 4, and 5, then boxes 3, 4, and 5 can 
be unlocked to look for more keys. The 0th box is unlocked from the start.

The above algorithm recieves as parameters a list of lists (list of boxes),
and returns true if all boxes can be unlocked given starting access to box 0,
otherwise false.

## assumptions
* all keys are integers
* all keys are positive numbers
