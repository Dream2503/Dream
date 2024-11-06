/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> img) {
        int size1 = img.size(), size2 = img[0].size();
        auto smooth = [&size1, &size2, &img](int &i, int &j) -> int {
            int sum = img[i][j], cnt = 1;

            if (i - 1 > -1) {
                if (j - 1 > -1) {
                    sum += img[i-1][j-1];
                    cnt++;
                } if (j + 1 < size2) {
                    sum += img[i-1][j+1];
                    cnt++;
                }
                sum += img[i-1][j];
                cnt++;
            } if (j - 1 > -1) {
                sum += img[i][j-1];
                cnt++;
            } if (j + 1 < size2) {
                sum += img[i][j+1];
                cnt++;
            } if (i + 1 < size1) {
                if (j - 1 > -1) {
                    sum += img[i+1][j-1];
                    cnt++;
                } if (j + 1 < size2) {
                    sum += img[i+1][j+1];
                    cnt++;
                }
                sum += img[i+1][j];
                cnt++;
            }
            return sum / cnt;
        };
        vector<vector<int>> res(size1, vector<int>(size2));

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                res[i][j] = smooth(i ,j);
            }
        }
        return res;
    }
};
// @lc code=end

