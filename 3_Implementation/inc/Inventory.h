#ifndef inventory.h
#define inventory.h

#include<stdio.h>

int number_of_items;

//int n = 10;  //tried to initialise array of items in category..

  typedef struct 
    {
        /* data */
        char *item_name;
        int stock;
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