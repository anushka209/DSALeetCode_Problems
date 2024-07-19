# Write your MySQL query statement below

select contest_id,round(count(distinct user_id) * 100.0 / (select count(user_id) from Users),2) as percentage from Register 
group by contest_id order by percentage desc,contest_id asc;


-- SELECT contest_id:
-- Selects the contest ID.
-- COUNT(DISTINCT user_id):
-- Counts the number of unique users registered for each contest.
-- ROUND(..., 2):
-- Calculates the percentage of users registered for each contest, multiplying by 100.0 to ensure floating-point division, and rounds to two decimal places.
-- (SELECT COUNT(user_id) FROM Users):
-- Selects the total number of users from the Users table to calculate the percentage.
-- GROUP BY contest_id:
-- Groups the results by contest ID.
-- ORDER BY percentage DESC, contest_id ASC:
-- Orders the results by percentage in descending order. In case of a tie, it orders by contest ID in ascending order.