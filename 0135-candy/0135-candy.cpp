class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();

    //    vector<int>left(n);             // taking extra space as array-concept
    //  //  vector<int>right(n);
    //    left[0]=1;
    //    // right[n-1]=1;
    //    for(int i=1;i<n;i++)
    //    {
    //      if(ratings[i]>ratings[i-1])
    //         left[i]=left[i-1]+1;
    //      else
    //         left[i]=1;
    //    }
    //    int curr=1,right=1,sum=max(1,left[n-1]);
    //    for(int i=n-2;i>=0;i--)
    //    {
    //       if(ratings[i]>ratings[i+1])
    //       {
    //         // right[i]=right[i+1]+1;
    //         curr=right+1;
    //         right=curr;
    //       }
    //       else
    //        // right[i]=1;
    //         curr=1;
    //     sum+=max(left[i],curr);
    //    }
    // //    int sum=0;
    // //    for(int i=0;i<n;i++)
    // //    {
    // //      sum+=max(left[i],right[i]);
    // //    }
    //    return sum;

    // -------------- slope method----------
        int sum=1,i=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i-1]>ratings[i])
            {
                sum+=down;
                i++;
                down+=1;
            }
            if(down>peak)
                sum+=down-peak;
        }
      return sum;
    }
};