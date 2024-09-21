class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    int l[n];
    int r[n];
    stack<int>s,st;
    for(int i=0;i<n;i++)                  //store minimum at left
    {
        while(!s.empty() && arr[s.top()] >=arr[i])    //take equal to avoid duplicate elements we can take it in either of cases
            s.pop();
        if(!s.empty())
            l[i]=s.top();
        else
            l[i]=-1;
        s.push(i);       //store index
    }
                                                 //store maximum at right
   for(int i=n-1;i>=0;i--)                 
    {
        while(!st.empty() && arr[st.top()] >arr[i])
            st.pop();
        if(!st.empty())
            r[i]=st.top();
        else
            r[i]=n;       // store n as index+1
        st.push(i);
    }

    long long sum=0;
    int M=1e9+7;

    for(int i=0;i<n;i++)
    {
        long long total=(i-l[i]) * (r[i]-i);        //total subarray jinka minimum arr[i] hoga
        long long totalsum=total*arr[i];
        sum=(sum+totalsum)%M; 
    }
    return sum;    
    }
};