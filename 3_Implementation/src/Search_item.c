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

void Search_item()
{
    int count =0;
        item itemFromSearch;
        itemFromSearch.stock = 0;
        itemFromSearch.item_name = NULL;
    itemFromSearch.item_name = malloc(30);
     
    printf("\tSearch item\n");
   
    char *stringTosearch = malloc(30);      //name from input to search
    printf("Enter name of item to search\n");
    scanf("%s" , stringTosearch);
    //getchar();
    
  
    fileptr = fopen("myfile.txt" , "r");     //opening inventory file
	
    if(fileptr == NULL) {
	//	return(-1);
    printf("File not found\n");
	}
    else
    {
    
    char * stringFromFile = malloc(30);
    while(!feof(fileptr))
    {
        fscanf(fileptr,"%s", stringFromFile);
        if(strcmp(stringFromFile,stringTosearch)==0 ) 
        {
           strcpy(itemFromSearch.item_name,stringFromFile);
            fscanf(fileptr , "%s", stringFromFile) ;
           itemFromSearch.stock = atoi(stringFromFile);
           count++;
        }
       
    }
    free(stringTosearch);
    if (count == 0 )
    {
           printf("\nItem Not found \n");
    }
    else {
    printf("Item found \n");
    printf("Name : %s stock available : %d\n", itemFromSearch.item_name , itemFromSearch.stock );
    }

    free(itemFromSearch.item_name);
    //free(stringTosearch);
    free(stringFromFile);
    }
    fclose(fileptr);
}