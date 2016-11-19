/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
  typedef struct node{
     bool isWord;
     struct node* children[27];
 }
 node;
 node* root;
 
 
bool check(const char* word)
{
    
    node* temp=root; 
    for(int i=0;i<=strlen(word);i++)  {
        char testword = word[i];
        if(isupper(testword)){
            testword = tolower(testword);
        }
        if(temp->children[testword-96]!=NULL && i<strlen(word)){
            temp = temp->children[testword-96];
        }
        else if(temp->children[testword-96]==NULL && i<strlen(word)){
            return false;
        }
        else if(i==strlen(word)){
            if(temp->isWord==true){
            return true;
        }
        else{
            return false;
        }
        }
        
    }
        
return false;
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

 unsigned int sizeVal=0;
 void insert(char* word){
    node* temp=root; 
    for(int i=0;i<=strlen(word);i++){
        
    if(temp->children[(word[i])-96]==NULL && i<strlen(word)){
     node* temp1 = malloc(sizeof(node));
     temp1->isWord = false;
     temp->children[word[i]-96] = temp1;
     temp=temp1;
     temp1=NULL;
    }
    else{
        if(i==strlen(word)){
            temp->isWord=true;
            return;
        }
        temp=temp->children[word[i]-96];
    }
    }
    temp=NULL;
 }
bool load(const char* dictionary)
{
       FILE* inptr = fopen(dictionary, "r");
        
    if (inptr == NULL)
    {
        return false;
    }
    root = malloc(sizeof(node));
    int n=1;
    while(n > 0)
    {
     char tempWord[46];//= malloc(46*sizeof(char));
      n = fscanf(inptr, "%s", tempWord);
      if(n<0){
          break;
      }
      insert(tempWord);
       free(tempWord);
      sizeVal++;
    }
    
    fclose(inptr);
    inptr=NULL;
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return sizeVal;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 void unloadAll(node* point){
    //  int j=0;
     for(int i=0;i<27;i++){
         if(point->children[i]!=NULL){
             unloadAll(point->children[i]);
         }
     }
     
         free(point);
         point = NULL;
     
 }
bool unload(void)
{
     unloadAll(root);
    
    return true;
}
