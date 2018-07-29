class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if(A.size() == 0)
            return A;
        std::sort(A.begin(), A.end());
        std::vector<int> advantageA;
        for(int i = 0; i < B.size(); ++i){
            for(int j = 0; j < A.size(); ++j){
                if(A[j] > B[i]){
                    advantageA.push_back(A[j]);
                    A.erase(A.begin()+j);
                    break;
                } else if(j == A.size() - 1){
                    advantageA.push_back(A[0]);
                    A.erase(A.begin());
                }                      
            }
        }
        return advantageA;
    }
};