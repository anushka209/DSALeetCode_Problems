# Write your MySQL query statement below

select a1.machine_id,round(avg(a2.timestamp-a1.timestamp),3) as processing_time from Activity a1 join activity a2
on a1.machine_id=a2.machine_id AND a1.process_id=a2.process_id AND a1.activity_type='start' AND a2.activity_type='end'
group by a1.machine_id;


-- Self-join on Activity table:
-- a1 is the alias for the Activity table representing the start activity.
-- a2 is the alias for the Activity table representing the end activity.
-- Joins a1 and a2 on machine_id and process_id, ensuring the join only includes pairs where one is a start activity and the other is an end activity.
-- Calculates the processing time:
-- a2.timestamp - a1.timestamp computes the time difference between end and start activities.
-- AVG(a2.timestamp - a1.timestamp) calculates the average processing time for each machine.
-- ROUND(..., 3) rounds the average processing time to three decimal places.
-- Groups by machine_id:
-- Groups the results by machine_id to calculate the average processing time for each machine.