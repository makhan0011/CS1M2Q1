#include "Q1.hpp"

/*
int getNumLines(string filename)
{
        return cnt;
}
int getNumWords(string filename)
{
        return cnt;
}
char getMFU(string filename)
{
        return mfu;
}
*/

int main()
{
    // given main function
    string filename;
    int cnt, wnum;
    char mfu;

    filename = "textfile0.dat";
    cnt = getNumLines(filename);
    cout << "The number of lines: " << cnt << endl;
    wnum = getNumWords(filename);
    cout << "The number of words: " << wnum << endl;
    mfu = getMFU(filename);
    cout << "The most requently used character: " << mfu << endl;
    return 0;
}

int getNumLines(string filename)
{
    // for determining line condition check
    string line = " ";

    // opening file
    ifstream myFile(filename);
    int cnt = 0;
    
    // if statement with nested while loop that checks lines 
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            getline(myFile, line);
            cnt++;
        }
    }

    // closing file after completion
    myFile.close();
    // return statement returning count
    return cnt;
}

int getNumWords(string filename)
{

    // initializing variables to find number of words
    int cnt = 0;
    string word = " ";

    // opening file
    ifstream myFile(filename);
    
    // if statement with nested while loop that checks for words then adds 1 
    if (myFile.is_open())
    {
        while (myFile >> word)
        {
            cnt += 1;
        }
    }
    // returning count
    return cnt;
}

// setting up to get MFU character
char getMFU(string filename)
{
    // initializing a vector and variables
    vector<int> list(226);
    ifstream myFile(filename);
    char MFU;
    char cnt;
    int high = 0;

    // while loop that stores mfu characters
    while (myFile >> MFU)
    {
        list[(int)MFU]++;
    }

    // for loop that compares frequently used characters
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] > high)
        {
            high > list[i];
            cnt = i;
        }
    }
    // returning count
    return cnt;
}
