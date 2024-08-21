 #include<bits/stdc++.h>
class Solution {
public:
    int romanToInt(string s) {
       map<char,int>mpp;
       mpp.insert({'I',1});
       mpp.insert({'V',5});
       mpp.insert({'X',10});
       mpp.insert({'L',50});
       mpp.insert({'C',100});
       mpp.insert({'D',500});
       mpp.insert({'M',1000});

       int ans=mpp[s[s.size()-1]];
       for(int i=s.size()-2;i>=0;i--)
       {
        if(mpp[s[i]]<mpp[s[i+1]])
            ans-=mpp[s[i]];
        else
            ans+=mpp[s[i]];
       }
       return ans;
    }
};