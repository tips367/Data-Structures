/* Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
 
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and 
it has infinite capacity). 
Assume for 1-litre petrol, the truck can go 1 unit of distance.
For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as 
{4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where the truck can make a circular tour is 2nd petrol pump. 

Output should be “start = 1” (index of 2nd petrol pump).
*/

#include <iostream>

struct SPetrolPump
{
    int petrol;
    int distance;
};

int tourStartPoint(SPetrolPump arr[], int n)
{
    int start = 0;
    int end = 1;
    int currentPetrol = arr[start].petrol - arr[start].distance;
    // Loop while all petrol pumps are not visited
    while (end != start || currentPetrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (end != start && currentPetrol < 0)
        {
            // Remove starting petrol pump
            currentPetrol -= (arr[start].petrol - arr[start].distance);
            // change start
            start = (start + 1) % n;
            // if start becomes 0 again then there is no possible solution
            if (start == 0)
            {
                return -1;
            }
        }
        // Add a petrol pump to current tour
        currentPetrol += (arr[end].petrol - arr[end].distance);
        end = (end + 1) % n;
    }
    return start;
}

int main()
{
    SPetrolPump arr[] = { {4, 6}, {6, 5}, {7, 3}, {4, 5} };

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = tourStartPoint(arr, n);

    if (start == -1)
    {
        std::cout << "No solution";
    }
    else
    {
        std::cout << "Start = " << start;
    }

    return 0;
}

