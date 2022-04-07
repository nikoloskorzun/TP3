#pragma once

#define NULL 0

//abstract
class printed_publication
{
public:

	
	printed_publication() {
		title = NULL;
		year = NULL;
		name_publisher = NULL;
		amount_pages = NULL;
		annotation = NULL;
	};
	virtual ~printed_publication();
	virtual void print() = 0;
	virtual int write_data_in_file(char* fn);
	virtual int read_data_from_file(char *fn);

	void set_title(char *str);
	void set_year(int number);
	void set_name_publisher(char *str);
	void set_amount_pages(int number);
	void set_annotation(char *str);
	
	char* get_title();
	int get_year();
	char* get_name_publisher();
	int get_amount_pages();
	char* get_annotation();
	


	



protected: 
	char *title;
	int year;
	char *name_publisher;
	int amount_pages;
	char* annotation;
	


};
