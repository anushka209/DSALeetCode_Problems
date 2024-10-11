class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<pair<int,int>>arrival;
        for(int i=0;i<n;i++)
        {
            arrival.push_back({times[i][0],i});
        }
        sort(arrival.begin(),arrival.end());

        // min heap to track available chairs
        priority_queue<int, vector<int>, greater<int>> available_chairs;
        for(int i=0;i<n;i++)
        {
            available_chairs.push(i);
        }

        // priority queue to track when chairs are freed
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> leaveQueue;

        for(auto &arr : arrival)
        {
            int arrTime=arr.first;
            int friendIndex=arr.second;

        while(!leaveQueue.empty() && leaveQueue.top().first <= arrTime)
        {
            available_chairs.push(leaveQueue.top().second);
            leaveQueue.pop();
        }

        //assign smallest available chair
        int chair = available_chairs.top();
        available_chairs.pop();

        if(friendIndex == targetFriend)
            return chair;

        leaveQueue.push({times[friendIndex][1],chair});
        }
        return -1;
    }
};