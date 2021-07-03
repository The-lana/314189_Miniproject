
#include "Inventory.h"
item  array_of_items[];
number_of_items = 0;

int main (){
    
    int option =0, check_to_continue = 1;
    do {
    printf("Would you like to Add , Remove or View contents\n");
    printf("press 1 for Add \n 2 to remove and \n 3 to search and view\n");
    scanf("%d" , &option);
    switch (option)
    {
        case 1 : Add_item();
                break;
        case 2 : Removeitem();
                break;
        case 3 : Search_item();
                break;
        default : printf("Invalid choice\n");
    }
    printf("do you want to continue\n Enter 1 to continue and 0 to exit");
    scanf("%d" , &check_to_continue);

    }while(check_to_continue == 1);
    
    //ask what to do
    

}