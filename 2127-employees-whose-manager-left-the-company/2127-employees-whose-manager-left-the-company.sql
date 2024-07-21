# Write your MySQL query statement below

select employee_id from Employees where salary<30000 and manager_id is not null and manager_id not in 
(select employee_id from Employees) order by employee_id;


-- Ensure the employee has a manager: Use manager_id IS NOT NULL to filter out employees without managers.
-- Check if the manager has left the company: Use a subquery to check if manager_id is not present 
-- in the list of current employee IDs (employee_id).
-- Order the result by employee_id: Ensure the output is sorted as required.