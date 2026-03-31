class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int last;

        for(int i=0; i<nums.size();i++){
            if(i!=0 && last == nums[i]){
                continue;
            }
            last = nums[i];

            int left=i+1, right=nums.size()-1, target = -1 * nums[i];
            while(left < right){
                if(nums[left]+nums[right] == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;

                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(target-nums[left] < nums[right]){
                    right--;
                }
                else{
                    left++;
                }
            }
        }

        return ans;
    }
};