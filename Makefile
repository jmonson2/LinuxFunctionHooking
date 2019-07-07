CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g 
LDFLAGS =  -ldl 

SRC = src/test.cpp
OBJ = $(SRC:.cc=.o)
EXEC = bin/main

SOSRC = src/dl.cpp
SOOBJ = $(SRC.cc=.o)
SOEXEC = bin/liboffense.so
SOCXXFLAGS = -fPIC -shared
HIJACKSRC = hacks/hijack.cpp
HIJACKEXEC = bin/hijack.so



all: $(EXEC) $(SOEXEC) $(HIJACKEXEC)
$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

$(SOEXEC): $(SOOBJ)
	$(CXX) $(SOCXXFLAGS) -o $@ $(SOSRC) $(SOOBJ)
$(HIJACKEXEC): $(SOOBJ)
	$(CXX) $(SOCXXFLAGS) -o $@ $(HIJACKSRC) $(SOOBJ)

clean:
	rm -rf $(EXEC) $(SOEXEC) $(HIJACKEXEC) $(DLLEXEC)