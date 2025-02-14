#include <iostream>
#include <fstream>
#include <cstdlib>

const int NUM = 10;
const int ROWS = 10;
const int COLUMNS = 5;

void get_names(std::string *names);
//Precondition: The array for the names must have 10 indices
//Postcondtion: Stores the names within the 'names' text file within an array

void get_scores(int *scores);

int main()
{
    std::string names[NUM];

    int scores[ROWS][COLUMNS];

    //get_names(names);

    /*
    for (int i = 0; i < 10; i++)
    {
        std::cout << names[i] << std::endl;
    }
    */

    return 0;
}

void get_scores(int *scores)
{
    char next;
    std::ifstream ins;
    int row = 0, column = 0;


    ins.open("test scores.txt");
    if (ins.fail())
    {
        std::cout << "The file failed to open" << std::endl;
        exit(1);
    } 

    while(!ins.eof())
    {
        if (next == " ")
        {

        }

        ins.get(next);
    }
}

void get_names(std::string *names)
{
    char next;
    std::ifstream ins;
    std::string name = "";
    int index = 0;

    ins.open("names.txt");
    if (ins.fail())
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

    ins.close();
}
