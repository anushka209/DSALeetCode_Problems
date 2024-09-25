class Solution {
public:
    string minWindow(string s, string t) {
       int m=s.size();
       int n=t.size();
       int l=0,r=0,count=0,minlen=INT_MAX,sidx=-1;
       vector<int>hash(256,0);
       for(int i=0;i<n;i++)
       {
          hash[t[i]]++;
       }
       while(r<m)
       {
         if(hash[s[r]]>0)
            count++;
         hash[s[r]]--;
         while(count==n)
         {
            if(r-l+1<minlen)
            {
                minlen=r-l+1;
                sidx=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)
                count--;
            l++;
         }
         r++;
       }
       return sidx==-1 ? "" : s.substr(sidx,minlen);
    }
};