
create database people;

use people;

create table person(
	id int auto_increment,
	name varchar(100),
	gender char(1),
	age int,
	primary key person_pk(id)
	);

create table friend(
	a int not null,
	b int not null,
	primary key friend_pk(a, b)
	);
