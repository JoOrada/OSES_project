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
       z= 1;
       }


static void BrakeWait_entry(void* parameter)
{
    while(1){

 err2= rt_mb_recv(&target1,y , RT_WAITING_FOREVER);

       if (y=10){
           BrakeTimeout = rt_timer_create("BrakeTimeout", Breakout1,
                                                           RT_NULL, 70,
                                                           RT_TIMER_FLAG_PERIODIC);
           rt_timer_start(BrakeTimeout);
               rt_enter_critical();
               LOG_D("Brake_System Starts!");
                    rt_pin_mode(Sensor_PIN, PIN_MODE_INPUT);
                        z=0;
                      while(z==0)
                      {
                          z=rand()%2;
                          LOG_D("Wait!");

                      }

                            if (z==1){
                                LOG_D("Braking!");
                                rt_timer_stop(BrakeTimeout);
                        rt_exit_critical();
                    }

    }}}
