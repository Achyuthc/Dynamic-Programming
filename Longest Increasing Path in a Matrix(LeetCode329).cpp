/*Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).*/

class Solution {
public:
    int dp[201][201];
    int a[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int m,n;
    int helper(vector<vector<int>>& mat,int l,int r)
    {
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        else
        {
            int x,y;
            for(int i=0;i<4;i++)
            {
                x=l+a[i][0],y=r+a[i][1];
                if(x>=0&&y>=0&&y<n&&x<m&&mat[x][y]<mat[l][r])
                {
                   dp[l][r]=max(dp[l][r],1+helper(mat,x,y));

                }
        
             }
         
        }
        if(dp[l][r]==-1)
            dp[l][r]=1;
        return dp[l][r];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       memset(dp,-1,sizeof(dp));
       
        m=matrix.size();
        n=matrix[0].size();
        int ans=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                {
                    ans=max(helper(matrix,i,j),ans);
                }
                //cout<<dp[i][j]<<" ";
            }
        }
        return ans;
    }
};
