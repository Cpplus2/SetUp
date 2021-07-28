#ifndef SORTEDLIST_H
#define SORTEDLIST_H

struct NodeType{
    int info;
    NodeType* next;
};

class SortedList
{
    private:
        NodeType* listData;
        NodeType* cursor;
        int length;

    public:
        SortedList();
        ~SortedList();
        int GetLength();
        int GetItem(int, bool&);
        void InsertItem(int);
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        bool IsEdged() const;
        void DeleteItem(int);
        void ResetList();
        int GetNextItem();
};
#endif // SORTEDLIST_H

