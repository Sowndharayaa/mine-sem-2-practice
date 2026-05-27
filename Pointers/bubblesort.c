#include <stdio.h>
#include <stdlib.h>
/*Write a C program that reads in a user-defined number of integers and outputs
them in ascending sorted order. To do this, use the bubblesort algorithm by
iterating over the sequence of numbers and swapping adjacent numbers 𝑥𝑥𝑖𝑖, 𝑥𝑥𝑖𝑖+1
in the sequence if 𝑥𝑥𝑖𝑖 > 𝑥𝑥𝑖𝑖+1. Repeat until no more swaps are needed.
Implement two C functions to do this:
void bubblesort(int * p, int length)
void swap(int * a, int * b).*/
void swap(int*a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(int *p,int len){
	int swapped =1;
		for(int i =0;i<len;i++){
			swapped =0;
			for(int j=0;j<len-i-1;j++){
				if(*(p+j)>*(p+j+1)){
					swap(p+j,p+j+1);
					swapped =1;
				}
			
		}
		if(swapped ==0){
			break;
		}
	}
}
void insertionsort(int *p,int len){
	for(int i=1;i<len;i++){
		int key = *(p+i);
		int j =i-1;
		while(j>=0 && *(p+j)>key){
			*(p+(j+1))=*(p+j);
			j--;
		}
		*(p+(j+1))=key;
	}
}
void merge(int *p,int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	//int L[n1], R[n2];
	//using malloc
	int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2 *sizeof(int));
	//copy the data to the temp array, left and right
	for(i=0;i<n1;i++){ //for the left part
		L[i]=p[l+i];
	}
	for(j=0;j<n2;j++){ //for the right part
		R[j]=p[m+j+1];
	}
	//core
	i = 0; //left
	j=0; //right
	k = l; //starts from the left most array, as the first set is already sorted when it is here
	while(i<n1 &&j<n2){
		if(L[i]<=R[j]){ //append which ever is low 
			p[k] = L[i];
			i++;
		}
		else{
			p[k] = R[j]; //
			j++;
		}
		k++; //next
	}
	//if odd numbers, the left and right are not the same so
	while(i<n1){
		p[k]=L[i];
		k++;
		i++;
	}
	while(j<n2){
		p[k]=R[j];
		k++;
		j++;
	}
	//free malloc
	free(L);
	free(R);

}
void mergeSort(int *p, int l, int r){
	if(l<r){ //left length is less than right
		int m =l +(r-l)/2; //minus 1 as the index starts from 0
		mergeSort(p,l,m);//left
		mergeSort(p,m+1,r);
		merge(p,l,m,r);


	}
}
//p[j+1] = *(p(j+1)) means the exact same thing
int is_sorted(int *p,int len){
	//returns 1 if sorted 
	for(int i =0;i<len-1;i++){
		if(p[i+1]<p[i]){
			return 0;
		}
	}
	return 1;
}
void uniq(int *p,int *len){
	if(is_sorted(p,*len) ==0){
		mergeSort(p,0,*(len)-1);
	}
	//for new array
	int j =0;
	for(int i=1;i<*len;i++){//can ignore the first element
		if(p[j]!=p[i]){
			//they both are not same so continue
			j++;
			p[j]=p[i];
		}
		
	}
	//j+1 is the new length , plus one because it starts from 0
	*len = j+1;
}

int main(void){
	int len,*p;
	printf("Type in the amount of numbers: ");
	scanf("%d",&len);
	int count=0;
	int arr[100]={0};
	p=arr;
	if(len>100||len<0){
		return 0;
	}
	printf("Type in the numbers:");
	while(count<len){
		scanf("%d",p);
		p++;
		count++;
	}
	/*
	bubblesort(arr,len);
	printf("Sorted array,bb: ");
	for(int i=0;i<len;i++){
		printf("%d",arr[i]);
	}*/
	/*insertionsort(arr,len);
	printf("Sorted array,is: ");
	for(int i=0;i<len;i++){
		printf("%d ,",arr[i]);
	}*/
/*
	mergeSort(arr,0,len-1);
	printf("fucn %d",is_sorted(arr,len));
	printf("Sorted array,is: ");
	for(int i=0;i<len;i++){
		printf("%d ,",arr[i]);
	}*/

	uniq(arr,&len);
	printf("Sorted array,is: ");
	for(int i=0;i<len;i++){
		printf("%d ,",arr[i]);
	}
	
	return 0;
}