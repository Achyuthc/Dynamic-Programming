/*There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.*/

class Solution {
public:
      const int c=1000000007;
    int findpath(int m,int n,int maxMove,int startRow,int startColumn,int dp[55][3050])
    {
            int k=startRow*n+startColumn;
            if((startRow>=m||startRow<0||startColumn<0||startColumn>=n)&&maxMove>=0)
            {
                    return 1;
            }
            else if(maxMove<=0)
                    return 0;
                    
            else if(dp[maxMove][k]!=-1)
            {
                    return dp[maxMove][k];
            }
            else
            {
                    long long s=0;
                    s=(s+findpath(m,n,maxMove-1,startRow-1,startColumn,dp))%c;
                    s=(s+findpath(m,n,maxMove-1,startRow+1,startColumn,dp))%c;
                    s=(s+findpath(m,n,maxMove-1,startRow,startColumn-1,dp))%c;
                    s=(s+findpath(m,n,maxMove-1,startRow,startColumn+1,dp))%c;  
                    dp[maxMove][k]=(int)s;
                    return dp[maxMove][k];
            }
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            
             int  dp[55][3050]={0};
             for(int i=0;i<55;i++)
                {
                        for(int j=0;j<3050;j++)
                        dp[i][j]=-1;
                }
            return findpath(m,n,maxMove,startRow,startColumn,dp);
        
    }
};
