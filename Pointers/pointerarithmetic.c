#include <stdio.h>

int main(void){
    int x =5;
    int *i =&x;
    //when %p is addressed the data type has to be void
    printf("address %p is stored in %i\n",(void*)i,*i);
    i++;
    printf("address %p is stored in %i\n",(void*)i,*i);
    return 0;
}