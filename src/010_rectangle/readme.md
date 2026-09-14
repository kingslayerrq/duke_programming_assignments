# Assignment 010

You're working at `SuperAmazing Game Company Inc.` on their real-time strategy game `Hectares: Corn v Wheat`.

Players compete in a pitched strategy battle to out-produce their opponents by laying out farm fields in rectangular, overlapping patterns. Overlapping farm fields produce biological mutants, which negatively affect growth.

You've been tasked with calculating the region of overlap given two rectangles.

For this problem, you will be writing a function which takes two rectangles, determines the region in which they overlap (which is also a rectangle), and returns that region.

Before proceeding, think about what the corner case(s) [no pun intended!] in this problem might be.

## Instructions

1. Open the provided file called `rectangle.c`

2. In the `rectangle.c` file, define a struct for rectangles which has 4 fields: x, y, width, and height.  

    Each of these fields should be an `int`.
    
    Use `typedef` so that the typename "rectangle" refers to your struct.

3. One corner case we might have to deal with is if the rectangle's representation is non-standard: if the width or height are negative.

    One way to deal with inputs that come in non-standard formats is to `canonicalize` them -- convert them to the standard (or `canonical`) representation.
    
    First, write the function

    ```c
    rectangle canonicalize(rectangle r);
    ```

    which takes a rectangle, and "fixes" its representation by ensuring that the width and height are non-negative (and appropriately adjusting the x and/or y co-ordinate).  
    
    That is, if your canonicalize function were passed a rectangle with

    `x=3, y=2, width=-2, height=4`

    then it should return a rectangle with

    `x=1, y=2, width=2, height=4`

    as these both describe the same rectangle, but the later is a canonical representation.

    It may be a good idea to stop and test this function before proceeding.
    
    Compile and run your code.
    
    The `main` function we have provided should be useful, as it canonicalizes the rectangles it prints.

4. Now, write the function
    ```c
    rectangle intersection(rectangle r1, rectangle r2)
    ```

    which takes two rectangles (r1, and r2), and returns the rectangle representing the intersection of the two.
    
    Note that there is a corner case where the correct answer is "no intersection".
    
    We have not learned how to represent "no such thing" yet, but we will consider a rectangle with both width and height equal to 0 to mean "no such rectangle".

    In other words, if two rectangles do NOT intersect, return a `zeroed` out rectangle:

    `x=0, y=0, width=0, height=0`
    
    _Note: It is possible for rectangles to share an edge without intersecting_

5. We have provided a `main` function which tests your code, as well as correct output `rectangle_ans.txt` to diff against.

6. Submit the assignment as normal

---
>   Hint:
>
>   Do Step 1 (work an example yourself) four or five times.
>
>    Draw a variety of different ways that rectangles can overlap.
>
>    Use these to help  you think abou the general algorithm for how
>    to determine their overlapping region.
