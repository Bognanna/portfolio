--6.2 Advanced Subqueries
--Ex.1
--Find departments without employees. Use correlated subquery. 
SELECT d.dept_id, d.dept_name, d.address
FROM departments d LEFT JOIN employees e USING(dept_id)
WHERE d.dept_id NOT IN
	(SELECT…

--Ex.2
--Find employees who earn more than average salary for their jobs. 
SELECT surname, job, salary
FROM employees e1
WHERE salary >
	(SELECT AVG(salary) FROM employees e2
	WHERE e1.job = e2.job)
ORDER BY surname;

--Ex.3
--Add to result of previous query an average salary for each job (you can use subquery in a SELECT clause or a subquery in a FROM clause).
SELECT surname, job, salary, 
	(SELECT AVG(salary) FROM employees e2
	WHERE e2.job = e1.job)
FROM employees e1
WHERE salary >
	(SELECT AVG(salary) FROM employees e2
	WHERE e1.job = e2.job)
ORDER BY surname;

--Ex.4
--Find employees who earn at least 60% of their bosses salaries. 
SELECT surname, job, salaray
FROM employees e1
WHERE salary >=
	(SELECT salary*0,6 FROM employees e2
	WHERE e1.boss_id = e2.emp_id)
ORDER BY surname;

--Ex.5
--Find the maximal sum of departments employees’ salaries (use subquery in a FROM clause). 
SELECT MAX(dept_sum) AS max_dept_sum
FROM (SELECT dept_id, SUM(salary) AS dept_sum
	FROM employees
	GROUP BY dept_id) sum_dept_ds;

--Ex.6
--Add to result of a previous query a department name (use previous query as a subquery in HAVING clause of a new query). 
SELECT d.dept_name, MAX(sum_dept_ds.dept_sum) AS sum_of_sal
FROM (SELECT dept_id, SUM(salary) AS dept_sum
	FROM employees
	GROUP BY dept_id) sum_dept_ds JOIN departments d USING(dept_id);
