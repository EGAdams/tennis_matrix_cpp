#ifndef WatchTimer_H
#define WatchTimer_H
#include "DIGI_V6_15.h"
#include "INPUTS.h"
#include "GameTimer.h"

class WatchTimer {
 public:
  WatchTimer();
  ~WatchTimer();

  int watchInputDelay( int delay, Inputs* input, int watchInterval );  
  
};

#endif
