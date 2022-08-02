// This program reads data from file
// Created by Lee, Emily on 9/29/2021.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void showRatings(string, ifstream &, int &, int &, string *&, int **&);
void printArrays();

const int SIZE = 100;

int main() {
    // Declare variables
    ifstream inputFile;
    string filename, name;
    int mCount = 0, bCount = 0;

    // Declare arrays
    string * members = new string[SIZE];
    int ** ratings = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
        ratings[i] = new int[SIZE];

    // Get the file name,
    cout << "Enter rating file: ";
    cin >> filename;

    // Open and read from file
    showRatings(filename, inputFile, mCount, bCount, members, ratings);
    cout << endl;

    // Print number of books and members
    cout << "# of books: " << bCount << endl;
    cout << "# of members: " << mCount << endl;
    cout << endl;

    // Print arrays
    for (int i = 0; i < mCount; i++) {
        cout << members[i] << endl;
        for (int j = 0; j < bCount; j++)
            cout << ratings[i][j] << " ";
        cout << endl;
    }

    // Deallocate arrays
    delete [] members;
    for (int i = 0; i < SIZE; i++)
        delete [] ratings[i];
    delete [] ratings;

    // Set to nullptr
    members = nullptr;
    ratings = nullptr;
}

void showRatings(string filename, ifstream &inputFile, int &mCount, int &bCount,
                 string *&mList, int *
                 *&rList) {
    string name, ratings;
    int rating;

    // Open and read file
    inputFile.open(filename);
    if (inputFile) {

        while (getline(inputFile, name)) {
            getline(inputFile, ratings);

            // Add members
            mList[mCount] = name;

            // Split ratings, separated by space
            istringstream ss(ratings);
            bCount = 0;

            // Add rating
            while (ss >> rating)
                rList[mCount][bCount++] = rating;

            // Update member count
            mCount++;
        }
    } else
        cout << "ERROR: cannot open file...\n";

    // Close file
    inputFile.close();
}