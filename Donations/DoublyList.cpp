/*
	Hsu, Golden
	CS A250
	06, October 2016

	Lab 07
*/
#include "DoublyList.h"

DoublyList::DoublyList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

DoublyList::~DoublyList()
{
	destroyList();
}

void DoublyList::insertBack(int newData)
{
	Node *newNode;
	newNode = new Node;

	newNode->setData(newData);

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->setNextLink(newNode);
		newNode->setPreviousLink(last);
		last = newNode;
	}
	count++;
}

bool DoublyList::search(int searchData) const
{
    Node *current = first;	

    while (current != NULL)	
	{		
		if (current->getData() == searchData)
			return true;
        else
            current = current->getNextLink();	
	}
}

void DoublyList::deleteNode(int deleteData) 
{
    if (first == NULL)		
	{
        cerr << "Cannot delete from an empty list." << endl;
	}
    else  
    {
		Node *current;		

        if (first->getData() == deleteData)   
		{
		
			current = first;	
			if (count == 1)
				first = nullptr;
			else
			{
				first = first->getNextLink();
				first->setPreviousLink(nullptr);
			}

			if (first == NULL)	
				last = NULL;				

			delete current;
			current = NULL;		
			count--;
		}
		else 
		{
			bool found = false;								
			current = first;	

			while (current != NULL && !found) 
			{				  
				if (current->getData() == deleteData) 
					found = true;					  
				else
				current = current->getNextLink(); 
			}

			if (current == NULL && !found)	
				cerr << "The item to be deleted is not in the list." << endl;
			else         
			{
				if (current != last)
				{
					current->getPreviousLink()->setNextLink(current->getNextLink());
					current->getNextLink()->setPreviousLink(current->getPreviousLink());
				}
				else
				{
					last = current->getPreviousLink();
					last->setNextLink(nullptr);
				}
		
				delete current;
				current = NULL;
				count--;
			}
		}
	}	
	
}

void DoublyList::print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = first;

		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNextLink();
		}
		cout << endl;
	}	
	cout << count;
}

void DoublyList::reversePrint() const 
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = last;

		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getPreviousLink();
		}
		cout << endl;
	}
}

void DoublyList::destroyList()
{ 
    Node  *temp;
	
    while (first != NULL)
    {
		first = temp;
        temp = temp->getNextLink();
        delete first;
		first = NULL;
    }

	last = NULL;	
	count = 0;
}
