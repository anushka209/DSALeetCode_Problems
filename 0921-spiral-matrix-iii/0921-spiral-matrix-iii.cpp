class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};    //E S W N
        vector<vector<int>>ans;
        int steps=0;     //how many steps to take
        int dir=0;       //in dir direction
        ans.push_back({rStart,cStart});

        while(ans.size()<rows*cols)
        {
          if(dir==0 || dir==2)     //0 for east and 2 for west
             steps++;

          for(int count=0;count<steps;count++)
          {
            rStart+=directions[dir][0];
            cStart+=directions[dir][1];

            if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)   //valid rows
                ans.push_back({rStart,cStart});
          }
        dir=(dir+1)%4;
        }
        return ans;
    }
};