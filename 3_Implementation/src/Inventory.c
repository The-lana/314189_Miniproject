/**
 * @file Inventory_main.c
 * @author Alna Satheesh
 * @brief To select options for the user to decide whether to Add , Delete or search for an item
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "inventory.h"


/**
 * @brief main function
 * Here the option to select between add remove or search for an item is given.
 * the program keeps running until a value other than 1 to check_to_continue
 * 
 * @return int 
 */
int main (){
    ///variable to store which option has been selected as 1,2 or 3.
    int option =0;
    ///variable to be kept at 1 for continuing,when a different option is given the program ends.
    int check_to_continue = 1;
    ///do while loop for reading the option entered by the user and select options and also check for contniue or not.
    do {
    printf("Would you like to Add , Remove or View contents\n");
    printf("press 1 for Add \n 2 to remove and \n 3 to search and view\n");
    scanf("%d" , &option);
    ///switch to select option
    switch (option)
    {
        case 1 : Add_item();
                break;
        case 2 : Remove_item();
               break;
        case 3 : Search_item();
              break;
        default : printf("Invalid choice\n");
    }
    printf("do you want to continue\n Enter 1 to continue and 0 to exit");
    scanf("%d" , &check_to_continue);
    
    /*
    if(check_to_continue != '1' || check_to_continue !='0') {
    printf("invalid input\n");
    printf("enter correct value\n");
    }
    */
   
    }while(check_to_continue == 1);
    
    printf("exiting\n");
    
    return 0;
}