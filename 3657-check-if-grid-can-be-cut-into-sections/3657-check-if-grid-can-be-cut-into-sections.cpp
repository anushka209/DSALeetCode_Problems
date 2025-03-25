class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<result.back()[1])   //overlap
            {
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // x axis
        vector<vector<int>>hor;
        // y axis
        vector<vector<int>>ver;
        for(auto &cord : rectangles)
        {
            int x1=cord[0];
            int y1=cord[1];
            int x2=cord[2];
            int y2=cord[3];

            hor.push_back({x1,x2});
            ver.push_back({y1,y2});
        }
        vector<vector<int>>result1=merge(hor);
        vector<vector<int>>result2=merge(ver);

        return result1.size()>=3 || result2.size()>=3;  // we can draw lines
    }
};