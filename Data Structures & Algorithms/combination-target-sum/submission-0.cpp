class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        findSubsets(candidates, current, 0, target);

        return ans;
    }

    void findSubsets(const vector<int>& candidates, vector<int>& current, int index, int target){
        if(target == 0) {
            ans.push_back(current);
            return;
        }

        if(index >= candidates.size()){
            return;
        }

        if(target < candidates[index]) return;

        current.push_back(candidates[index]);
        findSubsets(candidates, current, index, target - candidates[index]);
        current.pop_back();
        findSubsets(candidates, current, index + 1, target);

    }
};