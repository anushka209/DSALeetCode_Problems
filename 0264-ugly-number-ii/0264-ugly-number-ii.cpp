class Solution {
public:
    int nthUglyNumber(int n) {
        // vector<int>arr(n+1);          // using dp
        // // arr[i] = ith ugly number
        // // arr[n] = nth ugly number   return arr[n]
        // int i2,i3,i5;

        // //first ugly number
        // i2=i3=i5=1;

        // // first ugly number is 1.
        // arr[1]=1;
        // for(int i=2;i<=n;i++)
        // {
        //     int i2uglyNum=arr[i2]*2;
        //     int i3uglyNum=arr[i3]*3;
        //     int i5uglyNum=arr[i5]*5;
        //     int minUglyNum=min({i2uglyNum,i3uglyNum,i5uglyNum});
        //     arr[i]=minUglyNum;

        //     // jiska minimum hoga uske pointer ko increase krege
        //     if(minUglyNum==i2uglyNum)  i2++;
        //     if(minUglyNum==i3uglyNum)  i3++;
        //     if(minUglyNum==i5uglyNum)  i5++;
        // }
        // return arr[n];

        vector<int>primes={2,3,5};
        priority_queue<long,vector<long>, greater<long>> pq;
        unordered_set<long> st;

        pq.push(1);
        st.insert(1);
        long curr;
        
        for(int i=0;i<n;i++)
        {
           curr=pq.top();
           pq.pop();
           for(auto prime: primes)
           {
              long newCurr = curr*prime;
              if(st.find(newCurr)==st.end())
              {
                pq.push(newCurr);
                st.insert(newCurr);
              }
           }
        }
        return (int)curr;
    }
};