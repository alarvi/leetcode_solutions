// https://leetcode.com/problems/design-hashset/
static const int N = 1000001;
class MyHashSet {
public:
    bool data[N];
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(data, 0, N);
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */