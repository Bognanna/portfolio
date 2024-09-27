--11. Views
--Ex.1
CREATE VIEW professors(name, surname, hire_date, salary, add_salary, add_percent) AS
	SELECT  name, surname, hire_date, salary, add_salary, 
		COALESCE(add_salary, 0) / salary * 100) 
	FROM employees
	WHERE job = ‘PROFESSOR’;
SELECT * 
FROM professors
ORDER BY surname;
--Ex.2
CREATE VIEW departments_totals (dept_id, department, avg_salary, num_of_empls) AS
	SELECT d.dept_id, d.dept_name, AVG(e.salary), COUNT(e.emp_id)
	FROM departments d JOIN emploees e ON (dept_id)
	GROUP BY dept_id;
SELECT *
FROM departments_totals
ORDER BY dept_id;
--Ex.3
SELECT e.surname, e.name, e.salary, d.department, d.avg_salary, ABS(d.avg_salary – e.salary) AS ‘diff’
FROM employees e JOIN departments_totals d ON dept_id
WHERE e.salary > d.avg_salary
ORDER BY surname;
--Ex.4
SELECT department, num_of_empls
FROM departments_totals
WHERE num_of_empls = 
	SELECT MAX(num_of_empls)
	FROM departments_totals;

--Ex.5
CREATE VIEW emps_and_bosses (employee, emp_salary, boss, boss_salary) AS
	SELECT e.surname||’ ‘||e.name, e.salary, b.surname || ‘ ‘ || b.name, b.salary
	FROM e employees JOIN b employees ON (boss_id)
	WHERE e.salary < b.salary
	ORDER BY e.surname;
