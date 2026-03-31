class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1, j = *(max_element(piles.begin(), piles.end()));

        while(i<=j){
            int mid = (i+j)/2;

            if(canFinish(mid, piles, h)){
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return i;
    }

    bool canFinish(int speed, vector<int>& piles, int h){
        long long total = 0;

        for(int pile:piles){
            total += ( pile + speed - 1)/speed;
        }


        return total <= h;
    }
};