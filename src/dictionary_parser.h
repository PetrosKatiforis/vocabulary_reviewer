#ifndef _DICTIONARY_PARSER_H
#define _DICTIONARY_PARSER_H

// Maximum character per "dictionary word"
// Tried something simpler since the dictionary will only consist of real words which are typically less than 20 characters long
#define MAX_DICT_CHARS 30

typedef struct dictionary_item_s
{
    // Holds a pointer to the next dictionary item
    struct dictionary_item_s* next;

    // Here's where the actual item data is stored
    char original[MAX_DICT_CHARS];
    char translation[MAX_DICT_CHARS];

} dictionary_item_t;

/*
 * Accepts a filename and parses the specified dictionary-formatted file (item1 = item2)
 * Will return a linked list structure which can be navigated by the .next property
 *
 * If the parser fails (e.g. file not found error), it will return NULL
 */
dictionary_item_t* parse(const char* filename);


typedef void (*dictionary_item_handler_t)(dictionary_item_t*);

/*
 * Traverses the dictionary with a given function
 * Each item will be passed to the handler function which will be called
 *
 * The handler needs to accept a dictionary_item_t* and return void
 */
void traverse_dictionary(dictionary_item_t* root, dictionary_item_handler_t);

#endif


