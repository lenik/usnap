

# configures
CREATE TABLE posdoc_config(
	name CHAR(20) PRIMARY KEY,
	value CHAR(100) PRIMARY KEY
	);


# document arch
CREATE TABLE posdoc_graph_t(
	n1 INT,
	n2 INT,
	relation ENUM('parent', 'child', 'neighbour') DEFAULT 'child'
	);
CREATE TABLE posdoc_doctree LIKE posdoc_graph_t;


# document units
CREATE TABLE posdoc_docs(
	id INT PRIMARY KEY,
	tcid CHAR(10) UNIQUE,
	classid INT,
	t_subject TEXT,
	t_author TEXT,
	t_keyword TEXT,
	t_summary TEXT,
	t_seealso TEXT,
	);

	# stream template
	CREATE TABLE posdoc_stream_t(
		docid INT PRIMARY KEY,
		stm_typeid INT,
		t_text TXT,
		);

	CREATE TABLE posdoc_stm_typeid(
		id INT AUTO_INCREMENT PRIMARY KEY,
		typename VARCHAR(50),
		default_media VARCHAR(200);
		);


	# more streams were created dynamicly.
	CREATE TABLE posdoc_stm0 LIKE posdoc_stream_t;




# initialize data
INSERT INTO posdoc_config VALUES('created_streams', '1');
INSERT INTO posdoc_stm_typeid VALUES(0, 'main stream', NULL);
