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


int count =0 ;  ///< count to check if item was found or not

/**
 * @brief Function to read the name of the item to be removed.
 * And call functions to remove the item specified by the user
 * 
 */
void Remove_item()
{
    
    printf("\n\tRemove item\n\n");
    
    item itemToRemove;  ///< structure item to store the name of the item to be removed
    itemToRemove.item_name = malloc(30);
    
     printf("Enter item to be removed\n");
    scanf("%30s" , itemToRemove.item_name); 
    getchar();

    
    WritetoTempfile(&itemToRemove);
    WritefromTempfile();

    free(itemToRemove.item_name);
}

/**
 * @brief Write the contents of database to a temp file without excluding the item to be removed
 * 
 * @param itemToRemove Contains the name or details of the item to be removed
 * @return int Return to notify when error occurs 0 for error free and -1 for errors
 */
int WritetoTempfile(item *itemToRemove)
{
    FILE *fileptr1 ;     ///< pointer to databse file
    FILE *fileptrtemp1; ///< pointer to temporary file for removing purpose
    fileptr1 = fopen("myfile.txt" , "r");

    if(fileptr1 == NULL) {
    printf("Failed to open file\n");
    return (-1);
    }
    
    fileptrtemp1 = fopen("tempfile.txt", "w"); ///< pointer to temporary file 

       if(fileptrtemp1 == NULL){
    printf("Failed to open file\n");
    return (-1);
       }
    
    char * temp;
    temp = malloc(30);
   
    fseek(fileptr1, 0, SEEK_SET);

    while(!feof(fileptr1))
    {
        fscanf(fileptr1, "%30s",temp);
         if(strcmp(itemToRemove->item_name , temp)!=0 ) 
        {
            
            fprintf(fileptrtemp1 , "%s \n" , temp);
        }
        else {
            count ++;
            fscanf(fileptr1 , " %30s" , temp);

        }
    }
    fclose(fileptrtemp1);
    fclose(fileptr1);
    free(temp);
    return 0;
    }   

/**
 * @brief function to copy the contents of the temporary file back to the databse file.
 * The temporary file contains the data after deletion of the item
 * 
 * @return int Return to notify when error occurs 0 for error free and -1 for errors
 */
int WritefromTempfile() 
{
   
    fileptr = fopen("myfile.txt" , "w");     ///< pointer to databse file
    if(fileptr == NULL)
    {
        printf("falied to open file \n");
        return (-1);
    }
    
    
    fileptrtemp = fopen("tempfile.txt" , "r");  ///< pointer to temporary file 
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
    //check for count thus identifying whether the item to be removed was found in the database
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
