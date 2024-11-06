/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
    unordered_set<int> hashSet;

    MyHashSet() {
        
    }
    
    void add(int key) {
        this->hashSet.insert(key);
    }
    
    void remove(int key) {
        this->hashSet.erase(key);
    }
    
    bool contains(int key) {
        return find(this->hashSet.begin(), this->hashSet.end(), key) != this->hashSet.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

