/**
 * @file Process.cpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#ifndef Node_hpp
#define Node_hpp

#include <string>
using namespace std;

class Process{
    // You could also add different data information as: PID, directions, etc.
    int priority;
    int burst_time;
    string process_name;
    Process *p;

    public:
        Process(int _p, string _pn): burst_time(_p), process_name(_pn), p(nullptr){}
        int getBurstTime() const {return burst_time;}
        string getProcessName() const {return process_name;}    
        Process *next() {return p;}
        void next(Process *q) {p = q;}
};

#endif  