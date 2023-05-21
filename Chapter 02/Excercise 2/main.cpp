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
    
    //Substitute pad with x_pad for the side borders and y_pad for the top and bottom borders
    const int x_pad = 1;
    const int y_pad = 1;

    //rows now works with y_pad instead of just pad, while cols with x_pad
    const int rows = y_pad*2 +3;
    const string::size_type cols = greeting.size() + x_pad * 2 + 2;

    cout << endl;
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            //Calculated using y_pad
            if (r ==  y_pad + 1 && c == x_pad + 1)
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