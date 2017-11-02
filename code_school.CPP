//header files included 
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <fstream.h>
#include <string.h>
#include <time.h>
#include <iomanip.h>
#include <stdlib.h>

//using namespace std;

//streams declared
fstream user_file, temp, driver;

//functions prototype declared
void spaces();							//funtions for spaces
void open_in();							//function to open file in input mode
void open_out();						//function to open file in output mode
void close();							//function to close files
int  menu();							//function to provide user menu
void loading();
void ride();							//function for user ride
int  calculation(char a[], char b[]);  //function for calculation
int  login();							//function for user login
void open_temp();						//function to open temprory files
void edit();							//function to exit
void taxi();
void thumb();
void table();
void getdriver();

//classes for users
class info_user
{
	int money;
public:
	void get()
	{
		cout << "Enter your Initial money ";
		cin >> money;
	}
	void credit(int m)
	{
		money += m;
		cout << "MONEY " << money;
	}
	void debit(int m)
	{
		if (money - m > 0)
		{
			money -= m;
			cout << "MONEY " << money;
		}
		else if (money - m < 0)
			cout << "UNABLE TO COMPLETE REQUEST ";
	}
	void dis()
	{
		cout << "Money " << money << endl;
	}
	int paise()
	{
		return money;
	}
};
class user : public info_user
{
	char id[78];
	int  mob_no;
	char name[56];
	int  pin_code;
	int  like;
public:
	void registers()
	{
		system("cls");
		cout << "Enter username ";	cin >> name;
		cout << "Enter mob_no";		cin >> mob_no;
		cout << "Enter pin code ";	cin >> pin_code;
		cout << "Enter password ";	cin >> id;
		info_user::get();
		system("cls");
	}
	void display()
	{
		system("cls");
		spaces(); cout << "Mob_no :: " << mob_no << endl;
		spaces(); cout << "Name :: " << name << endl;
		spaces(); cout << "Pin code :: " << pin_code << endl;
		spaces(); info_user::dis();
	}
	void likes()
	{
		system("cls");
		thumb(); cout << " X " << like;
		//_sleep(700);
		like += 1;
		system("cls");

		thumb(); cout << " X " << like;
	}
	int name_s(char ch[])
	{
		if (strcmp(ch, name) == 0)
			return 1;
		else
			return 0;
	}
	int pass_s(char ch[])
	{
		if (strcmp(ch, id) == 0)
			return 1;
		else
			return 0;
	}
}us;
class driver
{
	char name[45];
	int  id;
	int  age;
	int  expierence;
	char sex[45];
	int  day;
	int  route;
public:
	void calculate_route()
	{
		int maxrand = 6;
		srand((unsigned)time(NULL));
		route = rand() % maxrand + 1;
	}
	void calculate_id()
	{
		int maxrand = 999;
		srand((unsigned)time(NULL));
		id = rand() % maxrand + 1;
	}
	void get()
	{
		spaces(); cout << "Enter name ";		cin >> name;
		spaces(); cout << "Enter Age ";			cin >> age;
		spaces(); cout << "Enter Expierence ";	cin >> expierence;
		spaces(); cout << "Enter Sex(M/F) ";	cin >> sex;
		calculate_id();
		calculate_route();
	}
	void dis()
	{
		spaces(); cout << "Name : " << name;
		spaces(); cout << "Id : " << id;
		spaces(); cout << "Age : " << age;
		spaces(); cout << "Sex(M/F) : " << sex;
		spaces(); cout << "Route : " << route << endl << endl;
		spaces(); cout << "OK YOU CAN JOIN BY "; calculate_day(); cout << endl;
	}
	void calculate_day()
	{
		int maxrand = 6;
		srand((unsigned)time(NULL));
		int j = rand() % maxrand;
		day = j + 1;
		calculate_date();
	}
	void calculate_date()
	{
		if (day == 1)	cout << " Monday	";
		else if (day == 2)	cout << " Tuesday	";
		else if (day == 3)	cout << " Wednesday ";
		else if (day == 4)	cout << " Thrusday	";
		else if (day == 5)	cout << " Friday	";
		else if (day == 6)	cout << " Saturday	";
	}
	void show()
	{
		cout << setw(4) << id << setw(7) << name << setw(10) << sex << setw(13) << age << setw(16) << route << endl;
	}
	void compare(char a[])
	{
		if (strcmp(a, sex) == 0)
			show();
	}
}d;

