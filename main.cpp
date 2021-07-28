#include <iostream>
#include <limits>
#include "SortedList.h"

using namespace std;

SortedList unite(int cardinality, int cardinalityToo, int ** sets);
SortedList intersect(int cardinality, int cardinalityToo, int ** sets);
SortedList setDiffer(int cardinality, int cardinalityToo, int ** sets);
void complement(SortedList resultant);

int main()
{
    cout << "This program computes following basic set operations. " << endl;

    cout << "What operation would you like to perform? (U) Union (I) Intersection (D) Set difference (C) Complement" << endl;
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;

    cout << endl;

    cout << "You're calculating for A";
    switch(choice)
    {
        case 'U':
            cout << " union B" << endl;
            break;

        case 'I':
            cout << " intersection B" << endl;
            break;

        case 'D':
            cout << " - B" << endl;
            break;

        case 'C':
            cout << "'" << endl;
            break;
    }

    int num, count;    //temporary element holder
    int ** sets = new int *[2];    //Resultant set

    cout << endl << "Set A: " << endl;
    cout << "Enter the number of values in the first set: ";
    int cardinality;
    cin >> cardinality;
    sets[0] = new int[cardinality];

    for(count = 0; count < cardinality; count++)
    {
        cout << "Enter element#" << count+1 << ": ";
        cin >> num;

        sets[0][count] = num;
    }

    cin.clear();

    SortedList resultant;

    int cardinalityToo;

    if(choice != 'C')
    {
        cout << endl << "Set B:" << endl;
        cout << "Enter the number of values in the second set: ";

        cin >> cardinalityToo;
        sets[1] = new int[cardinalityToo];

        for (count = 0; count < cardinalityToo; count++)
        {
            cout << "Enter element#" << count+1 << ": ";
            cin >> num;
            sets[1][count] = num;
        }
    }
    else
        for(int count = 0; count < cardinality; count++)
            resultant.InsertItem(sets[0][count]);

    int counter, counting, ct = 0;
    int temp;

    switch(choice)
    {
        case 'U':
            cout << "A union B = ";

            resultant = unite(cardinality, cardinalityToo, sets);

            cout << "{" << resultant.GetNextItem();

            while(!resultant.IsEmpty())
                cout << "," << resultant.GetNextItem();

            cout << "}" << endl;

            break;

        case 'I':
            cout << "A intersection B = ";

            resultant = intersect(cardinality, cardinalityToo, sets);

            cout << "{" << resultant.GetNextItem();

            while(!resultant.IsEmpty())
                cout << "," << resultant.GetNextItem();

            cout << "}" << endl;

            break;

        case 'D':
            cout << "A - B = ";

            resultant = setDiffer(cardinality, cardinalityToo, sets);

            cout << "{" << resultant.GetNextItem();

            while(!resultant.IsEmpty())
                cout << "," << resultant.GetNextItem();

            cout << "}" << endl;

            break;

        case 'C':
            complement(resultant);

            break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;
    }

    cout << endl << "Thank you for your using this program. " << endl;

    return 0;
}

SortedList unite(int cardinality, int cardinalityToo, int ** sets)
{
    SortedList resultant; int counting;

    for(counting = 0; counting < cardinality; counting++)
        resultant.InsertItem(sets[0][counting]);

    for(counting = 0; counting < cardinalityToo; counting++)
    {
        bool existence = false;

        for(int countingToo = 0; countingToo < cardinality; countingToo++)
        {
            if(sets[1][counting] == sets[0][countingToo])
            {
                existence = true;
                break;
            }
        }
        if(!existence)
            resultant.InsertItem(sets[1][counting]);
    }

    return resultant;
}

SortedList intersect(int cardinality, int cardinalityToo, int ** sets)
{
    SortedList resultant;
    int count, counting;

    for(count = 0; count < cardinality; count++)
        for(counting = 0; counting < cardinalityToo; counting++)
            if(sets[0][count] == sets[1][counting])
                resultant.InsertItem(sets[0][count]);

    return resultant;
}

SortedList setDiffer(int cardinality, int cardinalityToo, int ** sets)
{
    SortedList resultant;

    int count, counting;

    for(count = 0; count < cardinality; count++)
    {
        for(counting = 0; counting < cardinalityToo; counting++)
        {
            if(sets[0][count] == sets[1][counting])
                break;
        }
        if(sets[0][count] != sets[1][counting])
            resultant.InsertItem(sets[0][count]);
    }

    return resultant;
}

void complement(SortedList resultant)
{
    int temp = 0;

    temp = resultant.GetNextItem();

    cout << "{";
    for(int count = 0; count < 10; count++)
    {
        if(count != temp)
            cout << count << ",";
        else if(!resultant.IsEmpty())
            temp = resultant.GetNextItem();
    }
    cout << "}" << endl;
}
