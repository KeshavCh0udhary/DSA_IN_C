#include <stdio.h>

void reverseList(int array[], int n){
     
    int left = 0, right = n-1,temp;

    while(left < right){
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    
}

void printList(int array[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

}

int main(){
    
    int n;
    printf("Enter the size of the list\n");
    scanf("%d",&n);

    int array[n];
    printf("Enter the %d items seperated by space in the list\n",n);
    for(int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }

    printf("List before reversing is : \n");
    printList(array,n);
    printf("\nAfter reversing the list is : \n");
    reverseList(array,n);
    printList(array,n);

}