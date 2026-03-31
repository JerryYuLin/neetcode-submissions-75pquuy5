class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, index;
        
        while(i<j) {
            index = (i+j)/2;
            if(nums[index] == target) break;
            else if (nums[index] < target) {
                i = index + 1;
            }
            else {
                j = index - 1;
            }
        }
        
        index = (i+j)/2;

        if(nums[index]==target){
            return index;
        }
        else {
            return -1;
        }
    }
};