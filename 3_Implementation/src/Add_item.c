/**
 * @file Add_item.c
 * @author Alna Satheesh
 * @brief To add an item to the inventory database file by taking input from user 
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "inventory.h"

int writeToFile(item*);

void Add_item(){
    //number_of_items ++;
    item itemToAdd;
    itemToAdd.item_name = malloc(20);
    printf("Add Item\n");

    printf("Enter name of item\n");
    scanf("%s" , itemToAdd.item_name);
    getchar();

    printf("\nEnter number of %s\n" , itemToAdd.item_name);
    scanf("%d", &itemToAdd.stock );
    writeToFile(&itemToAdd);
    

}

int writeToFile(item *itemToAdd){
    fileptr = fopen("myfile.txt", "a");
    if(fileptr == NULL) {
        perror("Error opening file.\n");
        return -1;
        }
    else {
      
        char *tobewrittenl;
        tobewrittenl = malloc(50);
        snprintf(tobewrittenl ,30,"%s\n%d\n",itemToAdd->item_name,itemToAdd->stock);
       fputs(tobewrittenl,fileptr);
       free(tobewrittenl);
    }
    free(itemToAdd->item_name);
    fclose(fileptr);
    return 0;

}