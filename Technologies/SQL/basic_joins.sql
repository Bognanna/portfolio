--5.1 Basic Joins

--Ex.1
--Display employees names and surnames. If employee works in a department, display department 
name and address. Skip employees without departments. 
SELECT employees.name, employees.surname, departments.dept_name, departments.address
FROM employees JOIN departments
	ON employees.dept_id = departments.dept_id
ORDER BY employees.surname;

--Ex.2
--Transform previous query to produce following sentences for employees.
SELECT ‘Employee ‘|| employees.name || ‘ ‘ || employees.surname || ‘ works in ‘ ||  departments.dept_name || ‘ located at ‘ || departments.address
FROM employees JOIN departments
	ON employees.dept_id = departments.dept_id
ORDER BY employees.surname;

--Ex.3
--Find surnames and salaries of all employees working at departments located at 47TH STR. 
SELECT employees.surname, employees.salary
FROM employees JOIN departments
	ON employees.dept_id = departments.dept_id
WHERE departments.adress = ‘47TH STR.’
ORDER BY employees.surname;

--Ex.4
--Modify previous query and count employees working at departments located at 47TH STR. Also 
find an average salary of those employees (rounded to two decimal places).  
SELECT COUNT(employees.surname) AS employees_at_47th_str, TO_CHAR( AVG(employees.salary), ‘9999.99’) AS avg_salary
FROM employees JOIN departments
	ON employees.dept_id = departments.dept_id
WHERE departments.adress = ‘47TH STR.’
ORDER BY employees.surname;

--Ex.5
--Find surnames, jobs and salaries of employees. Display also salary ranges for employees jobs (use JOBS table). 
SELECT e.surname, e.job, e.salary, j.min_salary AS job_min_salary, j.max_salary AS job_max_salary
FROM employees e JOIN jobs j
	ON e.salary
ORDER BY e.surname;

--Ex.6
--Check if employees’ salaries are in salary ranges defined for their jobs. 
SELECT e.surname, e.job, e.salary, j.min_salary AS job_min_salary, j.max_salary AS job_max_salary
FROM employees e JOIN jobs j
	ON e.salary
	NOT BETWEEN j.min_salary AND j.max_salary
ORDER BY e.surname;

--Ex.7
--Find employees whose salaries are in salary range defined for assistants. 
SELECT e.surname, e.job, e.salary, j.min_salary AS job_min_salary, j.max_salary AS job_max_salary
FROM employees e JOIN jobs j
	ON e.salary
	BETWEEN j.min_salary AND j.max_salary
WHERE e.job = ‘ASSISTANT’
ORDER BY e.surname;

--Ex.8
--For every department that employs employees find the number of employees and sum of employees’ salaries. 
SELECT d.dept_name AS department, COUNT(e.emp_id) AS employees_at_dept, SUM(e.salary) AS salaries_at_dept
FROM employees e JOIN departments d
	ON e.dept_id = d.dept_id
GROUP BY  d.dept_name
ORDER BY d.dept_name;

--Ex.9
--Modify previous query and display only those departments that employ at least 2 employees. 
SELECT d.dept_name AS department, COUNT(e.emp_id) AS employees_at_dept, SUM(e.salary) AS salaries_at_dept
FROM employees e JOIN departments d
	ON e.dept_id = d.dept_id
WHERE COUNT(e.emp_id) > 1
GROUP BY  d.dept_name
ORDER BY d.dept_name;

--Ex.10
--Label departments according to employees number. If department employs less or equal to 2 
--employees, label it as “small”. If department employs from 3 to 6 employees, label it as “medium”. 
--If department employs 7 or more employees, label it as “big”. Skip departments with no employees. 
SELECT d.dept_name AS department
	CASE e.emp_id
		WHEN COUNT(e.emp_id) < 3 THEN ‘small’
		WHEN COUNT(e.emp_id) > 6 THEN ‘big’
		ELSE ‘medium’
	END AS label
FROM employees e JOIN departments d
	ON e.dept_id = d.dept_id
GROUP BY d.dept_name
ORDER BY d.dept_name;