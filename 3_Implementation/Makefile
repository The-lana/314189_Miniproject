#target : dependencies
#<tab>function

#header files
INC = -I ./inc\
-I ./unity\

#source codes
SRC = .\src\Inventory.c \
.\src\Add_item.c \
.\src\Remove_item.c \
.\src\Search_item.c 


all:$(SRC) 
	gcc -g -o out $(SRC) $(INC)


clean : 
	del .\out.exe

run : 
	.\out.exe

# All test source files
TEST_SRC = src/Inventory.c\
src/Add_item.c \
src/Remove_item.c \
src/Search_item.c \
test/Inventory_test.c\
unity/unity.c\

PROJECT_NAME = Inventory

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