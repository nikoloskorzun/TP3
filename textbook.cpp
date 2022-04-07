#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include "textbook.h"

using namespace std;

textbook::textbook() {
	title = NULL;
	year = NULL;
	name_publisher = NULL;
	amount_pages = NULL;
	annotation = NULL;
}
textbook::textbook(const textbook& copy_textbook)
{
	textbook::set_title(copy_textbook.title);
	textbook::set_year(copy_textbook.year);
	textbook::set_name_publisher(copy_textbook.name_publisher);
	textbook::set_amount_pages(copy_textbook.amount_pages);
	textbook::set_annotation(copy_textbook.annotation);
}

void textbook::print()
{
	if (textbook::title == NULL || textbook::name_publisher == NULL || textbook::annotation == NULL)
	{
		cout << "NO";
		return;
	}
	cout << "\ntextbook:\n";
	cout << "\t\t\t" << textbook::title << ", " << textbook::year;
	cout << "\namount pages: " << textbook::amount_pages;
	cout << "\npuplisher: " << textbook::name_publisher;
	cout << "\nanotation:\n" << textbook::annotation;

}

