# Write your MySQL query statement below
SELECT
e.name as Employee
FROM 
Employee as e
WHERE e.salary>(SELECT Employee.salary From Employee WHERE Employee.id = e.managerId)