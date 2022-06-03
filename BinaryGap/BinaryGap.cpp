#include <iostream>
#include <exception>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    try
    {
        int N = 529;
        int temp = 0;
        bool done = false;
        vector<int> binary_container;
        int count_zero = 0, count_one = 0;

        if (N > INT_MAX)
            throw overflow_error("LARGE INTEGER DETECTED");
        else if (N < 0)
            throw overflow_error("LARGE INTEGER DETECTED");

        while (!done)
        {
            binary_container.push_back(N % 2);
            temp = N % 2;

            if (temp == 0)
                count_zero++;
            else if (temp == 1)
                count_one++;

            N = N / 2;

            if (N <= 0)
            {
                done = true;
            }
        }

        int count_gap = 0;
        int temp_gap = 0;
        if (count_zero == 0 || count_one == 1 || count_one == 0)
        {
            cout << "NO GAP!" << endl;
        }
        else
        {
            for (int j = 0; j < binary_container.size(); j++)
            {
                if (binary_container.at(j) == 1)
                {
                    temp_gap = 0;
                    for (int i = j + 1; i < binary_container.size(); i++, j++)
                    {
                        if (binary_container.at(i) == 0)
                            temp_gap++;
                        else
                            break;
                    }
                    if (count_gap < temp_gap)
                        count_gap = temp_gap;
                }
            }
        }
        cout << count_gap;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
