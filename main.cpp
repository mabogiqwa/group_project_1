#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

const int NUM = 10;
const int ROWS = 10;
const int COLUMNS = 5;

void get_names(std::string *names);
//Precondition: The array for the names must have 10 indices
//Postcondtion: Stores the names within the 'names' text file within an array

void get_scores(int scores[ROWS][COLUMNS]);
//Precondition: The 2-dimensional array must be empty
//Postcondition: Stores the test scores with the scores file into a 2-dimensional array

int main()
{
    std::string names[NUM];

    int scores[ROWS][COLUMNS];

    get_scores(scores);

    //Shivam you can write the code that calculate the average of 
    //each of the students test score here
    //Note that each row of the 2-dimensional array has the test scores of each student
    //So while traversing through a row, you can sum up the scores and divide them by the number of columns to get the average of the student.

    return 0;
}

void get_scores(int scores[ROWS][COLUMNS])
{
    char next;
    std::string number ="";
    std::ifstream ins;
    int row = 0, column = 0;
    int score;

    ins.open("test scores.txt");
    if (ins.fail())
    {
        std::cout << "The file failed to open" << std::endl;
        exit(1);
    }

    while (ins.get(next))
    {
        if (next == ' ')
        {
            score = std::stoi(number);
            std::cout << score << std::endl;
            scores[row][column] = score;
            column = column + 1;
            number = "";
        } else if (next == '\n') {
            score = std::stoi(number);
            scores[row][column] = score;
            std::cout << score << std::endl;
            row = row + 1;
            column = 0;
            number = "";
        } else {
            number += next;
        }

    }

    if (!number.empty())
    {
        score = std::stoi(number);
        scores[row][column] = score;
        std::cout << score << std::endl;
    }

    ins.close();
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
