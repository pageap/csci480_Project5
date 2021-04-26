/*
Programmer: Adam Page
Programmer ID:z1859276
Class: csci480
Assignment#: 5
Date Due: 11/29/2020
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class PageTable
{
    public:
        PageTable(PhysicalMemory* PhysMemIn, int tableSize); 
        void reference(int ID_Page, string item); 
		//use getFaults to return # of faults
        int getFaults() const;  
        void printTable() const;
        void reset();
 
    private:
	
	  int numFaults;
	  PhysicalMemory* mainPhysicalMemory;
          void pageFault(int ID_Page, string item);  
	  void updateReplacedEntry(int replacedIndex, int ID_Page); 
	  
	  vector<entryPage> entryList;
								 
};

PageTable::PageTable(PhysicalMemory* PhysMemIn, int tableSize)
{
	//allocate page table size
entryList.resize(tableSize);					
//initialize everything to false
	for (size_t i = 0; i < entryList.size(); i++)
	{ 		
		entryList[i].valid = false;
		entryList[i].physicalMemoryIndex = -1;
	}
numFaults = 0;							
mainPhysicalMemory = PhysMemIn;
}

void PageTable::reference (int ID_Page, string item)
{
			if (entryList[ID_Page].valid == true)		
			mainPhysicalMemory->access(entryList[ID_Page].physicalMemoryIndex);
		else
			pageFault(ID_Page, item);
}

int PageTable::getFaults() const
{
return numFaults;
}

void PageTable::pageFault(int ID_Page, string item)
{
	//increment ++ then record 
numFaults++; 		
//display 
cout << "PageTable: page fault occured" << endl;
int frameID = mainPhysicalMemory->swapIn(item); 			
	for (size_t i = 0; i < entryList.size(); i++)
	{
		//delete traces of old page entry
		if (entryList[i].physicalMemoryIndex == frameID)
		{	
			entryList[i].physicalMemoryIndex = -1;
			entryList[i].valid = false;
			break;
		}
	}
	//set the index of the new page entry and set it to valid
entryList[ID_Page].physicalMemoryIndex = frameID;			
entryList[ID_Page].valid = true;
}

void PageTable::printTable() const
{
	for (size_t i = 0; i < entryList.size(); i++)
		cout << "PageTable: Index: " << i << " Physical Index: " << entryList[i].physicalMemoryIndex
			  << " In Use: " << boolalpha << entryList[i].valid << endl;

	cout << "PageTable: Current   number of page faults: " << getFaults() << endl;

}

void PageTable::reset()
{

 numFaults = 0;							

	for (size_t i = 0; i < entryList.size(); i++){
                entryList[i].valid = false;
                entryList[i].physicalMemoryIndex = -1;
        }

}
