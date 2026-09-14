#include <stdlib.h>
#include <stdio.h>

struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
};

typedef struct _retire_info retire_info;


double helper(int age, double initial, retire_info info){
    printf("Age %3d month %2d you have $%.2f\n", age / 12, age % 12, 
    initial);
    double interest = initial * (info.rate_of_return / 12);
    double savings = initial;
    savings += interest;
    savings += info.contribution;
    return savings;
}
void retirement(int startAge, double initial, retire_info working, retire_info retired){
    int curAge = startAge;
    double curSavings = initial;
    for (int i = 0; i < working.months; i++){
        curSavings = helper(curAge, curSavings, working);
        curAge++;
    }
    for (int i = 0; i < retired.months; i++){
        curSavings = helper(curAge, curSavings, retired);
        curAge++;
    }
}
int main(void){
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045;
    
    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01;

    retirement(327, 21345, working, retired);

}
