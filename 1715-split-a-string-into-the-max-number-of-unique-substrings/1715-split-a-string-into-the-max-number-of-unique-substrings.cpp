class Solution {
public:
    void solve(int i,string s,unordered_set<string>& st,int count,int& maxCount)
    {
        if(i>=s.size())
        {
            maxCount=max(maxCount,count);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end())
            {
                st.insert(sub);  // insert
                solve(j+1,s,st,count+1,maxCount);  // explore
                st.erase(sub);  // undo
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int count=0,maxCount=0;
        int i=0;
        solve(i,s,st,count,maxCount);
        return maxCount;
    }
};