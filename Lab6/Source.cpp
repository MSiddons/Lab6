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

void draw_piles(vector<int> const & pile)
{
	for (unsigned i = 0; i < pile.size(); i++)
		cout << pile[i] << ", ";
	cout << endl;
}

void form_new_pile(vector<int> & pile)
{
	bool removed = 0;
	for (unsigned i = 0; i < pile.size(); i++)
	{
		pile[i]--;
		if (pile[i] == 0)
			removed = 1;
	}
	pile.push_back(pile.size());

	if (removed != 0)
		for (unsigned i = 0; i < pile.size(); i++)
		{
			if (pile[i] == 0)
			{
				pile.erase(pile.begin() + i);
				i--;
			}
		}
}

int complete_check(vector<int> pile)
{
	if (pile.size() != 9)
		return 1;

	vector<int> run;
	for (int i = 1; i < 10; i++)
		run.push_back(i);
	for (unsigned i = 0; i < pile.size(); i++)
		for (unsigned j = 0; j < run.size(); j++)
		{
			if (pile[i] == run[j])
				run.erase(run.begin() + j);
		}
	if (run.size() == 0)
		return 0;
	else
		return 1;
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

vector<int> vectorCreate(minstd_rand0 & g)
{
	vector<int> a;
	int count = (g() % 8 + 3);
	for (int i = 0; i < count; i++)
		a.push_back(g() % 30 + 1);
	return a;
}

vector<int> mergeSorted(vector<int> const & a, vector<int> const & b)
{
	vector<int> merged;
	for (int i = 1; i <= 30; i++)
	{
		for (unsigned j = 0; j < a.size(); j++)
		{
			if (a[j] == i)
				merged.push_back(a[j]);
		}
		for (unsigned j = 0; j < b.size(); j++)
		{
			if (b[j] == i)
				merged.push_back(b[j]);
		}
	}
	return merged;
}

void vectorPrint(vector<int> const & a)
{
	for (unsigned i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

void exercise3()
{
	minstd_rand0 g((unsigned)time(0));
	vector<int> vectorA = vectorCreate(g);
	vector<int> vectorB = vectorCreate(g);
	vector<int> vectorC = mergeSorted(vectorA, vectorB);
	vectorPrint(vectorA);
	vectorPrint(vectorB);
	vectorPrint(vectorC);
	cout << endl;
}

//Q4------------------------------------------------------------------------------------------------

void trickySwap(int & a, int & b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

void exercise4()
{
	int a, b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	trickySwap(a, b);
	cout << "When trickyswapped, the first number is " << a << ", and the second is " << b << endl << endl;
}

//Q5------------------------------------------------------------------------------------------------

void rollDice(int *r)
{
	int a, *p = r - 2;
	for (int i = 1; i <= 360000; i++) // generate 360000 throws of 2 dice.
	{
		a = (rand() % 6 + 1) + (rand() % 6 + 1); // generate a random number between 1-6 and add it to another random number from the same range, then assign that to 'a'.
		for (int c = 2; c <= 12; c++) // loop which checks a (c)ounter and adds that result to the correct spot.
			if (a == c)
				p[c]++;
	}
}

void exercise5()
{
	int rolls[11]{ 0,0,0,0,0,0,0,0,0,0,0 }; // initialise the vector with 11 elements since that's all we're using.
	srand(time(0));
	rollDice(rolls);
	for (int i = 0; i <= 10; i++) // loop which iterates through numbers 2-12 to print the row numbers.
	{
		cout << (i + 2) << ": " << rolls[i] << endl;
		//cout << setw(2) << setfill(' ') << i << ":  "; // print the line up until the stars.
		//cout << setw(lrint(rolls[i] / 10000.0) + 1) << setfill('*') << " " << endl; // cleverly fill each row of stars using setw rather than another for loop.
	}
}

//Q6------------------------------------------------------------------------------------------------

bool isMember(char c, string delim)
{
	return (delim.find(c, 0) != string::npos);
}

string getNext(string const & toExtract, int & pos, string const & delim)
{
	string result;
	while (pos < toExtract.size() && isMember(toExtract[pos], delim))
		pos++; // if the first characters are in delim, skip and move to the next.
	while (pos < toExtract.size() && !isMember(toExtract[pos], delim))
	{
		result.push_back(toExtract[pos]);
		pos++;
	}
	return result;
}

void processLine(string const & line)
{
	int pos = 0;
	cout << "CODE:       " << getNext(line, pos, ",") << endl;
	cout << "TITLE:      " << getNext(line, pos, ",") << endl;
	cout << "CREDIT:     " << getNext(line, pos, ",") << endl;
	cout << "ASSESSMENT: ";
	while (pos < line.size())
	{
		cout << getNext(line, pos, ",") << ":";
		cout << getNext(line, pos, ",") << " ";
	}
	cout << endl;
}

void exercise6()
{
	processLine("CMP-0002A,FOUNDATIONS OF COMPUTING,20,CWK,50,CT,50");
	cout << endl << endl;
	processLine("CMP-0005A,INTRODUCTORY PROGRAMMING,20,CWK,25,CWK,25,EXAM,50");
	cout << endl;
}


//Menu------------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	while (exercise != 0)
	{
		srand((unsigned)time(0));
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