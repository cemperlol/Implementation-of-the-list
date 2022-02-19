/*
*************************************************************INFO************************************************************
Class cll_List is my own implementation of STL list. This class is generic so don't forget to point data type
Class Node is the inner class of cll_list. Each Node object contains data, the address  of the previous Node (if it exists) and the address  of the following Node (if it exists)
To use cll_List you've got to include "ClassList.h" and <iostream> also you've got you use namespace Lst!
List_Name.push_back(value) - adds value to the end of the list
List_Name.pop_back() - removes last Node from the list
List_Name.push_front(value) - adds value to the beginning of the list
List_Name.pop_frongt() - removes first Node from the list
List_Name.insert(value, index) - adds value at the chosen index (doest change it)
List_Name.erase(index) - removes Node at the chosen index
List_Name.random_fill(quantity) - adds chosen amount of random numbers to the list (doesnt work with user's data types and string)
List_Name.print() - shows all the data from all Nodes
List_Name.clear() - removes all Nodes in the list
List_Name.GetSize() - returns the number of Nodes in the list
List_Name.change_data(data, index) - changes data in the chosen Node
List_Name.change_data(index1, index2, unused) - exchanges data between two Nodes (parametr unused's being used to differ overloads)
List_Name.reverse() - reverses the order of Nodes
List_Name.unique() - deletes all Nodes with the same date, which come in the row
List_Name.remove(value) - removes all Nodes with the specified value
List_Name.sort(ReverseMode) - sorts all Nodes depending on their data in chosen way (direct or reverse)
List_Name.assign(quantity, value) - removes old Nodes and creates new ones instead with a specific value
List_Name[index] - returns data of a specific Node
*/

#include <iostream>
#include "ClassList.h"

using namespace Lst;
using namespace std;

int main()
{

	return 0;
}