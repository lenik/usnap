

CREATE TABLE _countries(
	id INT PRIMARY KEY,
	name CHAR(30) NOT NULL,
	lang_id INT NOT NULL,
	area REAL,
	population REAL
);

CREATE TABLE _languages(
	id INT PRIMARY KEY,
	name CHAR(30) NOT NULL,
	right_to_left BOOL DEFAULT FALSE,
	family ENUM('shape', 'sound', 'other') DEFAULT 'sound',
	popular_level REAL
);
