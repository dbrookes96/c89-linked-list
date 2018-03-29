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
 * testlinkedlist.c
 * 2015-10-9
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct
{
    char date[11];
    char text[101];
} TestEntry;

int main(void)
{
    TestEntry *lnData;
    LinkedListNode* ln;

    LinkedList* l = createList();

    TestEntry e = {"9/10/2015", "This is a test message."};
    TestEntry e2 = {"10/10/2015", "This is a test message 2."};
    TestEntry e3 = {"11/10/2015", "This is a test message 3."};
    TestEntry e4 = {"12/10/2015", "This is a test message 4."};
    insertStart(l, &e);
    insertStart(l, &e2);
    insertStart(l, &e3);
    insertStart(l, &e4);

    ln = removeStart(l);
    free(ln);

    insertEnd(l, &e4);

    printList(l);

    ln = peek(l, 1);
    lnData = (TestEntry*)ln->data;
    printf("%s\n%s\n", lnData->date, lnData->text);

    ln = removeEnd(l);
    lnData = (TestEntry*)ln->data;
    printf("%s\n%s\n", lnData->date, lnData->text);

    free(ln);
    freeList(l);
    
    return 0;
}
