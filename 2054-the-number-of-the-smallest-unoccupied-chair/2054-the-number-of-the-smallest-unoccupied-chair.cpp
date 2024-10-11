class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied;  // {deptTime,chair no}
        priority_queue<int, vector<int>, greater<int>> free;       // min index chair available

        int targetArrival=times[targetFriend][0];
        int chairNo=0;
        sort(times.begin(),times.end());    // based on arrival time

        for(int i=0;i<n;i++)
        {
            int arr=times[i][0];
            int dept=times[i][1];

            while(!occupied.empty() && occupied.top().first<=arr)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty())       // no free chairs available
            {
                occupied.push({dept,chairNo});
                if(arr==targetArrival)
                    return chairNo;
                chairNo++;
            }
            else
            {
                int leastChair=free.top();
                free.pop();
                if(arr==targetArrival)
                    return leastChair;
            occupied.push({dept,leastChair});
            }
        }
    return -1;
    }
};