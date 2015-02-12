#ifndef CONTACTS_H_
#define CONTACTS_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

const char * file = "contacts.txt";
const int MAXSIZE = 200;

struct Members
{
	string firstname;
	string lastname;
	string tellnum;
};

struct Members2
{
	char firstname[21];
	char lastname[21];
	char tellnum[21];
};


void ContactsIntroduction()
{
	cout << "\t\t\t=========================" << endl;
	cout << "\t\t\t=\tCONTACTS\t=" << endl;
	cout << "\t\t\t=========================" << endl;
	cout << "\t\t\t1.Show My Contacts." << endl;
	cout << "\t\t\t2.Add Members." << endl;
	cout << "\t\t\t3.Delete Members." << endl;
	cout << "\t\t\t4.Modify Members." << endl;
	cout << "\t\t\t5.Find Members." << endl;
	cout << "\t\t\t6.Exit." << endl;
	cout << "\t\t\tYour Choice: ";

}

void ShowMyContacts()
{
	ifstream inFiles;
	inFiles.open(file);
	char ch;

	if (!inFiles.is_open())
	{
		exit(EXIT_FAILURE);
	}

	//inFiles.seekg(0, ios_base::end);  How to use seekg  ?
	if (inFiles.is_open())
	{
		while(inFiles.get(ch))
		{
			cout << ch;
		}
	}

	inFiles.close();
}

void AddMembers()
{
	char choice;
	
	ofstream outFiles;
	outFiles.open(file, ios_base::app);

	Members2 NewMember = { "                    ", "                    ", "                    " };
	cout << "Enter the firstname: ";
	cin >> NewMember.firstname;
	cout << "Enter the last name: ";
	cin >> NewMember.lastname;
	cout << "Enter the tellnum: ";
	cin >> NewMember.tellnum;
	
	outFiles.seekp(0, ios_base::end);
	if (!outFiles.tellp())
	{
		outFiles << std::left << setw(15) << "Firstname" << std::left << setw(15) << "Lastname" << std::left << setw(15) << "Tell" << endl;
		outFiles << std::left << setw(15) << NewMember.firstname << std::left << setw(15) << NewMember.lastname << std::left << setw(15) << NewMember.tellnum << endl;
	}else
	{
		outFiles << std::left << setw(15) << NewMember.firstname << std::left << setw(15) << NewMember.lastname << std::left << setw(15) << NewMember.tellnum << endl;
	}
	

	cout << "Continue Add?";
	cin >> choice;
	if (choice=='y')
	{
		AddMembers();
	}
	outFiles.close();
}

void ModifyMembersother()
{
	Members2 m1 = { "                    ", "                    ", "                    " };
	Members2 tmp[20] = { 0 };
	char  firstname[20];
	char  lastname[20];
	char  str[20];
	int i = 0;
	int cnt = 0;
	int flag = 0;
	memset(str, 0, sizeof(str));
	memset(firstname, 0, sizeof(firstname));
	memset(lastname, 0, sizeof(lastname));
	memset(tmp, 0, sizeof(tmp));
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out);

	cout << "Enter the people you want modify"<<endl;
	cin.get();
	cout << "firstname:";
	cin.get(firstname, 20);
	cin.get();
	cout << "lastname:";
	cin.get(lastname, 20);
	cin.get();


	if (!finout.is_open())
	{
		exit(EXIT_FAILURE);
	}

	if (finout.eof())
		finout.clear();

	if (finout.is_open())
	{

		
		while (!finout.eof())
		{
			
			cnt = finout.tellg();
			finout >> str;
			//cnt = cnt - sizeof(str);
			strncpy(tmp[i].firstname,str,20);
			finout >> str;
			strncpy(tmp[i].lastname, str,20);
			finout >> str;
			strncpy(tmp[i].tellnum, str,20);

			//cout << tmp[i].firstname << tmp[i].lastname << tmp[i].tellnum << endl;

			if (strcmp(tmp[i].firstname,firstname)==0 &&strcmp(tmp[i].lastname , lastname)==0)
			{
				flag = 1;
				break;
			}
			i++;
			
		}


	}

	if (flag == 1)
	{
		if (finout.eof())
			finout.clear();
		cout << i << endl;
		streampos place = (i)* (sizeof m1);  // why didn't find the informaxion.
		finout.seekg(cnt);
		finout >> str;
		cout << str;
		//finout.read((char *)&m1, sizeof m1);
		//cout << "Your selection:\n";
		//cout << m1.firstname << " " << m1.lastname << " " << m1.tellnum << endl;

		if (finout.eof())
			finout.clear();
		cout << "Enter the newfirstname:";
		cin.get(m1.firstname, 21);
		cin.get();
		cout << "Enter the newlastname:";
		cin.get(m1.lastname, 21);
		cin.get();
		cout << "Enter the newtell:";
		cin.get(m1.tellnum, 21);
		cin.get();


		finout.seekg(cnt);
		finout << endl;
		finout << std::left << setw(15) << m1.firstname << std::left << setw(15) << m1.lastname << std::left << setw(15) << m1.tellnum << "\0" << endl;

	}

	if (flag == 0)
	{
		cout << "No find!";
	}

	finout.close();
}


