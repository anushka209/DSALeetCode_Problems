class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        return (s+s).contains(goal);
            
//npos is used as a special value to indicate that no matches or positions were found by some string 
//operations, such as find, rfind, find_first_of, find_last_of, substr, and erase

// For example, if you use the find method to search for a substring in a string, and the substring 
//is not found, the method will return npos as the result
    }
};