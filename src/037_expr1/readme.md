# Assignment 037

Calculator Program - Part 1

## Instructions

In this program, you will be practicing using inheritance, virtual methods, and method overriding to complete a simple "calculator" program, which accepts input in "prefix notation". That is, rather than entering "4 + 3" you would enter "(+ 4 3)" 

This problem is split into 3 parts (Assignment 37, 38 & 39).

- Part 1  Expressions are limited to numbers and pluses.
          We don't actually evaluate the expressions, just print them back out 
- Part 2  We add *, -, and /, but still don't evaluate
- Part 3  We add expression evaluation

We have written code for you (in `expr.cpp`) which reads the input, parses it, and makes "Expression" objects appropriately.

You should not need to modify this code at all.

```
Note: There are three different versions of expr.cpp for the three problems.
```

Instead, what you will write for this is the implementation of the `Expression` class and its sub-classes which will represent the math expression that gets read in, as well as provide a way to print it "normally" (in infix notation: 4 + 5) and evaluate it to an integer.

Your code must have the following classes, with the following functionality. 

```
Note: The parsing code relies on the following classes existing, with these exact names. The various Expression types being subtype compatible with Expression, and the classes having the methods and constructors noted below.
```

### Part 1

```cpp

  class Expression
  std::string toString() const = 0; // abstract method
  
  class NumExpression // subclass of Expression
  NumExpression(long) // constructor
  std::string toString() const; // must be implemented

  class PlusExpression // sublass of Expression
  PlusExpression(Expression *lhs, Expression *rhs) // constructor
  std::string toString() const; // must be implemented

```

### Part 2 (Assignment 38)

```cpp
  class MinusExpression // subclass of Expression
  MinusExpression(Expression *lhs, Expression *rhs) // constructor
  std::string toString() const; // must be implemented

  class TimesExpression // subclass of Expression
  TimesExpression(Expression *lhs, Expression *rhs) // constructor
  std::string toString() const; // must be implemented

  class DivExpression // subclass of Expression
  DivExpression(Expression *lhs, Expression *rhs) // constructor
  std::string toString() const; // must be implemented
```

### Part 3 (Assignment 39)

```cpp
  long evaluate() const = 0; // add to class Expression and implement in subclasses
```

You may wish to add other classes or methods as you wish. The various expression types must be a subclass of `Expression`, but do not have to extend it directly: if you see similarity between some of these classes that you wish to pull out into another class "in between" `Expression` and those classes, you are welcome (and encouraged) to.

You will want to implement a lot of this functionality by overriding methods and relying on dynamic dispatch.

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

## Hints
These are a few things we did in our implementation of this, which you may find useful to at least think about. You are free to do or not do these as you see fit. 

You might talk them over with a partner.

  - Our `Expression` class is abstract, and all of the functions in it are abstract.

  - We have one more abstract class that we put in our inheritance hierarchy. This class has some fields which would otherwise appear in each of its subclasses. This class adds one more abstract method which we make use of in `toString`. With this approach, we implement `toString` once in this class, and do not need to override it in any of its subclasses. 

  - A `PlusExpression` would evaluate itself by evaluating its left-hand side, evaluating its right-hand side, and then adding the two results together to get its answer.

  - Think about how your objects will get destructed. Note that the static type of pretty much everything in the parsing/printing code is `Expression*`. 

  - `stringstream` is very nice for implementing `toString`.
