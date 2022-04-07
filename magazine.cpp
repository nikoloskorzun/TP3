#include <iostream>


#include "magazine.h"


using namespace std;



magazine::magazine() {
	
	title = NULL;
	year=NULL;
	name_publisher=NULL;
	amount_pages=NULL;
	annotation=NULL;
}
magazine::magazine(const magazine& copy_magazine)
{
	magazine::set_title(copy_magazine.title);
	magazine::set_year(copy_magazine.year);
	magazine::set_name_publisher(copy_magazine.name_publisher);
	magazine::set_amount_pages(copy_magazine.amount_pages);
	magazine::set_annotation(copy_magazine.annotation);
}

void magazine::print()
{
	if (magazine::title == NULL || magazine::name_publisher == NULL || magazine::annotation == NULL)
	{
		cout << "NO";
		return;
	}
	cout << "\nmagazine:\n";
	cout << "\t\t\t"<<magazine::title<<", "<< magazine::year;
	cout << "\namount pages: "<< magazine::amount_pages;
	cout << "\npuplisher: "<< magazine::name_publisher;
	cout << "\nanotation:\n"<< magazine::annotation;
}


