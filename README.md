# Collision Detection Device based on RT-Thread 

The objective of this project is to develop a software for a STM32f413 board that detects incoming obstacke using sensors and sending instructions to propulsion device to slow down or using the braking system to prevent a collision. 
The expected simulated inputs are speed, break signal and distance, and the outputs correspond to Warning alerts and automatic breaking. 

# Sytem description
The system shall constantly monitor the values from the sensors and comparing it with the reference of the safe distance according to the car speed (m/s). In case of potencial collision, a message will be sent to the driver. If the driver presses the brakes in the period of 0.8 sec the system automatically presses the breaking system. 
The sensors are simulated by reading a file with random distances, in the beginning 4 sensors are simulated and then increased in order to pressure the system as proposed by the professor of this couse. 

# Implemented threads

# Diagram Flow

# Code specs

# Pressuring the system

In order to pressure the system, the implementation of new sensors was made. The sensors, as described before, are simulated by the reading of a file. Each sensor has a different file making the system to open and close the files consecutively. The number of simulated sensors varies, but the simulated ones correspond to X AND Y.
