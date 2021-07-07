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
  RUN_TEST(test_remove);
  RUN_TEST(test_search);
    /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_add(void) {
    item itemForTest;
    itemForTest.item_name="turtle";
    itemForTest.stock = 60;
  TEST_ASSERT_EQUAL(0, writeToFile(&itemForTest));
  //TEST_ASSERT_EQUAL(-10, add(10, -20));
  //TEST_ASSERT_EQUAL(-30, add(-10, -20));
  //TEST_ASSERT_EQUAL(10, add(-10, 20));
}

void test_remove()
{

}

void test_search(){
  
}