#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary_parser.h"

/*
 * Reads the file and generates the linked list
 * The data is extracted using fscanf
 */
dictionary_item_t* parse(const char* filename)
{
    // Opening the dictionary file
    FILE* file = fopen(filename, "r");

    if (!file) 
        return NULL;

    // Creating a linked list structure with pointers of malloced dictionary_item_t
    dictionary_item_t* previous_item = NULL;

    while (true)
    {
        dictionary_item_t* item = malloc(sizeof(dictionary_item_t));
        item->next = previous_item;

        // Collecting data from file and assigning to so that they can be processed later
        int result = fscanf(file, "%s = %s", item->original, item->translation);

        // Checking if it has reached the end of the file
        if (result == EOF) break;

        previous_item = item;
    }

    fclose(file);

    return previous_item;
}

/*
 * Uses a while loop to traverse the linked list and pass each item into a handler call
 */
void traverse_dictionary(dictionary_item_t* root, dictionary_item_handler_t handler)
{
    for (dictionary_item_t* current_item = root; current_item != NULL; current_item = current_item->next)
    {
        handler(current_item);
    }
}


