# Write your MySQL query statement below
WITH data AS (SELECT
id,
recordDate,
temperature,
LAG(temperature,1) OVER (ORDER BY recordDate ASC) AS lg,
LAG(recordDate,1) OVER (ORDER BY recordDate ASC) AS prev
FROM Weather
)


SELECT
    d.id
FROM data AS d
WHERE d.lg<d.temperature AND DATEDIFF(recordDate, prev)=1