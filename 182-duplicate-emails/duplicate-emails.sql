SELECT email AS Email
FROM Person AS p1
GROUP BY email
HAVING COUNT(email)>1