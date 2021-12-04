/****************************************************************
 * 
 * @file      motor_controller_msgs.h
 * 
 * @brief     messages send by motor controller
 * 
 * @version   1.0
 * @date   		12/4/2021
 * 
 * @authors 	Michael Lang
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

#ifndef _motor_controller_msgs_h
#define _motor_controller_msgs_h

typedef struct {
    volatile int32_t motor_hall_sensor;        // the ticks from hall sensor
    volatile int32_t motor_desired_velocity;   // The commanded velocity
    volatile int32_t motor_actual_velocity;    // The actual velocity
    volatile int32_t motor_pwm;                // The motor pwm duty cycle
    volatile int32_t motor_current;            // The current drawn by the motor
    volatile int32_t motor_p_gain;               // The P gain of the motor scaled
    volatile int32_t motor_i_gain;               // The I gain of the motor scaled
    volatile int32_t motor_d_gain;               // The D gain of the motor scaled
    volatile uint8_t motor_brake;              // The brake status of the motor
    uint8_t _padding[3];
} motor_health_msg_t;

typedef struct{
    motor_health_msg_t motors[5];
}motor_health_msg_all_t;



#endif /* _motor_controller_msgs_h */
