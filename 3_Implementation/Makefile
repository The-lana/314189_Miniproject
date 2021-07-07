#target : dependencies
#<tab>function

ifeq ($(OS), Windows_NT)
	EXECUTABLE=a.exe
else
	EXECUTABLE=a.out
endif


$(EXECUTABLE): prog.c
	gcc prog.c

#header files
INC = -I ./inc\
-I ./unity\

#source codes
SRC = .\src\Inventory.c \
.\src\Add_item.c \
.\src\Remove_item.c \
.\src\Search_item.c 


all:$(SRC) 
	gcc -g -o $(PROJECT_OUTPUT) $(SRC) $(INC)


clear : 
	del ./$(EXECUTABLE)

run : $(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

# All test source files
TEST_SRC = src/Inventory.c\
src/Add_item.c \
src/Remove_item.c \
src/Search_item.c \
test/Inventory_test.c\
unity/unity.c\

PROJECT_NAME = Inventory
POOJECT_OUTPUT = $(BUILD)/$(EXECUTABLE)

TEST_OUTPUT = $(BUILD)/$(PROJECT_NAME)_test.out

# Output directory
BUILD = build

test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) 
	./$(TEST_OUTPUT)

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