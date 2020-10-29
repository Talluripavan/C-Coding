#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int FindMINIMUNdifference(int arr[],int i,int csum,int tot){
    if(i==0)
        return abs((tot-csum)-csum);
        
    return min(FindMINIMUNdifference(arr,i-1,csum+arr[i-1],tot),
                FindMINIMUNdifference(arr,i-1,csum,tot));    
}

int findMin(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
    sum=sum+arr[i];
    
    return FindMINIMUNdifference(arr,n,0,sum);
}

int main() 
{ 
    int arr[] = {3, 1, 4, 2, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "The minimum difference between two sets is "<< findMin(arr, n); 
    return 0; 
} 