TARGET = mocktest
CC = g++
CFLAGS = -g -Wall -std=c++11
LIBS = -lgtest -lgmock -lpthread

DEPS = c_codeToBeTestedMock.h fake_cFunctions.h c_codeTobeTested.h
OBJ = c_codeTobeTested.o TestCwithMock.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ) TestCwithMock.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o
	rm -f $(TARGET)