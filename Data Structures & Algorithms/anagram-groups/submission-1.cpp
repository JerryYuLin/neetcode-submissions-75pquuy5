class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for(int i=0;i<strs.size();i++){
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            anagrams[sorted_str].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(const auto& pair : anagrams){
            ans.push_back(pair.second);
        }

        return ans;
    }
};