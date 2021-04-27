#include "bits/stdc++.h"
using namespace std;
int maxprofit(int wt[],int val[],int W,int n){

    int t[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j ==0) t[i][j]=0;
            else if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+
                            t[i-1][j-wt[i-1]],
                            t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int wt[]={5,6,8,9,5};
    int val[]={1,2,3,4,5};
    int n = sizeof(val)/sizeof(val[0]);
    int W=15;
    cout << "Max Profit:-" << maxprofit(wt,val,W,n);
    return 0;
}