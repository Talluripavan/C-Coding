#include<stdio.h>
#include<stdlib.h>
void Mergearray(int arr[],int l,int m,int n){
    int n1=m-l+1;
    int m1=n-m;
    int ll[n1];
    int rr[m1];
    
    for(int p=0;p<n1;p++)
        ll[p]=arr[l+p];
    for(int p=0;p<m1;p++)
        rr[p]=arr[m+p];
        
    int i=0,j=0,k=0;
    while(i<n1 && j<m1){
        if(ll[i]<rr[j]){
            arr[k]=ll[i];
            i++;
            k++;
        }
        else{
            arr[k]=rr[j];
            j++;
            k++;
        }
    }
    while(i<=n1){
        arr[k]=ll[i];
        i++;
        k++;
    }
      while(l<=m1){
        arr[k]=rr[j];
        j++;
        k++;
    }
  return;  
}


void mergeSort(int a[],int l,int n){
    
    if(l<n){
    int m=(l+(n-1))/2;
    
    mergeSort(a,l,m);
    mergeSort(a,m+1,n);
    
    Mergearray(a,l,m,n);
    }
return;
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1); 
  
    printArray(arr, arr_size); 
    return 0; 
} 