#include "bits/stdc++.h"
using namespace std;


int profit(int len[],int val[],int W,int n){

    int i=0,j=0;
    int dp[n+1][W+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0) dp[i][j]= 0;
            
            else if(len[i-1]<=j){
                dp[i][j]=max(val[i]+
                                dp[i-1][j-len[i-1]],
                                dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];

}

int main(){
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
    cout << profit(length,price,Max_len,n);
    return 0;
}