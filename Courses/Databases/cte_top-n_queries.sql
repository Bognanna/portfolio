--7. CTE. Top-N queries

--Ex.1
--Find employees who earn more than average salary for their jobs. Use CTE to define a structure to 
--hold an average salary for each job.
WITH
	average_salaries AS
		(SELECT job, AVG(salary) AS avg_salary
		FROM  employees
		GROUP BY job)
SELECT e.surname, e.job, e.salary, a.avg_salary
FROM employees e LEFT JOIN average_salaries a
WHERE e.salary > a.avg_salary
ORDER BY surname;

--Ex.2
-- Find the department with the maximal sum of its employees’ salaries. Use CTE to define a 
-- structure to hold a sum of salaries for each department. 
WITH
	sum_of_salaries AS
		(SELECT dept_id, SUM(salary) AS sum_salary
		FROM employees
		GROUP BY dept_id)
SELECT d.dept_name, MAX(s.sum_salary)
FROM departments d JOIN sum_of_salaries s USING dept_id;

--Ex.3
-- Find employees who earn at least 60% of their bosses salaries. Use CTE to define a structure to 
-- hold bosses’ surnames and salaries.  
WITH
	bosses AS
		(SELECT emp_id, name, salary
		FROM employees)
SELECT e.surname, e.salary, b.name, b.salary
FROM employees e JOIN bosses b USING emp_id
WHERE e.salary > 0.6*b.salary
ORDER BY e.surname;

--Ex.4
-- Find employee with the longest work history. Use FETCH clause. 
SELECT surname, hire_date
FROM employees
ORDER BY hire_date DESC
FETCH NEXT 1 ROW ONLY;

--Ex.5
-- Use previous query as CTE and for each employee find a number of days between his or her hire 
-- date and hire date of employee with the longest work history. Sort the result according to number of 
-- days. (to combine a row with information about longest working employee with rows of other 
-- employees you may use Cartesian product). 
WITH
	longest AS
		(SELECT surname, hire_date
		FROM employees
		ORDER BY hire_date DESC
		FETCH NEXT 1 ROW ONLY)
SELECT e.surname, (l.hire_date – e.hire_date) AS ‘num_of_days’
FROM employees e CROSS JOIN longest l
ORDER BY  l.hire_date – e.hire_date;

--Ex.6
-- For each employee show how many thousands ("grand") employee earns. 
WITH
	grands AS
		SELECT grand, word
		FROM
			(VALUES (1000, ‘one’), (2000, ‘two’), (3000, ‘three’), (4000, ‘four’), (5000, ‘five’)
			) grands(grand, word)
SELECT e.surname || ‘ earns ‘|| g.word ||’ grand’ AS „sentence”
FROM employees e JOIN grands g
	ON TO_CHAR(e.salary – e.salary%1000, ‘9999’) = TO_CHAR(g.grand)
ORDER BY e.surname;

--Ex.7
-- Build a query which will display employees hierarchy. For each employee display his/her name, 
-- surname and path, which shows an employee position in employees hierarchy. Put employee Smith 
-- on the top of hierarchy.  
WITH
	emp_hierarchy(emp_id, boss_id, surname, hier_level) AS
		(SELECT emp_id, boss_id, surname, 1
		FROM employees
		WHERE job = ‘PRINCIPAL’
			UNION ALL
		SELECT e.emp_id, e.boss_id, e.surname, hier_level+1
		FROM employees e JOIN emp_hierarchy h ON e.boss_id = h.emp_id)
	SEARCH DEPTH
		FIRST BY surname SET sibl_order
SELECT surname, emp_id, boss_id, hier_level
FROM emp_hierachy
ORDER BY sibl_order;