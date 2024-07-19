# Write your MySQL query statement below

-- Subquery or 2nd approach by self join 

select w1.id from Weather w1 join Weather w2 on w1.recordDate = DATE_ADD(w2.recordDate,INTERVAL 1 DAY)
where w1.temperature > w2.temperature;


-- SELECT w1.id selects the id of the dates with higher temperatures compared to the previous day.
-- FROM Weather w1 JOIN Weather w2 joins the Weather table with itself, using aliases w1 and w2.
-- ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY) matches each record with the record of the previous day.
-- WHERE w1.temperature > w2.temperature filters the records to include only those where the temperature is higher than the previous day.