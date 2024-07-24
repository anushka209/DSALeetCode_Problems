class Solution {
public:
    int get_mapped(int num,vector<int>& mapping)
    {
        if(num<10)
            return mapping[num];

        int mapNum=0;
        int placeVal=1;
        while(num)
        {
            int digit=num%10;
            int mapDigit=mapping[digit];
            mapNum+=(mapDigit*placeVal);
            placeVal*=10;
            num=num/10;
        }
        return mapNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);     //val & index
        for(int i=0;i<n;i++)
        {
           int ele=nums[i];
        //    string s="";
        //    if(ele==0)
        //         s=to_string(mapping[0]);
        //     else
        //     {
        //         while(ele>0)
        //         {
        //             int digit=ele%10;
        //             s=to_string(mapping[digit])+s;
        //             ele=ele/10;
        //         }
        //     }
        //     int val=stoi(s);

            int val=get_mapped(nums[i],mapping);
            v[i]={val,i};
        }
        sort(v.begin(),v.end());
        vector<int>sortNum;
        for(auto & it:v)
        {
            sortNum.push_back(nums[it.second]);
        }
        return sortNum;
    }
};