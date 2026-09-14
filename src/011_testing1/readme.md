# Assignment 011

Congratulations - you're still working at `SuperAmazing Game Company Inc.` on their real-time strategy game `Hectares: Corn v Wheat`.

The Project Manager (PM) needs you to verify some programs written by a third party contracting group `TryHard StuDIOs!!!1`. Unfortunately, most of the implementations are broken.

The PM wants you do identify exactly which inputs cause the broken implementations to fail. All you are given are the binaries (compiled programs), so you'll need to run each program and note the input value that causes a failure.

## Instructions

In this assignment, you will be black-box testing a few broken implementations of "isPrime".  You will see that there are four broken implementations of isPrime:

    isPrime-broken1
    isPrime-broken2
    isPrime-broken3
    isPrime-broken4

as well as a correct implementation:

    isPrime-correct

All of these take one command line argument, which is the number to test for primality.  

For example, you might run
```bash
$ ./isPrime-correct 3
3 is prime
```
```bash
$ ./isPrime-correct 4
4 is not prime
```

Your job is to find a test case for each broken implementation which shows that it is not correct - that is, where its behavior differs from that of `isPrime-correct`.

This assignment expects 4 files

    input.1
    input.2
    input.3
    input.4

For each broken program, write the input which breaks the program into its corresponding file (so `input.1` has the command line argument that shows `isPrime-broken1` is broken and `input.2` has the command line argument that shows `isPrime-broken2` is broken...and so forth).

Note that isPrime-correct's behavior is considered correct, and any test case which deviates from it is considered wrong.

You *could* manually discver the results, but there's probably a more efficient approach. You've been provided with a `test.sh` file that should help automating the discovery of broken implementations.
