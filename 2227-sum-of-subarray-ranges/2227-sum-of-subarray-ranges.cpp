class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
    int n=arr.size();
    int l[n];
    int r[n];
    stack<int>s,st;
    for(int i=0;i<n;i++)                  //store minimum at left
    {
        while(!s.empty() && arr[s.top()] >arr[i])    //take equal to avoid duplicate elements we can take it in either of cases
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
        while(!st.empty() && arr[st.top()] >=arr[i])
            st.pop();
        if(!st.empty())
            r[i]=st.top();
        else
            r[i]=n;       // store n as index+1
        st.push(i);
    }
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long total=(i-l[i]) * (r[i]-i);        //total subarray jinka minimum arr[i] hoga
        long long totalsum=total*arr[i];
        sum=(sum+totalsum); 
    } 
                                                        //find maximum in subarray
    int p[n];
    int q[n];
    stack<int>sp,sq;
    for(int i=0;i<n;i++)                  //store minimum at left
    {
        while(!sp.empty() && arr[sp.top()] <arr[i])    //take equal to avoid duplicate elements we can take it in either of cases
            sp.pop();
        if(!sp.empty())
            p[i]=sp.top();
        else
            p[i]=-1;
        sp.push(i);       //store index
    }
                                                 //store maximum at right
   for(int i=n-1;i>=0;i--)                 
    {
        while(!sq.empty() && arr[sq.top()] <=arr[i])
            sq.pop();
        if(!sq.empty())
            q[i]=sq.top();
        else
            q[i]=n;       // store n as index+1
        sq.push(i);
    }
    long long tsum=0;
    for(int i=0;i<n;i++)
    {
        long long ttotal=(i-p[i]) * (q[i]-i);        //total subarray jinka minimum arr[i] hoga
        long long ttotalsum=ttotal*arr[i];
        tsum=(tsum+ttotalsum); 
    } 
    long long ans=tsum-sum;
    return ans;  
    }
};