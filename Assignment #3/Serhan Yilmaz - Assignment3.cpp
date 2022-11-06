#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

bool checkFirst(string source) // checks source
{
    for (int i = 0; i < source.length(); i++){
        unsigned int myPos = source.at(i);
        if (source.length() == 0 || myPos < 97 || myPos > 122){
            return false;
        }
    }
    return true;
}

bool checkSecond(string source, string search) // checks search
{
    string fullQM;
    fullQM = string(search.length(), '?');
    if(fullQM == search){
        return false;
    }
    if(search.length() > source.length() || search.length() == 0){
        return false;
    }
    for (int i = 0; i < search.length(); i++){
        unsigned int myPos = search.at(i);
        if (((myPos > 122 || myPos < 97 )) && myPos != 63){
            return false;
        }
    }
    return true;
}

bool finalReturn(string substring, string search)
{
    for (int j = 0; j < substring.length(); j++)
    {
        unsigned int instantChar = search.at(j);
        if (instantChar != 63){
            if(instantChar != substring.at(j)){
                return false;
            }
        }
    }

    return true;
}

int finderFunc(string source, string search)
{
    string substring;
    int count = 0;

    for(int i = 0; i <= source.length() - search.length(); i++)
    {
        substring = source.substr(i, search.length());
        
        if(finalReturn(substring, search))
        {
            cout << endl << "\"" <<substring << "\" has been found at index " << i ;
        }
        else{
            count++;
        }
    }
    //cout << endl << endl;

    if (count == (source.length() - search.length() + 1)){
        return 5;
    }
    else {return 3;}

    //return 1;
}

int main()
{
    string selection;
    string source, search;
    bool smth = false;
    int a;

    cout << "This program searches a search string in a source string with the option of wildcards." << endl << endl;
    cout << "Example inputs with their meaning in parentheses:" << endl;
    cout << "1 thislectureisawesome (to enter a new source string)" << endl;
    cout << "2 lecture (to enter a new search string)" << endl;
    cout << "2 t?r? (to enter a search string with wildcards)  " << endl;
    cout << "3 (to exit the program)" << endl << endl;


    cout << "Enter your choice and string: " ;
    while (cin >> selection){
        if (selection == "1"){
            cin >> source;
            if (checkFirst(source) == false){
                cout << "Wrong input format! Try again." << endl << endl;
                cout << "Enter your choice and string: " ;
            }
            else{
                cout << "Source word has been changed to \"" << source << "\"" << endl << endl;
                cout << "Enter your choice and string: " ;
                smth = true;
            }
        }
        else if (selection == "2") {
            if(smth)
            {
                cin >> search;
                if(checkSecond(source, search)){
                    string puncstrip = search;
                    StripPunc(puncstrip);
                    if (source.find(puncstrip) != string::npos){
                        cout << "For the source word \"" << source << "\" and search word \"" << search << "\"," ;}
                    a = finderFunc(source, search);
                   
                    if (a == 5){
                        cout << "For the source word \"" << source << "\" and search word \"" << search << "\", no match has been found." << endl << endl;
                    }
                    else if (a == 3) {
                        cout << endl << endl;
                    }
                    cout << "Enter your choice and string: " ;
                }
                else{
                    cout << "Wrong input format! Try again." << endl << endl;
                    cout << "Enter your choice and string: " ;
                }
            }
            else{
                cout << "Wrong input format! Try again." << endl <<endl;
                cout << "Enter your choice and string: " ;
                cin.clear();
                string trash;
                cin >> trash;
            }
        }

        else if(selection == "3"){
            cout << "See you!" << endl;
            return 0;
        }

        else{
            cout << "Choice can be 1, 2 or 3! Try again." << endl << endl;
            cout << "Enter your choice and string: " ;
        }
    }

    return 0;
}