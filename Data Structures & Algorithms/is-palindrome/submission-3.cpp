class Solution {
public:
    bool isPalindrome(string s) {
        int head_ptr = 0, tail_ptr = s.length() - 1;
        while(tail_ptr > head_ptr) {
            if(!isalnum(s[tail_ptr])){
                tail_ptr--;
                continue;
            }
            else if(!isalnum(s[head_ptr])){
                head_ptr++;
                continue;
            }
      
            if(tolower(s[tail_ptr])!=tolower(s[head_ptr])) return false;

            head_ptr++;
            tail_ptr--;
        }

        return true;
    }
};
