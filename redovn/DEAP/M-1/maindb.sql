
# data defs.
CREATE TABLE person_basic(
	id INT AUTO_INCREMENT PRIMARY KEY,
	name CHAR(50) UNIQUE,
	);

CREATE TABLE person_phy(
	person_id PRIMARY KEY,
	sex ENUM('m','f'),
	birthday DATETIME,
	blood_type CHAR(10),
	);

# environment / person live in
CREATE TABLE person_env(
	person_id PRIMARY KEY,
	longitude REAL,
	latitude REAL,
	);

CREATE TABLE person_culture(
	person_id PRIAMRY KEY,
	mother_country_id INT,
	);


# task templates, each task name as task_<person name>
CREATE TABLE t_task(
	id INT AUTO_INCREMENT PRIMARY KEY,
	name CHAR(100),

	INDEX idx_name(name)
	);

CREATE TABLE t_