# elsa

Elsa was our first foray into the realm of electronics. Prior to this, the car had little to no electrical systems, with the most advanced electrics being a horn. With Elsa, we experiemented with a host of new systems:

- Steer by wire
- Engine temperature sensing
- Basic LED display
- Basic user input
- Electric start

These systems were put together in a very short amount of time, and the degree to which they were completed was impressive given the time contstraints. Detailed descriptions follow below, but in short all systems achieved some level of success, with several of them working flawlessly

Elsa's code is very simple, and more hacked together than a product of good design. Nonetheless, she serves as a good starting point and a solid foundation from which to build going forward. Her steer-by-wire and temperature system will be used and improved in Lux, and hopefully in all our cars to follow. 

# Steer by wire

With Elsa we decided to completely remove the steering column and use an electronic steer-by-wire system to control the car. This system consisted of a quadrature encoder, whose rotation was then communicated to two high-powered servos which moved a rack and pinion to steer the car. The quadrature encoder and servos were controlled via an Arduino Nano with an ATmega 328P microcontrooler running the Arduino bootloader. 

Steer-by-wire worked well from a code standpoint, but unfortunately the servos that were used burnt out at competition. Limited trials were completed before the servos burnt out, and all trials were successful.

# Engine temperature

Elsa's engine temperature was measured using a thermistor stuck on the engine. The variable-resistance values coming from the thermistor were read and interpreted on the same Arduino Nano used for the steer-by-wire system. To change the thermistor values to a readable temperature scale, we used the Steinhart-Hart equation.

# LED Display and user input

Elsa displayed information on a very rough 'screen' of 10 LEDs. These LEDs either showed the current steering angle, or upon a button press from the user, switched to a thermometor display which read the values from the thermistor. 

Since the steer-by-wire system would take the starting position of the quadrature encoder as its zero-position, another button enabled the driver to zero the steering at whatever neutral position they desired. 

