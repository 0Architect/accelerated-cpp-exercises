#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    const string greeting = "Hello, " + name + "!";
    const int pad = 1;

    //Set rows to 3 to remove padding between borders
    const int rows = 3;

    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout << endl;
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            //Print greeting when r == 1, to avoid padding between border.
            if (r ==  1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}