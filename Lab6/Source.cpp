#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <random>
#include <time.h>

using namespace std;

//Q1------------------------------------------------------------------------------------------------
int next_visitor(vector<bool> & occupied)
{
	vector<int> occPos; // list of occupied positions
	int OccupiedSize = occupied.size();

	// make a list of postion numbers currently empty
	for (int i = 0; i < OccupiedSize; i++)
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
	for (int i = 0; i < (occPosSize + 1); i++)
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
	for (int i = 0; i < occupied.size(); i++)
		cout << (occupied[i] ? "X" : "_");
	cout << endl;
}

void exercise1()
{
	int urinalNum;
	cout << "Number of urinals: ";
	cin >> urinalNum;
	vector<bool> urinals(urinalNum, false);
	for (int i = 0; i < urinals.size(); i++)
	{
		cout << "Next position is number: " << next_visitor(urinals) << endl;
		draw_stalls(urinals);
	}
	cout << "No positions remaining" << endl;
}

//Q2------------------------------------------------------------------------------------------------

void draw_piles(vector<int> const & pile)
{
	for (int i = 0; i < pile.size(); i++)
		cout << pile[i] << ", ";
	cout << endl;
}

void form_new_pile(vector<int> & pile)
{
	bool removed = 0;
	for (int i = 0; i < pile.size(); i++)
	{
		pile[i]--;
		if (pile[i] == 0)
			removed = 1;
	}
	pile.push_back(pile.size());

	if (removed != 0)
		for (int i = 0; i < pile.size(); i++)
		{
			if (pile[i] == 0)
				pile.erase(pile.begin() + i);
		}
}

int complete_check(vector<int> pile)
{
	int max = 0;
	for (int i = 0; i < pile.size(); i++)
		if (pile[i] > max)
			max = pile[i];
	if (max > 9)
		return 1;

	vector<int> run;
	for (int i = 1; i < 10; i++)
		run.push_back(i);
	for (int i = 0; i < pile.size(); i++)
		for (int j = 0; j < run.size(); j++)
		{
			if (pile[i] == run[j])
				run.erase(run.begin() + j);
		}
	if (run.size() == 0) // shit hit the fan somewhere here fuck it idk
		return 0;
}

void exercise2()
{
	vector<int> pile;
	int pack = 45;
	for (int i = 0; i < 4; i++)
	{
		pile.push_back(rand() % (pack - 5 + i) + 1);
		pack = pack - pile[i];
	}
	pile.push_back(pack);
	draw_piles(pile);
	while (complete_check(pile) != 0)
	{
		form_new_pile(pile);
		draw_piles(pile);
	}
	cout << "Complete" << endl << endl;
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
	srand(time(0));
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