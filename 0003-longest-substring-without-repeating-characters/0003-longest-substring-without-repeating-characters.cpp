class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.size();
      int l=0,r=0,maxlen=0;
      vector<int>hash(256,-1);
      while(r<n)
      {
        if(hash[s[r]]!=-1)   //present in map
        {
            if(hash[s[r]]>=l)   //in the range
                l=hash[s[r]]+1;
        }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;   //insert index
        r++;
      }
      return maxlen;
    }
};