/*Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.*/

class Solution {
public:
    int sum=0;
    
    bool canPartition(vector<int>& nums) {
      for(int i=0;i<nums.size();i++)
      {
          sum+=nums[i];
      }
        if(sum%2==1)
            return 0;
      bool dp[201][20001];
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    dp[i][j]=true;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    if(j-nums[i-1]>=0)
                        dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
                }
            }
        }
        int n=nums.size();
        return dp[n][sum/2];
    }
};
