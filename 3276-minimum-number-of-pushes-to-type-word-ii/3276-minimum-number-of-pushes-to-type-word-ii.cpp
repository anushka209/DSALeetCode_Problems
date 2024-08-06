class Solution {
public:
    int minimumPushes(string word) {
      vector<int>v(26,0);
      int ans=0;
      for(char &ch:word)
      {
        v[ch-'a']++;
      }
      sort(v.begin(),v.end(),greater<int>());   //descending order
      for(int i=0;i<26;i++)
      {
         int freq=v[i];
         int press=i/8 +1;
         ans+=freq*press;
      }
      return ans;
    }
};