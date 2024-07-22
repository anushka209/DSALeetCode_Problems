# Write your MySQL query statement below


select round(count(distinct player_id) / (select count(distinct player_id) from Activity), 2) as fraction
from Activity where (player_id, date_sub(event_date, INTERVAL 1 DAY)) in 
(select player_id, min(event_date) as first_login from Activity group by player_id);


-- Inner Query (Subquery):
-- (select player_id, min(event_date) as first_login from Activity group by player_id): 
-- This subquery finds the first login date for each player.
-- It groups the data by player_id and selects the minimum event_date for each player as their first_login.
-- Main Query:
-- The WHERE clause: (player_id, date_sub(event_date, INTERVAL 1 DAY)) in (subquery): This part filters the Activity table to 
-- include only those records where (player_id, date_sub(event_date, INTERVAL 1 DAY)) matches a tuple in the subquery result.
-- select round(count(distinct player_id) / (select count(distinct player_id) from Activity), 2) as fraction: 
-- This part calculates the fraction by dividing the count of distinct player_id values from the filtered records by the total 
-- count of distinct player_id values in the entire Activity table. The result is rounded to two decimal places.

-- The date_sub(event_date, INTERVAL 1 DAY) function in SQL is used to subtract one day from the event_date. 
-- This function is commonly used in date manipulation and helps in deriving dates relative to a given date. In this context:
-- event_date is the date of an event for a player.
-- INTERVAL 1 DAY specifies the amount of time to subtract from event_date.
-- So, date_sub(event_date, INTERVAL 1 DAY) computes the date that is one day before the event_date. 
-- For example, if event_date is 2024-07-22, date_sub(event_date, INTERVAL 1 DAY) would return 2024-07-21.