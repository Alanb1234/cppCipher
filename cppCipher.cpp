// cppCipher.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>


#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>






int main()
{
    //Reading the text file that is in the same directory as the cpp file
    std::fstream inputFile("textFile.txt", std::ios::in);
    std::string str ((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

   

    std::string cipher;
    std::string decipher;

    int key = 3;

    for (char& c : str) {

        char ci;

        // For lowercase
        if (c >= 'a' && c <= 'z') {

            ci = c + key;

            if (ci > 'z') {
                ci = ci - 'z' + 'a' - 1;
            }
            cipher.push_back(ci);

        }

        // For uppercase
        if (c >= 'A' && c <= 'Z') {

            ci = c + key;

            if (ci > 'Z') {
                ci = ci - 'Z' + 'A' - 1;
            }
            cipher.push_back(ci);

        }
    }


    // Decipher
    for (char& d : cipher) {

        char di;

        // For lowercase
        if (d >= 'a' && d <= 'z') {

            di = d - key;

            if (di < 'a') {
                di = di + 'z' - 'a' + 1;
            }
            decipher.push_back(di);

        }

        // For uppercase
        if (d >= 'A' && d <= 'Z') {

            di = d + key;

            if (di < 'A') {
                di = di + 'Z' - 'A' + 1;
            }
            decipher.push_back(di);

        }
    }



    std::ofstream file("cipher.txt");
    file << cipher;

    std::cout << str << std::endl;
    std::cout << cipher << std::endl;
    std::cout << decipher << std::endl;
}
