// Implements a dictionary's functionality

#include "dictionary.h"

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// reference:- https://github.com/Mayconpm/CS50x_2021/tree/master/pset5/speller (Line :22-42 )

// Number of buckets in hash table
const unsigned int H= 5381;  
node *table[H]; //hashtable : //to compute an index to an array in which an element will be inserted @ searched.

unsigned int count_words = 0; //value of words in dictionary
unsigned int code_hash = 0; // Hash code from the word

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    code_hash = hash(word);
    node *cursor = table[code_hash];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// to convert hashes from word to a number
// reference : djb2 from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int k;
    while ((k = tolower(*word++)))
    {
        hash = ((hash<<5) + hash) + k;
    }
    return hash % H;
}

// Loads dictionary into memory, returning true if successful else false
//to open dictionary
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    FILE *files = fopen(dictionary, "r");
    if (files != NULL)
    { while (fscanf(files, "%s", word) != EOF)
        {
            node *n=malloc(sizeof(node));
            if (n !=NULL)
            {   code_hash = hash(word);
                strcpy(n->word,word);
                n->next = table[code_hash];
                table[code_hash] = n;
                // free(n);
               count_words++;
            }
        }
        fclose(files);
    } else
    {
        return false;
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < H; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        } if (i == H - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
