#include "stdafx.h"
#include "queue.h"
#include"pqueue.h""
queue::queue()
{
	myFront = myBack = NULL;
}
queue::queue(const queue & original)
{
	myFront = new Node(original.myFront->data, original.myFront->ship);
	NodePointer ptr = myFront;
	NodePointer oriptr = original.myFront->next;
	while (oriptr != NULL)
	{
		ptr->next = new Node(oriptr->data, original.myFront->ship);
		ptr = ptr->next;
		oriptr = oriptr->next;
	}
	myBack = ptr;
}
queue::~queue()
{
	Node* ptr = myFront;
	while (ptr != NULL)
	{
		myFront = myFront->next;
		delete ptr;
		ptr = myFront;
	}
}
const queue & queue::operator=(const queue & rightHandSide)
{
	if (&rightHandSide != this)
	{
		this->~queue();
		myFront = new Node(rightHandSide.myFront->data, rightHandSide.myFront->ship);
		NodePointer ptr = myFront;
		myFront->next = ptr;
		NodePointer oriptr = rightHandSide.myFront->next;
		while (oriptr != NULL)
		{
			ptr->next = new Node(oriptr->data, rightHandSide.myFront->ship);
			ptr = ptr->next;
			oriptr = oriptr->next;
		}
		myBack = ptr;
	}
	return *this;
}
bool queue::empty() const
{
	if (myFront == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void queue::enqueue(const QueueElement & value,pqueue ship)
{
	Node* ptr = myFront;
	Node* temp = new Node(value,ship);
	if (myBack == NULL&&myFront == NULL)
	{
		myFront = temp;
		myBack = temp;
	}
	else
	{
		myBack->next = temp;
		myBack = temp;
	}
}
void queue::display(ostream & out) const
{
	if (myBack == NULL&&myFront == NULL)
	{
		cout << "the queue is empty";
	}
	else
	{
		Node* ptr = myFront;
		while (ptr != NULL)
		{
			cout <<"delivery man  ";
			out << ptr->data << endl;
			ptr->ship.display(cout);
			cout << endl;
			ptr = ptr->next;
			cout << "--------------------"<<endl;
		}
	}
}
QueueElement queue::front() const
{
	return myFront->data;
}
void queue::dequeue()
{
	if (myBack == NULL&&myFront == NULL)
	{
		cout << "the queue is empty";
	}
	else if (myBack == myFront)
	{
		Node* ptr = myFront;
		myFront = NULL;
		myBack = NULL;
		delete ptr;
	}
	else
	{
		Node* ptr = myFront;
		myFront = myFront->next;
		delete ptr;
	}
}

