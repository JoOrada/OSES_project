#include <rtthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtdevice.h>
     int16_t z;
static void Breakout1(void* parameter)
       {
    LOG_D("Breaking!");
    rt_pin_mode(Brake_PIN, PIN_MODE_OUTPUT);
       rt_pin_write(Brake_PIN, PIN_HIGH);
       z= 10;
       }


static void BrakeWait_entry(void* parameter)
{
    while(1){

 err2= rt_mb_recv(&target1,y , RT_WAITING_FOREVER);

       if (y=10){
           BrakeTimeout = rt_timer_create("BrakeTimeout", Breakout1,
                                                           RT_NULL, 700,
                                                           RT_TIMER_FLAG_ONE_SHOT);
           rt_timer_start(BrakeTimeout);
               rt_enter_critical();
               LOG_D("Brake_System Starts!");
                    rt_pin_mode(Sensor_PIN, PIN_MODE_INPUT);
                    LOG_D("Wait!");
                      while(z!=10)
                      {
                          z=rand()%500;


                      }
                      LOG_D("Breaking!");
                                rt_timer_stop(BrakeTimeout);
                                z=0;
                        rt_exit_critical();

    }}}
