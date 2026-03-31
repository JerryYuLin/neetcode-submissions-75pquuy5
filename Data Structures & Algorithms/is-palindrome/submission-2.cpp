class Solution {
public:
    bool isPalindrome(string s) {
        int head_ptr = 0, tail_ptr = s.length() - 1;
        while(tail_ptr > head_ptr) {
            if(s[head_ptr]>=65 && s[head_ptr]<=90) s[head_ptr]+=32;
            if(s[tail_ptr]>=65 && s[tail_ptr]<=90) s[tail_ptr]+=32;

            if(s[tail_ptr] < '0' || s[tail_ptr]> '9' && s[tail_ptr]<'a' || s[tail_ptr]>'z'){
                tail_ptr--;
                continue;
            }
            else if(s[head_ptr] < '0' || s[head_ptr]> '9' && s[head_ptr]<'a' || s[head_ptr]>'z'){
                head_ptr++;
                continue;
            }

      
            if(s[tail_ptr]!=s[head_ptr]) return false;

            head_ptr++;
            tail_ptr--;
        }

        return true;
    }
};
