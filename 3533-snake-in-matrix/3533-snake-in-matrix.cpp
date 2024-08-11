class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
       int x=0;  //row
       int y=0;  //column

       for(auto command:commands)
       {
        if(command=="RIGHT")
            y++;
        else if(command=="LEFT")
            y--;
        else if(command=="DOWN")
            x++;
        else if(command=="UP")
            x--;   
       }
       return (x*n)+y;
    }
};