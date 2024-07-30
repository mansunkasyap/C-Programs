#include<stdio.h>
#include<stdlib.h>
int * sortArray(int * arr, int l){
     for(int i=0; i<l; i++)
     {
        for(int j=0; j<l; j++)
        {
           if(arr[i]<arr[j])
           {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
           }
        }
     }
     printf("\n");
     return arr;
}
void printArray(int * a, int l){
    for(int i=0; i<l; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main (){
     int ** arr = (int **)calloc(3, 3*sizeof(int));
     int arr1[] = {1, 2, 3};
     int arr2[] = {90, 12, 32};
     int arr3[] = {11, 21, 35};
     arr[0] = arr1;
     arr[1] = arr2;
     arr[2] = arr3;
     for(int i=0; i<3; i++)
     {
        for(int j=0; j<3; j++)
        {
            printf("%d  ", arr[i][j]);
        }
     }
     int * a = sortArray(arr2, 3);
     printArray(a, 3);
}
