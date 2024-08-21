class Solution {
public:
    string frequencySort(string s) {
      vector<int>h(128,0);
      for(auto ch:s)
        h[ch]++;
      auto cmp = [&](char a,char b)
      {
        if(h[a]==h[b])
           return a<b; //sort lexicographically if same
        return h[a]>h[b];  // in decreasing order
      };
      sort(s.begin(),s.end(),cmp);
      return s;
    }
};