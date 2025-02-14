#include <iostream>
#include <fstream>
#include <cstdlib>

const int NUM = 10;

void get_names(std::string *names);
//Precondition: The array for the names must have 10 indices
//Postcondtion: Stores the names within the 'names' text file within an array

int main()
{
    std::string names[NUM];

    get_names(names);

    for (int i = 0; i < 10; i++)
    {
        std::cout << names[i] << std::endl;
    }

    return 0;
}

void get_names(std::string *names)
{
    char next;
    std::ifstream ins;
    std::string name = "";
    int index = 0;

    ins.open("names.txt");
    if(ins.fail())
    {
        std::cout << "The file failed to open" << std::endl;
        exit(1);
    }

    while (!ins.eof())
    {
        if (next == '\n')
        {
            names[index] = name;
            index++;
            name="";
        }
        ins.get(next);
        name += next;
    }
}
