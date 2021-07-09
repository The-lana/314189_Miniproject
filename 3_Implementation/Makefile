#target : dependencies
#<tab>function

ifeq ($(OS), Windows_NT)
	EXECUTABLE = exe
	RM = del
else
	EXECUTABLE=out
	RM = rm -rf
endif

# Output directory
BUILD = build

#$(EXECUTABLE) : out.exe

#header files
INC = -I ./inc\
-I ./unity \

#source codes
SRC = ./src/Inventory.c \
./src/Add_item.c \
./src/Remove_item.c \
./src/Search_item.c 


all : $(SRC) $(BUILD)
	gcc -o $(PROJECT_OUTPUT) $(SRC) $(INC)

# Remove all the built files, invoke by `make clean`
clean : 
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

TEST_OUTPUT = $(BUILD)/$(PROJECT_NAME)_test.$(EXECUTABLE)


test : $(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

coverageCheck:$(BUILD)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
	gcov -a $(TEST_SRC) 

$(BUILD):
	mkdir build


#Document files
DOCUMENTATION_OUTPUT = documentation/html
#document the code using doxygen
doc : 
	make -C ./documentation
# $(DOCUMENTATION_OUTPUT)