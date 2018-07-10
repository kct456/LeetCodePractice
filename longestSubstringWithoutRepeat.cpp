#include<unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> uniqueChar;
        int currentMax = 0;
        
        for(int i = 0; i < s.length(); ++i){
            if(uniqueChar.find(s[i]) == uniqueChar.end()){
                uniqueChar.insert(std::pair<char,int>(s[i], i));
            } else {
                if(currentMax < uniqueChar.size())
                    currentMax = uniqueChar.size();
                i = uniqueChar.at(s[i]) + 1;
                uniqueChar.clear();
                uniqueChar.insert(std::pair<char,int>(s[i], i));
            }
        }
        return currentMax < uniqueChar.size() ? uniqueChar.size() : currentMax;
    }
};