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

/**
 * @brief is called from main on selesction od add item to database.
 * Here the item to be added is received into a struct and then is written into the file using writeToFile function
 * 
 */
void Add_item(){
    ///adding details of item to be added to struct itemToAdd
    item itemToAdd;
    itemToAdd.item_name = malloc(20);
    printf("Add Item\n");

    printf("Enter name of item\n");
    scanf("%30s" , itemToAdd.item_name);
    getchar();

    printf("\nEnter number of %30s\n" , itemToAdd.item_name);
    scanf("%d", &itemToAdd.stock );

    writeToFile(&itemToAdd);
    

}

/**
 * @brief function to write the new item received into the file "myfile" which is used as database.
 * 
 * @param itemToAdd It passes a struct 'item' that has the details about the item to be added to database
 * @return int It is used here to detect errors in filehandling. It returns -1 when file does not open.
 */
int writeToFile(item *itemToAdd){
    fileptr = fopen("myfile.txt", "a");
    if(fileptr == NULL) {
        perror("Error opening file.\n");
        return -1;
        }
    else {
        ///store the data from struct 'item' into a string which is then written into the database
        char *tobewrittenl;
        tobewrittenl = malloc(50);
        snprintf(tobewrittenl ,30,"%50s\n%d\n",itemToAdd->item_name,itemToAdd->stock);
       fputs(tobewrittenl,fileptr);
       free(tobewrittenl);
    }
    free(itemToAdd->item_name);
    fclose(fileptr);
    return 0;

}