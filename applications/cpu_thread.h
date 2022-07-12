#ifndef __CPU_THREAD_H_
#define __CPU_THREAD_H_

#include <rtdef.h>
#include "cpuusage.h"

rt_thread_t cpu_thread_init(rt_thread_t get_cpu_use_thread);
rt_err_t cpu_thread_start(rt_thread_t get_cpu_use_thread);


#endif
