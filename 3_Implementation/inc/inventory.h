/**
 * @file inventory.h
 * @author Alna Satheesh
 * @brief Header file for the program to manage inventory
 * @version 0.1
 * @date 2021-07-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __inventory_h__
#define __inventory_h__

#include<stdio.h>
#include "stdlib.h"
#include <string.h>


///filepointer used by different files to write data into database file
FILE *fileptr;
///fileointer used to delete item from the database by copying into anither file
FILE *fileptrtemp;

//a struct to store the name and details of the items stored in the database, only stock has been added for now
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
int writeToFile(item*);
void Remove_item();
int WritetoTempfile(item *);
int WritefromTempfile();
void Search_item();
int Searchinfile(char *);

#endif