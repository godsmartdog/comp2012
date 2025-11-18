UNAME := $(shell uname)

CXX = g++
CFLAGS = -std=c++11 -Wall
SRCS = main.cpp Song.cpp BST.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

ifeq ($(UNAME), Linux)
	CFLAGS += -fsanitize=address,leak,undefined
	RM = -rm
else
	ifeq ($(UNAME), Darwin)
		CFLAGS += -fsanitize=address,leak,undefined
		RM = -rm
	else
		RM = -del
	endif
endif

lab8: $(OBJS)
	$(CXX) -g -o $@ $^ $(CFLAGS)

# To include the .d dependency files
-include $(DEPS)

%.o: %.cpp
	$(CXX) -MMD -MP -c -o $@ $< $(CFLAGS)

clean:
	$(RM) -f *.o *.d lab8 lab8.exe