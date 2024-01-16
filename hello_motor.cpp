/*
hello_motor is a program to learn to use a L298N dual
H Bridge motor driver with the PIGPIO library for the Raspberry Pi.
This program is an accompaniment to the book Practical Robotics in C++
written by Lloyd Brombach and published by Packt Publishing
*/


#include <iostream>
#include <pigpiod_if2.h>


//left motor
const int PWM_L = 21;
const int MOTOR_L_FWD = 26;
const int MOTOR_L_REV = 13;

//right motor
const int PWM_R = 12;
const int MOTOR_R_FWD = 20;
const int MOTOR_R_REV = 19;

//handshakes with Pigpio Daemon and sets up our pins.
int pigpio_setup()
{
    char *addrStr = NULL;
    char *portStr = NULL;
    const int pi = pigpio_start(addrStr, portStr);

    //next four lines sets up our pins. Remember that high is "off"
    //and we must drive in1 or in2 low to start the output to motor
    set_mode(pi,PWM_L, PI_OUTPUT);
    set_mode(pi,MOTOR_L_FWD, PI_OUTPUT);
    set_mode(pi,MOTOR_L_REV, PI_OUTPUT);

    set_mode(pi,PWM_R, PI_OUTPUT);
    set_mode(pi,MOTOR_R_FWD, PI_OUTPUT);
    set_mode(pi,MOTOR_R_REV, PI_OUTPUT);

    //initializes motor off
    gpio_write(pi, MOTOR_L_FWD, 1);
    gpio_write(pi, MOTOR_L_REV, 1);
    gpio_write(pi, MOTOR_R_FWD, 1);
    gpio_write(pi, MOTOR_R_REV, 1);

    return pi;
}

using namespace std;

int main()
{
    int pi = pigpio_setup();
    if(pi < 0)
    {
        cout<<"Failed to connect to Pigpio Daemon. Is it running?"<<endl;
        return -1;
    }


    //when you're ready to start the motors
    gpio_write(pi, MOTOR_L_FWD, 0);
    gpio_write(pi, MOTOR_R_FWD, 0);

    // starts a PWM signal to motors enable at half speed
    set_PWM_dutycycle(pi, PWM_L, 127);
    set_PWM_dutycycle(pi, PWM_R, 127);
    time_sleep(3); //3 second delay
    //starts motors at full speed
    set_PWM_dutycycle(pi, PWM_L, 255);
    set_PWM_dutycycle(pi, PWM_R, 255);
    time_sleep(3);

    //stops the motors
    gpio_write(pi, MOTOR_L_FWD, 1);
    gpio_write(pi, MOTOR_R_FWD, 1);
    time_sleep(1);
    //repeats in reverse
    gpio_write(pi, MOTOR_L_REV, 0);
    set_PWM_dutycycle(pi, PWM_L, 127);
    gpio_write(pi, MOTOR_R_REV, 0);
    set_PWM_dutycycle(pi, PWM_R, 127);
    time_sleep(3);
    set_PWM_dutycycle(pi, PWM_L, 255);
    set_PWM_dutycycle(pi, PWM_R, 255);
    time_sleep(3);
    gpio_write(pi, MOTOR_L_REV, 1);
    gpio_write(pi, MOTOR_R_REV, 1);

    pigpio_stop(pi);
    return 0;
}
