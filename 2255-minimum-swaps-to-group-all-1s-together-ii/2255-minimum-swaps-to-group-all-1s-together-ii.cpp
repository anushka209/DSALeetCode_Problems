class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n=nums.size();
       vector<int>temp(2*n);
       for(int i=0;i<2*n;i++)
       {
        temp[i]=nums[i%n];
       } 

       int totalOnes=0;
       for(int i=0;i<n;i++)
       {
        if(nums[i]==1)
            totalOnes++;
       }

       int i=0,j=0;
       int currentOnes=0,maxCount=0;
       while(j<2*n)
       {
        if(temp[j]==1)
            currentOnes++;
        if(j-i+1>totalOnes)
        {
            currentOnes-=temp[i];
            i++;
        }
            maxCount=max(maxCount,currentOnes);
            j++;
       }
     return totalOnes-maxCount;
    }
};