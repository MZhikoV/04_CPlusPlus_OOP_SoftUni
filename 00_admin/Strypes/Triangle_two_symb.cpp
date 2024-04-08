#include <iostream>

int main()
{
    int n;
    do
    {
        std::cout << "Please enter a positive int value:" <<  std::endl;
         std::cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == j)
            {
                if (i == 0 || i % 2 == 0)
                {
                     std::cout << "#";
                }
                else
                {
                     std::cout << "$";
                };
            }
            else
            {
                if (j > i)
                {
                     std::cout << " ";
                }
                else
                {
                     std::cout << ' ';
                    if (i == 0 || i % 2 == 0)
                    {
                         std::cout << "#";
                    }
                    else
                    {
                         std::cout << "$";
                    };
                }
            }
        }
         std::cout <<  std::endl;
    };
    return 0;
}