/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            int m=triangle[i].size();
            vector<int> v(m+1);
            v[0]=INT_MAX;
            for(int j=0;j<triangle[i].size();j++)
            {
                v[j+1]=INT_MAX;
                v[j]=min(v[j],dp[i][j]+triangle[i+1][j]);
                v[j+1]=min(v[j+1],dp[i][j]+triangle[i+1][j+1]);
            }
            dp.push_back(v);
         }
        for(int j=0;j<triangle[n-1].size();j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};