void DeleteMembers()
{
	Members2 m1 = { "                    ", "                    ", "                    " };
	Members2 tmp[20] = { 0 };
	char  firstname[20];
	char  lastname[20];
	char  str[20];
	int i = 0;
	int cnt = 0;
	int flag = 0;
	memset(str, 0, sizeof(str));
	memset(firstname, 0, sizeof(firstname));
	memset(lastname, 0, sizeof(lastname));
	memset(tmp, 0, sizeof(tmp));
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out);

	cout << "Enter the people you want modify" << endl;
	cin.get();
	cout << "firstname:";
	cin.get(firstname, 20);
	cin.get();
	cout << "lastname:";
	cin.get(lastname, 20);
	cin.get();


	if (!finout.is_open())
	{
		exit(EXIT_FAILURE);
	}

	if (finout.eof())
		finout.clear();

	if (finout.is_open())
	{


		while (!finout.eof())
		{

			cnt = finout.tellg();
			finout >> str;
			//cnt = cnt - sizeof(str);
			strncpy(tmp[i].firstname, str, 20);
			finout >> str;
			strncpy(tmp[i].lastname, str, 20);
			finout >> str;
			strncpy(tmp[i].tellnum, str, 20);

			//cout << tmp[i].firstname << tmp[i].lastname << tmp[i].tellnum << endl;

			if (strcmp(tmp[i].firstname, firstname) == 0 && strcmp(tmp[i].lastname, lastname) == 0)
			{
				flag = 1;
				break;
			}
			i++;

		}


	}

	if (flag == 1)
	{
		if (finout.eof())
			finout.clear();
		cout << i << endl;
		streampos place = (i)* (sizeof m1);  // why didn't find the informaxion.
		finout.seekg(cnt);
		finout >> str;
		cout << str;
		//finout.read((char *)&m1, sizeof m1);
		//cout << "Your selection:\n";
		//cout << m1.firstname << " " << m1.lastname << " " << m1.tellnum << endl;

		if (finout.eof())
			finout.clear();
		
		m1 = { "\0", "\0", "            " };


		finout.seekg(cnt);
		finout << endl;
		finout << std::left << setw(15) << m1.firstname << std::left << setw(15) << m1.lastname << std::left << setw(15) << m1.tellnum ;
	

	}

	if (flag == 0)

	{
		cout << "No find!";
	}

	finout.close();
}

void ModifyMembers()
{
	string firstname;
	string lastname;
	string str;
	char  newvalue[10] = { 0 };
	int i = 0;
	int flag = 0;
	Members tmp[MAXSIZE];
	Members m1 = { "firstname", "lastname", "tell" };
	int cnt=0;
	int cntl = 0;
	int cntt = 0;
	memset(tmp, 0, sizeof(tmp));
	memset(newvalue, 0, sizeof(newvalue));

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out|ios_base::binary);

	cout << "Enter the people you want modify:";
	cin >> firstname >> lastname;

	if (!finout.is_open())
	{
		exit(EXIT_FAILURE);
	}

	if (finout.is_open())
	{
		while (!finout.eof())
		{
			cnt = finout.tellg();
			finout >> str;
			tmp[i].firstname = str;	
			cntl = finout.tellg();
			finout >> str;
			tmp[i].lastname = str;
			cntt= finout.tellg();
			finout >> str;
			tmp[i].tellnum = str;
		
			if (tmp[i].firstname == firstname && tmp[i].lastname == lastname )
			{
				flag = 1;
				break;
			}
			i++;
		}

	
	}

	if (flag == 1)
	{
		cout << "The information as follows:" << endl;
		finout.seekg(cnt);
		finout >> m1.firstname;
		finout >> m1.lastname;
		finout >> m1.tellnum;
		cout << m1.firstname << setw(15) << m1.lastname << setw(15) << m1.tellnum << endl;
		finout.seekg(cnt+2);
		cin.get();
		cout << "Enter new information:" ;
		cin.get(newvalue, 10);
		//const char * newchar = newvalue.c_str();


		if (finout.eof())
			finout.clear();
		cout << "change which one? f,l or t?";
		char ch;
		cin >> ch;
		if (ch == 'f')
		{
			finout.write((char *)newvalue,m1.firstname.length()+1)<<flush;
		}

		if (finout.eof())
			finout.clear();
		finout.seekg(cnt +2+sizeof(m1.firstname));
		if (ch == 'l')
		{
			finout.write((char *)newvalue, m1.lastname.length() + 1) << flush;
		}

		if (finout.eof())
			finout.clear();
		finout.seekg(cnt+ 2+sizeof(m1.firstname)+sizeof(m1.lastname));
		if (ch == 't')
		{
			finout.write((char *)newvalue, m1.tellnum.length() + 1) << flush;
		}


	}


	if (flag == 0)
	{
		cout << "No Find!" << endl;
	}

	finout.close();
}

void FindMembers()
{
	ifstream inFiles;
	inFiles.open(file);
	string str;
	string find;
	int flag;
	int flag2;
	flag2 = 0;
	flag = 0;
	int i;
	i = 0;

	cout << "Enter the information you want find: ";
	cin >> find;

	Members tmp[MAXSIZE];

	if (!inFiles.is_open())
	{
		exit(EXIT_FAILURE);
	}

	if (inFiles.is_open())
	{
		while (inFiles>>str)
		{
			tmp[i].firstname = str;
			
			inFiles >> str;
			tmp[i].lastname = str;
			inFiles >> str;
			tmp[i].tellnum = str;

			if (tmp[i].firstname == find || tmp[i].lastname == find || tmp[i].tellnum == find)
			{
				flag ++;
				
			}

			if (flag == 1&&flag2==0)
			{
				cout << setw(15) << "Firstname" << setw(15) << "Lastname" << setw(15) << "Tell" << endl;
				cout << setw(15) << tmp[i].firstname << setw(15) << tmp[i].lastname << setw(15) << tmp[i].tellnum << endl;
				flag2 = 1;
				
			}

			if (flag > 1)
			{
				cout << setw(15) << tmp[i].firstname << setw(15) << tmp[i].lastname << setw(15) << tmp[i].tellnum << endl;
			}
		
			i++;
		}

		if (flag == 0)
		{
			cout << "No Find!" << endl;
		}


	}

	inFiles.close();
}

void EXIT()
{
	system("exit");
}


#endif