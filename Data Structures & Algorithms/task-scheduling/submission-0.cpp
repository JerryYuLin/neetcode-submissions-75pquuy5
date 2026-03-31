class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        vector<int> cooldown(26, 0);
        queue<char> cooling;

        auto cmp = [&](char left, char right) {
            return f[left - 'A'] < f[right - 'A'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);

        for(char task:tasks) {
            f[task - 'A']++;
        }

        for(int i=0; i<26; ++i) {
            if (f[i] > 0) pq.push('A' + i);
        }

        int c = 0;

        while (!cooling.empty() || !pq.empty()) {
            if (!cooling.empty()) {
                char w = cooling.front();
                if(cooldown[w - 'A'] == 0) {
                    pq.push(w);
                    cooling.pop();
                }
            }

            if (!pq.empty()) {
                char w = pq.top();
                pq.pop();
                f[w - 'A']--;
                if (f[w - 'A'] > 0) {
                    cooling.push(w);
                    cooldown[w - 'A'] = n+1;
                }
            }

            for (int i = 0; i < 26; ++i) {
                if (cooldown[i] > 0) cooldown[i]--;
            }

            c++;
        }

        return c;
    }
};
