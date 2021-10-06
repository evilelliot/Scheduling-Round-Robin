/**
 * @file Datalaoder.cpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#include <iostream>
#include "../include/Dataloader.hpp"
#include <fstream>
#include <vector>
#include <assert.h>
#include <iterator>
#include <iomanip>
using namespace std;

Dataloader::Dataloader(){}
vector<string> Dataloader::getData(){

    string filename = "datapack/googleplaystore.txt";
    ifstream file(filename);
    assert(file);

    vector<string> fileContents;
    copy(istream_iterator<string>(file), istream_iterator<string>(),back_inserter(fileContents));
    return fileContents;
}