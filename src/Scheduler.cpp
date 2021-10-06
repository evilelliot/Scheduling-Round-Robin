/**
 * @file Scheduler.cpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#include "../include/Process.hpp"
#include "../include/Scheduler.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

Scheduler::Scheduler(int c, string sn): _capacity(c), schedule_name(sn){
  _size = 0;
  arrival_time = 0;
  eoq = NULL;
  soq = NULL;
}
// Destructor
Scheduler::~Scheduler(){
  while(!empty()){
    drop();
  }
}
// Enqueue
void Scheduler::add(int x, string pn){
  if(full()){
    cout << "Queue overflow!" << endl;
    throw("Message");
  }else{
    Process *tmp = new Process(x, pn);
    tmp->next(NULL);

    if(size() == 0){
      eoq = tmp;
      soq = tmp;
    }else{
      eoq->next(tmp);
      eoq = tmp;
    }
    // cout << "in: " << eoq->getProcessName() <<" - "<<eoq->getBurstTime() << endl;
    _size++;
  }
}
// Dequeue
string Scheduler::drop(){
  if(empty()){
    cout << "Queue underflow!" << endl;
    return "-1";
  }else{
    if(size() == 1){
      string tmp_data = soq->getProcessName();

      delete soq;
      soq = NULL;
      eoq = NULL;

      _size = 0;
      return tmp_data;
    }else{
      string tmp_data = soq->getProcessName();

      Process *tmp = soq;
      soq = soq->next();

      delete tmp;

      _size--;

      return tmp_data;
    }

  }
}
void Scheduler::print(){
  int p_aux = 0;
  if(!empty()){
    system("clear");
    Process *soq_copy = soq;
    cout << "\033[1;32m"<< schedule_name << "\033[0m" << endl;
    cout.width(15); 
    cout << left << "Burst time |" << setw(2) << "Process name" << endl;
    while(soq_copy != NULL){
      cout.width(15); 
      cout << left << soq_copy->getBurstTime() << soq_copy->getProcessName() << endl;

      p_aux++;
      wt_total = wt_total + soq_copy->getBurstTime();
      soq_copy = soq_copy->next();
    }
    cout << "Process count: " << size() << endl;
    cout << "Quantum: " << wt_total / (float) size() << endl;
    cout << "Total waiting time: " << wt_total << endl;
  }
}