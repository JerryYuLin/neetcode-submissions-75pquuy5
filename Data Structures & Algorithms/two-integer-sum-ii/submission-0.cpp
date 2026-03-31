class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while(left < right){
            int r = target - numbers[left];

            if(r>numbers[right]){
                left++;
                continue;
            }
            else if(r<numbers[right]){
                right--;
                continue;
            }
            else{
                break;
            }
        }

        vector<int> ans;
        ans.push_back(left+1);
        ans.push_back(right+1);

        return ans;
    }
};