/*You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.*/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        unordered_map<char,unordered_set<string>> mp;
        for(auto idea:ideas)
            mp[idea[0]-'a'].insert(idea.substr(1));
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int c1=0,c2=0;
                for(auto &c:mp[i])
                    if(!mp[j].count(c))
                        c1++;
                for(auto &c:mp[j])
                    if(!mp[i].count(c))
                        c2++;
                ans+=c2*c1;
            }
        }
        return ans*2;
        
        
    }
};
