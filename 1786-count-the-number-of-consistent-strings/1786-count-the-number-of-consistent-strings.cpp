class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int hash[26]={0};
        for(int i=0;i<allowed.size();i++)
        {
            hash[allowed[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string ans=words[i];
            bool c=true;
            for(int j=0;j<ans.length();j++)
            {
                if(hash[ans[j]-'a']==0)
                {
                    c=false;
                    break;
                }
            }
            if(c)
                count++;
        }
        return count;
    }
};