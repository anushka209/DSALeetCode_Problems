# Write your MySQL query statement below

-- But, problem arises for the other product_id which do not have price change on or before this date.
-- So we find those product_id and set their price as 10 using:

select 
    distinct product_id,
    10 as price 
from 
    products
group by
    product_id
having
    min(change_date) > "2019-08-16"

union

-- We can find the last price before 2019-08-16 for products whose price has been changed on or before this date simply by using:

select 
    product_id, 
    new_price
from 
    Products 
where 
    (product_id, change_date) in(
                                select 
                                    product_id, 
                                    max(change_date) as recent_date
                                from 
                                    Products
                                where 
                                    change_date <= "2019-08-16"
                                group by 
                                    product_id
                                )