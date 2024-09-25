class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n=cardPoints.size();
      int l=0,r=n-1,sum=0,maxSum=0;
      for(int i=0;i<k;i++)
      {
        sum=sum+cardPoints[i];
        maxSum=sum;
      }
      for(int i=k-1;i>=0;i--)
      {
        sum=sum-cardPoints[i];
        sum=sum+cardPoints[r];
        r--;
        maxSum=max(maxSum,sum);
      }
      return maxSum;
    }
};