CXX      = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Wextra -Iinclude -MMD -MP
SRC      = $(wildcard src/*.cpp)
OBJ      = $(patsubst src/%.cpp,obj/%.o,$(SRC))
BIN      = bin/tp1.out

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o obj/*.d bin/tp1.out

-include $(OBJ:.o=.d)
