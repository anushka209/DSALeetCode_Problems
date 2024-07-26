# Write your MySQL query statement below

-- Select the department name, employee name, and salary
SELECT 
    d.name AS Department, 
    emp.name AS Employee, 
    emp.salary 
FROM (
    -- Select all columns from employee and add a rank based on salary within each department
    SELECT 
        employee.*, 
        DENSE_RANK() OVER (PARTITION BY departmentid ORDER BY salary DESC) AS rnk 
    FROM 
        employee
) AS emp
-- Join the department table to get the department name
LEFT JOIN 
    department AS d 
    ON d.id = emp.departmentid
-- Filter to get only the top 3 salaries per department
WHERE 
    emp.rnk <= 3;