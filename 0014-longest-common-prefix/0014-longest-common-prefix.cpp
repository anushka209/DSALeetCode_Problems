class Solution {
public:
    // string common(string s1,string s2)
    // {
    //     int n=min(s1.size(),s2.size());
    //     string new_str;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(s1[i]==s2[i])
    //             new_str[i]=s1[i];
    //         else
    //             break;
    //     }
    //     return new_str;
    // }

    string longestCommonPrefix(vector<string>& strs) {
       string ans="";
       int n=strs.size();
       sort(strs.begin(),strs.end());
       int i=0;
       while(i<strs[0].size() && strs[0][i]==strs[n-1][i])
       {
         ans+=strs[0][i];
         i++;
       }
       return ans;
    }
};