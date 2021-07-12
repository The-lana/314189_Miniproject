#include "unity.h"
#include "inventory.h"

/* Modify these two lines according to the project */
#include "inventory.h"
#define PROJECT_NAME    "Inventory"
/* Prototypes for all the test functions */
void test_add(void);
void test_remove(void);
void test_search(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_search);
  RUN_TEST(test_remove);
    /* Close the Unity Test Framework */
  return UNITY_END();
}
item itemForTest;
    
/* Write all the test functions */ 

void test_add(void)
 {
    itemForTest.item_name="turtle";
    itemForTest.stock = 60;
  TEST_ASSERT_EQUAL(0, writeToFile(&itemForTest));
 }

void test_remove()
{
  itemForTest.item_name = "turtle";
  TEST_ASSERT_EQUAL(0 ,  WritetoTempfile(&itemForTest));
  TEST_ASSERT_EQUAL(0 ,  WritefromTempfile());
}


void test_search()
{
  char *stringTosearch ="turtle";
  TEST_ASSERT_EQUAL(0, Searchinfile(stringTosearch));
  TEST_ASSERT_EQUAL(0, Searchinfile("noitem"));
}
