# csci480 Virtual Memory Simulation!
Write a program in C or C++ which simulates a paging-based virtual memory system.

Specification:
As we know, the virtual memory mechanism called demand paging divides the virtual memory into evenly sized pages and the real physical memory into frames of the same size.  The page table does the address mapping, which contains one entry for each virtual address page.  Each entry has at least two fields: a Boolean flag indicating whether there is physical memory present for that virtual page, and the  frame id of physical memory for the virtual page if the frame is present. The number of entries in the page table is equal to the number of virtual pages in the address range of the system.
In this assignment, you assume the page size (frame size) is 1K and the system has 9K virtual memory. You can hardcode the page size and virtual memory size. By default, you can also assume that the system has 4K physical memory, but this should be a variable and your assignment will be written generically for different physical memory sizes (it will be an argument from the command line as explained later).
Assume a program (that does some tax calculation) consisting of a driver block of code (main()), 5 functions, and 3 blocks of memory containing arrays of numbers. Each of these units will be assigned to a specific virtual page.  Each function or an array is 1K (1 page in size).  Their starting virtual addresses are provided as below:
Table 1:  The virtual memory layout for the program.
Data	Starting Virtual addresses/Virtual page number
net[]	7k/7
activity[]	6k/6
holding[]	5k/5
print()	4k/4
update()	3k/3
tax()	2k/2
load()	1k/1
Main()	0k/0

The program is about loading some data for tax calculation.  The flow goes like this:
m; l; h;  m; a; n; m; u; h; n; a; m; t; n; m; p; n;
where m is for main(), l is for load() etc.   Since we assume each unit is one page, the above is essentially the page reference string.
This program will be loaded and run by your assignment in your simulated virtual memory.  
Detailed assignment specification:  
•	The driver program executes the flow.  --- It is provided with the assignment but you can change it if you would like. You need to at least modify it so that it takes in a command line argument for number of frames.  The default argument is 4.
•	The algorithm will be pure demand paging, which means the physical memory was initially empty and the frames fill from 0 up as the program executes.  
•	For each page reference, the program will try to access the page based on the page table. Depending on if it is already in the memory, you would need to decide if there is a page fault.
•	When the physical memory is full, you need to implement a page replacement algorithm.  You will code the First in First Out (FIFO) algorithm.   You need to swap in the page to replace one that is not currently used by the above algorithms. You do not need to consider swapping out first in this assignment. Note that after page replacement, you need to update the page table correspondingly by making the original mapping for the frame invalid, and making the new mapping valid.
•	You will print out some information in the console when there is a page fault.  At the end, you print out the layout of page table and the physical memory, as well as the total number of page faults (See example output).
•	Change the physical memory size from 4K to 5K by changing the command line argument from 4 to 5. Run the program again.

Bonus 
Implement the Least Recently Used (LRU) for page replacement.   Print out the same required info as above (memory layout for 4K physical memory and 5K physical memory).  

Output (FIFO with 4 frames):  
Welcome!
FIFO with 4 physical frames
PageTable: page fault occurred
Physical: Stored: main
PageTable: page fault occurred
Physical: Stored: load
PageTable: page fault occurred
Physical: Stored: holding
Physical: Accessed frameID: 0 contains: main
PageTable: page fault occurred
Physical: Stored: activity
PageTable: page fault occurred
Physical: Stored: net
PageTable: page fault occurred
Physical: Stored: main
PageTable: page fault occurred
Physical: Stored: update
PageTable: page fault occurred
Physical: Stored: holding
Physical: Accessed frameID: 0 contains: net
PageTable: page fault occurred
Physical: Stored: activity
Physical: Accessed frameID: 1 contains: main
PageTable: page fault occurred
Physical: Stored: tax
PageTable: page fault occurred
Physical: Stored: net
PageTable: page fault occurred
Physical: Stored: main
PageTable: page fault occurred
Physical: Stored: print
Physical: Accessed frameID: 2 contains: net
Main: now print

Physical: Memory Frame: 0 contains: print
Physical: Memory Frame: 1 contains: tax
Physical: Memory Frame: 2 contains: net
Physical: Memory Frame: 3 contains: main
PageTable: Index: 0 : Physical Index: 3 : In Use: true
PageTable: Index: 1 : Physical Index: -1 : In Use: false
PageTable: Index: 2 : Physical Index: 1 : In Use: true
PageTable: Index: 3 : Physical Index: -1 : In Use: false
PageTable: Index: 4 : Physical Index: 0 : In Use: true
PageTable: Index: 5 : Physical Index: -1 : In Use: false
PageTable: Index: 6 : Physical Index: -1 : In Use: false
PageTable: Index: 7 : Physical Index: 2 : In Use: true
PageTable: Current number of page faults: 13


This program needs all of the files to run correctly 

## this is is used for refference only. thank you 
