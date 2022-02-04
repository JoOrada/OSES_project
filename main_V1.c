/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-02-03     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
int Getspeed=0;
int Safe=0;
int distance=0;
int Sensor_return=0;
#define Ultrasonicsensor_PIN 0
#define EchoR_PIN 1
#define Speed_PIN 2

//Task definitions
int task3();
int task2();
int task1();



int task1(){ //sensors return Stop or not [ALERT]
    printf("Task 1 here");

    rt_pin_mode(Ultrasonicsensor_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(EchoR_PIN, PIN_MODE_INPUT);
    rt_pin_write(Ultrasonicsensor_PIN, PIN_HIGH);
    rt_thread_mdelay(8);
    rt_pin_write(Ultrasonicsensor_PIN, PIN_LOW);
    Sensor_return =rt_pin_read(EchoR_PIN);

    Getspeed= rt_pin_read(Speed_PIN);
    Safe= Getspeed*(Getspeed/6+1.1);
    distance= Sensor_return*0.034/2;
  
    //Verifying if it is necessary to brake or not
    if (distance <= Safe);
    {
        task2();
    }   

}
int task2(){ //Alert the user
    //output sensor

    printf("Output 1 -> Task 2 here");
    alert=1;
    task3();
    return alert;
}

int task3(){
    printf("Task 3 here");
    
    //loop(timer)
    while(1){
        //wait to check the brakes 
    }
    
    if (check==1){
        //Back to task 1
        task1();
        
    }else{
        //at the end jump to  or 4
        task4();
    }
        
 
    return ;
}

int task4(){
    //output to the braking system
    
}


int main(void)
{
    task1();
    
  
    return RT_EOK;
}
