
/*You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.*/
class Solution {
public:
    bool possible(string &a,string &b)
    {
        int cnt=0;
        int i1=0,i2=0;
        while(i1<a.size()&&i2<b.size())
        {
            if(a[i1]!=b[i2])
				i1++,cnt++;
            else
				i1++,i2++;
            if(cnt>1)
                return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
		//stores the index of word with size like size 1 words index in v[1]
        vector<vector<int>> v(17);
		//stores the longest word ends at words[v[i][j]]
        vector<vector<int>> dp(17);
		//build index list 
        for(int i=0;i<words.size();i++)
        {
            v[(int)words[i].size()].push_back(i);
            dp[(int)words[i].size()].push_back(1);
        }
        int ans=1;
        for(int i=2;i<=16;i++)
        {
            for(int k=0;k<v[i].size();k++)
            {
				//look for all words with size i-1
                for(int p=0;p<v[i-1].size();p++)
                {
					//if word with size i is build by word with size i-1 by adding single character
                    if(possible(words[v[i][k]],words[v[i-1][p]]))
                    {
                        dp[i][k]=max(dp[i][k],dp[i-1][p]+1);
                    }
                    ans=max(ans,dp[i][k]);
                }
            }
        }
        return ans;
        
    }
};
