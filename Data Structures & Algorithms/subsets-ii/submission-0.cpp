class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        findSubsets(nums, current, 0);

        return ans;
    }

    void findSubsets(const vector<int>& nums, vector<int>& current, int index) {
        ans.push_back(current);

        for(int i=index; i<nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            findSubsets(nums, current, i+1);
            current.pop_back();
        }
    }
};