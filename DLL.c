#include <stdlib.h>
#include "DLL.h"


struct dllobject
{
    dllobject *prev;
    dllobject *next;
    int content;
};

struct dlinkedlist
{
    dllobject *start;
    dllobject *end;
    int length;
};

dlinkedlist* dllCreate() {
    dlinkedlist *llist = (dlinkedlist*) malloc(sizeof(dlinkedlist));
    (*llist).start = (dllobject*) malloc(sizeof(dllobject));
    (*llist).end = (*llist).start;
    (*llist).length = 1;
    (*(*llist).start).content = 0;
    (*(*llist).start).prev = 0;
    (*(*llist).start).next = 0;
    return llist;
}

dlinkedlist* dllCreateSlice(dlinkedlist *list, int start, int end) {
    dlinkedlist *llist = (dlinkedlist*) malloc(sizeof(dlinkedlist));
    (*llist).start = (*list).start;
    for (int i = 0; i < start; i++)
    {
        (*llist).start = (*(*llist).start).next;
    }
    (*llist).end = (*llist).start;
    for (int i = 0; i < end; i++)
    {
        (*llist).end = (*(*llist).end).next;
    }
    (*llist).length = end - start + 1;
    return llist;
}

dllobject* dllGetAddr(dlinkedlist *list, int index) {
    if (index + 1 > (*list).length) return NULL;
    dllobject *curAddr;
    if ((index < (*list).length/2) || (index < 2)) {
        curAddr = (*list).start;
        for (int i = 0; i < index; i++)
        {
            curAddr = (*curAddr).next;
        }
    } else {
        curAddr = (*list).end;
        for (int i = 0; i < (*list).length-index-1; i++)
        {
            curAddr = (*curAddr).prev;
        }
    }
    return curAddr;
}

int dllPop(dlinkedlist *list, int index) {
    dllobject *curAddr = dllGetAddr(list, index);
    int popped = (*curAddr).content;
    if (index > 0) {
        (*(*curAddr).prev).next = (*curAddr).next;
    }
    if (index < (*list).length) {
        (*(*curAddr).next).prev = (*curAddr).prev;
    }
    if (index == 0) {
        (*list).start = (*curAddr).next;
    } else if (index == (*list).length - 1) {
        (*list).end = (*curAddr).prev;
    }
    (*list).length -= 1;
    free(curAddr);
    return popped;
}

int dllGet(dlinkedlist *list, int index) {
    if (index + 1 > (*list).length) return -1;
    dllobject *curAddr = dllGetAddr(list, index);
    return (*curAddr).content;
}

int dllSet(dlinkedlist *list, int index, int value) {
    if (index + 1 > (*list).length) return -1;
    dllobject *curAddr = dllGetAddr(list, index);
    (*curAddr).content = value;
    return index;
}

int dllAppend(dlinkedlist *list, int value) {
    (*(*list).end).next = (dllobject*) malloc(sizeof(dllobject));
    (*(*(*list).end).next).prev = (*list).end;
    (*(*(*list).end).next).next = 0;
    (*(*(*list).end).next).content = value;

    (*list).end = (*(*list).end).next;
    (*list).length = (*list).length + 1;
    return (*list).length;
}