#include <rtthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtdevice.h>

struct rt_thread Alert;
static char Alert_stack[256];
#define BEEP_PIN 5

static void Alert_entry(void* parameter)
{while(1){
   err= rt_mb_recv(&target,x, RT_WAITING_FOREVER);
   if (x=10){
       rt_enter_critical();
       LOG_D("Alert happened!");
    rt_pin_mode(BEEP_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(BEEP_PIN, PIN_HIGH);
    rt_mb_send(&target1, 10);
    x=0;
    rt_exit_critical();
    }}}
