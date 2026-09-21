# Assignment 015

It's finally back to normal at `SuperAmazing Game Company Inc.`

One of the gameplay programmers is looking for some help. They're working on an inventory management system and running into problems identifying the heaviest item in the player's inventory.

The code uses pointers, a feature they're not familiar with, so they need your help.

## Instructions
 
1. Open the provided `arrayMax.c` file and write the function:
    ```c
      int* arrayMax(int *array, int n);
    ```

    which returns a pointer to the largest element in the array passed in (whose length is n).

    If the array has no elements (n is 0), this function should return NULL.

2. Compile and test your code.

    We have provided a main function which will print test cases and your function's answer for them. You should get `99`, `-3`, `425`, `NULL`, and `NULL` for the 5 tests provided.

3. Submit the assignment as normal. 
