#include <stdio.h>
/*Write a C program that prompts the user to enter a user-defined
number of integers, which are stored in an array by means of a
pointer. Then, the program should determine the maximum
element of the array and output both the value and the address
at which it is stored. the address where it is stored. The access
to the elements of the array is to be done with a pointer.*/

/*Method to follow:
1. prompt the user to enter the number of integers
2. the first digit should be stored - *padd - points to the address of the first element
3.*max address of the max
4.increment padd and check if it is the max...stop at zero.*/

int main(void){
    int len,count;
    int arr[100] = {0};
    int *max; //for the maximum number storage
    int *padd;

    printf("Amount of numbers(bw 1 and 100: ");
    scanf("%d",&len);
    printf("\n");
    count = 1;
    if(len>0 &&len<100){
        //then increment in the array
        scanf("%d", &arr[0]);
        padd =arr;
        max = arr;
        if(len>1){
            while(count<len){
                padd++;
                scanf("%d",padd);
                if(*padd>*max){
                    max = padd;
                }
                count++;
            }
        }
        
    }
    printf("Max value is %d located at %p",*max,max);

}