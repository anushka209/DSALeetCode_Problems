class Solution {
public:
    char findKthBit(int n, int k) {
       if(n == 1)
        return '0';
       int len = (1<<n)- 1;   // pow(2,n)-1
       if (k<ceil(len/2.0))
        return findKthBit(n-1,k);
       else if(k==ceil(len/2.0))
        return '1';
       else
       {
         char ch=findKthBit(n-1,len-(k-1));    //handle reverse
         return (ch=='0')?'1':'0';      // handle flip bit
       }
    }
};