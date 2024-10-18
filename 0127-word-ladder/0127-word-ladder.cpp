class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      queue<pair<string,int>> q;   //bfs - level order traversal
// Push all values of wordList into a set to make deletion from it easier and also finding word is easier and in less time complexity ie. amotised. 
      unordered_set<string>st(wordList.begin(),wordList.end());
      q.push({beginWord,1});
      st.erase(beginWord);
      while(!q.empty())
      {
         string word=q.front().first;
         int step=q.front().second;
         q.pop();
         if(word==endWord)  return step;     // return answer

         for(int i=0;i<word.size();i++)
         {     // Now, replace each character of ‘word’ with char from a-z then check if ‘word’ exists in wordList.
            char original=word[i];
            for(int ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    q.push({word,step+1});      //increase the length
                    st.erase(word);
                }
            }
            word[i]=original;   //for next conversions bring back to original
         }
      }
      return 0;
    }
};