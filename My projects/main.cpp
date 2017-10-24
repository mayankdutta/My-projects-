#include <iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<stdlib.h>

using namespace std;
class employee
{
    int id;
    char name[20];
    int salary;
public:
    employee()
    {    }
    ~employee()
    {    }
    void setid(int tid)
    {
        id=tid;
    }
    int getID()
    {
        return (id);
    }
    void setData()
    {
        cout<<"\n Enter the Name :";
        cin>>name;
        cout<<"\n Enter the Salary :";
        cin>>salary;
    }
    void display()
    {
        cout<<id;
        cout<<"\t"<<name;
        cout<<"\t"<<salary;
    }
};

void append_Employee();
void display_All_Employee();
void modify_Employee();
void delete_Employee();
void search_Employee();

int getSizeofFile();
int getID();

char fname[]={"one.dat"};//actual file
char fid[]={"fid.dat"};//Id related information

int main()
{
    char choice='y';
    int ch;
    while(choice=='y'||choice=='Y')
    {
        cout<<"\t\t Welcome to Employee Management System\n\n";
        cout<<"1. Add New Employee \n\n";
        cout<<"2. Modify Existing Employee Details \n\n";
        cout<<"3. Delete Employee\n\n";
        cout<<"4. Search Employee by ID \n\n";
        cout<<"5. Display All Employee Details \n\n";
        cout<<"=======================================================\n\n";
        cout<<"\nPlease Enter your choice :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            append_Employee(); break;
        case 2:
            modify_Employee(); break;
        case 3:
            delete_Employee(); break;
        case 4:
            search_Employee(); break;
        case 5:
            display_All_Employee(); break;
        default:
            cout<<"\n============ Wrong Choice ============\n"; break;
        }
        cout<<"\n\n ========== Do you Want to Continue ============\n\n";
        choice=getche();
    }
    return 0;
}

int getID()
{
ifstream fin(fid,ios::binary);
int value=0;
if(!fin)
{
    fin.close();
    ofstream fout(fid,ios::binary);
    fout<<0;
    fout.close();
    fin.open(fid,ios::binary);
}
fin>>value;
fin.close();

ofstream fout(fid,ios::binary);
fout<<value+1;

fout.close();

return (value + 1);
}

void append_Employee()
{
    employee emp;
    fstream fout(fname,ios::app|ios::out);

    emp.setid(getID());
    emp.setData();

    fout.write((char *)&emp, sizeof(emp));
    fout.close();
}

void modify_Employee()
{
    employee emp;
    int fsize=getSizeofFile();

    fstream fout(fname,ios::ate|ios::out|ios::in);
    fout.seekg(0);

    int id;
    int counter=0;

    cout<<"\nEnter the Employee ID :";
    cin>>id;

    if(!fout)
    {
        cout<<"\n Sorry no record found \n";
    }
    else
    {
        for(int i=0 ; i <fsize ; i++)
    {
       fout.read((char *) &emp , sizeof(emp));
        if(emp.getID()==id)
        {
            int fsize=fout.tellg();
            fsize = fsize - sizeof(emp);
            fout.seekp(fsize , ios::beg);

            employee newobj = emp;
            newobj.setData();
            fout.write((char *)&newobj , sizeof(newobj));

            counter = 1;
            break;
        }
        cout<<"\n";
    }
    }
    fout.close();

    if(counter==0)
    {
        cout<<"\n\n Sorry No Record Found \n";
    }
    else
    {
        cout<<"\n Record Updated \n";
    }
}

int getSizeofFile()
{
    int filesize;
    int total;
    employee obj;
    ifstream fin(fname,ios::binary);
    fin.seekg(0,ios::end);//move read pointer to lass byte

    total = fin.tellg();
    filesize = total / sizeof(obj);
    return (filesize);
}

void delete_Employee()
{
    employee emp;
    int fsize=getSizeofFile();
    ifstream fin(fname);
    ofstream fout("temp.dat");

    int id;
    int counter=0;

    cout<<"Enter the Employee ID to be deleted:";
    cin>>id;

    if(!fin)
    {
        cout<<"\n Sorry no record found\n";
    }
    else
    {
        for(int i=0 ; i<fsize ; i++)
        {
            fin.read((char *)&emp , sizeof(emp));
            if(emp.getID()==id)
            {
                counter=1;
            }
            else
            {
                fout.write((char *)&emp, sizeof(emp));
            }
        }
    }
    fin.close();
    fout.close();
    if(counter==0)
    {
        cout<<"\n == Sorry no record found \n";
    }
    else
    {
        fin.open("temp.dat");
    fout.open(fname);

    for(int i = 0; i<fsize - 1;i++)
    {
        fin.read((char *)&emp, sizeof(emp));

        fout.write((char * )&emp , sizeof(emp));
    }
    fin.close();
    fout.close();
    }
}

void search_Employee()
{
    employee emp;
    int fsize=getSizeofFile();
    int id=0;
    int counter=0;

    cout<<"Enter the Employee ID";
    cin>>id;

    ifstream fin(fname);
    cout<<"\n===========================\n";
    cout<<"\n\t\t Employee Details\n\n";
    cout<<"ID\tName\tSalary\n\n";

    for (int i = 0; i< fsize; i++)
    {
        fin.read((char *)&emp , sizeof(emp));
        if(emp.getID()==id)
        {
            emp.display();
            counter=1;
        }
        cout<<endl;
    }
    fin.close();
    if(counter==0)
    {
        cout<<"\n Sorry no record found \n";
    }
}
void display_All_Employee()
{
    employee emp;
    int fsize= getSizeofFile();

    ifstream fin(fname);
    if(!fin)
    {
        cout<<"Sorry No record is found \n";
    }
    else
    {
        cout<<"\n\t\t All Employee Details are \n";
        cout<<"ID\tName\tSalary\n\n";
        for(int i=0; i<fsize ;i++)
        {
            fin.read((char *)&emp , sizeof(emp));
            emp.display();
            cout<<endl;
        }
    }
    fin.close();
}
