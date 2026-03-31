class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(int num:nums) {
            this->nums.push(num);
        }

        while(this->nums.size() > k) this->nums.pop();
    }

    int add(int val) {
        nums.push(val);

        while(this->nums.size() > k) this->nums.pop();

        return nums.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> nums;
};
