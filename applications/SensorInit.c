#include <rtthread.h>
#include <stdlib.h>
#include <stdio.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtdevice.h>
#include "main.h"

static char SensorInit_stack[512];


static void SensorInitiation_entry(void* parameter)
{ LOG_D("Hello! SensorInit starts");
        rt_pin_mode(Laser_pin, PIN_MODE_OUTPUT);
           rt_pin_mode(Detect_pin, PIN_MODE_INPUT);
             rt_pin_write(Laser_pin, PIN_HIGH);
                   rt_pin_write(Laser_pin, PIN_LOW);

                          Getspeed= rand()%40;
                          Safe= Getspeed*(Getspeed/6+1.1);
                          Sensor_return= rand()%200;
                          distance= Sensor_return*299792458/2;

     if (distance<=Safe) {
         LOG_D("Hello! SensorInit Failed");
         rt_mb_send(&target, 10);
             }
     }
