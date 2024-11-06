/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int size1 = list1.size(), size2 = list2.size();
        vector<pair<int,string>> vec;

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (list1[i] == list2[j]) {
                    vec.push_back({i+j, list1[i]});
                    break;
                }
            }
        }
        sort(vec.begin(), vec.end());
        int min = vec[0].first, size = vec.size();
        vector<string> res{vec[0].second};

        for (int i = 1; i < size; i++) {
            if (vec[i].first == min) res.push_back(vec[i].second);
            else break;
        }
        return res;
    }
};
// @lc code=end

