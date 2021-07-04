#include "inventory.h"

void Search_item()
{
        item itemFromSearch;
        itemFromSearch.stock = 0;
    itemFromSearch.item_name = malloc(30);
    printf("Search item\n");
   
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
        //fscanf(fileptr,"%s%*[^\n]",stringFromFile);
          // printf("%s \n" , stringFromFile);
        if(strcmp(stringFromFile,stringTosearch)==0 ) 
        {
           strcpy(itemFromSearch.item_name,stringFromFile);
            fscanf(fileptr , "%s", stringFromFile) ;
           itemFromSearch.stock = atoi(stringFromFile);
        }
       
    }
    if (itemFromSearch.item_name == NULL )
    {
           printf("\nItem Not found \n");
    }
    else
    printf("Name %s %d\n", itemFromSearch.item_name , itemFromSearch.stock );
    
    free(itemFromSearch.item_name);
    free(stringTosearch);
    free(stringFromFile);
    }
    fclose(fileptr);
}