#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"

void addListElem(listElement *start)
{

    listElement *new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL)
    {
        printf("can't reserve storage.\n");
        return;
    }

    listElement *currElem = start;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = new;          // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &(new->age));
}

void printList(listElement *start)
{

    if (start->nextElem == NULL)
        printf("List is empty.\n");
    else
    {
        int i = 0;
        listElement *currElem = start;
        printf("\ncurrent list:\n\n");
        do
        {
            currElem = currElem->nextElem;
            printf("%d", i);
            i++;
            printf("\t last name: %s\n", currElem->lastName);
            printf("\t first name: %s\n", currElem->firstName);
            printf("\t age: %d\n", currElem->age);
        } while (currElem->nextElem != NULL);
    }
}

void delListElem(listElement *start)
{
    if (start->nextElem == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printList(start);

    int selected;
    printf("What element do you want to delete? [index] ");
    scanf("%d", &selected);
    // printf("%d", selected);

    if (selected > getLenOfList(start))
    {
        printf("Your index is not in the list.");
        return;
    }

    listElement *prevElement = start,
                *thisElement = start->nextElem;

    for (int i = 0; i < selected; i++)
    {
        prevElement = thisElement;
        thisElement = thisElement->nextElem;
    }

    prevElement->nextElem = thisElement->nextElem;
    free(thisElement);
    printf("The element has been deleted :D");
}

void delList(listElement *start)
{
    listElement *currElem, *prevElem;
    currElem = start->nextElem;
    while (currElem != NULL)
    {
        prevElem = currElem;
        currElem = currElem->nextElem;
        free(prevElem);
    }
    start->nextElem = NULL;
    printf(">> the list has been deleted.");
}

int getLenOfList(listElement *start)
{
    // we use this for save list fcn
    int counter = 0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL)
    { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(listElement *start)
{
    FILE *fileptr;
    char filename[] = "liste.txt";

    fileptr = fopen(filename, "w");

    listElement *thisElement = start->nextElem;
    int index = 0;
    while (thisElement != NULL)
    {
        fprintf(fileptr, "\n%d\n%s\n%s\n%d\n",
                index++,
                thisElement->lastName,
                thisElement->firstName,
                thisElement->age);
        thisElement = thisElement->nextElem;
    }
    fclose(fileptr);
    printf("\n>> your list has been saved.\n\n");
}

void loadList(listElement *start)
{
    // read file in array
    int linelength = 50;
    char lines[1000][linelength];
    int linectr = 0; // real amount of lines
    char *filename = "liste.txt";

    FILE *fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(lines[linectr], linelength, fileptr) != NULL)
    {
        lines[linectr][strlen(lines[linectr]) - 1] = '\0';
        linectr++;
    }
    printf("%d", linectr);

    fclose(fileptr);

    /*for (int i = 0; i < linectr; i++) {
        printf("Line %d: %s\n", i + 1, lines[i]);
    }*/

    listElement *currElem = start;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list

    for (int i = 0; i < linectr; i++)
    {
        if (strcmp(lines[i], " ")) // start of list element
        {
            listElement *new;
            strcpy(new->lastName, lines[i + 1]);
            strcpy(new->firstName, lines[i + 2]);
            new->age = atoi(lines[i + 3]);
            new->nextElem = NULL;

            currElem->nextElem = new;
            currElem = currElem->nextElem;
        }
    }
    printf("\nThe list from %s has been added to your current list\n", filename);
}

void exitFcn(listElement *start)
{
    int save;
    printf("Do you want to save your list? [no: 0 (default)][yes: 1]");
    scanf("%d", &save);
    if (save == 1)
        saveList(start);
    printf("\n>> exit.\n\n");
}

void sortList(listElement *start)
{
    printf("\n>>sortList fcn is tbd.\n\n");
}