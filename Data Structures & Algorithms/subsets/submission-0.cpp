class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        findSubsets(nums, current, 0);

        return ans;
    }

    void findSubsets(const vector<int>& nums, vector<int>& current ,int index) {
        if(index == nums.size()) {
            ans.push_back(current);
            return;
        }

        findSubsets(nums, current, index+1);
        current.push_back(nums[index]);
        findSubsets(nums, current, index+1);
        current.pop_back();
    }
};