#include<unordered_set>
#include<unordered_map>
#include<string>

class Solution {
public:
    bool checkIfPalindrome(std::string s, int x, int y){
        while(x <= y){
            if(s[x++] != s[y--])
                return false;
        }    
        return true;
    }
    
    std::string longestPalindrome(std::string s) {
        if(s.length() == 0 || s.length() == 1)
            return s;
        std::unordered_map<char, std::unordered_set<int>> charIndex;
        int currentMax = 0;
        std::string longest = s.substr(0,1);
        for(int i = 0; i < s.length(); ++i){
            if(charIndex.find(s[i]) == charIndex.end()){
                std::unordered_set<int> temp;
                temp.insert(i);
                charIndex.insert(std::pair<char, std::unordered_set<int>>(s[i], temp));
            } else {
                for(int x : charIndex.at(s[i])){
                    bool palindrome = checkIfPalindrome(s, x+1, i-1);
                    if(palindrome){
                        if(currentMax < (i - x)){
                            currentMax = i - x;
                            longest = s.substr(x, i+1-x);
                        } 
                    }
                }
                charIndex.at(s[i]).insert(i);
            }
        }
        return longest;
    }
};