class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;       //by bfs ie. level-wise traversal
        q.push({beginWord,1});

    // Push all values of wordList into a set to make deletion from it easier and also finding word is easier and in less time complexity ie. amotised.
        unordered_set<string>st(wordList.begin(),wordList.end());    
        st.erase(beginWord);

        while(!q.empty())
        {
            string word=q.front().first;
            int len=q.front().second;
            q.pop();

            if(word==endWord)  return len;    //return answer

            for(int i=0;i<word.size();i++)
            {
         // Now, replace each character of ‘word’ with char from a-z then check if ‘word’ exists in wordList.
                char orginal=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,len+1});  //increase the length
                    }
                }
                word[i]=orginal;    //for next conversions bring back to original
            }
        }
        return 0;
    }
};