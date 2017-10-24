/*
____________________
HEADER FILE INCLUDED 
____________________
*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>

using namespace std;




/*
_____________________
STRUCTURE FOR RECORDS
_____________________
*/
struct info
{
	int id;
	char name[34];
}s; // OBJECT DECLARED 

/*
__________________
DECLARING STREAMS
___________________
*/
fstream a, b;   

/*
___________________________
FUNCTION PROTOTYPE DECLARED
___________________________
*/
void display();     // TO DISPLAY DATA
void add();			//TO ADD DATA
void del();			//TO DELETE DATA
void srh();			//TO SEARCH DATA
void mod();			//TO MODIFY DATA 
int choice();		//TO GET CHOICE
void enter();		//TO ENTER DATA FROM USER
void assign(int n);	//TO ASSIGN CHOICE OF USER
void intro();		//TO INTRODUCE PROGRAMMER
void edit();		//TO EDIT STREAMS
void open();		//TO OPEN STREAMS
void close();		//TO CLOSE STREAMS



/*
______________
PROGRAM STARTS 
______________
*/
void main()
{
	system("cls");
	intro();
	enter();

	int i=1;

	do 
	{
		system("cls");

		cout << "           ____________" << endl;
		cout << "          |   WELCOME  |" << endl;
		cout << "          |____________|" << endl << endl << endl;

		int n = choice();
		assign(n);

		cout << endl << endl;
		i = getch();

	} while (i != 0);

	cout << "Want to Use Again(0 for exit) !! ";
	cin >> i;

	getch();
}

//______________________________________________________________________________

/*
____________________
FUNCTION DEFINATIONS
____________________
*/

//__________________
// TO INTRODUCE USER
//__________________
void intro()  
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t By Mayank " << endl;
	getch();
}

//________________
// TO OPEN STREAMS
//________________
void open()
{
	a.open("info ", ios::in | ios::app | ios::binary);
	b.open("info2", ios::out | ios::app | ios::binary);
}


//_________________
// TO CLOSE STREAMS
//_________________
void close()
{
	a.close();
	b.close();
}


//________________
// TO EDIT STREAMS 
//________________
void edit()  
{
	remove("info");
	rename("info2", "info");
}


//________________________
//FUNCTION TO DISPLAY DATA 
//________________________
void display()     
{
	system("cls");
	open();	//TO OPEN STREAMS
	while (!a.eof() && a.read((char*)&s, sizeof(info)))
	{
		cout << "Name = " << s.name << endl;
		cout << "Id = " << s.id << endl;
	}
	close();	//TO CLOSE STREAMS
}

//_____________________
//FUNCTION TO ADD RECORD
//_____________________
void add()
{
	system("cls");
	int i = 1;
	open();		//TO OPEN STREAMS

	do
	{
		cout << "Name = ";
		cin >> s.name;
		cout << "Id = ";
		cin >> s.id;

		a.write((char*)&s, sizeof(info));
		cout << "Enter more (0 for NOT) ";
		cin >> i;
		
	} while (i != 0);
	

	close();		//TO CLOSE STREAMS
	display();     // TO DISPLAY DATA
}

//________________________
//FUNCTION TO DELETE RECORD
//________________________
void del()		
{
	system("cls");
	open();		//TO OPEN STREAMS

	int n, k=1;
	cout << "Enter id ";
	cin >> n;

	while (!a.eof() && a.read((char*)&s, sizeof(info)))
	{
		if (n == s.id)
		{
			cout << "Name = " << s.name << endl;
			cout << "Id = " << s.id << endl;

			cout << "Are you Sure (0/1) ";
			k = getch();

			if (k == 0)
			{
				b.write((char*)&s, sizeof(info));
			}

		}

		else
		{
			b.write((char*)&s, sizeof(info));
		}
	}
	close();	//TO CLOSE STREAMS

	edit(); //TO EDIT STREAMS
	
	display();     // TO DISPLAY DATA

}

//__________________________
//FUNCTION TO PERFORM SEARCH
//__________________________
void srh()			
{
	system("cls");
	open();	//TO OPEN STREAMS

	int n;
	cout << "Enter id ";
	cin >> n;

	while (!a.eof() && a.read((char*)&s, sizeof(info)))
	{
		if (n == s.id)
		{
			cout << "Name = " << s.name << endl;
			cout << "Id = " << s.id << endl;
		}
	}
	close();	//TO CLOSE STREAMS

}

//______________________________
//FUNCTION FOR MODIFIYING VALUES 
//______________________________
void mod()		
{
	system("cls");
	
	int n, k;
	cout << "Enter id ";
	cin >> n;

	open();	//TO OPEN STREAMS

	while (!a.eof() && a.read((char*)&s, sizeof(info)))
	{
		if (n == s.id)
		{
			cout << "Name = ";
			cin >> s.name;
			cout << "Id = ";
			cin >> s.id;

			b.write((char*)&s, sizeof(info));
		}

		else
		{
			b.write((char*)&s, sizeof(info));
		}
	}
	close(); //TO CLOSE STREAMS
	edit(); //TO EDIT STREAMS 
	display(); // TO DISPLAY DATA

}

//_____________________________________
//FUNCTION FOR ENTERING CHOICE OF USERS
//_____________________________________
int choice()		 
{
	system("cls");
	int n;

	cout << "1.View " << endl;
	cout << "2.Add " << endl;
	cout << "3.Delete " << endl;
	cout << "4.Search " << endl;
	cout << "5.Modify" << endl << endl;
	cout << "Your Choice = ";
	cin >> n;


	return n;
}

//_________________________________
//FUNCTION FOR GETTING INFORMATIONS
//_________________________________
void enter()		 
{
	system("cls");
	fstream a;
	a.open("info", ios::out | ios::binary);
	int i = 0;
	while (i != 3)
	{
		cout << "Name = ";
		cin >> s.name;
		cout << "ID = ";
		cin >> s.id;
		cout << endl;

		a.write((char*)&s, sizeof(info));
		i++;
	}
	a.close();
}

//___________________________________________
//FUCITON TO ASSIGN VLAUES TO OTHER FUNCTIONS
//___________________________________________
void assign(int n)
{
	if (n == 1)
	{
		display();     // TO DISPLAY DATA
	}

	else if (n == 2)
	{
		add();
	}

	else if (n == 3)
	{
		del();
	}

	else if (n == 4)
	{
		srh();
	}

	else if (n == 5)
	{
		mod();
	}
}
