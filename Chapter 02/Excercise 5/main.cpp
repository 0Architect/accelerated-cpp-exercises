#include <iostream>

int main()
{
    // Square
    const int square_length = 5;
    for (int counter = 0; counter < square_length; ++counter)
    {
        for (int writer = 0; writer < square_length; ++writer)
        {
            if (writer == 0 || writer == square_length - 1 ||
                counter == 0 || counter == square_length - 1)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << '\n'
              << '\n';

    // Square
    const int rec_length = 5;
    const int rec_width = 10;
    for (int counter = 0; counter < rec_length; ++counter)
    {
        for (int writer = 0; writer < rec_width; ++writer)
        {
            if (writer == 0 || writer == rec_width - 1 ||
                counter == 0 || counter == rec_length - 1)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << '\n'
              << '\n';

    // Triangle
    const int tri_length = 10;
    for (int counter = 0; counter < tri_length; ++counter)
    {
        for (int writer = 0; writer < tri_length * 2 - 1; ++writer)
        {
            if (counter == tri_length - 1 ||
                writer == tri_length - counter - 1 ||
                writer == tri_length + counter - 1)
                std::cout << '*';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << '\n'
              << '\n';

    return 0;
}