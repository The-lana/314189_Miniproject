
#include "inventory.h"

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
   
    fileptr = fopen("myfile.txt", "a");
    if(fileptr == NULL) {
        perror("Error opening file.\n");
        }
    else {
      
        char *tobewrittenl;
        tobewrittenl = malloc(50);
        snprintf(tobewrittenl ,30,"%s %d\n",itemToAdd.item_name,itemToAdd.stock);
       fputs(tobewrittenl,fileptr);
       free(tobewrittenl);
    }
    free(itemToAdd.item_name);
    fclose(fileptr);

}