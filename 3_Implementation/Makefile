#target : dependencies
#<tab>function

ifeq ($(OS), Windows_NT)
	EXECUTABLE = exe
	RM = del
else
	EXECUTABLE=out
	RM = rm -rf
endif


#$(EXECUTABLE): prog.c
#	gcc prog.c

$(EXECUTABLE) : out.exe

#header files
INC = -I ./inc\
-I ./unity\

#source codes
SRC = .\src\Inventory.c \
.\src\Add_item.c \
.\src\Remove_item.c \
.\src\Search_item.c 


all:$(SRC) 
	gcc -o $(PROJECT_OUTPUT) $(SRC) $(INC)


clear : 
	$(RM) $(BUILD)

run : $(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

# All test source files
TEST_SRC = src/Add_item.c \
src/Remove_item.c \
src/Search_item.c \
test/Inventory_test.c\
unity/unity.c\

PROJECT_NAME = Inventory
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).$(EXECUTABLE)

TEST_OUTPUT = $(BUILD)/$(PROJECT_NAME)_test.out

# Output directory
BUILD = build

test : $(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

coverageCheck:$(BUILD)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
	gcov -a $(TEST_SRC) 

$(BUILD):
	mkdir build

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD)

#Document files
DOCUMENTATION_OUTPUT = documentation/html
#document the code using doxygen
doc : 
	make -C ./documentation
# $(DOCUMENTATION_OUTPUT)