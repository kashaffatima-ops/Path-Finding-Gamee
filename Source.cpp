

#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
	graph gr;
	Dijkstra dijks;
	int source;
	int destination;
	LinkedList shortestPath;
	int source2;
	int destination2;
	LinkedList shortestPath2;
mainmenu:

	changeColor(14);

	cout << "		*********************************" << endl;
	cout << "		*WELCOME TO THE MAZE RACING GAME*" << endl;
	cout << "		*********************************" << endl;

	cout << endl
		 << endl;
choice:

	cout << "		*-----------M E N U-----------*\n\n";
	cout << "			1. RULES" << endl;
	cout << "			2. Go to Game menu" << endl;
	cout << "			3. Score Board\n";
	cout << "			4. Exit" << endl;
	cout << "\n	Enter choice: ";
	int o1;
	cin >> o1;
	cout << endl;
	system("CLS");
	if (o1 == 1)
	{

		cout << "		*************" << endl;
		cout << "		*   RULES   * " << endl;
		cout << "		*************\n"
			 << endl;
		changeColor(12);
		cout << "\tTHE RULES ARE AS FOLLOWS READ CAREFULLY" << endl;
		cout << "\t1.use w/a/s/d buttons to move your car around the maze." << endl;
		cout << "\t2.the car is represented by C and the nodes or positions are represented by numbers" << endl;
		cout << "\t3.you need to find your way from the start (S) to the finish line (F)." << endl;
		cout << "\t4.there are multiple ways to reach the finish line you need to find one which is the best" << endl;
		cout << "\t5.there are randomly placed obstacles and traps that will deduct from your health so if you reach to 0 you will die." << endl;
		cout << "\t6.there is a -10 devils lair that will hurt you." << endl;
		cout << "\t7.there is also the angels help that will help you with a +5\n"
			 << endl;
		changeColor(14);
		cout << "\n\tEnter anything to return to the main menu: ";
		string any;
		cin >> any;
		system("CLS");
		goto mainmenu;
	}
	else if (o1 == 2)
	{

	gamemenu:
		changeColor(14);
		system("CLS");
		cout << "		\t**************" << endl;
		cout << "		\t* MODES MENU * " << endl;
		cout << "		\t**************\n"
			 << endl;
		cout << "			1. Move to Manual game play mode" << endl;
		cout << "			2. Move to Automatic game play mode" << endl;
		cout << "			3. Exit to main menu" << endl;
		cout << "\n	Enter choice: ";
		int op2;
		string name = "guest";
		cin >> op2;
		system("CLS");
		if (op2 == 1)
		{
		op3entry:
			cout << "		**************" << endl;
			cout << "		* LEVEL MENU * " << endl;
			cout << "		**************\n"
				 << endl;
			cout << "\n		Choose level:\n"
				 << "			1. level 1\n"
				 << "			2. level 2\n"
				 << "			3. Move to previous menu\n";
			cout << "\n	Enter choice: ";
			int op3;
			cin >> op3;
			system("CLS");
			switch (op3)
			{
			case 1:
				system("CLS");
			nameen:
				cout << "\n\tDo you want to enter name or continue as guest (y/n): ";
				char s;
				cin >> s;

				if (s == 'y' || s == 'Y')
				{
					cout << "enter your name: ";

					cin >> name;
				}
				else if (s == 'n' || s == 'N')
				{
				}
				else
				{
					cout << "error : invalid input" << endl;
					goto nameen;
				}

				system("ClS");
				changeColor(12);
				cout << "			YOU MAY BEGIN YOUR JOURNEY THROUGH THE LANDS" << endl;
				changeColor(7);
				gr.insertvertex();
				gr.gameplay(name);

				goto gamemenu;

				break;
			case 2:
				system("ClS");
			nameen2:
				cout << "\n\tDo you want to enter name or continue as guest (y/n): ";
				char s1;
				cin >> s1;

				if (s1 == 'y' || s1 == 'Y')
				{
					cout << "enter your name: ";

					cin >> name;
				}
				else if (s1 == 'n' || s1 == 'N')
				{
				}
				else
				{
					cout << "error : invalid input" << endl;
					goto nameen2;
				}
				system("CLS");
				changeColor(12);
				cout << "			YOU MAY BEGIN YOUR JOURNEY THROUGH THE LANDS" << endl;
				changeColor(7);
				gr.insertvertexlv2();
				gr.gameplaylv2(name);

				goto gamemenu;

				break;
			case 3:
				goto gamemenu;
				break;
			default:
				cout << "\n		Wrong choice!! Try again!!\n";
				goto op3entry;
			}
		}
		else if (op2 == 2)
		{
		op4entry:
			cout << "		**************" << endl;
			cout << "		* LEVEL MENU * " << endl;
			cout << "		**************\n"
				 << endl;

			cout << "\n		Choose level:\n"
				 << "			1. level 1\n"
				 << "			2. level 2\n"
				 << "			3. Move to previous menu\n";
			cout << "\n	Enter choice: ";
			int op4;
			cin >> op4;
			switch (op4)
			{
			case 1:

				system("ClS");
				changeColor(12);
				cout << "			YOU MAY BEGIN YOUR JOURNEY THROUGH THE LANDS" << endl;
				changeColor(7);
				gr.insertvertex();
				source = 1;
				destination = 20;
				shortestPath = dijks.getShortestPath(gr, source, destination);
				gr.gameplay2(shortestPath);

				goto gamemenu;

				break;
			case 2:
				system("ClS");
				changeColor(12);
				cout << "			YOU MAY BEGIN YOUR JOURNEY THROUGH THE LANDS" << endl;
				changeColor(7);
				gr.insertvertexlv2();
				source2 = 1;
				destination2 = 40;
				shortestPath2 = dijks.getShortestPath2A(gr, source2, destination2);
				gr.gameplaylv2A(shortestPath2);

				goto gamemenu;

				break;
			case 3:
				goto gamemenu;
				break;
			default:
				cout << "\n		Wrong choice entered!! Try again!!";
				goto op4entry;
			}
		}
		else if (op2 == 3)
		{
			system("CLS");
			goto mainmenu;
		}
		else
		{
			cout << "\nWrong entry entered!! Try Again!!\n\n";
			goto gamemenu;
		}
		changeColor(7);
		gr.insertvertex();

		gr.gameplay();
	}
	else if (o1 == 3)
	{
		// score board
		ifstream leaderboaed("leaderboard.txt");
		ifstream lvl1obj("scorehistorylv1.txt");
		ifstream lvl2obj("scorehistorylv2.txt");
		string line;
		system("CLS");
		cout << "\n\n";
		changeColor(14);
		cout << "		***************" << endl;
		cout << "		* SCORE BOARD * " << endl;
		cout << "		***************" << endl;
		cout << endl
			 << endl;
		cout << "$------------- LEADER BOARD -------------$\n\n\n";
		while (getline(leaderboaed, line))
		{
			cout << "\t" << line << endl;
		}
		cout << endl
			 << endl;
		cout << "$--------------- LEVEL 1 ---------------$\n\n\n";
		while (getline(lvl1obj, line))
		{
			cout << "\t" << line << endl;
		}
		cout << endl
			 << endl;
		cout << "$--------------- LEVEL 2 ---------------$\n\n\n";
		while (getline(lvl2obj, line))
		{
			cout << "\t" << line << endl;
		}
		cout << "\n\n$---------------------------------------$\n";
		cout << "\n\t Press anything to go back: ";
		string any2;
		cin >> any2;
		cout << endl;
		system("CLS");
		goto mainmenu;
	}
	else if (o1 == 4)
	{
		cout << "\n		*-----------Game Exit-----------*\n\n";
		return 0;
	}
	else
	{
		cout << "\nWrong entry entered!! Try again!!\n\n";

		goto choice;
	}
	return 0;
}
