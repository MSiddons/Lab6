#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

//Q1------------------------------------------------------------------------------------------------
int next_visitor(vector<bool> & occupied)
{
	vector <int> occPos; // list of occupied positions
	int OccupiedSize = occupied.size();

	// make a list of postion numbers currently empty
	for (unsigned i = 0; i < OccupiedSize; i++)
		if (occupied[i])
			occPos.push_back(i);

	// check if entire occupied vector has one position remaining, it'll be element 0, fill it and end.
	int occPosSize = occPos.size();
	if ((OccupiedSize - 1) == occPosSize)
	{
		occupied[0] = 1;
		return 1;
	}

	// check if entire occupied vector is empty, if true change value of middle element to true and return the position of the element changed
	if (occPosSize == 0)
	{
		occupied[(OccupiedSize - 1) / 2] = 1;
		return (OccupiedSize / 2);
	}

	// check list of positions and find the largest gap, store larger of the two numbers as max
	int max = 0, last = 0, gap;
	occPos.push_back(OccupiedSize + 1);
	for (unsigned i = 0; i < (occPosSize + 1); i++)
	{
		if ((occPos[i] - last) > max)
		{
			max = occPos[i];
			gap = occPos[i] - last - 1;
		}
		last = occPos[i];
	}

	// divide gap value by 2 and subtract it from max (above)
	int insert = max - (gap / 2);

	// change value of above element to 1 and return position of element changed
	occupied[insert - 1] = 1;
	return (insert);
}

void draw_stalls(vector<bool> const & occupied)
{
	for (unsigned i = 0; i < occupied.size(); i++)
		cout << (occupied[i] ? "X" : "_");
	cout << endl;
}

void exercise1()
{
	int urinalNum;
	cout << "Number of urinals: ";
	cin >> urinalNum;
	vector<bool> urinals(urinalNum, false);
	for (unsigned i = 0; i < urinals.size(); i++)
	{
		cout << "Next position is number: " << next_visitor(urinals) << endl;
		draw_stalls(urinals);
	}
	cout << "No positions remaining" << endl;
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


//Menu------------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	while (exercise != 0)
	{
		cout << "Select an exercise number (1-6) or 0 to exit: ";
		cin >> exercise;
		switch (exercise)
		{
		case 0: return 0; break;
		case 1:	exercise1(); break;
		case 2: exercise2(); break;
		case 3:	exercise3(); break;
		case 4:	exercise4(); break;
		case 5:	exercise5(); break;
		case 6:	exercise6(); break;

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