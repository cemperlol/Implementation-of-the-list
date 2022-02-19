#include <iostream>
#include "ClassList.h"

using namespace Lst;
using namespace std;
/*
*************************************************************INFO************************************************************
Class cll_List is my own implementation of STL list. This class is generic so don't forget to point data type
Class Node is the inner class of cll_list. Each Node object contains data, the address  of the previous Node (if it exists) and the address  of the following Node (if it exists)
To use cll_List you've got to include "ClassList.h" and <iostream> also you've got you use namespace Lst!
List_Name.push_back(value) - adds value to the end of the list
List_Name.pop_back() - removes last Node from the list
List_Name.push_front(value) - adds value to the beginning of the list
List_Name.pop_frongt() - removes first Node from the list
List_Name.insert_at(value, index) - adds value at the chosen index (doest change it)
List_Name.remove_at(index) - removes Node at the chosen index
List_Name.random_fill(quantity) - adds chosen amount of random numbers to the list (doesnt work with user's data types and string)
List_Name.show_all() - shows all the data from all Nodes
List_Name.clear() - removes all Nodes in the list
List_Name[index] - returns data of a specific Node
List_Name.GetSize() - returns the number of Nodes in the list
List_Name.change_data(data, index) - changes data in the chosen Node
List_Name.change_data(index1, index2, unused) - exchanges data between two Nodes (parametr unused's being used to differ overloads)
*/

int main()
{

	return 0;
}