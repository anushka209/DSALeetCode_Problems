class Solution {
public:
    int minChanges(int n, int k) {
       k=n^k;
       int count=__builtin_popcount(k);
       n=n&k;
       int count1=__builtin_popcount(n);
       if(count==count1)
        return count;
        else 
        return -1;
    }
};