//code begins
int main()
{
	char ch;
	while (1)
	{
	logout:
		int n, k = 100, m = 100, j;
		loading();
		taxi();

		system("cls");									   //_sleep(700);
		spaces();	cout << "1.For SIGN IN " << endl;      //_sleep(700);
		spaces();	cout << "2.For SIGN UP " << endl;	   //_sleep(700);
		spaces();	cout << "3.Apply for Drivers " << endl;
		cout << endl << endl << endl;
		cout << "Your Choice :: ";
		cin >> n;

		if (n == 1)
		{
			j = login();
			cout << j << endl;

			if (j != 0)
				k = menu();
			else
				exit(0);
		}
		else if (n == 2)
		{
			open_in();
			us.registers();
			user_file.write((char*)&us, sizeof(us));
			close();
		start:
			m = menu();
		}
		else if (n == 3)
		{
			open_out();
			system("cls");
			spaces(); cout << "REGISTRATION FORM   " << endl;

			d.get();
			driver.write((char*)&d, sizeof(d));
			spaces();  cout << "You are REGISTERED !! ";
			system("cls");
			d.dis();
			getch();
			goto logout;
		}
		else exit(0);

		if (m == 1 || k == 1)	goto logout;
		else if (m == 0 || k == 0)	goto start;

		cout << "To use our software again press Y for yes and N for no" << endl;
		cin >> ch;
		if (ch == 'N' || ch == 'n') { break; }
	}
	getch();
}


