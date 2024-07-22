# Write your MySQL query statement below

select user_id, CONCAT(UPPER(LEFT(name, 1)), LCASE(SUBSTRING(name, 2))) as name from Users order by user_id;


-- Use UPPER() to capitalize the first letter of the name.
-- Use LCASE() (or LOWER()) to convert the rest of the name to lowercase.
-- Use CONCAT() and SUBSTRING() functions to combine these parts together.