#pragma once
#include<iostream>
using namespace std;
typedef int QueueElement;
class pqueue
{
private:
	/*** Node class ***/
	class Node
	{
	public:
		QueueElement data;
		int priority;
		Node* next;
		Node(QueueElement value,int p)
		{
			data = value; 
			priority = p;
			next = 0;
		}

	};

	typedef Node* NodePointer;
	NodePointer myFront,myBack;
public:
	pqueue();
	//deafult constructor that 
	pqueue(const pqueue& original);
	~pqueue();
	const pqueue& operator= (const pqueue& rightHandSide);
	bool empty() const;
	void enqueue(const QueueElement& value, int p);
	void display(ostream& out) const;
	QueueElement front() const;
	void dequeue();
};

