#include <iostream>



#include "printed_publication.h"
#include "magazine.h"
#include "textbook.h"
#include "book.h"

using namespace std;


int get_int()
{
	cout << "input int: ";
	int n;
	cin >> n;
	return n;
}


char* get_str(int n)
{



	cout << "input str: ";
	
	char *s = new char[n];
	gets_s(s, n);
	gets_s(s, n);
	return s;
}

int main()
{





	int exit = 1;
	magazine m;
	book b;
	textbook t;


	
	printed_publication *arr[3];


	arr[0] = &m;
	arr[1] = &b;
	arr[2] = &t;

	
	int c1;
	char* c2;


	cout << "input max str len:\n";
	int n = get_int();

	while (exit)
	{
		cout << "\nMENU:\n";
		cout << "1:<class>.read_data_from_file\n";
		cout << "2:<class>.write_data_to_file\n";
		cout << "3:<class>.print()\n";
		cout << "4:<class>.<set>()\n";
		cout << "0:exit\n";




		switch (get_int())
		{
		case 1:
			cout << "\n?\n";
			cout << "1:magazine\n";
			cout << "2:book\n";
			cout << "3:textbook\n";
			cout << "0:return\n";
			

			c1 = get_int();
			
			if(c1 == 1 || c1==2|| c1==3)
			{ 
			cout << "input file path:\n";
			c2 = get_str(n);
			
			if (arr[c1 - 1]->read_data_from_file(c2) == 0)
				cout << "error\n";
			delete[] c2;
			}
		

			break;
		case 2:

			cout << "\n?\n";
			cout << "1:magazine\n";
			cout << "2:book\n";
			cout << "3:textbook\n";
			cout << "0:return\n";


			c1 = get_int();

			if (c1 == 1 || c1 == 2 || c1 == 3)
			{
				cout << "input file path:\n";
				c2 = get_str(n);

				if (arr[c1 - 1]->write_data_in_file(c2) == 0)
					cout << "error\n";
				delete[] c2;
			}

			break;
		case 3:
			cout << "\n?\n";
			cout << "1:magazine\n";
			cout << "2:book\n";
			cout << "3:textbook\n";
			cout << "0:return\n";


			c1 = get_int();

			if (c1 == 1 || c1 == 2 || c1 == 3)
			{
			arr[c1 - 1]->print();
			}


			

			break;
		case 4:


			cout << "\n?\n";
			cout << "1:magazine\n";
			cout << "2:book\n";
			cout << "3:textbook\n";
			cout << "0:return\n";


			c1 = get_int();

			if (c1 == 1 || c1 == 2 || c1 == 3)
			{
				
				cout << "\n?\n";
				cout << "1:title\n";
				cout << "2:year\n";
				cout << "3:name_publisher\n";
				cout << "4:amount_pages\n";
				cout << "5:annotation\n";
				cout << "0:return\n";

				/*
				void set_title(char* str);
				void set_year(int number);
				void set_name_publisher(char* str);
				void set_amount_pages(int number);
				void set_annotation(char* str);
				*/
				switch (get_int())
				{

				case 1:
					cout << "input title:\n";
					c2 = get_str(n);
					arr[c1 - 1]->set_title(c2);
					delete[] c2;
					break;
					
				case 2:
					cout << "input year:\n";
					
					arr[c1 - 1]->set_year(get_int());
					break;
					
				case 3:
					cout << "input name publisher:\n";
					c2 = get_str(n);
					arr[c1 - 1]->set_name_publisher(c2);
					delete[] c2;
					break;
					
				case 4:
					cout << "input amount pages:\n";

					arr[c1 - 1]->set_amount_pages(get_int());
					break;
					
				case 5:
					cout << "input annotation:\n";
					c2 = get_str(n);
					arr[c1 - 1]->set_annotation(c2);
					delete[] c2;
					break;

				default:
					break;

				}


			}




			break;		
		case 0:

			exit = 0;
			break;

	
		default:
			cout << "nope\n";
			break;
		}


	}



	return 0;

}
