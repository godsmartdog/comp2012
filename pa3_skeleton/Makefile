OBJS = Datetime.o Flight.o Transaction.o CustomerList.o Ticket.o Customer.o main.o CustomerHashTable.o AirlineSystem.o
SUBMISSION = BSTImplementation.h CustomerHashTable.cpp CustomerList.cpp Ticket.cpp Customer.cpp AirlineSystem.cpp Flight.cpp Transaction.cpp
OBJ_DEBUG_PREFIX = leak

CPPFLAGS = -std=c++11 # -arch x86_64 -masm=intel
CPPFLAGS_DEBUG = -std=c++11 -fsanitize=address,leak,undefineds
OBJS_DEBUG = $(addprefix $(OBJ_DEBUG_PREFIX)_,$(OBJS))

ifeq (Windows_NT, $(OS))
RM_CMD := del /F
ZIP_CMD := zip.exe
else
RM_CMD := rm -vf
ZIP_CMD := zip
endif

all: pa3.exe
debug: pa3_leak.exe

pa3.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

pa3_leak.exe: $(OBJS_DEBUG)
	g++ -o $@ $(CPPFLAGS_DEBUG) $^


zinc: $(SUBMISSION)
	$(ZIP_CMD) pa3.zip $^

clean:
	$(RM_CMD) $(OBJS) pa3.exe pa3_leak.exe pa3.zip

clean_leak:
	$(RM_CMD) $(OBJS_DEBUG) pa3.exe pa3_leak.exe pa3.zip


%.o: %.cpp BSTImplementation.h
	g++ $(CPPFLAGS) -c $< -o $@

$(OBJ_DEBUG_PREFIX)_%.o: %.cpp BSTImplementation.h
	g++ $(CPPFLAGS_DEBUG) -c $< -o $@
