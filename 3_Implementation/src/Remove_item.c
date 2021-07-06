/**
 * @file Remove_item.c
 * @author Alna Satheesh
 * @brief To remove an item from the inventory database
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "inventory.h"

void Remove_item()
{
    printf("Remove item\n");
    item itemToRemove;
    itemToRemove.item_name = malloc(30);
    char * temp;
    temp = malloc(30);
    itemToRemove.stock=0;
    fileptr = fopen("myfile.txt" , "r");

    if(fileptr == NULL)
    printf("Failed to open file\n");

    fileptrtemp = fopen("tempfile.txt", "w");

       if(fileptrtemp == NULL)
    printf("Failed to open file\n");

    printf("Enter item to be removed\n");
    scanf("%s\n" , itemToRemove.item_name);
    getchar();
    getchar();
    fseek(fileptr, 0, SEEK_SET);
    while(!feof(fileptr))
    {
        fscanf(fileptr, "%s",temp);
        //printf("%s " , temp);
         if(strcmp(itemToRemove.item_name , temp)!=0 ) 
        {
            //fputs(temp,fileptrtemp);
            fprintf(fileptrtemp , "%s \n" , temp);
            printf("printing to temp file %s\n" , temp);
            free(temp);
        }
        else {
            fscanf(fileptr , " %s" , temp);
            printf("in else\n");
        }
    }
    fclose(fileptrtemp);
    fclose(fileptr);
}
