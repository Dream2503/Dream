/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    unordered_map<int,int> hashMap;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        this->hashMap[key] = value;
    }
    
    int get(int key) {
        if (this->hashMap.find(key) == this->hashMap.end()) return -1;
        return this->hashMap[key];
    }
    
    void remove(int key) {
        hashMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

