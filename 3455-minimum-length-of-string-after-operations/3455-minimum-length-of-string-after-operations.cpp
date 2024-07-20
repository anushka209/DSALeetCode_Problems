class Solution {
public:
    int minimumLength(string s) {
       int n=s.size();
       int count=0;
       unordered_map<char,int>mpp;
       for(int i=0;i<n;i++)
       {
         mpp[s[i]]++;
         if(mpp[s[i]]>2)
         {
            count+=2;
            mpp[s[i]]=mpp[s[i]]-2;
         }
       }
       return n-count;
    }
};