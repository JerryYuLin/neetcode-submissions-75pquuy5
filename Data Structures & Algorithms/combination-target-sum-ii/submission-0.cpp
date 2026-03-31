class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;

        findCombination(candidates, current, 0, target);

        return ans;
    }

    void findCombination(const vector<int>& candidates, vector<int>& current, int index, int target){
        if(target == 0) {
            ans.push_back(current);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i>index && candidates[i-1]==candidates[i]) continue;

            if(target < candidates[i]) return;

            current.push_back(candidates[i]);
            findCombination(candidates, current, i+1, target - candidates[i]);
            current.pop_back();
        }
    }
};