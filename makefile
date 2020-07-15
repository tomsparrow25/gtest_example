TARGET = unittest
CC = g++
CFLAGS = -g -Wall -std=c++11
LIBS = -lgtest -lgmock

DEPS = Factorial.h
OBJ = tMain.o Factorial_Test.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ) tMain.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o
	rm -f $(TARGET)