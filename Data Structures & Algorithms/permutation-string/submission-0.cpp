class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_count(26, 0), s2_count(26, 0);
        int left=0, right=0;

        for(char c:s1){
            s1_count[c-97]++;
        }
        cout << "s1: " << s1.size() << ", s2: " << s2.size() <<endl;

        while(right < s2.size()){
            cout << "left: " << left << ", right: " << right <<endl;
            if(right-left < s1.size()){
                s2_count[s2[right]-97]++;
                right++;
                continue;
            }
            else {
                bool isSame = true;
                for(int i=0;i<26;i++){
                    if(s1_count[i] != s2_count[i]){
                        isSame = false;
                        break;
                    }
                }

                if(isSame){
                    return true;
                }
                else {
                    s2_count[s2[left]-97]--;
                    left++;
                }
            }
        }

        bool isSame = true;
        for(int i=0;i<26;i++){
            if(s1_count[i] != s2_count[i]){
                isSame = false;
                break;
            }
        }

        if(isSame){
            return true;
        }
        else {
            return false;
        }
    }
};