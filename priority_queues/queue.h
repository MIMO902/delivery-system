#pragma once
#include<iostream>
#include"pqueue.h""
using namespace std;
typedef int QueueElement;
class queue
{
private:
	/*** Node class ***/
	class Node
	{
	public:
		QueueElement data;
		pqueue ship;
		Node* next;
		Node(QueueElement value,pqueue Ship)
		{
			data = value;
			ship = Ship;
			next = 0;
		}

	};

	typedef Node* NodePointer;
	NodePointer myFront, myBack;
public:
	queue();
	queue(const queue& original);
	~queue();
	const queue& operator= (const queue& rightHandSide);
	bool empty() const;
	void enqueue(const QueueElement& value, pqueue ship);
	void display(ostream& out) const;
	QueueElement front() const;
	void dequeue();
};



