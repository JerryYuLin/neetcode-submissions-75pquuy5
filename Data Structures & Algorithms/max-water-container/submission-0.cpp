class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, area = 0;

        while(left < right) {
            int h, w = right - left;

            if(height[left]>height[right]){
                h = height[right];
                right--;
            }
            else {
                h = height[left];
                left++;
            }

            int a = h*w;
            if (a > area) {
                area = a;
            }
        }

        return area;
    }
};