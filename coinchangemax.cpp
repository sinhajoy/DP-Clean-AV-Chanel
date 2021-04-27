#include "bits/stdc++.h"
using namespace std;

int coinchange(int coin[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[i][j]=0;
            else if(j==0) t[i][j]=1;
            else if(coin[i-1]<=j){
                t[i][j]=(t[i][j-coin[i-1]]+
                            t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int coin[]={1,2,3};
    //int val[]={1,2,3,4,5};
    int n = sizeof(coin)/sizeof(coin[0]);
    int SUM1=5;
    cout << "Max Profit:-" << coinchange(coin,SUM1,n);
    return 0;
}