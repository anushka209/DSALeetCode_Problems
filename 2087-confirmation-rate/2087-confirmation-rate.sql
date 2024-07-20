# Write your MySQL query statement below

select s.user_id,round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate from Signups s left join Confirmations c on s.user_id=c.user_id
group by user_id;


-- to display confirmation_rate , we need to find average using aggregation function avg(), here using 
-- if clause we specified that if action is confirmed 
-- we count it as 1 and else if null or timeout we will count it as 0.