#include <iostream>
#include <vector>
// to use find
#include<bits/stdc++.h>
using namespace std;

// print the entries of the input vector
// by using the first approach - array-style indexing
void printVectorClassical(vector<int> &vectorToBePrinted)
{
	cout<<"Printing the vector entries by using the array-style indexing!"<<endl;
	for (int i=0; i<vectorToBePrinted.size();i++)
	{
		cout<<vectorToBePrinted[i]<<endl; // here we index the vector by using the classical array-style indexing
	}
	// vectorToBePrinted.size() - returns the number of elements in the vector
}

// print the entries of the input vector
// by using the second approach - approach based on iterators
void printVectorIterators(vector<int> &vectorToBePrinted)
{
	// here we define an iterator
	vector<int>::iterator vectorIterator;
	cout<<"Printing the vector entries by using vector iterators!"<<endl;
	
	for(vectorIterator=vectorToBePrinted.begin(); vectorIterator!=vectorToBePrinted.end();vectorIterator++)
	{
		cout<< *vectorIterator <<endl; // use the dereferencing operator to print the current data of the iterator
	}
	//vectorToBePrinted.begin() returns an iterator located at the first element of the vector
	//vectorToBePrinted.begin() returns an iterator located immediatelly after the last element in the vector
}


int main()
{
	// declarations
	// declaring vectors
	vector<int> vector1;
	// declaring a vector container of integer type of size 5
	vector<int> vector2(5);
	// declare a vector container of integer type of size 6, and initialize the entries to 2
	vector<int> vector3(6,2);
	
		
	// add 15,20,2,-1,-10 to the vector
	vector1.push_back(15);
	vector1.push_back(20);
	vector1.push_back(2);
	vector1.push_back(-1);
	vector1.push_back(-10);
	vector1.push_back(-5);
	vector1.push_back(25);
	
	// accesing and printing the entries individually
	cout<<vector1[0]<<endl; //indexing starts from 0 similarly to the indexing of arrays
	cout<<vector1.at(1)<<endl;
	cout<<vector1.front()<<endl;
	cout<<vector1.back()<<endl;		
	
	// two ways for printing vectors
	printVectorClassical(vector1);
	printVectorIterators(vector1);
	

	// information about vectors
	cout<<"vector1 size is: "<<vector1.size()<<endl;
	// resize the vector
	vector2.resize(10); // 0s are placed automatically at new entries
	cout<<"vector2 size is: "<<vector2.size()<<endl;
	printVectorIterators(vector2); 
	// resize with a specific number set to be copied at the empty spots
	int numberToCopy=2;
	vector2.resize(20,numberToCopy);
	printVectorIterators(vector2); 	
	

	// remove the last entry
	cout<<"Removing last two entries"<<endl;
	// remove the last two entries of the vector
	// first remove -10
	vector1.pop_back();
	// then remove -1
	vector1.pop_back();
	printVectorIterators(vector1);
	
	//delete an entry at a specific position
	unsigned int positionToBeErased=1; // positions start from 0
	vector<int>:: iterator vectorIterator=vector1.begin();
	vector1.erase(vectorIterator+positionToBeErased);
	printVectorIterators(vector1);
	
	//delete entries from an interval
	unsigned int interval=3;
	vector1.erase(vectorIterator,vectorIterator+interval);  // not including the entry at "vectorIterator+interval"
	printVectorIterators(vector1);
	
	// insert an entry at a specific location
	vector<int>:: iterator vectorIteratorInsert=vector1.begin();
	int elementToInsert=1000;
	vector1.insert(vectorIteratorInsert+1,elementToInsert); // insert 1000 at the position "vectorIteratorInsert+1"
	printVectorIterators(vector1); 
	// insert copies 
	unsigned int numberOfCopies=5;
	unsigned int elementToInsert2=2000;
	vector1.insert(vectorIteratorInsert+1,numberOfCopies,elementToInsert2);
	printVectorIterators(vector1); 

	// find a specific entry
	// first approach
	
	int entryToFind=2000;
	
	vector<int>:: iterator findIterator;
	// this function returns an iterator to the first element that is equal to entryToFind
	// if there is no such element in the vector, the function returns iterator to vector1.end()
	findIterator=find(vector1.begin(),vector1.end(),entryToFind);
	if (findIterator!=vector1.end())
	{
	 	cout<<"First entry that matches the search query found at the position "<<findIterator-vector1.begin()<<endl;
	}
	else
	{
		cout<<"The entry is not found!";
	}
	
	// find a specific entry
	// second approach
	
	int entryToFind2=2000;
	vector<int>:: iterator findIterator2;
	
	for (findIterator2=vector1.begin();findIterator2!=vector1.end();findIterator2++)
	{
		if (*findIterator2==entryToFind2)
		{
			break;
		}
	}
	
	if (findIterator2!=vector1.end())
	{
	 	cout<<"First entry that matches the search query found at the position "<<findIterator2-vector1.begin()<<endl;
	}
	else
	{
		cout<<"The entry is not found!";
	}

	//erase all the vector entries
	vector1.clear();
	printVectorIterators(vector1);

	return 0;
}
