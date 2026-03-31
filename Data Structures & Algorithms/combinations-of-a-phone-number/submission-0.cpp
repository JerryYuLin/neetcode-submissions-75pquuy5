class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> number_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string current;
        combination(digits, current, 0);

        return ans;
    }

    void combination(string& digits, string& current, int index){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        for(char c:number_map[digits[index]]){
            current.push_back(c);
            combination(digits, current, index+1);
            current.pop_back();
        }
    }
};