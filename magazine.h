#pragma once
#include "printed_publication.h"


class magazine : public printed_publication
{

	
public:
	
	magazine();
	magazine(const magazine& copy_magazine);
	
	virtual void print();
};
