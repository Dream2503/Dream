#include <iostream>       // Standard input and output streams
#include <iomanip>        // Manipulators for input and output formatting
#include <string>         // std::string class and related functions
#include <vector>         // std::vector container
#include <array>          // std::array container
#include <list>           // std::list container
#include <deque>          // std::deque container
#include <set>            // std::set and std::multiset containers
#include <map>            // std::map and std::multimap containers
#include <unordered_set>  // std::unordered_set and std::unordered_multiset containers
#include <unordered_map>  // std::unordered_map and std::unordered_multimap containers
#include <algorithm>      // Standard algorithms (e.g., sort, find)
#include <utility>        // std::pair and std::make_pair
#include <tuple>          // std::tuple and related functions
#include <random>         // Random number generation facilities
#include <cmath>          // Common mathematical functions
#include <numeric>        // Numeric operations (e.g., std::accumulate)
#include <queue>
#include <chrono>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// ListNode *create(vector<int> vec) {
//     ListNode *head = new ListNode(vec[0]), *current = head;
    
//     for (int num: vec) {
//         current->next = new ListNode(num);
//         current = current->next;
//     }
//     return head->next;
// }
// void print(ListNode *head) {
//     cout << '[';

//     while (head->next) {
//         cout << head->val << ", ";
//         head = head->next;
//     }
//     cout << head->val << ']';
// }

class Solution {
public:
    void nextPermutation(vector<int> nums) {
        int i = nums.size() - 2;
        
        while (i > -1 and nums[i] >= nums[i + 1]) i--;
        
        if (i > -1) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    sol.nextPermutation({1, 3, 2});
    chrono::duration<double> time = chrono::high_resolution_clock::now() - start;
    cout << "Total time taken: " << time.count();
    return 0;
}