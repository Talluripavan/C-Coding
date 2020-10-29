
#include<iostream> 
#include<cstring> 
#include<cstdlib> 
using namespace std; 
int max(int a, int b)
{
	return a > b? a: b;
}
int lcs(char *x,char *y,int m,int n){
    int arr[m+1][n+1];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0)
                arr[i][j]=0;
            else if(x[i-1]==y[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
                
        }
    }
    return arr[m][n+1];
}


int main() 
{ 
char X[] = "AGGTAB"; 
char Y[] = "GXTXAYB"; 
int m = strlen(X); 
int n = strlen(Y); 
printf("LENTH=%d\n",lcs(X, Y, m, n)); 
return 0; 
} 
