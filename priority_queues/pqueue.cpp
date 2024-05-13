#include "stdafx.h"
#include "pqueue.h"
pqueue::pqueue()
{
	myFront = myBack = NULL;
}
pqueue::pqueue(const pqueue & original)
{
	myFront = new Node(original.myFront->data, original.myFront->priority);
	NodePointer ptr = myFront;
	NodePointer oriptr = original.myFront->next;
	while (oriptr != NULL)
	{
		ptr->next = new Node(oriptr->data, oriptr->priority);
		ptr = ptr->next;
		oriptr = oriptr->next;
	}
	myBack = ptr;
}
pqueue::~pqueue()
{
	Node* ptr = myFront;
	while (ptr != NULL)
	{
		myFront = myFront->next;
		delete ptr;
		ptr = myFront;
	}
}
const pqueue & pqueue::operator=(const pqueue & rightHandSide)
{
	if (&rightHandSide != this)
	{
		this->~pqueue();
		myFront = new Node(rightHandSide.myFront->data, rightHandSide.myFront->priority);
		NodePointer ptr = myFront;
		myFront->next = ptr;
		NodePointer oriptr = rightHandSide.myFront->next;
		while (oriptr != NULL)
		{
			ptr->next = new Node(oriptr->data, oriptr->priority);
			ptr = ptr->next;
			oriptr = oriptr->next;
		}
		myBack = ptr;
	}
	return *this;
}
bool pqueue::empty() const
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
void pqueue::enqueue(const QueueElement & value,int p)
{
	Node* ptr = myFront;
	Node* temp = new Node(value, p);
	if (myBack == NULL&&myFront == NULL)
	{
		myFront = temp;
		myBack = temp;
	}
	else if (myFront->priority > p)
	{
		temp->next = myFront;
		myFront = temp;
	}
	else if (myBack->priority <= p)
	{
		myBack->next = temp;
		myBack = temp;
	}
	else 
	{
		while (ptr->next != NULL&& ptr->next->priority == p)
		{
			ptr = ptr->next;
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
}
void pqueue::display(ostream & out) const
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
			out << ptr->data << "  ";
			ptr = ptr->next;
		}
	}
}
QueueElement pqueue::front() const
{
	return myFront->data;
}
void pqueue::dequeue()
{
	if (myBack == NULL&&myFront == NULL)
	{
		cout << "the queue is empty";
	}
	else if(myBack==myFront)
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
