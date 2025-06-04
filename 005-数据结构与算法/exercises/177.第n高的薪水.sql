/* 第N高的薪水
编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
*/
-- 方法1：
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e.salary
      FROM employee e
      WHERE (SELECT count(DISTINCT salary) FROM employee WHERE salary>e.salary) = N-1
  );
END

--方法2:
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e1.salary
      FROM employee e1 LEFT JOIN employee e2 ON e1.salary < e2.salary
      GROUP BY e1.salary
      HAVING count(DISTINCT e2.salary) = N-1
  );
END

--方法3：
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
      FROM (SELECT salary, @r:=IF(@p=salary, @r, @r+1) AS 'rank',  @p:= salary 
            FROM  employee, (SELECT @r:=0, @p:=NULL)init 
            ORDER BY salary DESC) tmp
      WHERE rank = N
  );
END

