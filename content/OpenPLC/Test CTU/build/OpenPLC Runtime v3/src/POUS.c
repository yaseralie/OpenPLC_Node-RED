void MAIN_init__(MAIN *data__, BOOL retain) {
  R_TRIG_init__(&data__->R_TRIG0,retain);
  __INIT_VAR(data__->PULSE_COUNTER,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->PULSE_RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX4_0,data__->RELAY_START,retain)
  __INIT_LOCATED_VALUE(data__->RELAY_START,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX4_1,data__->START_STATE,retain)
  __INIT_LOCATED_VALUE(data__->START_STATE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX4_2,data__->RELAY_DOWNTIME,retain)
  __INIT_LOCATED_VALUE(data__->RELAY_DOWNTIME,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX4_3,data__->DOWNTIME_STATE,retain)
  __INIT_LOCATED_VALUE(data__->DOWNTIME_STATE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX4_4,data__->COUNTER_TRIGGER,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_TRIGGER,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX4_5,data__->RESET_COUNTER,retain)
  __INIT_LOCATED_VALUE(data__->RESET_COUNTER,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__MW10,data__->COUNTER_REGISTER,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_REGISTER,0)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_LOCATED(data__->,START_STATE,,__GET_LOCATED(data__->RELAY_START,));
  __SET_LOCATED(data__->,DOWNTIME_STATE,,__GET_LOCATED(data__->RELAY_DOWNTIME,));
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_LOCATED(data__->COUNTER_TRIGGER,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,PULSE_COUNTER,,__GET_VAR(data__->R_TRIG0.Q,));
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->PULSE_COUNTER,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->PULSE_RESET,));
  __SET_VAR(data__->CTU0.,PV,,999);
  CTU_body__(&data__->CTU0);
  __SET_LOCATED(data__->,COUNTER_REGISTER,,__GET_VAR(data__->CTU0.CV,));
  if (__GET_VAR(data__->PULSE_COUNTER,)) {
    __SET_LOCATED(data__->,COUNTER_TRIGGER,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_LOCATED(data__->RESET_COUNTER,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,PULSE_RESET,,__GET_VAR(data__->R_TRIG1.Q,));
  if (__GET_VAR(data__->PULSE_RESET,)) {
    __SET_LOCATED(data__->,RESET_COUNTER,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // MAIN_body__() 





