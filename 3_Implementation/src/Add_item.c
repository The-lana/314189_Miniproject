
#include "Inventory.h"

void Add_item(){
    number_of_items ++;
    item itemn;
    printf("Add Item\n");
    //scan values
    //open a file to write
    printf("Enter name of item\n");
    scanf("%s" , &itemn.item_name);
    printf("Enter number of %s" , itemn.item_name);
    scanf("%d", itemn.stock );
    

}