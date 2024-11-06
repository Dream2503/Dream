/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int> score) {
        int size = score.size(), idx;
        vector<string> res(size);
        vector<int> copy = score;
        sort(copy.begin(), copy.end(), greater<int>());

        auto index = [&size, &copy](int value) -> int {
            int low = 0, high = size - 1, mid;

            while (low <= high) {
                mid = (low + high) / 2;
                if (copy[mid] == value) return mid;
                else if (copy[mid] > value) low = mid + 1;
                else if (copy[mid] < value) high = mid - 1;
            }
            return -1;
        };
        for (int i = 0; i < size; i++) {
            idx = index(score[i]);

            switch (idx) {
                case 0:
                    res[i] = "Gold Medal";
                    break;
                case 1:
                    res[i] = "Silver Medal";
                    break;
                case 2:
                    res[i] = "Bronze Medal";
                    break;
                default:
                    res[i] = to_string(idx+1);
            }
        }
        return res;
    }
};
// @lc code=end

