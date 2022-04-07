#pragma once
#include "printed_publication.h"

class textbook : public printed_publication
{
public:

	textbook();
	textbook(const textbook& copy_textbook);

	virtual void print();
	
};
