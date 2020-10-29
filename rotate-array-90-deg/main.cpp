
#include<bits/stdc++.h>
#define N 4
#define n 4
using namespace std;

void rotate90Clockwise(int arr[n][n]){
    
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int tmp=arr[i][j];
            arr[i][j]=arr[n-1-j][i];
            arr[n-1-j][i]=arr[j][n-1-i];
            arr[j][n-1-i]=tmp;
        }
    }
    
    
    
    
}
void printMatrix(int arr[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << arr[i][j] << " "; 
        cout << '\n'; 
    } 
} 
 
int main() 
{ 
    int arr[N][N] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
    printMatrix(arr);                  
    rotate90Clockwise(arr); 
    printMatrix(arr); 
    return 0; 
}