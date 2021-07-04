#ifndef inventory_h
#define inventory_h

#include<stdio.h>
#include "stdlib.h"
#include <string.h>


//int number_of_items;
FILE *fileptr;

//int n = 10;  //tried to initialise array of items in category..

  typedef struct 
    {
        /* data */
        char *item_name;
        int stock ;
    }item;
    
/*
typedef struct category
{
    
    char *category_name;
    int number_of_category;
    item *array_of_item[item::number_of_items+1] ;
   
};               
  */
 

void Add_item();
void Remove_item();
void Search_item();

#endif