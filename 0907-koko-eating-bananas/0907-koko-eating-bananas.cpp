#include<bits/stdc++.h>
class Solution {
public:
   int findMax(vector<int>& piles)
   {
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++)
        maxi=max(maxi,piles[i]);
    return maxi;
   }

  long long calculateHours(vector<int>&piles,int hours)
  {
    long long th=0;
    for(int i=0;i<piles.size();i++)
    {
        th+=(piles[i]/hours)+((piles[i]%hours)!=0);
    }
    return th;
  }

    int minEatingSpeed(vector<int>& piles, int h) {
     int n=piles.size();
     int ans=0;
     int s=1,e=findMax(piles);
     if(h==pow(10,9))
        return n;
     while(s<=e)
     {
        int mid=s+(e-s)/2;
        int totalH=calculateHours(piles,mid);
        if(totalH<=h)
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
     }
     return ans;
    }
};

