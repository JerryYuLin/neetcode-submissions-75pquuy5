class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> partner_map;

        for(int i=0; i<=nums.size(); i++){
            if(partner_map.count(nums[i]) > 0){
                vector<int> ans = {i, partner_map[nums[i]]};
                sort(ans.begin(), ans.end());
                return ans;
            }
            else {
                int partner = target - nums[i];

                partner_map[partner] = i;
            }
        }

        return {};
    }
};
