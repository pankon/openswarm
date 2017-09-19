CPPS=$(filter-out %_test.cpp, $(wildcard *.cpp))
OBJS=$(subst .cpp,.o, $(CPPS))
TESTS_CPPS=$(filter %_test.cpp, $(wildcard *.cpp))
TESTS=$(subst .cpp,.dbg.out, $(TESTS_CPPS))

TEST_DIR= #tests

CPP=/usr/bin/g++
CPPFLAGS=-g

all: $(OBJS) $(TESTS)

clean:
	rm *.o *.dbg.out -v

$(CPPS):
	$(CPP) $(CPPFLAGS) $(@).cpp -c
	#g++ $(subst .cpp, _test.cpp, $(@)) $(OBJS) -o $(@)

$(TESTS): $(CPPS)
	$(CPP) $(CPPFLAGS) $(subst .dbg.out,.cpp, $(@)) -o $(@) $(OBJS)