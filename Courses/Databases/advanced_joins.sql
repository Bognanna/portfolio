--5.2 Advanced Joins
--Ex.1
SELECT employees.name, employees.surname, departments.dept_name, departments.address
FROM employees LEFT JOIN departments
	ON employees.dept_id = departments.dept_id
ORDER BY employees.surname;

--Ex.2
SELECT employees.name, employees.surname, departments.dept_name, departments.address
	CASE departments.dept_name
		WHEN departments.dept_name IS NULL THEN ‘no department’
		ELSE departments.dept_name
	END AS dept_name
	CASE departments.address
		WHEN departments.address IS NULL THEN ‘no department’
		ELSE departments.address
	END AS address
FROM employees LEFT JOIN departments
	ON employees.dept_id = departments.dept_id
ORDER BY employees.surname;

--Ex.3
SELECT employees.name, employees.surname, departments.dept_name, departments.address
	CASE departments.dept_name
		WHEN departments.dept_name IS NULL THEN ‘no department’
		ELSE departments.dept_name
	END AS dept_name
	CASE departments.address
		WHEN departments.address IS NULL THEN ‘no department’
		ELSE departments.address
	END AS address
	CASE employee.name
		WHEN employee.name IS NULL THEN ‘no employee’
		ELSE employee.name
	END AS dept_name
	CASE  employee.surname
		WHEN employee.surname IS NULL THEN ‘no employee’
		ELSE  employee.surname
	END AS address
FROM employees FULL JOIN departments
	ON employees.dept_id = departments.dept_id
ORDER BY employees.surname;

--Ex.4
SELECT d.dept_name AS department, COUNT(e.emp_id) AS employees_at_dept, TO_CHAR(SUM(e.salary), ‘9999.99’) AS salaries_at_dept
FROM employees e RIGHT JOIN department d
GROUP BY d.dept_name
ORDER BY d.dept_name;

--Ex.5
SELECT e.surname AS employee, b.surname AS boss
	CASE b.surname
		WHEN b.surname IS NULL THEN ‘no boss’
		ELSE b.surname
	END AS boss
FROM employees e LEFT JOIN employees b
	ON e.boss_id = b.emp_id
ORDER BY employee;

--Ex.6
SELECT e.surname AS employee, b.surname AS boss
	CASE b.surname
		WHEN b.surname IS NULL THEN ‘no boss’
		ELSE b.surname
	END AS boss
FROM employees e LEFT JOIN employees b
	ON e.boss_id = b.emp_id
	AND b.surname = ‘Smith’ OR b.surname = ‘Wilson’
ORDER BY employee;

--Ex.7
SELECT e.surname AS employee, TO_CHAR(12*(e.salary+COALESCE(add_salary,0)), ‘9999.99’) AS emp_annual_salary, TO_CHAR(12*(b.salary + COALESCE(b.add_salary,0) – e.salary – COALESCE(e.add_salary,0)), ‘9999.99’) AS less_than_boss
FROM employees e JOIN employees b
	ON e.boss_id = b.emp_id
ORDER BY employee;

--Ex.8
SELECT b.surname AS boss, COUNT(e.boss_id) AS subordinates
FROM employees e JOIN empoloyees b
	ON e.boss_id = b.emp_id
ORDER BY employee;

--Ex.9
SELECT e.name || ‘ ‘ || e.surname AS employee, d.dept_name AS employee_department, b.name || ‘  ‘ || b.surname AS boss, d.dept_name AS boss_department
FROM employees e JOIN departments d USING(dept_id) JOIN employees b  ON e.boss_id = b.emp_id
ORDER BY employee;

--Ex.10
SELECT e.name || ‘ ‘ || e.surname AS employee, d.dept_name AS employee_department, b.name || ‘  ‘ || b.surname AS boss, d.dept_name AS boss_department
	CASE boss
		WHEN boss IS NULL THEN ‘no boss’
		ELSE  b.name || ‘  ‘ || b.surname
	END AS boss
	CASE d.dept_name
		WHEN d.dept_name IS NULL THEN ‘no department’
		ELSE  d.dept_name
	END AS boss_departments
FROM employees e JOIN departments d USING(dept_id) LEFT JOIN employees b  ON e.boss_id = b.emp_id
ORDER BY employee;

--Ex.11
SELECT COUNT(e.emp_id) AS rows_of_cartesian_product
FROM employees CROSS JOIN departments CROSS JOIN jobs;
