class Solution {
public:
    int minSwaps(string s) {
        int swapCount=0;
        int imBalance=0;        // Tracks the imbalance between opening and closing brackets
        for(char ch : s)
        {
            if(ch==']')
            {
                if(imBalance==0)   // No matching opening bracket
                {
                    swapCount++;
                    imBalance++;      // Adjust imbalance to account for the swap
                }
                else
                {
                    imBalance--;         // A matching opening bracket is available, so balance out
                }
            }
            else
            {
                imBalance++;          // Encountered an opening bracket, increase the imbalance
            }
        }
        return swapCount;
    }
};