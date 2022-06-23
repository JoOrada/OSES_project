#include <rtthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "cpuusage.h"

static void get_cpu_use_thread_entry(void* parameter)
{
    rt_uint8_t major,minor;

    cpu_usage_get(&major,&minor);

    rt_kprintf("CPU Utilization = %d.%d%\n",major,minor);

}

rt_thread_t cpu_thread_init(rt_thread_t get_cpu_use_thread)
{
    get_cpu_use_thread = rt_thread_create_periodic("get_cpu_thread",
                                                   get_cpu_use_thread_entry,
                                                   RT_NULL,
                                                   512,
                                                   1,
                                                   1,
                                                   100);

    return get_cpu_use_thread;

}

rt_err_t cpu_thread_start(rt_thread_t get_cpu_use_thread)
{
    rt_err_t err;
    cpu_usage_init();
    err = rt_thread_startup(get_cpu_use_thread);
    if (err)
        return err;
    return 1;
}
