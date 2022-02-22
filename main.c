int main()
/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *

 */

// Including Required Libraries and Preprocessors
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* Timer Control Block */
static rt_timer_t timer1;
static int cnt = 0;

#define Ultrasonicsensor_PIN 0
#define EchoR_PIN 1
#define Speed_PIN 2
#define Brake_PIN 2
#define BEEP_PIN 3
rt_int16_t Safe;
    rt_int16_t distance;
    rt_int16_t Sensor_return = 0;
    rt_int16_t Getspeed = 0;

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#define Sensor               GET_PIN(C, 0)
#include <rtdbg.h>
// Creating Structures for Threads
struct rt_thread thread1;
struct rt_thread thread2;
struct rt_thread thread3;
struct rt_thread thread4;
#define THREAD_TIMESLICE        5
#define THREAD_PRIORITY         25
static char thread1_stack[64];
static char thread2_stack[64];
static char thread3_stack[64];
static char thread4_stack[64];
static rt_uint32_t data = 1;
rt_uint32_t val;

// Thread defenitions

static void thread3_entry(void* parameter)
{
    if (timer1 != RT_NULL) rt_timer_start(timer1);

    rt_pin_mode(Sensor, PIN_MODE_INPUT);

    if (Sensor== 1)
    {
        rt_thread_startup(&thread1);
        rt_timer_stop(timer1);
        }
    }



static void thread1_entry(void* parameter)
{
    rt_pin_mode(Ultrasonicsensor_PIN, PIN_MODE_OUTPUT);
       rt_pin_mode(EchoR_PIN, PIN_MODE_INPUT);
       rt_pin_write(Ultrasonicsensor_PIN, PIN_HIGH);
       rt_thread_mdelay(8);
       rt_pin_write(Ultrasonicsensor_PIN, PIN_LOW);
       Sensor_return =rt_pin_read(EchoR_PIN);

                          Getspeed= rt_pin_read(Speed_PIN);
                          Safe= Getspeed*(Getspeed/6+1.1);
                          distance= Sensor_return*0.034/2;
     if (distance<=Safe) {
         rt_thread_startup(&thread2);


    }
}

static void thread2_entry(void* parameter)
{
    rt_pin_mode(BEEP_PIN, PIN_MODE_OUTPUT);

    rt_pin_write(BEEP_PIN, PIN_HIGH);

    rt_thread_startup(&thread3);

    }



static void thread4_entry(void* parameter)
{
    rt_pin_mode(Brake_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(Brake_PIN, PIN_HIGH);
    rt_thread_startup(&thread1);
}

// Setting thread Priority

//static void _tc_cleanup()
{
    /* lock scheduler */
    rt_enter_critical();

    if (thread1.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread1);
    if (thread2.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread2);
    if (thread3.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread3);

    /* unlock scheduler */
    rt_exit_critical();
}


static void timeout1(void *parameter)
{
    rt_thread_startup(&thread4);
}



int main(void)
{
    //timer
    timer1 = rt_timer_create("timer1", timeout1,
                                RT_NULL, 70,
                                RT_TIMER_FLAG_PERIODIC);

    // Initializing and starting the threads
    rt_thread_init(&thread3,"t3",thread3_entry, RT_NULL,&thread3_stack[0], sizeof(thread3_stack),THREAD_PRIORITY + 2, THREAD_TIMESLICE);

    rt_thread_init(&thread2,"t2",thread2_entry, RT_NULL,&thread2_stack[0], sizeof(thread2_stack),THREAD_PRIORITY + 1, THREAD_TIMESLICE);

       rt_thread_init(&thread4,"t4",thread4_entry, RT_NULL,&thread4_stack[0], sizeof(thread3_stack),THREAD_PRIORITY + 3, THREAD_TIMESLICE);

       rt_thread_init(&thread1,"t1",thread1_entry, RT_NULL,&thread1_stack[0], sizeof(thread1_stack),THREAD_PRIORITY - 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread1);


    return 0;
}
