class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(s.begin(),s.end());
       sort(g.begin(),g.end());
       int l=0,r=0;
       while(l<g.size() && r<s.size())
       {
         if(s[r]>=g[l])
            l++;
         r++;
       }
       return l;
    }
};