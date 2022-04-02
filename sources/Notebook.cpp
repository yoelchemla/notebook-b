#include "Direction.hpp"
#include "Notebook.hpp"
#include <iostream>
#include <map>
#include <locale>
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel
{
 //ascii table
    const int maximum = 99;
    const int minimumChar = 32;
    const int maximumChar = 125;
   
    
    void Notebook::write(int page, int row, int col, Direction d, string txt) {
        int leng = txt.length();
        //default cases
        if ((d == Direction::Horizontal) && (col + leng > maximum)){ // out of range 
            throw runtime_error("error");
        }
        if (row < 0 || col < 0|| page < 0){ //negative
            throw runtime_error("error");
        } 
        if (col > maximum){ 
            throw runtime_error("error");
        }
        for (int i = 0; i < leng; i++){ 
            if (txt[(unsigned int)i] < minimumChar || txt[(unsigned int)i] >maximumChar ){
                throw runtime_error("error"); // out of range 
            }
        }

        if (d == Direction::Vertical){
            for (int i = 0; i < leng; i++){ //pass on the length of the txt
                if (notebook[page][row+i][col] == '~' || txt[(unsigned int)i] == '~' ){ //out of range
                    throw runtime_error("error");
                }
                if (notebook[page][row+i][col] <= maximumChar && minimumChar <= notebook[page][row+i][col]){
                    if (notebook[page][row+i][col] == '_'){
                        notebook[page][row+i][col] = txt[(unsigned int)i];
                    }
                    else{// != '_'
                        throw runtime_error("error");
                    }
                }
                else{
                    notebook[page][row+i][col] = txt[(unsigned int)i];
                }
            }
        }
        else{ // horizontal
            for (int i = 0; i < leng; i++){
                if (notebook[page][row][col+i] == '~' || txt[(unsigned int)i] == '~'){ //out of range
                    throw runtime_error("error");
                }
                if (notebook[page][row][col+i] <= maximumChar && minimumChar <= notebook[page][row][col+i]){
                    if (notebook[page][row][col+i] == '_'){
                        notebook[page][row][col+i] = txt[(unsigned int)i];
                    }
                    else{// != '_'
                        throw runtime_error("error");
                    }
                }
                else{
                    notebook[page][row][col+i] = txt[(unsigned int)i];
                }
            }
        }
    }
    string Notebook::read(int page, int row, int col, Direction d, int numsChars){
        //default cases
         if (col > maximum){
            throw runtime_error("error");
        }
        if (row < 0 || col < 0 || page < 0 || numsChars < 0){ //negative
            throw runtime_error("error");
        }
        if ((d == Direction::Horizontal) && (col + numsChars > maximum + 1)){ //num of chars > 100 
            throw runtime_error("error");
        }
        string str; // define a new string
        if (d == Direction::Vertical){
            for (int i = 0; i < numsChars; i++){
                if (notebook[page][row+i][col] <= maximumChar+1 && minimumChar <= notebook[page][row+i][col]){
                    str += notebook[page][row+i][col];
                }
                else{
                    str += '_';
                }
            }
        }
        else{ // horizontal
            for (int i = 0; i < numsChars; i++){
                if (notebook[page][row][col+i] <= maximumChar+1 && minimumChar <= notebook[page][row][col+i] ){
                    str += notebook[page][row][col+i];
                }
                else{
                    str += '_';
                }
            }
        }
        return str;
    }
    void Notebook::erase(int page, int row, int col, Direction d, int numsChars){ 
        //default cases
         if (col > maximum){
            throw runtime_error("error");
        }
        if (row < 0 || col < 0 || page < 0 || numsChars < 0){ //negative
            throw runtime_error("error");
        }
        if ((d == Direction::Horizontal) && (col + numsChars > maximum + 1)){ //out of range
            throw runtime_error("error");
        }

        if (d == Direction::Vertical){
            for (int i = 0; i < numsChars; i++){
                notebook[page][row+i][col] = '~';
            }
        }
        else{ // horizontal
            for (int i = 0; i < numsChars; i++){
                notebook[page][row][col + i] = '~';
            }
        }
    }
    void Notebook::show(int page)
    {
        if (page < 0){ //  the page is negative
            throw runtime_error("error");
        }
        cout << notebook[page][0][0]<<"page";
    }
}