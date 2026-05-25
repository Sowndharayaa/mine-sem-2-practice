#include <stdio.h>
/*Write a C program that prompts the user for a user-defined number of integers
to be stored in an array. Then, the program is to determine and output the two
largest elements of the array. For this purpose, a C function maximum2(int * p,
int length, int * max1, int * max2) is to be implemented, where the two largest
elements are to be stored in max1 and max2.*/

int main(void){
    int *p,len,*max1,*max2;
    int arr[100] ={0};
    printf("How many numbers?: ");
    scanf("%d",&len);
    
    if(len<100 && len>0){
        int count= 1;
        scanf("%d",&arr[0]);
        p =arr;
        max1 =p;
        max2 =p;
        while(count<len){
            p++;
            scanf("%d",p);
            if(*p>*max1){
                max2 = max1;
                max1 = p;
            }else if(*p>*max2){
                max2=p;
            }
            count++;
        }
    }
    printf("max1 is %d, max2 is %d, located at %p and %p respectively",*max1, *max2,max1,max2);
}