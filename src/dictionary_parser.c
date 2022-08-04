#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary_parser.h"

/*
 * Reads the file and generates the linked list one level at a time
 * The data is extracted using an fscanf format
 */
dictionary_item_t* parse(const char* filename)
{
    // Opening the dictionary file
    FILE* file = fopen(filename, "r");

    if (file == NULL) 
        return NULL;

    // Holding a reference to the previously parsed item
    dictionary_item_t* previous_item = NULL;

    // Reading each line one by one until there's no more input
    while (true)
    {
        dictionary_item_t* item = malloc(sizeof(dictionary_item_t));
        item->next = previous_item;

        // Collecting data from file and assigning to struct
        int result = fscanf(file, "%s = %s", item->original, item->translation);

        // Checking if it has reached the end of the file
        if (result == EOF)
            break;

        previous_item = item;
    }

    // Closing up the file
    fclose(file);

    return previous_item;
}

/*
 * Uses a while loop to traverse the linked list and pass each item into a handler call
 */
void traverse_dictionary(dictionary_item_t* root, dictionary_item_handler_t handler)
{
    // Temporary and auxiliary pointer
    dictionary_item_t* current_item = root;
    
    while (current_item != NULL)
    {
        // Calling handler function
        handler(current_item);

        current_item = current_item->next;
    }
}


