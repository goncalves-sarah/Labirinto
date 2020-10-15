#include <time.h>

#include "Clock.h"


using namespace std;

Clock::Clock() {
  this->tempo = clock();
}

double Clock::end() {
  return (((clock() - tempo)/(double)CLOCKS_PER_SEC)*1000);
}

Clock::~Clock(){}



