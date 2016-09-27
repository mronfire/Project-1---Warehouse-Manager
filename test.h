/*
 * This file will exist instead of the objects I don't have yet
 * during the first sprint while we make the parts of the program
 * that would read data into the objects
 */

#ifndef TEST_H_
#define TEST_H_

#include "header.h"

struct purchase
{
	string	date;
	string	memNum;
	string	item;
	float 	price;
	int		quant;
	purchase *memptr = NULL;
	purchase *dayptr = NULL;
};

struct member
{
	string	name;
	string	num;
	bool	exec;
	string	date;
	member *ptr = NULL;
	purchase *purchList = NULL;
	purchase *lastPurch = NULL;
};

const int NUMDAYS = 5;

struct salesDay
{
	int day;
	salesDay *ptr = NULL;
	purchase *purchList = NULL;
	purchase *lastPurch = NULL;
};





#endif /* TEST_H_ */
