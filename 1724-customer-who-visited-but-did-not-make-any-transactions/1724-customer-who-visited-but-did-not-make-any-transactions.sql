# Write your MySQL query statement below

select v.customer_id,count(v.visit_id) as count_no_trans from Visits v left join Transactions t on v.visit_id=t.visit_id
where t.transaction_id is null group by v.customer_id;



-- SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans selects the customer_id and counts the number of visits without transactions for each customer.
-- FROM Visits v specifies the Visits table with an alias v.
-- LEFT JOIN Transactions t ON v.visit_id = t.visit_id performs a left join with the Transactions table on the visit_id to include all visits, with or without transactions.
-- WHERE t.transaction_id IS NULL filters the rows to include only those visits where no transaction was made (transaction_id is NULL).
-- GROUP BY v.customer_id groups the results by customer_id to count the number of such visits per customer.