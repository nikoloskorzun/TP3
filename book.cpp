#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include "book.h"

using namespace std;

book::book() {
	
	title = NULL;
	year = NULL;
	name_publisher = NULL;
	amount_pages = NULL;
	annotation = NULL;
}
book::book(const book& copy_book)
{
	book::set_title(copy_book.title);
	book::set_year(copy_book.year);
	book::set_name_publisher(copy_book.name_publisher);
	book::set_amount_pages(copy_book.amount_pages);
	book::set_annotation(copy_book.annotation);
}

void book::print()
{
	if (book::title == NULL || book::name_publisher == NULL || book::annotation == NULL)
	{
		cout << "NO";
		return;
	}
	cout << "\book:\n";
	cout << "\t\t\t" << book::title << ", " << book::year;
	cout << "\namount pages: " << book::amount_pages;
	cout << "\npuplisher: " << book::name_publisher;
	cout << "\nanotation:\n" << book::annotation;
}

