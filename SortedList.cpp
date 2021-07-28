#ifndef SORTEDLIST_CPP
#define SORTEDLIST_CPP

#include "SortedList.h"
#include <cstddef>
#include <new>

SortedList::SortedList()
{
    listData = NULL;
    cursor = NULL;
    length = 0;
}

SortedList::~SortedList()
{
    NodeType* tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

int SortedList::GetLength()
{
    return length;
}

int SortedList::GetItem(int otherItem, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;

    while(moreToSearch && !found)
    {
        if(otherItem == location->info)
        {
            found = true;
            otherItem = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        }
    }
    return otherItem;
}

void SortedList::DeleteItem(int otherItem)
{
    NodeType * location = listData;
    NodeType * tempLocation;

    if(otherItem != listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while(otherItem != location->next->info)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void SortedList::InsertItem(int otherItem)
{
    NodeType* location = new NodeType;
    location->info = otherItem;
    location->next = listData;

    listData = location;
    length++;
}

void SortedList::MakeEmpty()
{
    NodeType* tempPtr = listData;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool SortedList::IsEmpty() const
{
    return (length == 0);
}

bool SortedList::IsEdged() const
{
    return (length == 1);
}

bool SortedList::IsFull() const
{
    NodeType* location;

    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

void SortedList::ResetList()
{
    cursor = NULL;
}

int SortedList::GetNextItem()
{
    if(cursor == NULL)
        cursor = listData;
    else
        cursor = cursor->next;

    length--;

    return cursor->info;
}

#endif // SORTEDLIST_CPP

