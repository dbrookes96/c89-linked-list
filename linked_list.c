/*
 *  Copyright (c) 2015 Daniel Brookes
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Daniel Brookes
 * linked_list.c
 * 2015-10-9 
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Allocate a new linked list into memory and return it.
 */
LinkedList* createList(void)
{
    return (LinkedList*)calloc(1, sizeof(LinkedList));
}

/* Insert an address into the start of the linked list.
 */
void insertStart(LinkedList* list, void* in)
{
    /* Create a new linked list node and set the node's data.
     */
    LinkedListNode* new = (LinkedListNode*)calloc(1, sizeof(LinkedListNode));
    new->data = in;

    /* If the head of this list is not set, set this as the head.
     * Otherwise set the existing head node as the next node for this new node and 
     *  set the new node as the head of the list.
     */
    if(list->head == NULL)
        list->head = new;
    else
    {
        new->next = list->head;
        list->head = new;
    }
}

/* Insert an address to the end of the linked list.
 */
void insertEnd(LinkedList* list, void* in)
{
    LinkedListNode* current;

    /* Create a new linked list node and set the node's data.
     */
    LinkedListNode* new = (LinkedListNode*)calloc(1, sizeof(LinkedListNode));
    new->data = in;

    /* If the head of this list is not set, set this as the head.
     * Otherwise traverse the linked list to find the tail node (this linked
     *  list is not double linked). Once the tail node is found, set its
     *  next node to the new node.
     */
    if(list->head == NULL)
        list->head = new;
    else
    {
        current = list->head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
    }
}

/* Take the element off the front of the list.
 */
LinkedListNode* removeStart(LinkedList* list)
{
    LinkedListNode* out;

    /* If the head is NULL (list is empty), return NULL.
     * Otherwise return the head of the list and set the head of the list
     *  to the returned head's next value.
     */
    if(list->head == NULL)
        out = NULL;
    else
    {
        out = list->head;
        list->head = out->next;
    }
    return out;
}

/* Take the element off the end of the list.
 */
LinkedListNode* removeEnd(LinkedList* list)
{
    LinkedListNode* out;
    LinkedListNode* current;
    LinkedListNode* previous;
    
    /* If the head is NULL (list is empty), return NULL.
     * Otherwise, traverse the list to the last node. Once found,
     *  set out to this node and set the previous node's next to NULL.
     */
    if(list->head == NULL)
        out = NULL;
    else
    {
        previous = NULL;
        current = list->head;
        while(current->next != NULL)
        {
            previous = current;
            current = current->next;
        }

        if(previous == NULL)
        {
            /* If previous wasn't set, the out node would be equal to the list head.
             * Therefore we set the list head to NULL as it is to be removed.
             */
            list->head = NULL;
        }
        else
            previous->next = NULL;
        
        out = current;
    }

    return out;
}

/* Peek at a node at the i'th position in the list.
 */
LinkedListNode* peek(LinkedList* list, int position)
{
    int i;
    LinkedListNode* out;

    /* Return NULL when the list is empty or the requested index is less than 0.
     * Otherwise traverse the list to the position specified.
     */
    if(list->head == NULL || position < 0)
        out = NULL;
    else
    {
        out = list->head;
        for(i = 0; i < position; i++)
        {
            out = out->next;

            /* Stop traversing when the list runs out of elements.
             * The function will return NULL.
             */
            if(out == NULL)
                break;
        }
    }
    return out;
}

/* Print out the linked list.
 */
void printList(LinkedList* list)
{
    LinkedListNode* current;

    printf("---\nHead: %p\n---\n", (void*)list->head);

    current = list->head;
    while(current != NULL)
    {
        printf("|\n-----\n%p\nData: %p\nNext: %p\n-----\n", (void*)current, current->data, (void*)current->next);
        current = current->next;
    }
}

/* Free the list and nodes in the list.
 */
void freeList(LinkedList* list)
{
    LinkedListNode* current;
    LinkedListNode* next;

    current = list->head;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
