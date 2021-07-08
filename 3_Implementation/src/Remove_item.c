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
int count =0 ;


void Remove_item()
{
    ///write the contents of database to a new file without the item to be removed
    printf("\n\tRemove item\n\n");
    item itemToRemove;
    itemToRemove.item_name = malloc(30);
    
     printf("Enter item to be removed\n");
    scanf("%30s\n" , itemToRemove.item_name); 
    //has an error that it doesnt move to next command automatically unless you enter any character
    getchar();

    WritetoTempfile(&itemToRemove);
    WritefromTempfile();

    free(itemToRemove.item_name);
}

int WritetoTempfile(item *itemToRemove)
{

    fileptr = fopen("myfile.txt" , "r");

    if(fileptr == NULL) {
    printf("Failed to open file\n");
    return (-1);
    }

    fileptrtemp = fopen("tempfile.txt", "w");

       if(fileptrtemp == NULL){
    printf("Failed to open file\n");
    return (-1);
       }

    char * temp;
    temp = malloc(30);
   
    fseek(fileptr, 0, SEEK_SET);

    while(!feof(fileptr))
    {
        fscanf(fileptr, "%30s",temp);
         if(strcmp(itemToRemove->item_name , temp)!=0 ) 
        {
            
            fprintf(fileptrtemp , "%s \n" , temp);
        }
        else {
            count ++;
            fscanf(fileptr , " %30s" , temp);

        }
    }
    fclose(fileptrtemp);
    fclose(fileptr);
    free(temp);
    }   


int WritefromTempfile() 
{
    /// put the contents of the temp file back to myfile thus removing the contents
    fileptr = fopen("myfile.txt" , "w");
    if(fileptr == NULL)
    {
        printf("falied to open file \n");
        return (-1);
    }
   
    fileptrtemp = fopen("tempfile.txt" , "r");
    if(fileptrtemp == NULL)
    {
        fclose(fileptr);
        printf("failed to open file\n");
        return (-1);
    } 
    char *temp2;
    temp2 = malloc(30);
    //copying contents
    fseek(fileptrtemp, 0, SEEK_SET);

       while(!feof(fileptrtemp))
       {
           fscanf(fileptrtemp ,"%30s", temp2) ;
         fprintf(fileptr ,"%s\n" ,temp2);
       }

    if(count==0)
    {
        printf("\nItem not found to remove\n\n");
    }
    else
    printf("\nremoved item successfully\n\n");

    fclose(fileptr);
    fclose(fileptrtemp);
    free(temp2);
    return 0;
}
