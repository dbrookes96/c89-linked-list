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
 * linked_list.h
 * 2015-10-9
 */

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct
{
    LinkedListNode* head;
} LinkedList;

LinkedList* createList(void);
void insertStart(LinkedList*, void*);
void insertEnd(LinkedList*, void*);
LinkedListNode* removeStart(LinkedList*);
LinkedListNode* removeEnd(LinkedList*);
LinkedListNode* peek(LinkedList*, int);
void printList(LinkedList*);
void freeList(LinkedList*);
