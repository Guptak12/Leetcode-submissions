WITH rankEmp AS(
    SELECT 
    name,
    salary,
    departmentId,
    DENSE_RANK() OVER(
        PARTITION BY departmentId
        ORDER BY salary DESC) AS rnk
        FROM Employee  
)


SELECT
d.name AS Department,
r.name AS Employee,
r.salary AS Salary
FROM rankEmp r
INNER JOIN Department d ON d.id = r.departmentId
WHERE r.rnk<=3