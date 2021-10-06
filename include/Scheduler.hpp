/**
 * @file Scheduler.hpp
 *
 * @author Alberto Ocaranza
 * Contact: fevil.corp@gmail.com
 *
 */
#ifndef Scheduler_hpp
#define Scheduler_hpp

#include "Process.hpp"

class Scheduler{
  Process *soq;
  Process *eoq;

  string schedule_name;
  int arrival_time;
  int _size, _capacity;
  int wt_total;
  float quantum;
  public:
  Scheduler(int, string);
  ~Scheduler();  

  void add(int, string);
  string drop();
  int capacity() const {return _capacity;}
  int size() const {return _size;}

  bool empty() const {return _size == 0;};
  bool full() const {return _size == _capacity;}

  void print();
};

#endif