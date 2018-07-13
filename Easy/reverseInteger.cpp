class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return 0;
        bool negative = false;
        if(x < 0){
            negative = true;
            x *= -1;  
        }
        while(x % 10 == 0)
            x /= 10;
        std::string s = std::to_string(x);
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            std::swap(s[i++],s[j--]);
        }
        try{
            x = stoi(s);
        }catch(...){
            return 0;
        }
        return negative ? x*-1 : x;
    }
};