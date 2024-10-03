class Solution {
public:
    double myPow(double x, int n) {
        int m=n;
        n=abs(n);
        double ans=1;
        while(n>0)
        { 
            if(n%2==1)          // odd
            {
                ans=ans*x;
                n=n-1;
            }
            else
            {                  // even
                n=n/2;
                x=x*x;
            }
        }
        if(m<0)
            ans=1.0/ans;
        return ans;
    }
};