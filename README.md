# Collision Detection Device based on RT-Thread 

The objective of this project is to develop a software for a STM32f413 board that detects incoming obstacke using sensors and sending instructions to propulsion device to slow down or using the braking system to prevent a collision. 
The expected simulated inputs are speed, break signal and distance, and the outputs correspond to Warning alerts and automatic breaking. 

# Sytem description
The system shall constantly monitor the values from the sensors and comparing it with the reference of the safe distance according to the car speed (m/s). In case of potencial collision, a message will be sent to the driver. If the driver presses the brakes in the period of 0.8 sec the system automatically presses the breaking system. 
The sensors are simulated by using random function with random distances, in the beginning a laser and detection sensor is initialized but values are simulated.
# Implemented threads
There are 3 direct threads and a function linked to a timer.
(Thread 1 - LIDAR Intialisation) For the first Thread we added a periodic thread creation functionality into the base rt-os system. As this thread is continously run untill an event occurs. This thread begins by sending a laser for a one pluse and then a detection sensor is used to detect how much time it took for laser to reach back. Then according to this time a safe distance between two cars is calculated and compared with the distance that car will go if stopped at that moment. If the distance is less than safe distance a alert thread is started.
(Thread -2 Alert System) This a infinte loop thread that waits for message fronm first periodic thread 
# Diagram Flow

# Code specs

# Pressuring the system

In order to pressure the system, the implementation of new sensors was made. The sensors, as described before, are simulated by the reading of a file. Each sensor has a different file making the system to open and close the files consecutively. The number of simulated sensors varies, but the simulated ones correspond to X AND Y.
