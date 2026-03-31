class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int left=0, max_l=0;

        for(char c:s){
           while(ch.count(c) > 0 && left < s.size()){
            ch.erase(s[left]);
            left++;
           }
           ch.insert(c);

           if(ch.size()>max_l){
            max_l = ch.size();
           }
        }

        return max_l;
    }
};