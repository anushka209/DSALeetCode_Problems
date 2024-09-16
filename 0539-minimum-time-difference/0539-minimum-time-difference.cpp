class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes(n);
        for(int i=0;i<n;i++)         //convert time to minutes
        {
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3));
            minutes[i]=h*60+m;
        }
        sort(minutes.begin(),minutes.end());  //sort time
        int minDiff=INT_MAX;
        //find minimum difference in adjacent elements
        for(int i=0;i<n-1;i++)
        {
            minDiff=min(minDiff,minutes[i+1]-minutes[i]);
        }
        // circular difference between last and first element
        minDiff=min(minDiff,24*60-minutes.back()+minutes.front());
        return minDiff;
    }
};