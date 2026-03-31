class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(const string& s, int start, int end){
        int l=start, r=end;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        palindromePartition(s, current, 0);

        return ans;
    }

    void palindromePartition(const string& s, vector<string>& current, int index){
        if(index == s.size()){
            ans.push_back(current);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)) {
                current.push_back(s.substr(index, i - index + 1));
                palindromePartition(s, current, i + 1);
                current.pop_back();
            }
            else continue;
        }
    }
};