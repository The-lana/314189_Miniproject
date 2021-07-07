/**
 * @file Search_item.c
 * @author Alna Satheesh
 * @brief To search an item and display its stock and other details which have not been added yet , for example price
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 #include "inventory.h"

/**
 * @brief 
 * 
 */
void Search_item()
{
    
        item itemFromSearch;
        itemFromSearch.stock = 0;
        itemFromSearch.item_name = NULL;
    itemFromSearch.item_name = malloc(30);
     
    printf("\tSearch item\n");
   
    char *stringTosearch = malloc(30);      //name from input to search
    printf("Enter name of item to search\n");
    scanf("%30s" , stringTosearch);
    //getchar();
    
  
    fileptr = fopen("myfile.txt" , "r");     //opening inventory file
	
    if(fileptr == NULL) {
	//	return(-1);
    printf("File not found\n");
	}
    else
    {
    
    int count =0;
    char * stringFromFile = malloc(30);
    while(!feof(fileptr))
    {
        fscanf(fileptr,"%30s", stringFromFile);
        if(strcmp(stringFromFile,stringTosearch)==0 ) 
        {
           strcpy(itemFromSearch.item_name,stringFromFile);
            fscanf(fileptr , "%30s", stringFromFile) ;
           itemFromSearch.stock = atoi(stringFromFile);
           count++;
        }
       
    }
    //free(stringTosearch);
    
    if (count == 0 )
    {
           printf("\nItem Not found \n");
    }
    else {
    printf("Item found \n");
    printf("Name : %30s stock available : %d\n", itemFromSearch.item_name , itemFromSearch.stock );
    }

    free(itemFromSearch.item_name);
    free(stringTosearch);
    free(stringFromFile);
    }
    fclose(fileptr);
}