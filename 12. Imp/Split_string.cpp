/*
    The getline() function is a C++ standard library function that reads a string from an input stream and inserts it into a vector string until delimiter characters are found. By importing the <string> header file, we can use the std::getline() function.

    Syntax:
        getline(string, token, delimiter);

        The getline() function takes three parameters;
            string:- It is the variable that stores the original string;
            token:- It saves the extracted string tokens from the original string.
            delimiter:- It is the parameter or character based on which we separate the string.

    Note:-
    Article Link: https://www.scaler.com/topics/split-string-in-cpp/
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, token;

    s = "Gautam Nandkishor Sharad Muralidhar Dhaurao Khaire";

    // obj is an object of stringstream that references the S string.
    stringstream obj(s);

    // // Use while loop to check the getline() function condition.
    while (getline(obj, token, ' ')) // Spliting is done based on white spaces (In place of delimiter we can give anything like ' ','.',',',':' and so on)
        // `token` is used to store the token string while ' ' whitespace is used as the delimiter.
        cout << token << endl;

    return 0;
}
