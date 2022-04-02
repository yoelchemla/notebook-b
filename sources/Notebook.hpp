#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
#include <unordered_map>



using namespace std;
namespace ariel
{
    class Notebook
    {
    unordered_map< int, unordered_map< int, char[100]>> notebook;
    public:
        void write( int page,  int row, int col, Direction d, string txt);
        string read( int page, int row,  int col, Direction d, int numsChars);
        void erase( int page,  int row,  int col, Direction d,  int numsChars);
        void show( int page);
 };
}

