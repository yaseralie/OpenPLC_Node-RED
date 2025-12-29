#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  R_TRIG R_TRIG0;
  __DECLARE_VAR(BOOL,PULSE_COUNTER)
  CTU CTU0;
  R_TRIG R_TRIG1;
  __DECLARE_VAR(BOOL,PULSE_RESET)
  __DECLARE_LOCATED(BOOL,RELAY_START)
  __DECLARE_LOCATED(BOOL,START_STATE)
  __DECLARE_LOCATED(BOOL,RELAY_DOWNTIME)
  __DECLARE_LOCATED(BOOL,DOWNTIME_STATE)
  __DECLARE_LOCATED(BOOL,COUNTER_TRIGGER)
  __DECLARE_LOCATED(BOOL,RESET_COUNTER)
  __DECLARE_LOCATED(INT,COUNTER_REGISTER)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
