CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = TestingMain

OBJS = TestingMain.o User.o Subject.o ChatRoom.o CtrlCat.o Dogorithm.o SendMessageCommand.o SaveMessageCommand.o UserIterator.o MessageObserver.o Name1.o Name2.o Name3.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

TestingMain.o: TestingMain.cpp
	$(CXX) $(CXXFLAGS) -c TestingMain.cpp -o TestingMain.o

User.o: User.cpp
	$(CXX) $(CXXFLAGS) -c User.cpp -o User.o

Subject.o: Subject.cpp
	$(CXX) $(CXXFLAGS) -c Subject.cpp -o Subject.o

ChatRoom.o: ChatRoom.cpp
	$(CXX) $(CXXFLAGS) -c ChatRoom.cpp -o ChatRoom.o

CtrlCat.o: CtrlCat.cpp
	$(CXX) $(CXXFLAGS) -c CtrlCat.cpp -o CtrlCat.o

Dogorithm.o: Dogorithm.cpp
	$(CXX) $(CXXFLAGS) -c Dogorithm.cpp -o Dogorithm.o

SendMessageCommand.o: SendMessageCommand.cpp
	$(CXX) $(CXXFLAGS) -c SendMessageCommand.cpp -o SendMessageCommand.o

SaveMessageCommand.o: SaveMessageCommand.cpp
	$(CXX) $(CXXFLAGS) -c SaveMessageCommand.cpp -o SaveMessageCommand.o

UserIterator.o: UserIterator.cpp
	$(CXX) $(CXXFLAGS) -c UserIterator.cpp -o UserIterator.o

MessageObserver.o: MessageObserver.cpp
	$(CXX) $(CXXFLAGS) -c MessageObserver.cpp -o MessageObserver.o

Name1.o: Name1.cpp
	$(CXX) $(CXXFLAGS) -c Name1.cpp -o Name1.o

Name2.o: Name2.cpp
	$(CXX) $(CXXFLAGS) -c Name2.cpp -o Name2.o

Name3.o: Name3.cpp
	$(CXX) $(CXXFLAGS) -c Name3.cpp -o Name3.o

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

coverage: $(TARGET)
	$(CXX) $(CXXFLAGS) --coverage -o coverage $(filter %.cpp, $(wildcard *.cpp))
	./coverage
	gcov $(filter %.cpp, $(wildcard *.cpp))
	@rm -f *.gcda *.gcno

clean:
	rm -f $(OBJS) $(TARGET) coverage *.gcov