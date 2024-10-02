class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       if(arr.empty())
         return arr;
        vector<int>v=arr;
        sort(v.begin(),v.end());
        map<int,int>mpp;
        int temp=1;
        for(int i=0;i<v.size();i++)
        {
            if(mpp[v[i]]==0)
            {
                mpp[v[i]]=temp;
                temp++;
            }
        }
        for(int i=0;i<arr.size();i++)
            v[i]=mpp[arr[i]];
        return v;
    }
};