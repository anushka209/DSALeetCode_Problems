class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // if(sentence1.size()<sentence2.size())
        //     swap(sentence1,sentence2);
        // vector<string>v1,v2;

        // stringstream ss1(sentence1);
        // string token;
        // while(ss1>>token)
        //     v1.push_back(token);

        // stringstream ss2(sentence2);
        // while(ss2>>token)
        //     v2.push_back(token);

        // int i=0,j=v1.size()-1;  //sentence1 {v1}
        // int k=0,l=v2.size()-1;  //sentence2 {v2}

        // while(i<v1.size() && k<v2.size() && v1[i]==v2[k])
        // {
        //     i++; k++;
        // }
        // while(l>=k && v1[j]==v2[l])
        // {
        //     j--; l--;
        // }
        // if(l<k) return true;
        // return false;

        //---------------------using deque-------------------

         if(sentence1.size()<sentence2.size())
            swap(sentence1,sentence2);
        deque<string>d1,d2;

        stringstream ss1(sentence1);
        string token;
        while(ss1>>token)
            d1.push_back(token);

        stringstream ss2(sentence2);
        while(ss2>>token)
            d2.push_back(token);

        while(!d1.empty() && !d2.empty() && d1.front()==d2.front())
        {
            d1.pop_front();
            d2.pop_front();
        }
        while(!d1.empty() && !d2.empty() && d1.back()==d2.back())
        {
            d1.pop_back();
            d2.pop_back();
        }
        return d2.empty();
    }
};