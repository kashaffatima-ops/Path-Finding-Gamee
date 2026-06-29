

#pragma once
#include <iostream>
#include <windows.h>
#include <limits.h>
#include <fstream>
#include <ctime>

using namespace std;

void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

struct Node
{
	int data;
	char ach;
	Node *next;
};
class LinkedList
{
public:
	Node *head;
	LinkedList() : head(nullptr) {}
	void insert(int data)
	{
		Node *newNode = new Node{data, NULL, NULL};
		if (!head)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void insertach(char data)
	{
		Node *newNode = new Node{0, data, NULL};
		if (!head)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	int deletenode(double x)
	{
		Node *prevnode = NULL;
		Node *currnode = head;
		int currindex = 1;
		while (currnode && currnode->data != x)
		{
			prevnode = currnode;
			currnode = currnode->next;
			currindex++;
		}

		if (currnode)
		{
			if (prevnode)
			{
				prevnode->next = currnode->next;
				delete currnode;
			}
			else
			{
				head = currnode->next;
				delete currnode;
			}
			return currindex;
		}
		return 0;
	}

	void display()
	{
		Node *current = head;
		while (current)
		{
			cout << current->data;
			if (current->next != NULL)
			{
				cout << "->";
			}
			current = current->next;
		}
		cout << endl;
	}
};

class obstaclenode
{
public:
	int minus_health;
	obstaclenode *next;
};

class obstaclequeue
{
public:
	obstaclenode *front;
	obstaclenode *rear;
	int numitems;

	obstaclequeue()
	{
		front = NULL;
		rear = NULL;
		numitems = 0;
	}

	void enqueue(int num)
	{
		obstaclenode *newnode;
		newnode = new obstaclenode;

		newnode->minus_health = num;
		newnode->next = NULL; // we null here because we know it will always come at the enqueue at the end.
		if (isEmpty())
		{
			front = newnode;
			rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
		numitems++;
	}

	int dequeue(void)
	{
		obstaclenode *temp;
		int num = -1;
		if (isEmpty())
		{
			cout << "the queue is empty\n";
		}
		else
		{
			num = front->minus_health;
			temp = front->next;
			delete front;
			front = temp;
			numitems--;
			if (!numitems)
			{
				return NULL; // works to make rear null when only one element was present and was removed.
			}
		}
		return num;
	}

	bool isEmpty()
	{
		if (numitems)
		{
			return false;
		}
		else
			return true;
	}

	void makenull()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	~obstaclequeue()
	{
		makenull();
	}
};

class node
{
public:
	int data;
	int weight;
	char direction;
	obstaclequeue obstaclehead;
	node *next;

	void setObstacleValue(int x)
	{
		obstaclehead.enqueue(x);
	}
};

class adjlist
{
public:
	node *head;

	adjlist()
	{
		head = NULL;
	}

	void insert(int val, char dir, int wei)
	{
		node *currnode = head;

		if (head)
		{
			while (currnode->next)
			{
				currnode = currnode->next;
			}
			node *newnode = new node;
			newnode->data = val;
			newnode->direction = dir;
			newnode->weight = wei;
			newnode->next = NULL;

			currnode->next = newnode;
		}
		else
		{
			node *newnode = new node;
			newnode->data = val;
			newnode->weight = wei;
			newnode->next = NULL;

			head = newnode;
		}
	}

	void setobstacle(int x)
	{
		head->setObstacleValue(x);
	}

	void displaylist(void)
	{
		node *currnode = head;
		if (currnode && currnode->obstaclehead.front)
		{
			cout << endl
				 << "with the obstacle value = " << currnode->obstaclehead.front->minus_health << " -> ";
		}
		while (currnode != NULL)
		{
			if (currnode == head)
			{
				cout << currnode->data << " is connected to-> ";
			}
			else
			{
				cout << currnode->data << ", ";
			}

			currnode = currnode->next;
		}
	}
};

class graph
{
public:
	adjlist *arr;
	int numberofvertex;
	graph()
	{
		numberofvertex = 0;
	}

	void createmap()
	{
	}

	void display2darraywise()
	{
		for (int i = 0; i < numberofvertex; i++)
		{
			arr[i].displaylist();
			cout << endl;
		}
	}

	// inserting vertex for level 1
	void insertvertex()
	{
		srand(time(0));
		int ver = 21;
		arr = new adjlist[ver];
		numberofvertex = ver;

		// declaring all verteces
		arr[1].insert(1, ' ', 0);
		arr[2].insert(2, ' ', 0);
		arr[3].insert(3, ' ', 0);
		arr[4].insert(4, ' ', 0);
		arr[5].insert(5, ' ', 0);
		arr[6].insert(6, ' ', 0);
		arr[7].insert(7, ' ', 0);
		arr[8].insert(8, ' ', 0);
		arr[9].insert(9, ' ', 0);
		arr[10].insert(10, ' ', 0);
		arr[11].insert(11, ' ', 0);
		arr[12].insert(12, ' ', 0);
		arr[13].insert(13, ' ', 0);
		arr[14].insert(14, ' ', 0);
		arr[15].insert(15, ' ', 0);
		arr[16].insert(16, ' ', 0);
		arr[17].insert(17, ' ', 0);
		arr[18].insert(18, ' ', 0);
		arr[19].insert(19, ' ', 0);
		arr[20].insert(20, ' ', 0);

		// links of vertex 1
		int a = rand() % 10 + 1, A = rand() % 10 + 1;
		arr[1].insert(2, 'd', a);
		arr[2].insert(1, 'a', a);
		arr[1].insert(9, 's', A);
		arr[9].insert(1, 'w', A);

		// links of vertex 2
		int c = rand() % 10 + 1;
		arr[2].insert(3, 'd', c);
		arr[3].insert(2, 'a', c);

		// links of vertex 3
		int C = rand() % 10 + 1, d = rand() % 10 + 1;
		arr[3].insert(4, 'd', C);
		arr[4].insert(3, 'a', C);
		arr[3].insert(11, 's', d);
		arr[11].insert(3, 'w', d);
		arr[3].setobstacle(-5); // setting obstacle value

		// links of vertex 4
		int D = rand() % 10 + 1, e = rand() % 10 + 1;
		arr[4].insert(5, 'd', D);
		arr[5].insert(4, 'a', D);
		arr[4].insert(7, 'w', e);
		arr[7].insert(4, 's', e);

		// links of vertex 5
		int E = rand() % 10 + 1;
		arr[5].insert(13, 's', E);
		arr[13].insert(5, 'w', E);

		// links of vertex 6
		int f = rand() % 10 + 1;
		arr[6].insert(7, 'd', f);
		arr[7].insert(6, 'a', f);

		// links of vertex 7
		int F = rand() % 10 + 1;
		arr[7].insert(8, 'd', F);
		arr[8].insert(7, 'a', F);

		// links of vertex 8
		arr[8].setobstacle(-5); // setting obstacle value

		// links of vertex 9
		int g = rand() % 10 + 1;
		arr[9].insert(10, 'd', g);
		arr[10].insert(9, 'a', g);

		// links of vertex 10
		int G = rand() % 10 + 1, h = rand() % 10 + 1;
		arr[10].insert(11, 'd', G);
		arr[11].insert(10, 'a', G);
		arr[10].insert(17, 's', h);
		arr[17].insert(10, 'w', h);

		// links of vertex 11
		int H = rand() % 10 + 1;
		arr[11].insert(14, 's', H);
		arr[14].insert(11, 'w', H);
		arr[11].setobstacle(5); // setting obstacle value(bonus)

		// links of vertex 12
		int i = rand() % 10 + 1;
		arr[12].insert(13, 'd', i);
		arr[13].insert(12, 'a', i);

		// links of vertex 13
		arr[13].setobstacle(-5); // setting obstacle value

		// links of vertex 14
		int I = rand() % 10 + 1;
		arr[14].insert(15, 'd', I);
		arr[15].insert(14, 'a', I);

		// links of vertex 15
		int j = rand() % 10 + 1, J = rand() % 10 + 1, k = rand() % 10 + 1;
		arr[15].insert(12, 'w', j);
		arr[12].insert(15, 's', j);
		arr[15].insert(16, 'd', J);
		arr[16].insert(15, 'a', J);
		arr[15].insert(18, 's', k);
		arr[18].insert(15, 'w', k);
		arr[15].setobstacle(-5); // setting obstacle value

		// links of vertex 16
		arr[16].setobstacle(-10); // setting obstacle value(extra punishment)

		// links of vertex 17
		int K = rand() % 10 + 1;
		arr[17].insert(19, 'd', K);
		arr[19].insert(17, 'a', K);
		arr[17].setobstacle(-5); // setting obstacle value

		// links of vertex 18
		int l = rand() % 10 + 1;
		arr[18].insert(20, 'd', l);
		arr[20].insert(18, 'a', l);
		arr[18].setobstacle(-5); // setting obstacle value

		// links of vertex 19
		int L = rand() % 10 + 1;
		arr[19].insert(14, 'w', L);
		arr[14].insert(19, 's', L);

		// links of vertex 20
	}

	// inserting vertex for level 2
	void insertvertexlv2()
	{

		int ver = 41;
		arr = new adjlist[ver];
		numberofvertex = ver;

		// declaring all verteces
		arr[1].insert(1, ' ', 0);
		arr[2].insert(2, ' ', 0);
		arr[3].insert(3, ' ', 0);
		arr[4].insert(4, ' ', 0);
		arr[5].insert(5, ' ', 0);
		arr[6].insert(6, ' ', 0);
		arr[7].insert(7, ' ', 0);
		arr[8].insert(8, ' ', 0);
		arr[9].insert(9, ' ', 0);
		arr[10].insert(10, ' ', 0);
		arr[11].insert(11, ' ', 0);
		arr[12].insert(12, ' ', 0);
		arr[13].insert(13, ' ', 0);
		arr[14].insert(14, ' ', 0);
		arr[15].insert(15, ' ', 0);
		arr[16].insert(16, ' ', 0);
		arr[17].insert(17, ' ', 0);
		arr[18].insert(18, ' ', 0);
		arr[19].insert(19, ' ', 0);
		arr[20].insert(20, ' ', 0);
		arr[21].insert(21, ' ', 0);
		arr[22].insert(22, ' ', 0);
		arr[23].insert(23, ' ', 0);
		arr[24].insert(24, ' ', 0);
		arr[25].insert(25, ' ', 0);
		arr[26].insert(26, ' ', 0);
		arr[27].insert(27, ' ', 0);
		arr[28].insert(28, ' ', 0);
		arr[29].insert(29, ' ', 0);
		arr[30].insert(30, ' ', 0);
		arr[31].insert(31, ' ', 0);
		arr[32].insert(32, ' ', 0);
		arr[33].insert(33, ' ', 0);
		arr[34].insert(34, ' ', 0);
		arr[35].insert(35, ' ', 0);
		arr[36].insert(36, ' ', 0);
		arr[37].insert(37, ' ', 0);
		arr[38].insert(38, ' ', 0);
		arr[39].insert(39, ' ', 0);
		arr[40].insert(40, ' ', 0);

		// links of vertex 1
		int a = rand() % 10 + 1, A = rand() % 10 + 1;
		arr[1].insert(2, 'd', a);
		arr[2].insert(1, 'a', a);
		arr[1].insert(9, 's', A);
		arr[9].insert(1, 'w', A);

		// links of vertex 2
		int c = rand() % 10 + 1;
		arr[2].insert(3, 'd', c);
		arr[3].insert(2, 'a', c);

		// links of vertex 3
		int C = rand() % 10 + 1, d = rand() % 10 + 1;
		arr[3].insert(4, 'd', C);
		arr[4].insert(3, 'a', C);
		arr[3].insert(11, 's', d);
		arr[11].insert(3, 'w', d);

		// links of vertex 4
		int D = rand() % 10 + 1, e = rand() % 10 + 1;
		arr[4].insert(5, 'd', D);
		arr[5].insert(4, 'a', D);
		arr[4].insert(7, 'w', e);
		arr[7].insert(4, 's', e);

		// links of vertex 5
		int E = rand() % 10 + 1;
		arr[5].insert(13, 's', E);
		arr[13].insert(5, 'w', E);

		// links of vertex 6
		int f = rand() % 10 + 1;
		arr[6].insert(7, 'd', f);
		arr[7].insert(6, 'a', f);

		// links of vertex 7
		int F = rand() % 10 + 1;
		arr[7].insert(8, 'd', F);
		arr[8].insert(7, 'a', F);

		// links of vertex 8

		// links of vertex 9
		int g = rand() % 10 + 1;
		arr[9].insert(10, 'd', g);
		arr[10].insert(9, 'a', g);

		// links of vertex 10
		int G = rand() % 10 + 1, h = rand() % 10 + 1;
		arr[10].insert(11, 'd', G);
		arr[11].insert(10, 'a', G);
		arr[10].insert(17, 's', h);
		arr[17].insert(10, 'w', h);

		// links of vertex 11
		int H = rand() % 10 + 1;
		arr[11].insert(14, 's', H);
		arr[14].insert(11, 'w', H);

		// links of vertex 12
		int i = rand() % 10 + 1;
		arr[12].insert(13, 'd', i);
		arr[13].insert(12, 'a', i);

		// links of vertex 13

		// links of vertex 14
		int I = rand() % 10 + 1;
		arr[14].insert(15, 'd', I);
		arr[15].insert(14, 'a', I);

		// links of vertex 15
		int j = rand() % 10 + 1, J = rand() % 10 + 1, k = rand() % 10 + 1;
		arr[15].insert(12, 'w', j);
		arr[12].insert(15, 's', j);
		arr[15].insert(16, 'd', J);
		arr[16].insert(15, 'a', J);
		arr[15].insert(18, 's', k);
		arr[18].insert(15, 'w', k);

		// links of vertex 16
		arr[16].setobstacle(-10); // setting obstacle value(extra punishment)

		//	//links of vertex 17
		int aa = rand() % 10 + 1;
		arr[17].insert(19, 'd', aa);
		arr[19].insert(17, 'a', aa);

		// links of vertex 18
		int AA = rand() % 10 + 1;
		arr[18].insert(20, 'd', AA);
		arr[20].insert(18, 'a', AA);

		// links of vertex 19
		int L = rand() % 10 + 1;
		arr[19].insert(14, 'w', L);
		arr[14].insert(19, 's', L);

		// links of vertex 20

		// links of vertex 21
		int BB = rand() % 10 + 1;
		arr[21].insert(22, 'd', BB);
		arr[22].insert(21, 'a', BB);

		// links of vertex 22
		int l = rand() % 10 + 1;
		int m = rand() % 10 + 1;
		int M = rand() % 10 + 1;
		arr[22].insert(17, 'w', l);
		arr[17].insert(22, 's', l);
		arr[22].insert(28, 's', m);
		arr[28].insert(22, 'w', m);
		arr[22].insert(23, 'd', M);
		arr[23].insert(22, 'a', M);

		// links of vertex 23
		int n = rand() % 10 + 1;
		arr[23].insert(24, 'd', n);
		arr[24].insert(23, 'a', n);

		// links of vertex 24
		int N = rand() % 10 + 1;
		int o = rand() % 10 + 1;
		arr[24].insert(18, 'w', N);
		arr[18].insert(24, 's', N);
		arr[24].insert(25, 'd', o);
		arr[25].insert(24, 'a', o);
		int O = rand() % 10 + 1;
		arr[24].insert(29, 's', O);
		arr[29].insert(24, 'w', O);

		// links of vertex 25
		int p = rand() % 10 + 1;
		arr[25].insert(20, 'w', p);
		arr[20].insert(25, 's', p);
		int P = rand() % 10 + 1;
		arr[25].insert(26, 'd', P);

		// links of vertex 26

		arr[26].insert(25, 'a', P);

		// links of vertex 27
		int q = rand() % 10 + 1;
		arr[27].insert(28, 'd', q);

		// links of vertex 28

		arr[28].insert(27, 'a', q);
		int Q = rand() % 10 + 1;
		arr[28].insert(32, 's', Q);
		int r = rand() % 10 + 1;
		arr[28].insert(29, 'd', r);

		// links of vertex 29

		arr[29].insert(28, 'a', r);
		int R = rand() % 10 + 1;
		arr[29].insert(30, 'd', R);
		int s = rand() % 10 + 1;
		arr[29].insert(34, 's', s);

		// links of vertex 30

		arr[30].insert(29, 'a', R);
		int S = rand() % 10 + 1;
		arr[30].insert(33, 's', S);

		// links of vertex 31
		int t = rand() % 10 + 1;
		arr[31].insert(32, 'd', t);
		int T = rand() % 10 + 1;
		arr[31].insert(37, 's', T);

		// links of vertex 32

		arr[32].insert(28, 'w', Q);
		arr[32].insert(31, 'a', t);
		int u = rand() % 10 + 1;
		arr[32].insert(35, 's', u);

		// links of vertex 33

		arr[33].insert(30, 'w', S);
		int U = rand() % 10 + 1;
		arr[33].insert(36, 's', U);

		// links of vertex 34

		arr[34].insert(29, 'w', s);
		int v = rand() % 10 + 1;
		arr[34].insert(38, 's', v);

		// links of vertex 35

		arr[35].insert(32, 'w', u);

		// links of vertex 36

		arr[36].insert(33, 'w', U);
		int V = rand() % 10 + 1;
		arr[36].insert(39, 's', V);

		// links of vertex 37

		arr[37].insert(31, 'w', T);
		int w = rand() % 10 + 1;
		arr[37].insert(38, 'd', w);

		// links of vertex 38

		arr[38].insert(37, 'a', w);
		arr[38].insert(34, 'w', v);
		int W = rand() % 10 + 1;
		arr[38].insert(40, 's', W);

		// links of vertex 39

		arr[39].insert(36, 'w', V);

		// links of vertex 40

		arr[40].insert(38, 'w', W);
	}

	// display map of level 1 manual mode
	void displaymap(int val)
	{
		// line1
		if (val == 6)
		{
			cout << "               C ----";
		}
		else
		{
			cout << "               6 ----";
		}
		if (val == 7)
		{
			cout << "C ----";
		}
		else
		{
			cout << "7 ----";
		}
		if (val == 8)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "8 " << endl;
		}
		// line2
		cout << "                     |" << endl;

		cout << "S->";
		if (val == 1)
		{
			cout << "C ----";
		}
		else
		{
			cout << "1 ----";
		}
		if (val == 2)
		{
			cout << "C ----";
		}
		else
		{
			cout << "2 ----";
		}
		if (val == 3)
		{
			cout << "C ----";
		}
		else
		{
			cout << "3 ----";
		}
		if (val == 4)
		{
			cout << "C ----";
		}
		else
		{
			cout << "4 ----";
		}
		if (val == 5)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "5 " << endl;
		}
		// line 3
		cout << "   |           |           |" << endl;
		if (val == 9)
		{
			cout << "   C ----";
		}
		else
		{
			cout << "   9 ----";
		}
		if (val == 10)
		{
			cout << "C ----";
		}
		else
		{
			cout << "10----";
		}
		if (val == 11)
		{
			cout << "C     ";
		}
		else
		{
			cout << "11    ";
		}
		if (val == 12)
		{
			cout << "C ----";
		}
		else
		{
			cout << "12----";
		}
		if (val == 13)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "13" << endl;
		}
		// line 4
		cout << "         |     |     | " << endl;
		cout << "         |     ";
		if (val == 14)
		{
			cout << "C ----";
		}
		else
		{
			cout << "14----";
		}
		if (val == 15)
		{
			cout << "C ----";
		}
		else
		{
			cout << "15----";
		}
		if (val == 16)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "16" << endl;
		}
		// line 5
		cout << "         |     |     |   " << endl;
		cout << "         |     |     ";
		if (val == 18)
		{
			cout << "C ----";
		}
		else
		{
			cout << "18----";
		}
		if (val == 20)
		{
			cout << "C  ";
		}
		else
		{
			cout << "20 ";
		}
		cout << "< -F" << endl;
		// line 6
		if (val == 17)
		{
			cout << "         C ----";
		}
		else
		{
			cout << "         17----";
		}
		if (val == 19)
		{
			cout << "C" << endl;
		}
		else
		{
			cout << "19" << endl;
		}
	}

	// display For level 1 automatic mode
	void displaymap2(int val, LinkedList sh)
	{
		LinkedList *shortPath = &sh;
		Node *curr;
		Node *prev = nullptr;
		// line1
		if (val == 6)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 6)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 6 && prev->data == 7)
				{
					changeColor(12);
				}
			}
			cout << "               C ----";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 6)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 6 && prev->data == 7)
				{
					changeColor(12);
				}
			}
			cout << "               6 ----";
			changeColor(7);
		}
		if (val == 7)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 7)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 7 && prev->data == 4)
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 7)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 7 && prev->data == 4)
				{
					changeColor(12);
				}
			}
			cout << "7";
			changeColor(7);
		}
		if (val == 8)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 8)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 8 && prev->data == 7)
				{
					changeColor(12);
				}
			}
			cout << " ----C " << endl;
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 8)
			{
				prev = curr;
				curr = curr->next;
			}

			if (curr != NULL)
			{
				if (curr->data == 8 && prev->data == 7)
				{
					changeColor(12);
				}
			}
			cout << " ----8 " << endl;
			changeColor(7);
		}
		// line2

		curr = sh.head;
		while (curr != NULL && curr->data != 7)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 7 && prev->data == 4)
			{
				changeColor(12);
			}
		}
		cout << "                     |" << endl;
		changeColor(7);

		cout << "S->";
		if (val == 1)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 1)
			{
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 1)
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 1)
			{
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 1)
				{
					changeColor(12);
				}
			}
			cout << "1";
			changeColor(7);
		}
		if (val == 2)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 2)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 2 && prev->data == 1)
				{
					changeColor(12);
				}
			}
			cout << " ----C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 2)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 2 && prev->data == 1)
				{
					changeColor(12);
				}
			}
			cout << " ----2";
			changeColor(7);
		}
		if (val == 3)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 3)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 3 && prev->data == 2)
				{
					changeColor(12);
				}
			}
			cout << " ----C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 3)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 3 && prev->data == 2)
				{
					changeColor(12);
				}
			}
			cout << " ----3";
			changeColor(7);
		}
		if (val == 4)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 4)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 4 && prev->data == 3)
				{
					changeColor(12);
				}
			}
			cout << " ----C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 4)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 4 && prev->data == 3)
				{
					changeColor(12);
				}
			}
			cout << " ----4";
			changeColor(7);
		}
		if (val == 5)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 5)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 5 && prev->data == 4)
				{
					changeColor(12);
				}
			}

			cout << " ----C " << endl;
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 5)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 5 && prev->data == 4)
				{
					changeColor(12);
				}
			}
			cout << " ----5 " << endl;
			changeColor(7);
		}
		// line 3

		curr = sh.head;
		while (curr != NULL && curr->data != 9)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 9 && prev->data == 1)
			{
				changeColor(12);
			}
		}
		cout << "   |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 11)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 11 && prev->data == 3)
			{
				changeColor(12);
			}
		}
		cout << "           |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 13)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 13 && prev->data == 5)
			{
				changeColor(12);
			}
		}
		cout << "	   | " << endl;
		changeColor(7);

		if (val == 9)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 9)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 9 && prev->data == 1)
				{
					changeColor(12);
				}
			}
			cout << "   C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 9)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 9 && prev->data == 1)
				{
					changeColor(12);
				}
			}
			cout << "   9";
			changeColor(7);
		}

		curr = sh.head;
		while (curr != NULL && curr->data != 10)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 10 && prev->data == 9)
			{
				changeColor(12);
			}
		}
		cout << " ----";
		changeColor(7);

		if (val == 10)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 10)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 10 && (prev->data == 9 || prev->data == 11))
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 10)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 10 && (prev->data == 9 || prev->data == 11))
				{
					changeColor(12);
				}
			}
			cout << "10";
			changeColor(7);
		}

		if (val == 11)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 10)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 10 && (prev->data == 11 || curr->next->data == 11))
				{
					changeColor(12);
				}
			}
			cout << " ----";
			changeColor(7);

			curr = sh.head;
			while (curr != NULL && curr->data != 11)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 11 && (prev->data == 10 || prev->data == 3))
				{
					changeColor(12);
				}
			}

			cout << "C     ";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 10)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 10 && (prev->data == 11 || curr->next->data == 11))
				{
					changeColor(12);
				}
			}
			cout << "----";
			changeColor(7);

			curr = sh.head;
			while (curr != NULL && curr->data != 11)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 11 && (prev->data == 10 || prev->data == 3))
				{
					changeColor(12);
				}
			}

			cout << "11    ";
			changeColor(7);
		}

		if (val == 12)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 12)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 12 && prev->data == 13)
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 12)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 12 && prev->data == 13)
				{
					changeColor(12);
				}
			}
			cout << "12";
			changeColor(7);
		}
		if (val == 13)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 13)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 13 && prev->data == 5)
				{
					changeColor(12);
				}
			}
			cout << " ----C " << endl;
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 13)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 13 && prev->data == 5)
				{
					changeColor(12);
				}
			}
			cout << "----13" << endl;
			changeColor(7);
		}
		// line 4

		curr = sh.head;
		while (curr != NULL && curr->data != 17)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 17 && prev->data == 10)
			{
				changeColor(12);
			}
		}
		cout << "         |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 14)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 14 && prev->data == 11)
			{
				changeColor(12);
			}
		}
		cout << "     |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 15)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 15 && prev->data == 12)
			{
				changeColor(12);
			}
		}
		cout << "     | " << endl;
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 17)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 17 && prev->data == 10)
			{
				changeColor(12);
			}
		}
		cout << "         |     ";
		changeColor(7);

		if (val == 14)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 14)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 14 && (prev->data == 11 || prev->data == 19))
				{
					changeColor(12);
				}
			}

			cout << "C ----";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 14)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 14 && (prev->data == 11 || prev->data == 19))
				{
					changeColor(12);
				}
			}

			cout << "14----";
			changeColor(7);
		}

		if (val == 15)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 15)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 15 && (prev->data == 14 || prev->data == 12 || prev->data == 16))
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 15)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 15 && (prev->data == 14 || prev->data == 12 || prev->data == 16))
				{
					changeColor(12);
				}
			}
			cout << "15";
			changeColor(7);
		}
		if (val == 16)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 16)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 16 && prev->data == 15)
				{
					changeColor(12);
				}
			}
			cout << " ----C " << endl;
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 16)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 16 && prev->data == 15)
				{
					changeColor(12);
				}
			}
			cout << "----16" << endl;
			changeColor(7);
		}

		// line 5
		curr = sh.head;
		while (curr != NULL && curr->data != 17)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 17 && prev->data == 10)
			{
				changeColor(12);
			}
		}
		cout << "         |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 14)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 14 && prev->data == 19)
			{
				changeColor(12);
			}
		}
		cout << "     |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 18)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 18 && prev->data == 15)
			{
				changeColor(12);
			}
		}
		cout << "     |   " << endl;
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 17)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 17 && prev->data == 10)
			{
				changeColor(12);
			}
		}
		cout << "         |";
		changeColor(7);

		curr = sh.head;
		while (curr != NULL && curr->data != 14)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (curr->data == 14 && prev->data == 19)
			{
				changeColor(12);
			}
		}
		cout << "     |     ";
		changeColor(7);

		if (val == 18)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 18)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 18 && prev->data == 15)
				{
					changeColor(12);
				}
			}
			cout << "C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 18)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 18 && prev->data == 15)
				{
					changeColor(12);
				}
			}
			cout << "18";
			changeColor(7);
		}
		if (val == 20)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 20)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 20 && prev->data == 18)
				{
					changeColor(12);
				}
			}
			cout << " ----C  ";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 20)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 20 && prev->data == 18)
				{
					changeColor(12);
				}
			}
			cout << "----20 ";
			changeColor(7);
		}
		cout << "< -F" << endl;
		// line 6
		if (val == 17)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 17)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 17 && prev->data == 10)
				{
					changeColor(12);
				}
			}
			cout << "         C";
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 17)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 17 && prev->data == 10)
				{
					changeColor(12);
				}
			}
			cout << "         17";
			changeColor(7);
		}
		if (val == 19)
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 19)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 19 && prev->data == 17)
				{
					changeColor(12);
				}
			}
			cout << " ----C" << endl;
			changeColor(7);
		}
		else
		{
			curr = sh.head;
			while (curr != NULL && curr->data != 19)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->data == 19 && prev->data == 17)
				{
					changeColor(12);
				}
			}
			cout << "----19" << endl;
			changeColor(7);
		}
		return;
	}

	// display for level 2 manual mode
	void displaymaplv2(int val)
	{
		// line1
		if (val == 6)
		{
			cout << "               C ----";
		}
		else
		{
			cout << "               6 ----";
		}
		if (val == 7)
		{
			cout << "C ----";
		}
		else
		{
			cout << "7 ----";
		}
		if (val == 8)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "8 " << endl;
		}
		// line2
		cout << "                     |" << endl;

		cout << "S->";
		if (val == 1)
		{
			cout << "C ----";
		}
		else
		{
			cout << "1 ----";
		}
		if (val == 2)
		{
			cout << "C ----";
		}
		else
		{
			cout << "2 ----";
		}
		if (val == 3)
		{
			cout << "C ----";
		}
		else
		{
			cout << "3 ----";
		}
		if (val == 4)
		{
			cout << "C ----";
		}
		else
		{
			cout << "4 ----";
		}
		if (val == 5)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "5 " << endl;
		}
		// line 3
		cout << "   |           |           |" << endl;
		if (val == 9)
		{
			cout << "   C ----";
		}
		else
		{
			cout << "   9 ----";
		}
		if (val == 10)
		{
			cout << "C ----";
		}
		else
		{
			cout << "10----";
		}
		if (val == 11)
		{
			cout << "C     ";
		}
		else
		{
			cout << "11    ";
		}
		if (val == 12)
		{
			cout << "C ----";
		}
		else
		{
			cout << "12----";
		}
		if (val == 13)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "13" << endl;
		}
		// line 4
		cout << "         |     |     | " << endl;
		cout << "         |     ";
		if (val == 14)
		{
			cout << "C ----";
		}
		else
		{
			cout << "14----";
		}
		if (val == 15)
		{
			cout << "C ----";
		}
		else
		{
			cout << "15----";
		}
		if (val == 16)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "16" << endl;
		}
		// line 5
		cout << "         |     |     |   " << endl;
		cout << "         |     |     ";
		if (val == 18)
		{
			cout << "C ----";
		}
		else
		{
			cout << "18----";
		}
		if (val == 20)
		{
			cout << "C ";
		}
		else
		{
			cout << "20";
		}
		cout << endl;
		// line 6
		if (val == 17)
		{
			cout << "         C ----";
		}
		else
		{
			cout << "         17----";
		}
		if (val == 19)
		{
			cout << "C     |     |" << endl;
		}
		else
		{
			cout << "19    |     |" << endl;
		}
		// line 7
		cout << "         |           |     | " << endl;
		if (val == 21)
		{
			cout << "   C ----";
		}
		else
			cout << "   21----";
		if (val == 22)
			cout << "C ----";
		else
			cout << "22----";
		if (val == 23)
			cout << "C----";
		else
			cout << "23----";
		if (val == 24)
			cout << "C ----";
		else
			cout << "24----";
		if (val == 25)
			cout << "C ----";
		else
			cout << "25----";
		if (val == 26)
			cout << "C " << endl;
		else
			cout << "26" << endl;

		// line 8

		cout << "         |           |    " << endl;
		if (val == 27)
			cout << "   C ----";
		else
			cout << "   27----";
		if (val == 28)
			cout << "C ----------";
		else
			cout << "28----------";
		if (val == 29)
			cout << "C ----------";
		else
			cout << "29----------";
		if (val == 30)
			cout << "C " << endl;
		else
			cout << "30" << endl;

		// line 9
		cout << "         |           |           |" << endl;
		if (val == 31)
			cout << "   C ----";
		else
			cout << "   31----";
		if (val == 32)
			cout << "C          ";
		else
			cout << "32         ";
		if (val == 33)
			cout << " | C " << endl;
		else
			cout << " |           33" << endl;

		// line 10
		if (val == 34)
			cout << "   |     |           C ";
		else
			cout << "   |     |           34";
		cout << "          | " << endl;
		// line 11
		if (val == 35)
			cout << "   |     C          ";
		else
			cout << "   |     35         ";
		if (val == 36)
			cout << " |           C " << endl;
		else
			cout << " |           36" << endl;
		// line 12
		cout << "   |                 |           |" << endl;
		if (val == 37)
			cout << "   C ----------------";
		else
			cout << "   37----------------";
		if (val == 38)
			cout << "C           | " << endl;
		else
			cout << "38          | " << endl;
		if (val == 39)
			cout << "                     |           C " << endl;
		else
			cout << "                     |           39" << endl;
		if (val == 40)
			cout << "                     C " << endl;
		else
			cout << "                     40" << endl;
	}

	// display of level 2 automatic mode
	void displaymaplv2A(int val, LinkedList sh)
	{

		cout << "Shortest path utilizing minimum cost: \n\n";
		changeColor(12);
		sh.display();
		cout << "\n\n";
		changeColor(7);

		// line1
		if (val == 6)
		{
			cout << "               C ----";
		}
		else
		{
			cout << "               6 ----";
		}
		if (val == 7)
		{
			cout << "C ----";
		}
		else
		{
			cout << "7 ----";
		}
		if (val == 8)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "8 " << endl;
		}
		// line2
		cout << "                     |" << endl;

		cout << "S->";
		if (val == 1)
		{
			cout << "C ----";
		}
		else
		{
			cout << "1 ----";
		}
		if (val == 2)
		{
			cout << "C ----";
		}
		else
		{
			cout << "2 ----";
		}
		if (val == 3)
		{
			cout << "C ----";
		}
		else
		{
			cout << "3 ----";
		}
		if (val == 4)
		{
			cout << "C ----";
		}
		else
		{
			cout << "4 ----";
		}
		if (val == 5)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "5 " << endl;
		}
		// line 3
		cout << "   |           |           |" << endl;
		if (val == 9)
		{
			cout << "   C ----";
		}
		else
		{
			cout << "   9 ----";
		}
		if (val == 10)
		{
			cout << "C ----";
		}
		else
		{
			cout << "10----";
		}
		if (val == 11)
		{
			cout << "C     ";
		}
		else
		{
			cout << "11    ";
		}
		if (val == 12)
		{
			cout << "C ----";
		}
		else
		{
			cout << "12----";
		}
		if (val == 13)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "13" << endl;
		}
		// line 4
		cout << "         |     |     | " << endl;
		cout << "         |     ";
		if (val == 14)
		{
			cout << "C ----";
		}
		else
		{
			cout << "14----";
		}
		if (val == 15)
		{
			cout << "C ----";
		}
		else
		{
			cout << "15----";
		}
		if (val == 16)
		{
			cout << "C " << endl;
		}
		else
		{
			cout << "16" << endl;
		}
		// line 5
		cout << "         |     |     |   " << endl;
		cout << "         |     |     ";
		if (val == 18)
		{
			cout << "C ----";
		}
		else
		{
			cout << "18----";
		}
		if (val == 20)
		{
			cout << "C ";
		}
		else
		{
			cout << "20";
		}
		cout << endl;
		// line 6
		if (val == 17)
		{
			cout << "         C ----";
		}
		else
		{
			cout << "         17----";
		}
		if (val == 19)
		{
			cout << "C     |     |" << endl;
		}
		else
		{
			cout << "19    |     |" << endl;
		}
		// line 7
		cout << "         |           |     | " << endl;
		if (val == 21)
		{
			cout << "   C ----";
		}
		else
			cout << "   21----";
		if (val == 22)
			cout << "C ----";
		else
			cout << "22----";
		if (val == 23)
			cout << "C----";
		else
			cout << "23----";
		if (val == 24)
			cout << "C ----";
		else
			cout << "24----";
		if (val == 25)
			cout << "C ----";
		else
			cout << "25----";
		if (val == 26)
			cout << "C " << endl;
		else
			cout << "26" << endl;

		// line 8

		cout << "         |           |    " << endl;
		if (val == 27)
			cout << "   C ----";
		else
			cout << "   27----";
		if (val == 28)
			cout << "C ----------";
		else
			cout << "28----------";
		if (val == 29)
			cout << "C ----------";
		else
			cout << "29----------";
		if (val == 30)
			cout << "C " << endl;
		else
			cout << "30" << endl;

		// line 9
		cout << "         |           |           |" << endl;
		if (val == 31)
			cout << "   C ----";
		else
			cout << "   31----";
		if (val == 32)
			cout << "C          ";
		else
			cout << "32         ";
		if (val == 33)
			cout << " | C " << endl;
		else
			cout << " |           33" << endl;

		// line 10
		if (val == 34)
			cout << "   |     |           C ";
		else
			cout << "   |     |           34";
		cout << "          | " << endl;
		// line 11
		if (val == 35)
			cout << "   |     C          ";
		else
			cout << "   |     35         ";
		if (val == 36)
			cout << " |           C " << endl;
		else
			cout << " |           36" << endl;
		// line 12
		cout << "   |                 |           |" << endl;
		if (val == 37)
			cout << "   C ----------------";
		else
			cout << "   37----------------";
		if (val == 38)
			cout << "C           | " << endl;
		else
			cout << "38          | " << endl;
		if (val == 39)
			cout << "                     |           C " << endl;
		else
			cout << "                     |           39" << endl;
		if (val == 40)
			cout << "                     C " << endl;
		else
			cout << "                     40" << endl;
	}

	// gameplay for level 1 manual mode
	void gameplay(string name = "guest")
	{
		LinkedList achievementlist;
		obstaclequeue obstacles;
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		int health = 25;
		node *currposition = arr[1].head;
		displaymap(currposition->data);

	movement:
		if (currposition->data == 20)
		{
			system("CLS");
			Node *currach = achievementlist.head;

			ofstream outputFile;
			outputFile.open("scorehistorylv1.txt", ios::app);

			outputFile << name << " , score = " << health << ", achievements: ";
			while (currach)
			{
				outputFile << currach->ach;
				currach = currach->next;
			}
			outputFile << endl;

			outputFile.close();
			currach = achievementlist.head;
			cout << "your achivements are: " << endl;
			while (currach)
			{
				cout << currach->ach << " ";
				currach = currach->next;
			}
			cout << endl;
			changeColor(14);
			cout << "CONGATULATION ON COMPLETING THE GAME YOU ARE A WINNER" << endl;
			cout << endl
				 << "enter anything to get back to the main menu" << endl;
			string any;
			cin >> any;
			system("CLS");
			return;
		}
		if (health <= 0)
		{
			cout << "Your health is finished K.O" << endl;
			return;
		}
		cout << "enter  w,a,s,d to move accordingly" << endl;
		char c;
		cin >> c;
		int moveto;
		bool flag = false;
		node *tempposition = currposition;
		while (tempposition)
		{
			if (c == tempposition->direction)
			{
				moveto = tempposition->data;
				flag = true;
				break;
			}
			tempposition = tempposition->next;
		}
		if (flag == false)
		{
			cout << "invalid move error try again" << endl;
			goto movement;
		}
		for (int i = 1; i < 21; i++)
		{
			if (arr[i].head->data == moveto)
			{
				currposition = arr[i].head;
				system("CLS");

				displaymap(currposition->data);
				int a = rand() % 10 + 1;
				if (a == 3 || a == 5 || a == 7)
				{
					cout << "you have encounteres a obstacles " << obstacles.front->minus_health << " score" << endl;
					health = health + obstacles.dequeue();
				}
				if (a == 2 || a == 4)
				{
					cout << "you got a achievement: $" << endl;
					achievementlist.insertach('$');
				}
				health += 2;
				cout << "score = " << health << endl;
				cout << "Health = " << health << endl;

				goto movement;
			}
		}
	}

	// gameplay of level 1 of automatic mode
	void gameplay2(LinkedList &shortestPath)
	{

		int health = 25;
		node *currposition = arr[1].head;
		displaymap2(currposition->data, shortestPath);

	movement:
		if (currposition->data == 20)
		{
			system("CLS");
			changeColor(14);
			cout << "CONGATULATION ON COMPLETING THE GAME YOU ARE A WINNER" << endl;
			cout << endl
				 << "enter anything to get back to the main menu" << endl;
			string any;
			cin >> any;
			system("CLS");
			return;
		}
		if (health <= 0)
		{
			cout << "Your health is finished K.O" << endl;
			return;
		}
		cout << "enter  w,a,s,d to move accordingly" << endl;
		char c;
		cin >> c;
		int moveto;
		bool flag = false;
		node *tempposition = currposition;
		while (tempposition)
		{
			if (c == tempposition->direction)
			{
				moveto = tempposition->data;
				flag = true;
				break;
			}
			tempposition = tempposition->next;
		}
		if (flag == false)
		{
			cout << "invalid move error try again" << endl;
			goto movement;
		}
		for (int i = 1; i < 21; i++)
		{
			if (arr[i].head->data == moveto)
			{
				currposition = arr[i].head;
				system("CLS");

				displaymap2(currposition->data, shortestPath);
				if (arr[i].head->obstaclehead.front)
				{
					if (arr[i].head->data == 16)
					{
						cout << "this node contains the devil his hit causes -10 health." << endl;
						health = health + arr[i].head->obstaclehead.front->minus_health;
					}
					else if (arr[i].head->data == 11)
					{
						cout << "you get the help of an angel +10 health" << endl;
						health = health + arr[i].head->obstaclehead.front->minus_health;
					}
					else
					{
						cout << "you are facing an obstacle hence your health will be subtracted from " << endl;
						health = health + arr[i].head->obstaclehead.front->minus_health;
					}
				}
				cout << "Health = " << health << endl;

				goto movement;
			}
		}
		return;
	}

	// gameplay for level 2 manual mode
	void gameplaylv2(string name = "guest")
	{

		obstaclequeue obstacles;
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);

		LinkedList achievementlist;

		srand(time(0));

		int health = 5;
		node *currposition = arr[1].head;
		displaymaplv2(currposition->data);

	movement:
		if (currposition->data == 40)
		{
			system("CLS");
			Node *currach = achievementlist.head;

			ofstream outputFile;
			outputFile.open("scorehistorylv2.txt", ios::app);

			outputFile << name << " , score = " << health << ", achievements: ";
			while (currach)
			{
				outputFile << currach->ach;
				currach = currach->next;
			}
			outputFile << endl;

			outputFile.close();

			currach = achievementlist.head;
			cout << "your achivements are: " << endl;
			while (currach)
			{
				cout << currach->ach << " ";
				currach = currach->next;
			}
			cout << endl;
			changeColor(14);

			cout << "CONGATULATION ON COMPLETING THE GAME YOU ARE A WINNER" << endl;
			cout << endl
				 << "Enter anything to get back to the main menu: " ;
			string any;
			cin >> any;
			system("CLS");
			return;
		}
		if (health <= 0)
		{
			system("CLS");

			cout << "Your health is finished K.O" << endl;
			return;
		}
		cout << "enter  w,a,s,d to move accordingly" << endl;
		char c;
		cin >> c;
		int moveto;
		bool flag = false;
		node *tempposition = currposition;
		while (tempposition)
		{
			if (c == tempposition->direction)
			{
				moveto = tempposition->data;
				flag = true;
				break;
			}
			tempposition = tempposition->next;
		}
		if (flag == false)
		{
			cout << "invalid move error try again" << endl;
			goto movement;
		}
		for (int i = 1; i < 41; i++)
		{
			if (arr[i].head->data == moveto)
			{
				currposition = arr[i].head;
				system("CLS");

				displaymaplv2(currposition->data);

				int a = rand() % 10 + 1;
				if (a == 3 || a == 5 || a == 7)
				{
					cout << "you have encounteres a obstacles " << obstacles.front->minus_health << " score" << endl;
					health = health + obstacles.dequeue();
				}
				if (a == 2 || a == 4)
				{
					cout << "you got a achievement: $" << endl;
					achievementlist.insertach('$');
				}
				health += 2;
				cout << "score = " << health << endl;

				goto movement;
			}
		}
	}

	// gameplay of level 2 automatic mode
	void gameplaylv2A(LinkedList &shortestPath, string name = "guest")
	{

		obstaclequeue obstacles;
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);
		obstacles.enqueue(-5);

		srand(time(0));

		int health = 5;
		node *currposition = arr[1].head;
		displaymaplv2A(currposition->data, shortestPath);

	movement:
		if (currposition->data == 40)
		{
			system("CLS");
			ofstream outputFile;
			outputFile.open("leaderboard.txt", ios::app);

			outputFile << name << " , score = " << health << endl;

			outputFile.close();
			changeColor(14);

			cout << "CONGATULATION ON COMPLETING THE GAME YOU ARE A WINNER" << endl;
			cout << endl
				 << "Enter anything to get back to the main menu: " ;
			string any;
			cin >> any;
			system("CLS");
			return;
		}
		if (health <= 0)
		{
			system("CLS");

			cout << "Your health is finished K.O" << endl;
			return;
		}
		cout << "enter  w,a,s,d to move accordingly" << endl;
		char c;
		cin >> c;
		int moveto;
		bool flag = false;
		node *tempposition = currposition;
		while (tempposition)
		{
			if (c == tempposition->direction)
			{
				moveto = tempposition->data;
				flag = true;
				break;
			}
			tempposition = tempposition->next;
		}
		if (flag == false)
		{
			cout << "invalid move error try again" << endl;
			goto movement;
		}
		for (int i = 1; i < 41; i++)
		{
			if (arr[i].head->data == moveto)
			{
				currposition = arr[i].head;
				system("CLS");

				displaymaplv2A(currposition->data, shortestPath);

				int a = rand() % 10 + 1;
				if (a == 3 || a == 5 || a == 7)
				{
					cout << "you have encounteres a obstacles " << obstacles.front->minus_health << " score" << endl;
					health = health + obstacles.dequeue();
				}
				health += 2;
				cout << "score = " << health << endl;

				goto movement;
			}
		}
	}

	// File reading
	void FileReading()
	{
	}
};

