/**
 * @file Dataloader.cpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#ifndef Dataloader_hpp
#define Dataloader_hpp

#include <vector>
using namespace std;


class Dataloader{
    vector<string> data;
    public:
        Dataloader();
        vector<string> getData();   
};

#endif