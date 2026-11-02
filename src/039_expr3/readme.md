# Assignment 039

Calculator Program - Part 3

## Instructions

For this problem, you need to declare this abstract method in `Expression`:

```cpp
  long evaluate() const = 0;
```

and implement it in each concrete subclass of `Expression`.

## Copied from Assignment 37

A few concrete details:

 1. Expression representation: An expression (+ E1 E2) will result in a new `PlusExpression` with E1 as its lhs (first argument to the constructor), and E2 as its rhs (second argument to the constructor). This is similar for `MinusExpression`, `TimesExpression`, and `DivExpression`.
 
    A number (like 9 or -27) will result in a new `NumExpression` being created, with the numeric value of that number passed as the argument to the constructor. 

 2. The parser will never make a copy or assign objects by value. You do not need to worry about operator= or the copy constructor. Each expression object will be created with "new", and will be referenced by at most one other Expression object (as either the lhs or rhs of a +,-,*, or /). 

 3. When an expression is destructed, it is responsible for destructing any "sub expressions" (its lhs or rhs) if it has them (Plus, Minus, Times, and Div Expressions). 

 4. The `toString` function should return a string representation of the `Expression` in `infix` notation (that is, if the input is "(+ 4 5)" it should return "(4 + 5)".  Note that for Plus, Minus, Times, and Div, it is difficult to figure out where () are truly needed, you should put them around the output always. So "(+ (+ 4 5) 7)" will result in "((4 + 5) + 7)" 

 5. You will declare your classes in expr.hpp. You can just implement the methods inside the class, or you can implement them in expr.cpp if you wish.

 6. We have provided you with a `sample_input.txt`, and `sample_output.txt` which show sample inputs and the output you should produce respectively. We have also included `invalid_inputs.txt` and `invalid_output.txt` which show some invalid inputs (which the parser handles) and the resulting output.

    ```
    Note: The parser handles the error cases here, but you should make sure that you do not leak memory on the invalid_inputs.txt when the parser cleans up.
    ```

### Hints
These are a few things we did in our implementation of this, which you may find useful to at least think about. You are free to do or not do these as you see fit. 

You might talk them over with a partner.

  - Our `Expression` class is abstract, and all of the functions in it are abstract.

  - We have one more abstract class that we put in our inheritance hierarchy. This class has some fields which would otherwise appear in each of its subclasses. This class adds one more abstract method which we make use of in `toString`. With this approach, we implement `toString` once in this class, and do not need to override it in any of its subclasses. 

  - A `PlusExpression` would evaluate itself by evaluating its left-hand side, evaluating its right-hand side, and then adding the two results together to get its answer.

  - Think about how your objects will get destructed. Note that the static type of pretty much everything in the parsing/printing code is `Expression*`. 

  - `stringstream` is very nice for implementing `toString`.
