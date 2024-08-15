class Solution {
public:

 int mini(vector<int> bloomday)
{
	int n=bloomday.size();
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		ans=min(ans,bloomday[i]);
	}
	return ans;
}

int maxi(vector<int> bloomday)
{
	int n=bloomday.size();
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,bloomday[i]);
	}
	return ans;
}

int minDays(vector<int>& bloomDay, int m, int k) {
 int n=bloomDay.size();
 long long val=m * 1LL * k * 1LL;
	if(n<val)
		return -1;
	int s=mini(bloomDay);
	int e=maxi(bloomDay);
    int ans=e;
    while(s<=e)
    {
    int mid=s+(e-s)/2;
	 if(possible(bloomDay,mid,k,m))
		{
			ans= mid;
            e=mid-1;
		}
        else
         s=mid+1;
    }
	return ans;
}

bool possible(vector<int> bloomDay,int day,int k, int m)
{
	int count=0,bouquets=0;
	int n=bloomDay.size();
	for(int i=0;i<n;i++)
	{
		if(bloomDay[i]<=day)
			count++;
		else
		{
			bouquets+=count/k;
			count=0;
		}
	}
		bouquets+=count/k;
		if(bouquets>=m)
			return true;
		else
			return false;
}
};