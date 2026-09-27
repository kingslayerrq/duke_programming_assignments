#include <stdio.h>
#include <stdlib.h>
//        80.      12
int f(int **r, int **s) {

    int temp = **r; // 80
    int temp2 = **s; // 12
    int *z = *r;    // z = &80(p)

    *r = *s;    // r =  &12(q)
    *s = z;     // s = &80(p)

    // r->p->b
    // s->q->a
    // z->a

    printf("**r = %d\n", **r); // 12
    printf("**s = %d\n", **s); // 80

    *z += 3;    // z -> &80 + 3 ->83
    **s -= 8;   // 
    **r -= 19;  // 61

    return temp + temp2;    // no change 92
}

int main(void) {

    int a = 80;
    int b = 12;
    int *p = &a;        //p->a
    int *q = &b;        //q->b
    int x = f(&p, &q);  //r->p  s->q  92

    printf("x = %d\n", x);  // 92
    printf("*p = %d\n", *p);    
    printf("*q = %d\n", *q);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return EXIT_SUCCESS;
}
