/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/

class Solution {
public:
    int coinChange(vector<int>& nums, int a) {
          int dp[13][10004];
        int n=nums.size(),sum=0;
        
        for(int i=0;i<=a;i++)
        {
            dp[0][i]=INT_MAX-1;
        }
        
         for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a;j++)
            {
                if(nums[i-1]<=j)
                {
            dp[i][j]=min((1+dp[i][j-nums[i-1]]),(dp[i-1][j]));
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
             
            }
            
        }
        
       if(dp[n][a]==INT_MAX-1)
       {
           return -1;
       }
         return dp[n][a];
    }
    
};
