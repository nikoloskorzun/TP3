

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "printed_publication.h"

using namespace std;



printed_publication::~printed_publication()
{
	if (printed_publication::title)
		delete printed_publication::title;	
	if (printed_publication::name_publisher)
		delete printed_publication::name_publisher;
	if (printed_publication::annotation)
		delete printed_publication::annotation;

}


void printed_publication::set_title(char* str)
{

	int len = strlen(str) + 1;

	if (printed_publication::title)
	{
 		delete[] printed_publication::title; 
	}

	printed_publication::title = new char[len];
	strcpy_s(printed_publication::title, len, str);

}
void printed_publication::set_year(int number)
{
	printed_publication::year = number;

}
void printed_publication::set_name_publisher(char* str)
{

	int len = strlen(str) + 1;

	if (printed_publication::name_publisher)
	{
		delete[] printed_publication::name_publisher;
	}

	printed_publication::name_publisher = new char[len];
	strcpy_s(printed_publication::name_publisher, len, str);

}
void printed_publication::set_amount_pages(int number)
{
	printed_publication::amount_pages = number;
}
void printed_publication::set_annotation(char* str)
{

	int len = strlen(str) + 1;

	if (printed_publication::annotation)
	{
		delete[] printed_publication::annotation;
	}

	printed_publication::annotation = new char[len];
	strcpy_s(printed_publication::annotation, len, str);

}



char* printed_publication::get_title()
{
	char* temp = NULL;
	if(printed_publication::title)
	{ 
	int len = strlen(printed_publication::title) + 1;
	temp = new char[len];
	strcpy_s(temp, len, printed_publication::title);
	}
	return temp;
}
int printed_publication::get_year()
{
	return printed_publication::year;
}
char* printed_publication::get_name_publisher()
{
	char* temp = NULL;
	if (printed_publication::name_publisher)
	{
		int len = strlen(printed_publication::name_publisher) + 1;
		temp = new char[len];
		strcpy_s(temp, len, printed_publication::name_publisher);
	}
	return temp;
}
int printed_publication::get_amount_pages()
{
	return printed_publication::amount_pages;
}
char* printed_publication::get_annotation()
{
	char* temp = NULL;
	if (printed_publication::annotation)
	{
		int len = strlen(printed_publication::annotation) + 1;
		temp = new char[len];
		strcpy_s(temp, len, printed_publication::annotation);
	}
	return temp;
}

int printed_publication::write_data_in_file(char* fn)
{
	if (printed_publication::title == NULL || printed_publication::name_publisher == NULL || printed_publication::annotation == NULL)
	{
		cout << "NO\n";
		return 0;
	}

	//sh*t code
	ofstream out;          // поток для записи
	out.open(fn); // окрываем файл для записи
	if (out.is_open())
	{
		out << "title:{"<<printed_publication::title << "}year:{" << printed_publication::year << "}name_publisher:{" << printed_publication::name_publisher << "}amount_pages:{" << printed_publication::amount_pages << "}annotation:{" << printed_publication::annotation << "}\n";
		out.close();
		return 1;
	}
	
	return 0;
}


int printed_publication::read_data_from_file(char* fn)
{
	
	//sh*t code

	std::string line;

	std::ifstream in(fn); // окрываем файл для чтения
	if (in.is_open())
	{
		

		getline(in, line);
	
			
			int start = 0;
			int end = 0;
			int iter = 0;
			int s=0;
			while (iter != -1)
			{
				if (line[iter] == '{')
					start = iter;
				if (line[iter] == '}')
				{
					end = iter;
					char* str = new char[end - start];

					
					
					for (int i = start + 1,  j=0; i < end; i++, j++)
					{
						str[j] = line[i];

					}
					str[end - start-1] = '\0';
					switch (s)
					{
						case 0:
							printed_publication::set_title(str);
							break;
						case 1:
							printed_publication::set_year(stoi(str));
							break;
						case 2:
							printed_publication::set_name_publisher(str);
							break;
						case 3:
							printed_publication::set_amount_pages(stoi(str));
							break;
						case 4:
							printed_publication::set_annotation(str);
							iter = -2;
							break;
					}
					s++;
					delete[] str;
				}

				iter++;
			}



		
		in.close();     // закрываем файл

		return 1;
	}

	return 0;
	
}