class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size() == 0 || nums[0] != 1 ? 1 : 2;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == i+1 || nums[i] > nums.size() || nums[i] <= 0)
                continue;
            else{
                if(nums[nums[i]-1] == nums[i])
                    nums[nums[i]-1] = 0;
                swap(nums[nums[i]-1],nums[i]);
                --i;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};