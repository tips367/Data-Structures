/* Given a dictionary that contains mapping of employee and his manager as a number of (employee, manager) pairs like below. 

{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" } 

In this example C is manager of A,  C is also manager of B, F is manager of C and so on.

Write a function to get no of employees under each manager in the hierarchy not just their direct reports. 
It may be assumed that an employee directly reports to only one manager. 
In the above dictionary the root node/ceo is listed as reporting to himself.

Output should be a Dictionary that contains following.

A - 0
B - 0
C - 2
D - 0
E - 1
F - 5

*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, int> memo;

int numberOfEmployeesUnderManager(std::string s, std::map<std::string, std::vector<std::string>>& managerEmployeeMap)
{
    // check if it is already stored in memo
    auto memoIt = memo.find(s);
    if (memoIt != memo.end()) 
        return memoIt->second;

    // return 0 if there is no employee under current one
    auto it = managerEmployeeMap.find(s);
    if (it == managerEmployeeMap.end()) 
        return memo[s] = 0;

    // if not computed yet, compute it recursively
    int ans = 0;
    for (auto s : it->second)
        ans += 1 + numberOfEmployeesUnderManager(s, managerEmployeeMap);

    return memo[s] = ans;
}

void printNumberOfEmployeesUnderEachManager(std::map<std::string, std::string>& employeeManagerMap)
{
    // To store reverse of original map, each key will have 0 to multiple values
    std::map<std::string, std::vector<std::string>> managerEmployeeMap;
    
    for (auto it = employeeManagerMap.begin(); it != employeeManagerMap.end(); ++it)
    {
        // excluding emp-emp entry
        if (it->first != it->second)
            managerEmployeeMap[it->second].push_back(it->first);
    }

    std::map<std::string, int> numberOfEmployees;
    // counting number of employees
    for (auto it = employeeManagerMap.begin(); it != employeeManagerMap.end(); ++it)
        numberOfEmployees[it->first] = numberOfEmployeesUnderManager(it->first, managerEmployeeMap);


    // print result
    for (auto it = numberOfEmployees.begin(); it != numberOfEmployees.end(); ++it)
        std::cout << it->first << " - " << it->second << std::endl;
}

int main() {

    std::map<std::string, std::string> employeeManagerMap = 
    {
        { "A", "C" },
        { "B", "C" },
        { "C", "F" },
        { "D", "E" },
        { "E", "F" },
        { "F", "F" }
    };

    printNumberOfEmployeesUnderEachManager(employeeManagerMap);

    return 0;
}