class Dijkstra
{
private:
	int *parent = new int[21];
	int *parent2A = new int[41];

	int minDistance(int dist[], bool sptSet[], int V)
	{
		int min = INT_MAX, min_index;
		for (int v = 1; v <= V; v++)
		{
			if (sptSet[v] == false && dist[v] <= min)
			{
				min = dist[v];
				min_index = v;
			}
		}
		return min_index;
	}

	LinkedList constructPath(int src, int dest, int *parent)
	{
		LinkedList path;
		int current = dest;
		while (current != -1)
		{
			path.insert(current);
			current = parent[current];
		}
		return path;
	}

public:
	LinkedList getShortestPath(graph &g, int src, int dest)
	{
		parent[src] = -1;
		int *dist = new int[g.numberofvertex + 1];
		bool *sptSet = new bool[g.numberofvertex + 1];
		for (int i = 1; i <= g.numberofvertex; i++)
		{
			dist[i] = INT_MAX;
			sptSet[i] = false;
		}
		dist[src] = 0;
		for (int count = 1; count <= g.numberofvertex - 1; count++)
		{
			int u = minDistance(dist, sptSet, g.numberofvertex);
			sptSet[u] = true;
			node *currentNode = g.arr[u].head;
			while (currentNode)
			{
				int v = currentNode->data;
				int weight = currentNode->weight; // for now let weight is 1
				if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
					parent[v] = u;
				}
				currentNode = currentNode->next;
			}
		}
		LinkedList shortestPath = constructPath(src, dest, parent);
		delete[] dist;
		delete[] sptSet;
		return shortestPath;
	}

	LinkedList getShortestPath2A(graph &g, int src, int dest)
	{
		parent2A[src] = -1;
		int *dist = new int[g.numberofvertex + 1];
		bool *sptSet = new bool[g.numberofvertex + 1];
		for (int i = 1; i <= g.numberofvertex; i++)
		{
			dist[i] = INT_MAX;
			sptSet[i] = false;
		}
		dist[src] = 0;
		for (int count = 1; count <= g.numberofvertex - 1; count++)
		{
			int u = minDistance(dist, sptSet, g.numberofvertex);
			sptSet[u] = true;
			node *currentNode = g.arr[u].head;
			while (currentNode)
			{
				int v = currentNode->data;
				int weight = currentNode->weight; // for now let weight is 1
				if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
					parent2A[v] = u;
				}
				currentNode = currentNode->next;
			}
		}
		LinkedList shortestPath = constructPath(src, dest, parent2A);
		delete[] dist;
		delete[] sptSet;
		return shortestPath;
	}
};
