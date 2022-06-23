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
#include "AlertThread.c"
#include "SensorInit.c"
#include "main.h"
#include "BrakeSystem.c"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

static void PeriodicInit_entry(void* parameter){
    periodic_t= rt_thread_create_periodic("t1",SensorInitiation_entry, RT_NULL, sizeof(SensorInit_stack),1, 10,100);
    rt_thread_startup(periodic_t);

}

int main(void)
{
    rt_thread_t get_cpu_use_thread = RT_NULL;
    get_cpu_use_thread = cpu_thread_init(get_cpu_use_thread);
  //  cpu_thread_start(get_cpu_use_thread);
        LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
                            /*timer*/

           BrakeTimeout = rt_timer_create("BrakeTimeout", timeout1,
                                        RT_NULL, 10,
                                        RT_TIMER_FLAG_PERIODIC);
                                    /* Initializing and starting the threads*/
           rt_thread_init(&BrakeWait,"t3",BrakeWait_entry, RT_NULL,&BrakeWait_stack[0], sizeof(BrakeWait_stack),THREAD_PRIORITY + 3, THREAD_TIMESLICE);
               LOG_D("BreakSense Intialised!");
           rt_thread_init(&Alert,"t2",Alert_entry, RT_NULL,&Alert_stack[0], sizeof(Alert_stack),THREAD_PRIORITY + 2, THREAD_TIMESLICE);
           LOG_D("Alert Sytem!");
           rt_thread_init(&PeriodicInit,"t4",PeriodicInit_entry, RT_NULL,&PeriodicInit_stack[0], sizeof(Alert_stack),THREAD_PRIORITY + 2, THREAD_TIMESLICE);
                                           /* Initialize a mailbox */
           rt_err_t result;
                   result = rt_mb_init(&target,
                             "mbt",                      /* Name is mbt */
                             &mb_pool[0],                /* The memory pool used by the mailbox is mb_pool */
                             sizeof(mb_pool) / 4,        /* The number of messages in the mailbox because a message occupies 4 bytes */
                             RT_IPC_FLAG_FIFO);          /* Thread waiting in FIFO approach */

                   rt_mb_init(&target1,
                                                "mbt1",                      /* Name is mbt */
                                                &mb_pool1[0],                /* The memory pool used by the mailbox is mb_pool */
                                                sizeof(mb_pool) / 4,        /* The number of messages in the mailbox because a message occupies 4 bytes */
                                                RT_IPC_FLAG_FIFO);          /* Thread waiting in FIFO approach */

/*  StartUp System */
                   rt_thread_startup(&BrakeWait);
                   rt_thread_startup(&Alert);
         rt_thread_startup(&PeriodicInit);
                     return RT_EOK;
}
