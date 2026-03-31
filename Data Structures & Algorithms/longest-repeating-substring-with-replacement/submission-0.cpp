class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left=0, w_size=0;

        for(char c:s){
            freq[c-65]++;
            w_size++;

            int max_f = 0;
            for(int f:freq){
                if(f>max_f) max_f = f;
            }


            if(w_size > k + max_f){
                w_size--;
                freq[s[left]-65]--;
                left++;
            }
        }

        return w_size;
    }
};
