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
 * @brief Function to read the item to be searched and then value is passed to a function that opens the file and serches in it
 * 
 */
void Search_item()
{
        
    
    printf("\n\tSearch item\n\n");
   
    char *stringTosearch = malloc(30);      //name from input to search
    printf("Enter name of item to search\n");
    scanf("%30s" , stringTosearch);
    //getchar();

    Searchinfile( stringTosearch);

    
    free(stringTosearch);
}

/**
 * @brief function to search if item in stringToSearch is found in file/database
 * 
 * @param stringTosearch string pointer that contains the name of the item to be searched
 * @return int to detect errors .the function returns 0 for normal working and -1 when error is encountered
 */
int Searchinfile(char *stringTosearch)
{
    ///A struct variable itemForSearch to receive and store data from the file about stringToSearch
   item itemFromSearch;
        itemFromSearch.item_name = NULL;
    itemFromSearch.item_name = malloc(30);
    ///pointer to database file
    fileptr = fopen("myfile.txt" , "r");     
	
    if(fileptr == NULL) {
	free(itemFromSearch.item_name);
    printf("File not found\n");
    return (-1);
	}
    else
    {
    ///variable to identify if the search string was encountered in the inventory string
    int count =0;
    ///string to recieve data from the file to be compared with the string to search
    char * stringFromFile = malloc(30);
    while(!feof(fileptr))
    {
        fscanf(fileptr,"%30s", stringFromFile);
        if(strcmp(stringFromFile , stringTosearch)==0 ) 
        {
           strcpy(itemFromSearch.item_name , stringFromFile);
            fscanf(fileptr , "%30s", stringFromFile) ;
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
    printf("Item found \n\n");
    printf("Name : %s \nstock available : %d\n", itemFromSearch.item_name , itemFromSearch.stock );
    }

    
    free(stringFromFile);
    free(itemFromSearch.item_name);
    }
    fclose(fileptr);
    return 0;
}
