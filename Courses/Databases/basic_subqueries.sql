--6.1 Basic Subqueries
--Ex.1
--Display surnames and jobs of those employees who work in the same department as employee Johnson (do not display Johnson).  
SELECT surname, job
FROM employees
WHERE dept_id = 
	(SELECT dept_id 
	FROM employees
	WHERE surname = ‘Johnson’)
	AND surname != ‘Johnson’
ORDER BY surname;

--Ex.2
--Add to result of previous query departments names. 
SELECT e.surname, e.job, d.dept_name
FROM employees e JOIN departments d
	ON e.dept_id = d.dept_id
WHERE e.dept_id = 
	(SELECT dept_id 
	FROM employees
	WHERE surname = ‘Johnson’)
	AND e.surname != ‘Johnson’
ORDER BY e.surname;

--Ex.3
--Find the longest-employed lecturer. 
SELECT surname, job, hire_date
FROM employees
WHERE hire_date = 
	(SELECT MIN(hire_date)
	FROM employees);

--Ex.4
--For every department find the shortest-employed employee. 
SELECT d.dept_name AS department, e.surname, e.hire_date
FROM employees e JOIN departments d
	ON e.dept_id = d.dept_id
WHERE (e.surname, e.hire_date) IN
	(SELECT surname, MIN(hire_date)
	FROM employees
	GROUP BY dept_id)
ORDER BY d.dept_name;

--Ex.5
--Find departments without employees. 
SELECT dept_id, dept_name, address
FROM departments
WHERE dept_id NOT IN
	(SELECT dept_id 
	FROM employees
	GROUP BY dept_id);

--Ex.6
--Find professors who have not any phd students among their subordinates. 
SELECT surname, ‘PROFESSOR’, salary
FROM employees
WHERE (boss_id) NOT IN
	(SELECT boss_id
	FROM employees
	WHERE job = ‘PHD_STUDENT’;)
ORDER BY surname;

--Ex.7
--Find departments which employ more employees than department “ADMINISTRATION” (use a subquery in a HAVING clause). 
SELECT d.dept_name, COUNT(e.emp_id)
FROM departments d JOIN employees e USING (dept_id)
GROUP BY d.dept_name
HAVING COUNT(e.emp_id) >
	(SELECT COUNT(e.emp_id)
	FORM departments d JOIN employees e USING (dept_id)
	WHERE d.dept_name = ‘ADMINISTRATION’)
ORDER BY d.dept_name;

--Ex.8
--Find the year in which the biggest number of professors were hired. Show also the number of professors hired in the year. 
SELECT  EXTRACT(YEAR FROM (hire_date)) AS  year, COUNT(empl_id) AS number_of_professors
FROM employees 
WHERE job = ‘PROFESSOR’ AND year = 
	(SELECT MAX(emp_id)
	FROM employees
	WHERE job = ‘PROFESSOR’
	GROUP BY EXTRACT(YEAR FROM (hire_date)) )
GROUP BY EXTRACT(YEAR FROM (hire_date))
ORDER BY EXTRACT(YEAR FROM (hire_date));

--Ex.9
--Find the department (write its name and sum of salaries) which pays the biggest amount (sum of 
salaries) of money to its employees. Take into account also additional salaries.
SELECT d.dept_name AS department, SUM(e.salary + COALESCE(e.add, 0)) AS max_sum
FROM employees e JOIN departments d USING (dept_id)
WHERE max_sum = 
	(SELECT MAX(SUM(salary + COALESCE(e.add, 0))
	FROM employees
	GROUP BY dept_id);

