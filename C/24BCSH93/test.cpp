#include <bits/stdc++.h>

int minCost(const std::vector<int>& heights) {
	const int size = heights.size();
	std::vector<int> dp(size, INT32_MAX);
	std::queue<int> queue;
	dp[0] = 0;
	queue.push(0);
	
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
		
		if (current + 1 < size) {
			int step = dp[current] + std::abs(heights[current] - heights[current + 1];
			
			if (dp[current + 1] > step) {
				dp[current + 1] = step;
				queue.push(current + 1);
			}
		}
		if (current + 2 < size) {
			int step = dp[current] + std::abs(heights[current] - heights[current + 2];
			
			if (dp[current + 2] > step) {
				dp[current + 2] = step;
				queue.push(current + 2);
			}
		}
	}
	return dp[size - 1];
}
	