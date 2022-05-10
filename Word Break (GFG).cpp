/*Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.*/

class Solution
{
public:
     class Trie
    {
        public:
        bool ends=false;
        Trie *child[26];
    };
    int dp[1103];
    Trie *t=new Trie();
    string str;
    void buildtrie(vector<string> &words)
    {
        Trie *tmp;
        for(string w: words)
        {
            tmp=t;
            for(char c:w)
            {
                if(tmp->child[c-'a']==NULL)
                {
                    tmp->child[c-'a']=new Trie();
                }
                tmp=tmp->child[c-'a'];
            }
            tmp->ends=true;
        }
    }
    int helper(int l)
    {
        if(l==str.size())
            return 1;
        if(dp[l]!=-1)
            return dp[l];
        bool ans=false;
        Trie *tmp=t;
        for(int i=l;i<str.size();i++)
        {
            if(tmp->child[str[i]-'a'])
            {
                tmp=tmp->child[str[i]-'a'];
                if(tmp->ends)
                ans=ans||helper(i+1);
            }
            else
            {
                return dp[l]=ans;
            }
        }
        return dp[l]=ans;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
         memset(dp,-1,sizeof(dp));
        buildtrie(B);
        str=A;
        return helper(0);
    }
};
