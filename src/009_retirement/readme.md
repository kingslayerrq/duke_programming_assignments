# Assignment 009

Link, hero of Hyrule, is ready to lay down the Master Sword and turn over the protection of Hyrule to someone else - anyone else. Before he can do that, he needs some help determining if he has collected enough `rupees` (the currency of Hyrule) to fund a lavish, heroic lifestyle.

Link approaches you, famed programmer of Hyrule, and requests you create a "retirement savings" calculator to be used by future Heroes of Hyrule.

For this heroic effort, Link promises you will receive a generous fee...from Princess Zelda...in the future...probably.

Lucky for you, Hyrule does not experience inflation! We'll remove the effects of inflation by keeping everything in "today's rupees" and using a "Rate of Return" that is in terms of "more than inflation."

## Instructions

1. Create a file called `retirement.c`.  Include the usual header files (`stdlib.h` and `stdio.h`) at the top.

2. We're going to model both savings (while working) and expenditure (while retired).

    It turns out that both of these require the same basic information, so we will make a `struct` to represent that.

    Declare a struct `_retire_info` which has three fields: 
    ```
    (1) an int called "months" for the number of months it is applicable to 

    (2) a double called "contribution" for how many rupees are contributed (or spent if negative) from the account per month 

    (3) a double called "rate_of_return" for the rate of returns
    ```

    After you have declared this struct, use `typedef` to make `retire_info` another name for this struct.

3. Write the function
    ```c
    void retirement (int startAge, double initial, retire_info working, retire_info retired) 
    ```

    This function should perform two tasks (which are similar---look for a chance to abstract something out into a function!).

    - First, it should compute the retirement account balance each month while a Hero of Hyrule is working.  To do this, you need to calculate the account balance increase from returns (balance * rate of return), and add that to the current balance.  
    
        You then need to add the monthly contribution to the balance.
    
        For example, if you have $1,000 in the account, earn a 0.5% rate of return per month, and contribute $100 per month, you would compute 1000 * 0.005 = $5 in interest earned. 
        
        You would then add this plus the monthly contribution to the balance to end up with $1105 in the account at the end of the month.
    
        At the start of each month (before the balance changes), you should print out the current balance with the following format:

        ```c
        "Age %3d month %2d you have $%.2f\n"
        ```
    
        The first two format conversions are the saver's age in years and months.
        
        The third format conversion is the account balance.
        
        This calculation goes on for the number of months specified in the "working" `retire_info` structure.  


    - Second, you should perform a very similar calculation for each month of retirement.  
    
        The difference here is that you will use the information in the "retired" retire_info structure instead of the information in the "working" structure. As with working, you should print out the same information as before.

        > [Hint: since you are performing a very similar computation, think about how you can abstract that part out into a function, and re-use it, rather than re-writing it]  

    
4. Write a `main` function which computes the retirement assuming

    - Working
        ---
        Months: 489

        Per Month Savings: $1000
    
        Rate of Return:  4.5% per year ( 0.045/12 per month) 
    
    - Retired
        ----
        Months: 384
    
        Per Month Spending: -4000
    
        Rate of Return: 1% per year ( 0.01/12 per month) 
    
    - Starting Conditions
        ---
        Age: 327 months (27 years, 3 months)
    
        Savings: $21,345

5. Compile your code (we provided a Makefile) and test it (we provided the output: `retirement_ans.txt`).

6. Commit your changes and submit as normal
