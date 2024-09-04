class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(vector<int>& obs: obstacles)
        {
            string key=to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x=0,y=0,maxDis=0;
        //pointing to north
        pair<int,int> dir={0,1};  //for north

        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2) //left 90 deg
                dir={-dir.second,dir.first};
            else if(commands[i]==-1)  //right 90 deg
                dir={dir.second,-dir.first};
            else  //move to direction step by step
            {
                for(int step=0;step<commands[i];step++) 
                {
                    int newX=x+dir.first;
                    int newY=y+dir.second;
                    string newkey=to_string(newX) + "_" + to_string(newY);
                    if(st.find(newkey)!=st.end())
                        break;
                    x=newX;
                    y=newY;
                }
            }
            maxDis=max(maxDis,x*x+y*y);
        }
        return maxDis;
    }
};