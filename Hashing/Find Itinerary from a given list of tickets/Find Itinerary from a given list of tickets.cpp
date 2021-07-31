/* Given a list of tickets, find itinerary in order using the given list.
Example: 
 

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
*/

#include <iostream>
#include <map>
#include <string>
#include <set>

void printItinerary(std::map<std::string, std::string>& dataSet)
{
    std::map<std::string, std::string> reverseMap;

    // Create the reverse map
    for (auto i : dataSet)
    {
        reverseMap[i.second] = i.first;
    }

    std::string start;

    // Find the starting point of itenerary
    for (auto i : dataSet)
    {
        if (reverseMap.find(i.first) == reverseMap.end())
        {
            start = i.first;
            break;
        }
    }

    // If we could not find a starting point, then something wrong with input
    if (start.empty())
    {
        std::cout << "Invalid Input" << std::endl;
        return;
    }

    std::map<std::string, std::string>::iterator it;
    it = dataSet.find(start);

    while (it != dataSet.end())
    {
        std::cout << it->first << "->" << it->second << std::endl;
        it = dataSet.find(it->second);
    }
}

int main()
{
    std::map<std::string, std::string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";

    printItinerary(dataSet);

    return 0;
}


