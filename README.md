# Collision Detection Device based on RT-Thread 

The objective of this project is to develop a software for a STM32F401Cb board that detects incoming obstacke using sensors and sending instructions to propulsion device to slow down or using the braking system to prevent a collision. 
The expected simulated inputs are speed, break signal and LIDAR Time, and the outputs correspond to Warning alerts and automatic breaking. 

# Sytem description
The system shall constantly monitor the values from the sensors and comparing it with the reference of the safe distance according to the car speed (m/s). In case of potencial collision, a message will be sent to the driver. If the driver do not presses the brakes in the period of 0.7 sec the system automatically presses the breaking system. 
The sensors are simulated by using random function with random distances, in the beginning a laser and detection sensor is initialized but values are simulated.
# Implemented threads

There are 3 direct threads and a function linked to a timer.

(Thread 1) LIDAR Intialisation- For the first Thread we added a periodic thread creation functionality into the base rt-os system. As this thread is continously run untill an event occurs. This thread begins by sending a laser for a one pluse and then a detection sensor is used to detect how much time it took for laser to reach back. Then according to this time a safe distance between two cars is calculated and compared with the distance that car will go if stopped at that moment. If the distance is less than safe distance a alert thread is started.

(Thread 2) Alert System - This a infinte loop thread that waits for message from first periodic thread. When a message is recevied it sends a beep signal as alert to the driver inside the car and sendes a message to activate next thread i.e. BreakSystem

(Thread 3) Break System - This is also an infinte loop that waits for a message from alert thread. When message is recevied it initialise a timer for 0.7 secs. It starts to receive breaking signal from the car and waits for it until break is applied or timer runout.

Timer Runout (Breaktimeout)- When timer runs out and break is not applied by the driver then break is automatically applied by the system and normal system working is resumed.
# Diagram Flow
![SS 2022-07-12 at 6 43PM 1](https://user-images.githubusercontent.com/80212336/178583944-07aba20c-5951-4d1f-af94-ddfc225d0e01.jpg)
![SS 2022-07-12 at 7 04PM 2](https://user-images.githubusercontent.com/80212336/178583969-81819321-e43b-4fd1-8810-152121d40b75.jpg)

# Pressuring the system

System is utilized till 96.7% at peak due to number of threads running at same time and heavy calculation for distance and comparison. To further pressure the system multiple LIDAR sensors can be incorporated to detect distance in different directions and at different angles for better accuracy.
