#include "stdafx.h"
#include "pqueue.h"
#include"queue.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

	
int main()
{
	cout << "enter the path of the file : ";
	string s;
	cin >> s;
	int id;
	string temp;
	string p;
	int p1=3;
	queue deliverymen;
	ifstream x(s,ios::binary);
	if (x.is_open())
	{
		int i = 0;
		while (x.good())
		{
			i++;
			pqueue shipments;
			for (int j = 0; j < 5; j++)
			{
				getline(x,temp,',');
				//cout << temp<<"  ";
				id = atoi(temp.c_str());
				x>> p;
				//cout << p<<endl;
				if (p == "plat")
				{
					p1 = 1;
				}
				else if (p == "gold")
				{
					p1 = 2;
				}
				else if(p=="silver")
				{
					p1 = 3;
				}
				else
				{
					p1 = 3;
				}
				shipments.enqueue(id, p1);
			}
			deliverymen.enqueue(i, shipments);
		}
		x.close();
	}
	else
	{
		cout << "error opening file." << endl;
	}
	deliverymen.display(cout);
		cout<<endl;
}

