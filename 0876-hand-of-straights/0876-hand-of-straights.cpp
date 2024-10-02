class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      int n=hand.size();
      if(n % groupSize)
        return false;
      map<int,int>mpp;
      for(int i=0;i<n;i++)
         mpp[hand[i]]++;
      while(!mpp.empty())
      {
        int curr=mpp.begin()->first;
        for(int i=0;i<groupSize;i++)
        {
            if(mpp[curr+i]==0)
                return false;
            else
            {
                mpp[curr+i]--;
                if(mpp[curr+i]<1)
                    mpp.erase(curr+i);
            }
        }
      }
      return true;
    }
};