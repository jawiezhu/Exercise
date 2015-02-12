#include "Contacts.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	ContactsIntroduction();
	int YourSelect;
	cin >> YourSelect;

	switch (YourSelect)
	{
	case 1: system("cls"); ShowMyContacts();
					break;
		case 2: system("cls"); AddMembers();
					break;
		case 3: DeleteMembers();
					break;
		case 4: system("cls"); ModifyMembersother();
					break;
		case 5: system("cls"); FindMembers();
					break;
		case 6: EXIT();
					break;
		default: cout << "Choose the function." << endl;
					break;
	}

	return 0;
}




