class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
       long inc=0,dec=0,op=0;
       for(int i=0;i<nums.size();i++)
       {
         long diff=target[i]-nums[i];
         if(diff>0)             //increment
         {
            if(inc<diff)
                op+=diff-inc;
            inc=diff;
            dec=0;
         }
         else if(diff<0)
         {
            if(dec< -diff)
                op+=-diff-dec;
            dec=-diff;
            inc=0;
         }
         else
            inc=dec=0;
       }
       return op;
    }
};