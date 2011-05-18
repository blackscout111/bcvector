#ifndef bcvector_h
#define bcvector_h

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <class type>
class bcvector
{
	public:
		// Constructor
		bcvector(int initial_capacity = 1);
		
		// Copy Constructor
		bcvector( const bcvector<type>& copyvec);
		
		// Destructor
		~bcvector();

		// The following two functions overide the [] operator
		type& operator [](int index);
		const type& operator [](int index) const;

		// Makes the vector speedy (default) 
		void makeSpeedy();

		// Makes the vector conservative
		void makeConservative();

		// Returns 'list_capacity'
		int capacity()	const;

		// Returns 'list_size'
		int size() const;

		// Returns value of 'is_conservative'
		bool isConservative() const;

		// Returns TRUE if 'list_size' == 0
		bool empty() const;

		// Returns TRUE if 'list_size' == 'list_capacity'
		bool full() const;

		// Adds an entry to the end of the list
		void append(type);

		// Removies the entry at the end of the list
		void rip();

		// Prints 'bcvector' data
		void print(int min_index = -1, int max_index = -1) const;

	protected:
		// The capacity of the array
		// (how many slots there are left that can be filled)
		int list_capacity;

		// The index of the highest filled array element
		int list_size;

		// Indicates if the vector grows conservatively or quickly
		// (true = conservatively = as little memory as possible)
		// (false = quickly)
		bool is_conservative;

		// The pointer array
		type *list;
};


/***************************************************************************
* BEGIN MEMBER FUNCTION DEFINITIONS
**************************************************************************/
//_________________________________________________________________________
template <class type>
bcvector<type>::bcvector(int initial_capacity)
{
	// Sets initial capacity of the list
	if (initial_capacity > 0)
	{
		list_capacity = initial_capacity;
	}

	// Sets initial size of list
	list_size = 0;

	// Allocates memory for list elements
	list = new type [list_capacity];

	// Sets the vector to grow quickly
	is_conservative = false;

}


//_________________________________________________________________________
template <class type>
bcvector<type>::bcvector(const bcvector<type>& copyvec)
{
	if (this != &copyvec)
	{
		list_capacity = copyvec.capacity();
		list_size = copyvec.size();

		list = new type [list_capacity];

		for (int i = 0; i < list_size; i++)
		{
			list[i] = copyvec[i];
		}
	}
}


//_________________________________________________________________________
template <class type>
bcvector<type>::~bcvector()
{
/*
	cout << endl << "delete!" << endl;
	cout << "deleting this: " << this << endl;
*/

	delete[] list;
	list = NULL;

//	cout << "iz deleted!" << endl;
}


//_________________________________________________________________________
template <class type>
type& bcvector<type>::operator [](int index)
{
	if (index >= 0 && index < list_size)
	{
		return list[index];
	}
	else
	{
		cout	<< endl
			<< "bcvector.h: In member function "
			<< "'template <class type>bcvector<type>&"
			<< "bcvector<type>::operator [](int index) "
			<< endl
			<< "bcvector.h: error: "
			<< "'index' of "
			<< index
			<< " is out of bounds! "
			<< "'index' must be greater than 0 and less than "
			<< list_size
			<< endl << endl;

		cout << "Press ENTER to terminate program...";

		cin.get();

		// Exits program returning the value '-1'
		exit(-1);
	}
}


//_________________________________________________________________________
template <class type>
const type& bcvector<type>::operator [](int index) const
{
	if (index >= 0 && index < list_size)
	{
		return list[index];
	}
	else
	{
		cout	<< endl
			<< "bcvector.h: In member function "
			<< "'template <class type>bcvector<type>&"
			<< "bcvector<type>::operator [](int index) "
			<< endl
			<< "bcvector.h: error: "
			<< "'index' of "
			<< index
			<< " is out of bounds! "
			<< "'index' must be greater than 0 and less than "
			<< list_size
			<< endl << endl;

		cout << "Press ENTER to terminate program...";

		cin.get();

		// Exits program returning the value '-1'
		exit(-1);
	}
}


//_________________________________________________________________________
template <class type>
void bcvector<type>::makeSpeedy()
{
	// Sets the vectors growth behavior
	is_conservative = false;
}


//_________________________________________________________________________
template <class type>
void bcvector<type>::makeConservative()
{
	// Sets the vectors growth behavior
	is_conservative = true;
}


//_________________________________________________________________________
template <class type>
int bcvector<type>::capacity() const
{
	return list_capacity;
}


//_________________________________________________________________________
template <class type>
int bcvector<type>::size() const
{
	return list_size;
}


//_________________________________________________________________________
template <class type>
bool bcvector<type>::empty() const
{
	return (list_size == 0);
}


//_________________________________________________________________________
template <class type>
bool bcvector<type>::full() const
{
	return (list_size == list_capacity);
}


//_________________________________________________________________________
template <class type>
void bcvector<type>::append(type newelem)
{

	// If the new element fills the list
	// then increase the list size
	if ((list_size + 1) > list_capacity)
	{
		// If the vector is conservative, the capacity is increased by one.
		// Otherwise the capacity is doubled
		if (is_conservative)
		{
			list_capacity++;
		}
		else
		{
			// Doubles the capacity of the list
			list_capacity = 2 * list_capacity;
		}

		// Temporary list
		type *templist;
		templist = new type [list_capacity];

		// Copies all elements in 'list' to 'templist'
		for (int i = 0; i < list_size; i++)
		{
			templist[i] = list[i];
		}

		// Frees the original list's memory
		delete[] list;
		
		// Makes list point to templist
		list = templist;
	}

	// Adds element to list
	list[list_size] = newelem;

	// Increases list_size by 1
	list_size++;
}


//_________________________________________________________________________
template <class type>
void bcvector<type>::rip()
{
	if (list_size > 0)
	{
		// If the vector is conservative, then the amount of allocated
		// memory is reduced to the needed amount.
		// Otherwise, only the value of 'list_size' is decreased.
		list_size--;
		if (is_conservative)
		{
			// If the vector is conservative the capacity of the list
			// should be the same as the size of the list
			list_capacity = list_size;

			// Temporary list
			type *templist;
			templist = new type [list_capacity];

			// Copies all elements in 'list' to 'templist'
			for (int i = 0; i < list_size; i++)
			{
				templist[i] = list[i];
			}

			// Frees the original list's memory
			delete[] list;
			
			// Makes list point to templist
			list = templist;
		}
	}
}


//_________________________________________________________________________
template <class type>
void bcvector<type>::print(int min_index, int max_index) const
{
	// Displays myvec capacity and size

	cout	<< "this= " << this << endl
		<< "capacity= " << list_capacity << endl
		<< "size= " << list_size << endl;

	// Prints the contents of myvec
	if (min_index >= 0 && max_index >= min_index && list_size > 0)
	{
		for (int i = min_index; i <= max_index; i++)
		{
			cout << "[" << i << "]= " << list[i] << endl;
		}
	}

}

#endif
