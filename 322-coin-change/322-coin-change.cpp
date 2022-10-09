class Solution {
        int f(int ind ,int t,vector<int>&coins,vector<vector<int>> &dp){
            if(ind==0){
                   if(t%coins[0]==0) return t/coins[0];
                   return 1e9;
            }
            if(t==0) return 0;
            if(dp[ind][t]!=-1) return dp[ind][t];
            int notpick=0+f(ind-1,t,coins,dp);
            int pick=INT_MAX;
            if(t>=coins[ind]){
                pick=1+f(ind,t-coins[ind],coins,dp);
            }
            return dp[ind][t]=min(pick,notpick);
        }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int notpick=0+dp[ind-1][t];
                int pick=INT_MAX;
                if(t>=coins[ind]){
                    pick=1+dp[ind][t-coins[ind]];
                }
                dp[ind][t]=min(pick,notpick);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
        
    }
};