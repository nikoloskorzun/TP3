#pragma once
#include "printed_publication.h"

class book final : public printed_publication
{
public:

	book();
	book(const book& copy_book);

	virtual void print() override;

};
