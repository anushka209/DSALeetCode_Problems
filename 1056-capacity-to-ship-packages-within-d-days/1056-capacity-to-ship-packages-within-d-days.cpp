class Solution {
public:

int maxi(vector<int> &weights)
{
    int n=weights.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,weights[i]);
    }
    return ans;
}

int sumi(vector<int> &weights)
{
    int n=weights.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans+weights[i];
    }
    return ans;
}


int caldays(vector<int> &weights,int mid)
{
    int day=1,load=0;
    for(int i=0;i<weights.size();i++)
    {
        if(load+weights[i]>mid)
        {
            day++;
            load=weights[i];
        }
        else
        {
            load+=weights[i];
        }
    }
    return day;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int s=maxi(weights);
    int e=sumi(weights);
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int dayreq=caldays(weights,mid);
        if(dayreq<=days)
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