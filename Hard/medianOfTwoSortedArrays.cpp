class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1Size = nums1.size(), n2Size = nums2.size();
        int arr[n1Size + n2Size];
        int n1, n2, index = 0;
        
        for(n1 = 0, n2=0; n1 < n1Size || n2 < n2Size;){
            if(n1 < n1Size && (n2 >= n2Size || nums1[n1] <= nums2[n2])){
                arr[index++] = nums1[n1++];
            }
            else{
                arr[index++] = nums2[n2++];
            }
        }
        int temp;
        if((temp = n1Size+n2Size)%2 == 0){
            temp /= 2;
            return (double)(arr[temp] + arr[temp-1])/2;
        }
        else{return arr[temp/2];}
    }
};