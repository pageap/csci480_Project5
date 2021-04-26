/*
Programmer: Adam Page
Programmer ID:
Class: csci480
Assignment#: 5
Date Due: 11/29/2020
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PhysicalMemory
{
public:
        PhysicalMemory(int memorySize, int algorithmIn); 
        //access the frame, update the time stamp and time list 							
        void access(int frameID);   
        //print out the physical memory layout
        void printMemory() const; 
        //returns the frame ID of the item just swapped in
        int swapIn(string item);  

    private:
      vector <int> timeList;
	  vector <string> memoryList;   
      //present clock for timestamp
          int presentTimeIndex;  
       
          int algorithmFlag; 
//get an avialable frame 
          int getNextAvailableFrame();  
//use bool to check if the memory isFull
          bool isFull();   
};

void PhysicalMemory::access(int frameID)
{
    //declare accessed memory
    cout << "Physical: Accessed frameID: " << frameID << " contains "
        << memoryList[frameID] << endl;
    presentTimeIndex++;
    timeList[frameID] = presentTimeIndex;

}


PhysicalMemory::PhysicalMemory (int memorySize, int algorithmIn)
{
presentTimeIndex = 0;
timeList.resize(memorySize);		
memoryList.reserve(memorySize);
algorithmFlag = algorithmIn;
}


int PhysicalMemory::getNextAvailableFrame()
{
  
 if (isFull() == false)				
	return memoryList.size();
 vector<int>::iterator it = min_element(timeList.begin(),timeList.end());
 int frameID = distance (timeList.begin(), it);

 return frameID;
}

bool PhysicalMemory::isFull()
{
    //if statement to see if memoryList is full.
 if (memoryList.capacity() > memoryList.size()) 
	return false;

return true;
}

int PhysicalMemory::swapIn(string item)
{
    //use int framID to get the next frame
 int frameID = getNextAvailableFrame();		
 //if it's not full, insert into the list
 	if (isFull() == false)
 		memoryList.push_back(item);	
 //else swap the value for the new item
 	else
		memoryList.at(frameID) = item;
    //update  time stamps 
 presentTimeIndex++;				
 timeList[frameID] = presentTimeIndex;

 cout << "Physical: Stored: " << item << endl; 

return frameID;
}

void PhysicalMemory::printMemory() const
{
	for (size_t i = 0; i < memoryList.size(); i++)
//display memory frame    
    {
		cout << "Physical: Memory Frame: " << i << " contains: " << memoryList[i] << endl;
	}
}
