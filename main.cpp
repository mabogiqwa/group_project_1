#include <iostream>
#include <fstream>
#include <cstdlib>

void get_names(std::string *names);

int main()
{
    std::string names[10];

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
