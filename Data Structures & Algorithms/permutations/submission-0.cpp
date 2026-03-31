class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;

        permutation(nums, current, 0);

        return ans;
        
    }

    void permutation(vector<int>& nums, vector<int>& current, int start){
        if(start == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int i=start; i<nums.size(); i++) {
            current.push_back(nums[i]);
            swap(nums[start], nums[i]);
            permutation(nums, current, start+1);
            swap(nums[start], nums[i]);
            current.pop_back();
        }
    }
};