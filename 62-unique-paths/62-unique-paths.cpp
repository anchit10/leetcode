class Solution {
    private:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 and j==0) return  1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<=m-1;i++){
            for(int j=0;j<=n-1;j++){
                if(i==0 and j==0){
                    dp[i][j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};