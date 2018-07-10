class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        map <int, int> seenValues;
        for(int i = 0; i < nums.size(); ++i){
            if(!seenValues.empty()){
                int temp = target - nums[i];
                map<int,int>::const_iterator it;
                if((it=seenValues.find(temp)) != seenValues.end()){
                    solution.push_back((*it).second);
                    solution.push_back(i);
                    return solution;
                }   
                else{
                    seenValues.insert(pair<int,int>(nums[i],i));
                }
            }
            else{
                seenValues.insert(pair<int,int>(nums[i], i));
            }
        }
    }
};