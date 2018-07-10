class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        std::vector<std::vector<int>> ATranspose;
        for(int i = 0; i < A[0].size(); ++i){
            std::vector<int> newRow;
            for(int j = 0; j < A.size(); ++j){
                newRow.push_back(A[j][i]);
            }
            ATranspose.push_back(newRow);
        }
        return ATranspose;
    }
};