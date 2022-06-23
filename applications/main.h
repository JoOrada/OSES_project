#define THREAD_TIMESLICE        10
#define THREAD_PRIORITY         5
#define Speed_PIN 3
#define Brake_PIN 4
#define Laser_pin 0
#define Detect_pin 1
#define Sensor_PIN 6

/* Mailbox control block */
static struct rt_mailbox target1;
static struct rt_mailbox target;
/* Memory pool for mails storage */
static char mb_pool[128];
static char mb_pool1[128];
rt_err_t err;
rt_err_t err2;
rt_ubase_t x;
rt_int16_t Safe;
    rt_int16_t distance;
    rt_int16_t Sensor_return;
    rt_int16_t Getspeed ;
    static rt_timer_t BrakeTimeout;
        int16_t z;
        // Creating Structures for Threads
        struct rt_thread BrakeWait;
        struct rt_thread PeriodicInit;
        rt_ubase_t y;
        rt_thread_t periodic_t;
        struct rt_thread SensorInit;
        static char PeriodicInit_stack[1024];
        static char BrakeWait_stack[256];
        rt_err_t err;
