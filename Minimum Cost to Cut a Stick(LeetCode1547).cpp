
/*Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.*/

class Solution {
public:
    int ans=0,dp[105][105]={};
    int helper(vector<int> &cuts,int l,int r)
    {
        if(r-l<=1)
        {
            return 0;
        }
        if(dp[l][r]!=-1)
        {
           return dp[l][r];
        }
        dp[l][r]=INT_MAX;
        for(auto k=l+1;k<r;k++)
        {
dp[l][r]=min(dp[l][r],cuts[r]-cuts[l]+helper(cuts,l,k)+helper(cuts,k,r));
        }
        return dp[l][r];
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
    return helper(cuts,0,cuts.size()-1);
    
    }
};
