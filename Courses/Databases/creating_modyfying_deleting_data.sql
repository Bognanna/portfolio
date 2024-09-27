--8. Creating new data. Modifying and deleting existing data.

--Ex.1
--Insert information about three new employees (use Employees table). 
INSERT INTO employees (emp_id, surname, name, job, boss_id, hire_date, salary, add_salary, dept_id)
VALUES (300, ‘Snow’, ‘Jack’, ‘PROFESSOR’, 
		(SELECT emp_id FROM employees
		WHERE name = ‘John’ AND surname = ‘Smith’),
	2013-05-01, 4750, NULL,
		(SELECT dept_id FROM departments
		WHERE dept_name = ‘EXPERT SYSTEMS’));
INSERT INTO employees (emp_id, surname, name, job, boss_id, hire_date, salary, add_salary, dept_id)
VALUES (310, ‘Cook’, ‘Robin’, ‘PROFESSOR’, 
		(SELECT emp_id FROM employees
		WHERE name = ‘John’ AND surname = ‘Smith’),
	 2016-09-15, 3500, 1250, 
		(SELECT dept_id FROM departments
		WHERE dept_name = ‘ALGORITHMS’));
INSERT INTO employees (emp_id, surname, name, job, boss_id, hire_date, salary, add_salary, dept_id)
VALUES (320, ‘Dormand’, ‘Francis’, ‘ASSISTANT’, 
		(SELECT emp_id FROM employees
		WHERE name = ‘Carl’ AND surname = ‘Jones’),
 2018-01-01, 3900, NULL, 
		(SELECT dept_id FROM departments
		WHERE dept_name = ‘ALGORITHMS’));

-- Display all information about new employees. 
SELECT *
FROM employees
WHERE emp_id = 300 OR emp_id = 310 OR emp_id = 320
ORDER BY emp_id;

--Ex.2
-- Define a new department DATABASE SYSTEMS. Its identifier should be set to 70, leave address 
-- unset. Display all information about new department. 
INSERT INTO departments (dept_id, dept_name, address)
VALUES (70, ‘DATEBASE SYSTEMS’, NULL);
SELECT *
FROM departments
WHERE dept_id = 70;

--Ex.3
-- Move new employees (defined in p. 1.) to department DATABASE SYSTEMS. Then display 
-- employees of this department. 
UPDATE employees
SET dept_id = 70
WHERE emp_id = 300 OR emp_id = 310 OR emp_id = 320;
SELECT surname, name, salary, add_salary
FROM employees
WHERE dept_id = 70
ORDER BY surname;

--Ex.4
-- Give a rise for employees of DATABASE SYSTEMS. Their salaries should be increased by 10%, 
-- their additional salaries by 20%. If employee has not an additional salary, set its value to 100. Try 
-- make all modifications using one command. Display new values of employees’ salaries. 
UPDATE employees
CASE
	WHEN COALESCE(salary) = 0 THEN SET add_salary = 100
	ELSE SET salary = salary * 1.2
WHERE dept_id = 70;
SELECT surname, name, salary, add_salary
FROM employees
WHERE dept_id = 70
ORDER BY surname;

--Ex.5
-- Once again give a raise to employees of departments DATABASE SYSTEMS. This time a raise 
-- should be equal to 10% of an average salary in department ADMINISTRATION. Display new 
-- values of employees’ salaries. 
UPDATE employees
SET  salary = salary +
	(SELECT 0.1 * AVG(salary)
	FROM employees JOIN departments USING (dept_id)
	WHERE dept_name = ‘ADMINISTRATION’)
WHERE dept_id =
	(SELECT dept_id
	FROM departments
	WHERE dept_name = ‘DATEBASE SYSTEMS’);
SELECT surname, name, salary
FROM employees
WHERE dept_id = 70
ORDER BY surname;

--Ex.6
-- Try to delete department DATABASE SYSTEMS. Why does this operation finish with error? 
DELETE FROM departments
WHERE dept_name = ‘DATABASE SYSTEMS’;

--Ex.7
-- Delete those employees of department DATABASE SYSTEMS who earn less than 5000. 
-- Remaining employees of this department leave without department. Use two commands. Next 
-- display all employees. 
DELETE FROM employees
WHERE jdept_id =
	(SELECT dept_id
	FROM departments
	WHERE dept_name = ‘DATEBASE SYSTEMS’)
AND salary < 5000;
UPDATE employees
SET dept_id = NULL
WHERE dept_id = 
	(SELECT dept_id
	FROM departments
	WHERE dept_name = ‘DATEBASE SYSTEMS’);
SELECT *
FROM employees
ORDER BY emp_id;

--Ex.8
-- Once again try to delete department DATABASE SYSTEMS. Next display information about all 
-- departments. 
DELETE FROM departments
WHERE dept_name = ‘DATABASE SYSTEMS’;

SELECT *
FROM departments
ORDER BY dept_id;

--Ex.9
-- Delete employee Jack Snow (the one you have inserted at the beginning). Then display current data 
-- of Employees table. 
DELETE FROM employees
WHERE name = ‘Jack’ AND surname = ‘Snow’;
SELECT *
FROM employees
ORDER BY emp_id;