//funtions included in code
void spaces()
{
	cout << endl << endl << "\t\t ";
}
void open_out()
{
	user_file.open("user.dat", ios::app | ios::out | ios::binary);
	driver.open("driver.dat", ios::app | ios::out | ios::binary);
}
void open_in()
{
	user_file.open("user.dat", ios::app | ios::in | ios::binary);
	driver.open("driver.dat", ios::app | ios::in | ios::binary);
}
void open_temp()
{
	temp.open("temp.dat", ios::app | ios::out | ios::binary);
}
void close()
{
	user_file.close();
	temp.close();
	driver.close();
}
void edit()
{
	remove("user.dat");
	rename("temp.dat", "user.dat");
}
void table()
{
	cout << setw(4) << "________________________________________________________________________" << endl;
	cout << setw(4) << " Id " << setw(7) << "Name " << setw(10) << "Sex " << setw(13) << "Age " << setw(16) << " route " << endl << endl;
	cout << setw(4) << "_______________________________________________________________________" << endl;
}
void thumb()
{
	cout << "      _____		" << endl;
	cout << "      \    |		" << endl;
	cout << "      |    |		" << endl;
	cout << " ____/     \___		" << endl;
	cout << "        		|	" << endl;
	cout << "          ____ /	" << endl;
	cout << "				|	" << endl;
	cout << "          ____ /	" << endl;
	cout << "               |	" << endl;
	cout << "          ____ /	" << endl;
	cout << "               |	" << endl;
	cout << "         ____ /		";
}
void loading()
{
	spaces();
	cout << "L "; //_sleep(700);
	cout << "O "; //_sleep(700);
	cout << "A "; //_sleep(700);
	cout << "D "; //_sleep(700);
	cout << "I "; //_sleep(700);
	cout << "N "; //_sleep(700);
	cout << "G "; //_sleep(700);
	system("cls");
	spaces();
	cout << "L O A D I N G ";	//_sleep(700);	system("cls");

	for (int i = 0; i < 2; i++)
	{
		spaces(); cout << "L O A D I N G .";		//_sleep(700);	system("cls");
		spaces(); cout << "L O A D I N G . .";		//_sleep(700);	system("cls");
		spaces(); cout << "L O A D I N G . . .";	//_sleep(700);	system("cls");
		spaces(); cout << "L O A D I N G  ";		//_sleep(400);	system("cls ");
	}
}
void taxi()
{
	system("cls");
	spaces();
	cout << "W "; //_sleep(400);
	cout << "E "; //_sleep(400);
	cout << "L "; //_sleep(400);
	cout << "C "; //_sleep(400);
	cout << "O "; //_sleep(400);
	cout << "M "; //_sleep(400);
	cout << "E "; //_sleep(700);
	cout << endl << endl << endl;

	spaces(); cout << "t "; //_sleep(700);
	cout << "o "; //_sleep(700);
	cout << endl;
	spaces();
	cout << "Y "; //_sleep(400);
	cout << "O "; //_sleep(400);
	cout << "U "; //_sleep(400);
	cout << "R "; //_sleep(400);
	cout << endl << endl;

	cout << "\t\t\t"; cout << "	||||||||||	||||||||||	  ||||||						" << endl;
	cout << "\t\t\t"; cout << "	||||		||||  ||||    ||||||||||||||||            	" << endl;
	cout << "\t\t\t"; cout << "	||||		||||||||||    ||||||	|||||				" << endl;
	cout << "\t\t\t"; cout << "	||||||||||	||||  ||||    ||||||||||||||||				" << endl;
	//_sleep(700);
}
int  menu()
{
	system("cls");
	int m;
	spaces(); cout << "1.YOUR INFO" << endl;  //_sleep(400);
	spaces(); cout << "2.CREDIT MONEY " << endl;  //_sleep(400);
	spaces(); cout << "3.DEBIT MONEY" << endl;  //_sleep(400);
	spaces(); cout << "4.NEW RIDE " << endl;  //_sleep(400);
	spaces(); cout << "5.LIKE US" << endl;  //_sleep(400);
	spaces(); cout << "6.VIEW OUR DRIVERS" << endl;  //_sleep(400)
	spaces(); cout << "7.LOG OUT" << endl;  //_sleep(400);
	spaces(); cout << "8.EXIT " << endl << endl << endl;  //_sleep(400);	
	cout << "YOUR CHOICE IS :: ";	cin >> m;

	if (m == 1)
	{
		close();	open_in();
		system("cls");
		char password[78];
		int k = 0, n;

		spaces(); cout << "Enter password ::";	cin >> password;
		//system("cls");
		while (!user_file.eof() && user_file.read((char*)&us, sizeof(user)))
		{
			n = us.pass_s(password);
			cout << n << endl;
			if (n == 1)
			{
				k = 0;
				us.display();
				getch();
				break;
			}
			else
				k = 1;
		}
		if (k == 1)
		{
			spaces();  cout << "ERROR "; //_sleep(600);
		}
		close();
	}
	else if (m == 2)
	{
		close();
		open_in();
		open_temp();
		system("cls");
		char password[45];
		cout << "Confirm your pass.. ";
		cin >> password;

		while (!user_file.eof() && user_file.read((char*)&us, sizeof(user)))
		{
			int n = us.pass_s(password);
			if (n == 1)
			{
				int money;
				cout << "Enter money ";
				cin >> money;
				us.credit(money);
				getch();
				temp.write((char*)&us, sizeof(us));
			}
			else
				temp.write((char*)&us, sizeof(us));
		}
		close();
		edit();
	}
	else if (m == 3)
	{
		close();
		open_in();
		open_temp();
		system("cls");
		char password[45];
		cout << "Confirm your pass.. ";
		cin >> password;

		while (!user_file.eof() && user_file.read((char*)&us, sizeof(us)))
		{
			int n = us.pass_s(password);
			if (n == 1)
			{
				int money;
				cout << "Enter money ";
				cin >> money;
				us.debit(money);
				getch();
				temp.write((char*)&us, sizeof(us));
			}
			else
				temp.write((char*)&us, sizeof(us));
		}
		close();
		edit();
	}
	else if (m == 4)
	{
		ride();
	}
	else if (m == 5)
	{
		close();
		open_in();
		open_temp();
		system("cls");
		char password[45];
		cout << "Confirm your pass.. ";
		cin >> password;

		while (!user_file.eof() && user_file.read((char*)&us, sizeof(us)))
		{
			int n = us.pass_s(password);
			if (n == 1)
			{
				us.likes();
				getch();
				temp.write((char*)&us, sizeof(us));
			}
			else
				temp.write((char*)&us, sizeof(us));
		}
		close();
		edit();
	}
	else if (m == 6)
	{
		close();
		system("cls");
		open_in();
		table();
		while (!driver.eof() && driver.read((char*)&d, sizeof(d)))
		{
			d.show();
			getch();
		}
		close();
	}
	else if (m == 7)
	{
		return 1;
	}
	else if (m == 8)
	{
		exit(0);
	}
	return 0;
}
void ride()
{
	system("cls");

	cout << "	////////////       /////////        /////////      /////////////  " << endl;
	cout << "	////      ///        ///              ////  ///    ///          	 " << endl;
	cout << "	///////////         ///              ////   ////   /////////	 " << endl;
	cout << "	//       ///       ///              ///   ///      //		 " << endl;
	cout << "	/       ////  //////////////       //////////      /////	 " << endl;

	system("cls");

	char from[45], to[45];
	spaces(); cout << "FROM :: " << endl;
	spaces(); cout << "A ";
	spaces(); cout << "B ";
	spaces(); cout << "C ";
	spaces(); cout << "D ";
	spaces(); cout << "E ";
	spaces(); cout << "F ";
	spaces(); cout << "G ";
	spaces(); cout << "H " << endl << endl;
	cout << "YOUR CHOICE IS :: "; cin >> from;	 system("cls");

	spaces(); cout << "TO :: " << endl << endl;
	spaces(); cout << "A ";
	spaces(); cout << "B ";
	spaces(); cout << "C ";
	spaces(); cout << "D ";
	spaces(); cout << "E ";
	spaces(); cout << "F ";
	spaces(); cout << "G ";
	spaces(); cout << "H " << endl << endl;
	cout << "YOUR CHOICE IS :: "; cin >> to;		system("cls");

	int money = calculation(from, to);
	int present = us.paise();

	if (money <= present)
	{
		spaces(); cout << "YOUR RIDE IS SUCCESFULLY PLACED ";
		us.debit(money);
		getdriver();
	}
	else if (money > present)
	{
		spaces();  cout << "INSUFFICIENT MONEY ";
	}
	system("cls");
}
int  calculation(char a[], char b[])
{
	int money;
	if (strcmp(a, b) == 0)
		cout << "What non-sense ";
	else if (strcmp(a, "A") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "B") == 0)
	{
		if (strcmp(b, "A") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "C") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "A") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "D") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "A") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "E") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "A") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "F") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "A") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "G") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "A") == 0)money = 7;
		else if (strcmp(b, "H") == 0)money = 8;
	}
	else if (strcmp(a, "H") == 0)
	{
		if (strcmp(b, "B") == 0)	 money = 2;
		else if (strcmp(b, "C") == 0)money = 3;
		else if (strcmp(b, "D") == 0)money = 4;
		else if (strcmp(b, "E") == 0)money = 5;
		else if (strcmp(b, "F") == 0)money = 6;
		else if (strcmp(b, "G") == 0)money = 7;
		else if (strcmp(b, "A") == 0)money = 8;
	}
	return money;
}
int  login()
{
	open_in();
	system("cls");
	char ch[56], ah[78];
	int k = 0;
	spaces(); cout << "Enter username::";	cin >> ch;
	spaces(); cout << "Enter password ::";	cin >> ah;	//_sleep(1000);
	system("cls");

	while (!user_file.eof() && user_file.read((char*)&us, sizeof(user)))
	{
		int n = us.name_s(ch);
		int m = us.pass_s(ah);
		cout << n << " " << m << endl;

		if (n == 1 && m == 1)
		{
			spaces();  cout << "WELCOME ";	//_sleep(600);
			return 1;
			break;
		}
		else
			k = 1;
	}
	if (k == 1)
	{
		spaces();  cout << "ERROR "; //_sleep(600);
		return 0;
	}
	close();
}
void getdriver()
{

	system("cls");
	char n[45];
	int k; char ch = 'y';
	spaces();  cout << "Want MALE driver or FEMALE driver(M/F) ?? ";
	spaces();	cin >> n;
	open_in();
	table();
	while (!driver.eof() && driver.read((char*)&d, sizeof(d)))
	{
		d.compare(n);
	}
	cout << "Choose your Id ::";
	cin >> k;

	spaces(); cout << "RIDE BOOKED !! ";
	spaces(); cout << "THANKS !! ";

	close();
}
