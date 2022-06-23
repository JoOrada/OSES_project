/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-02-23     RT-Thread    first version
 */

#include <rtthread.h>
#include "cpu_thread.h"


/* Mailbox control block */
static struct rt_mailbox target;
/* Memory pool for mails storage */
static char mb_pool[128];


#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
//#include "tc_comm.h"

/* Timer Control Block */
static rt_timer_t timer1;
#define Ultrasonicsensor_PIN 0
#define EchoR_PIN 1
#define Speed_PIN 3
#define Brake_PIN 4
#define BEEP_PIN 5
rt_int16_t Safe;
    rt_int16_t distance;
    rt_int16_t Sensor_return = 100;
    rt_int16_t Getspeed = 0;
    int16_t z;


#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#define Sensor_PIN 6
#include <rtdbg.h>
// Creating Structures for Threads
struct rt_thread thread2;
struct rt_thread thread3;
struct rt_thread thread4;

rt_thread_t periodic_t;

struct rt_thread thread5;
#define THREAD_TIMESLICE        10
#define THREAD_PRIORITY         5
static char thread2_stack[256];
static char thread4_stack[1024];

static char thread3_stack[256];
static char thread5_stack[512];
rt_err_t err;
rt_uint32_t stro = 0;
rt_uint32_t v = 1;


static void thread5_entry(void* parameter)
{ LOG_D("Hello! thread5 starts");
        LOG_D("Hello! thread5 starts");
        rt_pin_mode(Ultrasonicsensor_PIN, PIN_MODE_OUTPUT);
        LOG_D("Hello! thread5 starts");
         rt_pin_mode(EchoR_PIN, PIN_MODE_INPUT);
         LOG_D("Hello! thread5 starts");
        rt_pin_write(Ultrasonicsensor_PIN, PIN_HIGH);
        LOG_D("Hello! thread5 starts");
        rt_thread_mdelay(8);
        rt_pin_write(Ultrasonicsensor_PIN, PIN_LOW);
        LOG_D("Hello! thread5 starts");

                          Getspeed= 20;
                          Safe= Getspeed*(Getspeed/6+1.1);
                          distance= Sensor_return*0.034/2;
                          LOG_D("Hello! thread5 starts");

     if (distance<=Safe) {

             rt_mb_send(&target,v);}
     }


static void thread4_entry(void* parameter){
    periodic_t= rt_thread_create_periodic("t6",thread5_entry, RT_NULL, sizeof(thread5_stack),1, 10,100);
    rt_thread_startup(periodic_t);

}


static void thread3_entry(void* parameter)
{
    while(1){
 // err= rt_mb_recv(&target,str0 , RT_WAITING_FOREVER);

       if (err){

                if (timer1!= RT_NULL) { rt_timer_start(timer1);}
                    rt_pin_mode(Sensor_PIN, PIN_MODE_INPUT);
                    z= 0;

                        rt_timer_stop(timer1);
                        rt_thread_resume(&thread5);
                    }


    }}


static void thread2_entry(void* parameter)
{while(1){
    err= rt_mb_recv(&target,stro , RT_WAITING_FOREVER);
    if (err) {
    LOG_D("Thread2 starts!");
rt_thread_mdelay(1000);
    rt_pin_mode(BEEP_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(BEEP_PIN, PIN_HIGH);
    rt_mb_send(&target, 1);
   }

    }}

static void timeout1(void* parameter)
       {
    LOG_D("Breaking!");
    rt_pin_mode(Brake_PIN, PIN_MODE_OUTPUT);
       rt_pin_write(Brake_PIN, PIN_HIGH);
       rt_thread_resume(&thread5);
    }

int main(void)
{


    rt_thread_t get_cpu_use_thread = RT_NULL;
    get_cpu_use_thread = cpu_thread_init(get_cpu_use_thread);
    cpu_thread_start(get_cpu_use_thread);

        LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
        //timer
           timer1 = rt_timer_create("timer1", timeout1,
                                       RT_NULL, 10,
                                       RT_TIMER_FLAG_PERIODIC);

    // Initializing and starting the threads
       rt_thread_init(&thread3,"t3",thread3_entry, RT_NULL,&thread3_stack[0], sizeof(thread3_stack),THREAD_PRIORITY + 3, THREAD_TIMESLICE);
       LOG_D("Hello RT-Thread!");
             rt_thread_mdelay(1000);

       rt_thread_init(&thread2,"t2",thread2_entry, RT_NULL,&thread2_stack[0], sizeof(thread2_stack),THREAD_PRIORITY + 2, THREAD_TIMESLICE);
       LOG_D("Hello RT-Thread65456!");
       rt_thread_init(&thread4,"t4",thread4_entry, RT_NULL,&thread4_stack[0], sizeof(thread2_stack),THREAD_PRIORITY + 2, THREAD_TIMESLICE);


         rt_err_t result;

         /* Initialize a mailbox */
         result = rt_mb_init(&target,
                             "mbt",                      /* Name is mbt */
                             &mb_pool[0],                /* The memory pool used by the mailbox is mb_pool */
                             sizeof(mb_pool) / 4,        /* The number of messages in the mailbox because a message occupies 4 bytes */
                             RT_IPC_FLAG_FIFO);          /* Thread waiting in FIFO approach */


rt_thread_startup(&thread4);
    LOG_D("Hello!Thread5");
    return RT_EOK;
}
