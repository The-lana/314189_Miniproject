/**
 * @file Inventory.h
 * @author Alna Satheesh
 * @brief Header file for the program to manage inventory
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef inventory_h
#define inventory_h

#include<stdio.h>
#include "stdlib.h"
#include <string.h>


//int number_of_items;
FILE *fileptr;
FILE *fileptrtemp;

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