#include<iostream>
#include<vector>
using namespace std;

int knapsack01(vector<int> weights, vector<int> prices,int n , int M){
    int dp[n+1][M+1];
    for(int i =0;i<n+1;i++) dp[i][0]=0;
    for(int j =0;j<M+1;j++) dp[0][j]=0;

    for(int i =1;i<=n;i++){
        for(int j =0;j<=M;j++){
            if(weights[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+prices[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][M];
}

int main(){
    vector<int> weights={10,20,30};
    vector<int> prices={100,140,100};
    int n=weights.size();
    int M=50;
    cout<<knapsack01(weights,prices,n,M);
}