--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below
SELECT name AS Employee FROM Employee AS E1
INNER JOIN employee e2 ON e1.id = e2.managerID
WHERE e1.salary < e2.salary
-- @lc code=end

