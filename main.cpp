/**
 * @file main   .cpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#include "include/Process.hpp"
#include "include/Scheduler.hpp"
#include "include/Dataloader.hpp"
#include <random>
#include <iostream>
using namespace std;

int main(){
    int p_count = 500;
    // Random seed
    srand(time(NULL));

    Dataloader datapack;
    vector<string> data =  datapack.getData();

    // Creating a new schedule
    Scheduler my_pc(p_count, "Sessión Android.");

    try{
        for(int i = 0; i < p_count; i++){
            my_pc.add((rand() % 1000 + 1), data[rand() % data.size() + 1]);
        }
    }catch(const char* e){
        cout << e << endl;
    }
        

    my_pc.print();
    cout << data[4] << endl;    
    return 0;
}