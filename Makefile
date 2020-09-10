EXENAME = periodic_table
OBJS = PeriodicTable.o ElectronConfig.o GroupNum.o State.o ClassType.o Block.o Element.o GroupName.o ElementsOutput.o ElementsInput.o

CXX = g++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -lcurl

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(EXENAME)

Block.o : Block.cpp Block.h
	$(CXX) $(CXXFLAGS) Block.cpp

ClassType.o : ClassType.cpp ClassType.h
	$(CXX) $(CXXFLAGS) ClassType.cpp

ElectronConfig.o : ElectronConfig.cpp ElectronConfig.h
	$(CXX) $(CXXFLAGS) ElectronConfig.cpp

Element.o : Element.cpp Element.h GroupNum.h GroupName.h Block.h ElectronConfig.h
	$(CXX) $(CXXFLAGS) Element.cpp

ElementsOutput.o : ElementsOutput.cpp ElementsOutput.h Element.h ElementsInput.h
	$(CXX) $(CXXFLAGS) ElementsOutput.cpp

ElementsInput.o : ElementsInput.cpp ElementsInput.h Element.h
	$(CXX) $(CXXFLAGS) ElementsInput.cpp

GroupName.o : GroupName.cpp GroupName.h GroupNum.h
	$(CXX) $(CXXFLAGS) GroupName.cpp

GroupNum.o : GroupNum.cpp GroupNum.h
	$(CXX) $(CXXFLAGS) GroupNum.cpp

PeriodicTable.o : PeriodicTable.cpp State.h ClassType.h ElementsOutput.h ElementsInput.h Element.h
	$(CXX) $(CXXFLAGS) PeriodicTable.cpp

State.o : State.cpp State.h
	$(CXX) $(CXXFLAGS) State.cpp

clean :
	-rm -f *.o $(EXENAME) test