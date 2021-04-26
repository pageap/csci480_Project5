#Programmer: Adam Page
#zID: z1859276
# Compiler variables
CCFLAGS = -pthread

# Rule to link object code files to create executable file
all:
	g++ -g -o FIFO_4 FIFO_4.cpp
	g++ -g -o FIFO_5 FIFO_5.cpp
# Pseudo-target to remove object code and executable files
clean:
	-rm -f FIFO_4
	-rm -f FIFO_5
