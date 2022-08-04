#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary_parser.h"
#include "colors.h"

/*
 * This program parses dictionary-formatted files 
 * with the goal of creating a terminal based vocabulary revision application
 */

void handle_item(dictionary_item_t* item)
{
    printf("What does %s mean? ", item->original);

    // Getting user input
    char answer[MAX_DICT_CHARS];

    scanf("%s", answer);

    // If the answer doesn't match, print out a red colored message
    if (strcmp(answer, item->translation) != 0)
    {
        printf("%s[Wrong]%s Correct translation: %s\n\n", RED, NORMAL, item->translation); 
    }
}

int main()
{
    dictionary_item_t* root = parse("latin.dictionary");

    // Just in case the parsing failed
    if (root == NULL)
    {
        perror("Something went wrong, couldn't parse dictionary file");

        return EXIT_FAILURE;
    }

    // Call handle_item for each dictionary entry
    traverse_dictionary(root, handle_item);
}
