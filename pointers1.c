#include <stdio.h>

int main(void){
    int *a,b;
    b = 17;
    a  =&b;
    //Print values and address
    printf("inside the variable b: %i \n",b);
    printf("value pointed to by a: %i \n",*a);
    //Use %p to correctly display memory address
    printf("address of the var b: %p \n",&b);
    printf("inside the varaible a: %p \n",(void*)a);
    printf("address of the pointer vairable a itself: %p \n",&a);
    getchar();

    return 0;
}