#include<stdio.h>

long long calculate_power(long long n,long long x){
    
    if(x == 0) return 1;
    
    long long small = calculate_power(n,x/2);
        
    small *= small;
        
    if(x % 2 != 0) small *= n;
        
    return small;
        
}


int main(){
    

    int n;
    printf("How many numbers do you want enter \n");
    scanf("%d",&n);
    int val,t = n;
    long long int output = 0;
    while(t --> 0){
        scanf("%d",&val);
        
        output += calculate_power(val,n);
        printf("%lld\n",calculate_power(val,n));
    }
    printf("%lld",output);
    return 0;

}