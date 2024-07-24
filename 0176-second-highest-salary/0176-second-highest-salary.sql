# Write your MySQL query statement below


-- select max(e1.salary) as SecondHighestSalary from Employee e1 join Employee e2 on e1.salary < e2.salary;

select (select distinct salary from Employee order by salary desc LIMIT 1 OFFSET 1) as SecondHighestSalary;

-- Extract distinct salaries: Using the DISTINCT keyword ensures we do not have duplicate salary values.
-- Sort salaries in descending order: Using ORDER BY salary DESC arranges the salaries from highest to lowest.
-- Offset and limit: Using OFFSET 1 skips the highest salary and LIMIT 1 fetches the second highest salary.