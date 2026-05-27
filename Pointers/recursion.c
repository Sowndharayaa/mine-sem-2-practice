#include <stdio.h>
float recursion(float x,int n){
    if(n==0){
        return 1;
    }else{
        return (x*(recursion(x,n-1)));
    }
}

int main(void){
  float x;
  int n;
  //the power function y =xn should be calculated with recursion
  printf("Type in x: ");
  scanf("%f",&x);
  printf("Type in n: ");
  scanf("%d",&n);
  printf("sol: %f",recursion(x,n));
}