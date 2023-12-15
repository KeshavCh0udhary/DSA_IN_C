#include<stdio.h>

int factorial(int number){
    
    if(number == 0|| number == 1){
        return 1;
    }

    return number* factorial(number-1);

}

int main(){
    int n;
    printf("Enter number\n");
    scanf("%d",&n);
    if(n <= 0){
        printf("Please enter positive number\n");
    }
    int output = factorial(n);
    if(output != -1){
        printf("Factorial of %d is %d",n,factorial(n));
    return 0;
}