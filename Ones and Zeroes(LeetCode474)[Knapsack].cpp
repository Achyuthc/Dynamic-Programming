/*You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.*/

class Solution {
public:
    int dp[601][101][101];
    vector<int> v;
    int knapsack(int m,int n,int i)
    {
        if(m==0&&n==0)
            return 0;
        if(i<0)
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        if(v[i]%1000<=m&&v[i]/1000<=n)
        {
            dp[i][m][n]=1+knapsack(m-v[i]%1000,n-v[i]/1000,i-1);
        }
        
        dp[i][m][n]=max(dp[i][m][n],knapsack(m,n,i-1));
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp,-1,sizeof(dp));
        for(string s:strs)
        {
            int cnt=0;
            for(char c:s)
            {
                if(c=='0')
                    cnt++;
            }
            v.push_back(cnt+1000*(s.size()-cnt));
        }
        return knapsack(m,n,v.size()-1);
        
    }
};
