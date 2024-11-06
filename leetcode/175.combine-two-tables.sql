--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
# Write your MySQL query statement below
SELECT firstName, lastName, city, state FROM Person AS P LEFT JOIN Address AS A
ON P.personID = A.personID;
-- @lc code=end

