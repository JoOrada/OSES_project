#include <rtthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtdevice.h>

static void timeout1(void* parameter)
       {
    LOG_D("Breaking!");
    rt_pin_mode(Brake_PIN, PIN_MODE_OUTPUT);
       rt_pin_write(Brake_PIN, PIN_HIGH);
       rt_thread_resume(&SensorInit);
    }


static void BrakeWait_entry(void* parameter)
{
    while(1){ LOG_D("Brake_System Starts!");
 err2= rt_mb_recv(&target1,y , RT_WAITING_FOREVER);

       if (y=10){
               rt_enter_critical();
                if (BrakeTimeout!= RT_NULL) { rt_timer_start(BrakeTimeout);}
                    rt_pin_mode(Sensor_PIN, PIN_MODE_INPUT);
                            if (z= 1){

                        rt_timer_stop(BrakeTimeout);
                        rt_exit_critical();
                        rt_thread_resume(&SensorInit);
                    }
    }}}
