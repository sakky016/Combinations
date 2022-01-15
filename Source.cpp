#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//----------------------------------------------------------------------------------------------------------
template <typename T>
void displayArr(const vector<T>& arr)
{
    for (const auto& entry : arr)
    {
        std::cout << entry << " ";
    }
    std::cout << std::endl;
}


//----------------------------------------------------------------------------------------------------------
vector<string> getCombination(const string& inputStr, int R, bool keepDuplicates = false)
{
    vector<string> combinations;

    string input(inputStr);

    // Sorting it so as to handle duplicate entries. Duplicate entries would be consecutive
    // elements in a sorted array
    sort(input.begin(), input.end());

    // Create a vector which holds mapping of vector indices that should be considered
    // for adding it into the combination
    std::vector<bool> presenceVector(input.size());
    std::fill(presenceVector.end() - R, presenceVector.end(), true);

    do
    {
        string combination;
        for (int i = 0; i < input.size(); ++i)
        {
            if (presenceVector[i])
            {
                if (!keepDuplicates && i > 0 && input[i - 1] == input[i])
                {
                    // Skip this duplicate entry
                }
                else
                {
                    combination.push_back(input[i]);
                }
            }
        }

        // Add this combination only if its size is R. Certain combinations in which duplicates
        // were not included would not have R size
        if (combination.size() == R)
            combinations.push_back(combination);

    } while (std::next_permutation(presenceVector.begin(), presenceVector.end()));

    return combinations;
}


//----------------------------------------------------------------------------------------------------------
// M A I N
//----------------------------------------------------------------------------------------------------------
int main() 
{
    string input;
    cout << "Input: ";
    cin >> input;

    int R = 0;
    cout << "R: ";
    cin >> R;

    bool keepDuplicates = false;
    string keepDuplicatesStr;
    cout << "Keep duplicates (y/n)? ";
    cin >> keepDuplicatesStr;
    keepDuplicates = keepDuplicatesStr == "y";

    vector<string> combinations = getCombination(input, R, keepDuplicates);
    cout << "Combinations of " << input << " are:\n";
    displayArr(combinations);

    return 0;
}