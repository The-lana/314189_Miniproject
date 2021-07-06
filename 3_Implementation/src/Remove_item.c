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
    ///write the contents of database to a new file without the item to be removed
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
    //has an error that it doesnt move to next command automatically unless you enter any character
    getchar();
    //getchar();

    fseek(fileptr, 0, SEEK_SET);

    while(!feof(fileptr))
    {
        fscanf(fileptr, "%s",temp);
        //printf("%s " , temp);
         if(strcmp(itemToRemove.item_name , temp)!=0 ) 
        {
            //fputs(temp,fileptrtemp);
            fprintf(fileptrtemp , "%s \n" , temp);
            //printf("printing to temp file %s\n" , temp);
            //free(temp);
        }
        else {
            fscanf(fileptr , " %s" , temp);
            //printf("in else\n");
        }
    }
    fclose(fileptrtemp);
    fclose(fileptr);
    /// put the contents of the temp file back to myfile thus removing the contents
    fileptr = fopen("myfile.txt" , "w");
    if(fileptr == NULL)
    {
        printf("falied to open file \n");
    }
    else printf("open for writing to inventory\n");
    fileptrtemp = fopen("tempfile.txt" , "r");
    if(fileptrtemp == NULL)
    {
        fclose(fileptr);
        printf("failed to open file\n");
    } 
    else printf("temp file open for reading\n"); 
    char *temp2;
    temp2 = malloc(30);
    //copying contents
    fseek(fileptrtemp, 0, SEEK_SET);
      printf("fseek done\n");
       while(!feof(fileptrtemp))
       {
           //printf("in while \n");
             //temp2 =  malloc (30);
           fscanf(fileptrtemp ,"%s", temp2) ;
         fprintf(fileptr ,"%s\n" ,temp2);
        printf("%s" , temp2);
        //free(temp2);
       }

    printf("removed item successfully\n");

    fclose(fileptr);
    fclose(fileptrtemp);
    free(itemToRemove.item_name);
    free(temp);
    free(temp2);
}
