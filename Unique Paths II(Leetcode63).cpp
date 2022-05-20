/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 */

class Solution {
public:
    int dp[101][101];
    int ways(vector<vector<int>> grid,int i,int j)
    {
        if(i==0&&j==0)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=0;
        if(i-1>=0&&grid[i-1][j]==0)
            dp[i][j]+=ways(grid,i-1,j);
        if(j-1>=0&&grid[i][j-1]==0)
            dp[i][j]+=ways(grid,i,j-1);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        if(grid[0][0]==1||grid[m-1][n-1]==1)
            return 0;
        return ways(grid,m-1,n-1);
        
        
    }
};
