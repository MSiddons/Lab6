#include <iostream>

using namespace std;

//Q1------------------------------------------------------------------------------------------------


void exercise1()
{

}

//Q2------------------------------------------------------------------------------------------------


void exercise2()
{

}

//Q3------------------------------------------------------------------------------------------------


void exercise3()
{

}

//Q4------------------------------------------------------------------------------------------------


void exercise4()
{

}

//Q5------------------------------------------------------------------------------------------------


void exercise5()
{

}

//Q6------------------------------------------------------------------------------------------------


void exercise6()
{

}

//Q7------------------------------------------------------------------------------------------------


void exercise7()
{

}

//Menu------------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	while (exercise != 0)
	{
		cout << "Select an exercise number (1-7) or 0 to exit: ";
		cin >> exercise;
		switch (exercise)
		{
		case 0:
			break;
		case 1:
			exercise1();
			break;
		case 2:
			exercise2();
			break;
		case 3:
			exercise3();
			break;
		case 4:
			exercise4();
			break;
		case 5:
			exercise5();
			break;
		case 6:
			exercise6();
			break;
		case 7:
			exercise7();
			break;

		default:
			cout << "Incorrect choice" << endl;
		}
	}
}

/*
case 4:
{
char q4 = '1';
while (q4 != '0')
{
cout << "Which sub excersise? (a or c, 0 to go back): ";
cin >> q4;
switch (q4)
{
case '0':
break;
case 'a':
exercise4_a();
break;
case 'b':
exercise4_c();
break;
default:
cout << "That's not a choice." << endl;
}
}
break;
}
*/