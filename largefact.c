#include <stdio.h>
int multiply(int[],int,int);
void factorial(int);
int main(){
	int n;
	scanf("%d",&n);
	factorial(n);
	printf("\n");
	return 0;
}
int multiply(int res[],int x,int res_size){
	int carry=0;
	int prod;
	for(int i=0;i<res_size;i++){
		prod = res[i]*x+carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry!=0){
		res[res_size] = carry%10;
		carry = carry/10;
		res_size++;
	}
	return res_size;
}
void factorial(int n){
	int res[500];
	res[0] =1;
	int res_size = 1;
	for(int x=2;x<=n;x++){
		res_size = multiply(res,x,res_size);
	}
	printf("The Factorial of %d is\n",n);
	for(int i=res_size-1;i>=0;i--){
		printf("%d",res[i]);
	}
}