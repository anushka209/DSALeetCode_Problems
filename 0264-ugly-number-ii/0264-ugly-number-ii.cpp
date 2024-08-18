class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        // arr[i] = ith ugly number
        // arr[n] = nth ugly number   return arr[n]
        int i2,i3,i5;

        //first ugly number
        i2=i3=i5=1;

        // first uglt number is 1.
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            int i2uglyNum=arr[i2]*2;
            int i3uglyNum=arr[i3]*3;
            int i5uglyNum=arr[i5]*5;
            int minUglyNum=min({i2uglyNum,i3uglyNum,i5uglyNum});
            arr[i]=minUglyNum;
            
            // jiska minimum hoga uske pointer ko increase krege
            if(minUglyNum==i2uglyNum)  i2++;
            if(minUglyNum==i3uglyNum)  i3++;
            if(minUglyNum==i5uglyNum)  i5++;
        }
        return arr[n];
    }
};