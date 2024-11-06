/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> queue;
    int size;

    KthLargest(int k, vector<int> nums) {
        this->size = k;

        for (int &num: nums){
            this->queue.push(num);
            if (this->queue.size() > k) this->queue.pop();
        }
    }
    
    int add(int val) {
        this->queue.push(val);
        if(this->queue.size() > this->size) this->queue.pop();
        return this->queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

