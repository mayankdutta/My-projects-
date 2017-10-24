#include <iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<string>

using namespace std;

class Lic_Of_India
{
    float policy_no, sum_assured, premium;
    char name[30];
    char DOB[20];
    char DOP[20];
    char DOC[20];
    char tin_no[30];
    char address[100];
    char mode_of_payment[30];
    char nominee[30];
    char phone[20];

public:
    void getdata()
    {
        cout<<"\nEnter the policy no=>";
        cin>>policy_no;
        cout<<endl<<"Enter the name of policy holder=>";
        cin.ignore();
        cin.getline(name,29);
        cout<<endl<<"Enter the address of policy holder=>";
        //cin.ignore();
        cin.getline(address,99);
        cout<<endl<<"Enter the tin no.=>";
        //cin.ignore();
        cin.getline(tin_no,29);
        cout<<endl<<"Enter the DOB(DD/MM/YYYY)=>";
        //cin.ignore();
        cin.getline(DOB,19);
        cout<<endl<<"Enter the DOP(DD/MM/YYYY)=>";
        //cin.ignore();
        cin.getline(DOP,19);
        cout<<endl<<"Enter the DOC(DD/MM/YYYY)=>";
        //cin.ignore();
        cin.getline(DOC,19);
        cout<<endl<<"Enter the sum assured=>";
        cin>>sum_assured;
        cout<<endl<<"Enter the premium=>";
        cin>>premium;
        cout<<endl<<"Enter the nominee=>";
        cin.ignore();
        cin.getline(nominee, 29);
        cout<<endl<<"Enter the mode of payment=>";
        //cin.ignore();
        cin.getline(mode_of_payment, 19);
        cout<<endl<<"Enter the contact no.=>";
        cin>>phone;
    }

    void putdata()
    {
        cout<<endl<<"------------------------------------------------------------------------------------------------";
        cout<<endl<<"\t\t\tPolicy number:-"<<policy_no;
        cout<<endl<<"------------------------------------------------------------------------------------------------";
        cout<<endl<<"Name:-"<<name;
        cout<<endl<<"Address:-"<<address;
        cout<<endl<<"TIN.NO:-"<<tin_no;
        cout<<endl<<"DOB(DD/MM/YYYY):-"<<DOB;
        cout<<endl<<"DOP(DD/MM/YYYY):-"<<DOP;
        cout<<endl<<"DOC(DD/MM/YYYY):-"<<DOC;
        cout<<endl<<"Sum Assured:-"<<sum_assured;
        cout<<endl<<"Nominee:-"<<nominee;
        cout<<endl<<"Premium:-"<<premium;
        cout<<endl<<"Mode of payment:-"<<mode_of_payment;
        cout<<endl<<"Contact no:-"<<phone;
    }

    int ret_policy_no()
    {
        return policy_no;
    }

};

int getsizeoffile()
{
    int filesize;
    int total;
    Lic_Of_India obj;
    ifstream fin("record.dat", ios::binary);
    fin.seekg(0, ios::end);
    total=fin.tellg();
    filesize=total/sizeof(obj);
    return(filesize);
    fin.close();
}

void add_member()
{
    system("cls");
    Lic_Of_India emp;
    fstream fout("record.dat",ios::app|ios::out|ios::binary);
    emp.getdata();
    fout.write((char*)&emp, sizeof(emp));
    fout.close();
}
void modify_member()
{
    system("cls");
    Lic_Of_India emp;
    int fsize=getsizeoffile();
    fstream fout("record.dat", ios::app|ios::out|ios::in);
    fout.seekg(0);
    int policy_no;
    cout<<"\nEnter the policy no which do you want to modify:-";
    cin>>policy_no;
    for(int i=0; i<fsize; i++)
    {
        fout.read((char*)&emp, sizeof(emp));
        if(emp.ret_policy_no()==policy_no)
        {
            int fsize1=fout.tellg();
            fsize1=fsize1-sizeof(emp);
            fout.seekp(fsize1, ios::beg);
            Lic_Of_India newobj=emp;
            newobj.getdata();
            fout.write((char*)&newobj, sizeof(newobj));
            break;
        }
        else
        {
            cout<<"\n\t\t\tRecord not found";
        }
    }
            fout.close();
}
void search_member()
{
    system("cls");
    Lic_Of_India holder;
    fstream obj("record.dat", ios::in|ios::binary|ios::app);
    char found='y';
    int policy_no;
    cout<<"================================================================================="<<endl;
    cout<<"Enter policy no whose record do you want to search:-";
    cin>>policy_no;
    while(!obj.eof())
    {
        obj.read((char*)&holder, sizeof(holder));
        if (holder.ret_policy_no()==policy_no)
        {
            holder.putdata();
            found=='n';
            break;
        }
    }
    if (found!='y')
    {
        cout<<"Record not exist\n";
    }
    obj.close();

}

void delete_member()
{
    system("cls");
    Lic_Of_India holder;
    fstream fw, fr;
    fw.open("temp.dat", ios::out|ios::binary|ios::app);
    fr.open("record.dat", ios::out|ios::binary|ios::app);

    cout<<"Enter the policy no which do you want to delete";
    int policy_no;
    cin>>policy_no;
    while(!fr.eof())
    {
        fr.read((char*)&holder, sizeof(holder));
        if (holder.ret_policy_no()!=policy_no)
        {
            fw.write((char*)&holder, sizeof(holder));
        }
        else
        {
            cout<<"Record not found\n";
        }
        fw.close();
        fr.close();
    }
    remove("record.dat");
    rename("temp.dat", "record.dat");

}

void display_member()
{
    system("cls");
    Lic_Of_India emp;
    int fsize=getsizeoffile();
    ifstream fin("record.dat");
    cout<<"=====================================================================================";
    cout<<"\n\t\t\tAll employee details are:-";

    for(int i=0; i<fsize; i++)
    {
        fin.read((char*)&emp, sizeof(emp));
        emp.putdata();
        cout<<endl;
    }
    fin.close();
}

int main()
{
    cout<<"\n\n\n\n\n\t\t\t\tLIC OF INDIA"<<"\n\t\t\t============================"<<"\n\n\t\t\tMADE BY:- VAIBHAV GOEL"<<"\n\n\t\t\tAIR FORCE SCHOOL HINDAN, GZB";
    getch();
    system("cls");
    char choice='y';
    int ch;
    while(choice=='y'||choice=='Y')
    {
        system("cls");
        cout<<"\n\n\n\n\t\t\t\tMAIN MENU:"<<"\n\n\t\t\t 1=>TO ADD MEMBER"<<"\n\n\t\t\t 2=>TO MODIFY MEMBER"<<"\n\n\t\t\t 3=>TO SEARCH MEMBER"<<"\n\n\t\t\t 4=>TO DELETE MEMBER"<<"\n\n\t\t\t 5=>TO DISPLAY ALL MEMBERS";
        cout<<"\n\n\n\n\t\t\tPlease enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: add_member();
            break;
            case 2: modify_member();
            break;
            case 3: search_member();
            break;
            case 4: delete_member();
            break;
            case 5: display_member();
            break;
            default:
            cout<<"\n\n\t\t\tYou enter the wrong input";
        }
        cout<<"\n================================================================================";
        cout<<endl<<"DO you want to continue";
        choice=getche();
    }
    return 0;
}
