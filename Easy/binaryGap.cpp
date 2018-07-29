class Solution {
public:
    int binaryGap(int N) {
        std::string s = "";
        while(N != 0){
            int temp = N%2;
            s += std::to_string(temp);
            N /= 2;
        }
        std::reverse(s.begin(), s.end());
        int currentMax = 0;
        int last1 = -1;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '1'){
                if(last1 == -1)
                    last1 = i;
            else {
                if(currentMax < i - last1)
                    currentMax = i - last1;
                last1 = i;
            }
          }
        } 
        return currentMax;
    }
};