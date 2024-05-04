# Vehicle Control System

#### This C programming project implements a Vehicle Control System that allows users to interact with vehicle functionalities such as engine control, sensor simulation, and environmental control. The system provides a user-friendly interface through the console where users can select options to turn on/off the vehicle engine, simulate sensor readings, and manage vehicle parameters.

## Features:

1. **User Interaction Menu:**
    - Users are presented with a menu allowing them to choose between turning on the vehicle engine, turning off the engine, or quitting the system.

2. **Engine Control:**
    - Users can turn the vehicle engine on or off. When the engine is on, the system continuously displays a sensor simulation menu.

3. **Sensor Simulation Menu:**
    - When the engine is turned on, users are presented with a menu to simulate sensor readings including traffic light color, room temperature, and engine temperature.

4. **Traffic Light Sensor:**
    - Based on the simulated traffic light color, the system adjusts the vehicle speed accordingly (Green: 100 km/hr, Orange: 30 km/hr, Red: 0 km/hr).

5. **Room Temperature Sensor:**
    - The system adjusts the air conditioning (AC) based on the simulated room temperature. If the temperature is below 10°C or above 30°C, the AC is turned on and set to 20°C.

6. **Engine Temperature Sensor:**
    - The system adjusts the engine temperature controller based on the simulated engine temperature. If the temperature is below 100°C or above 150°C, the controller is turned on and set to 125°C.

7. **Dynamic Control Adjustments:**
    - The system dynamically adjusts AC and engine temperature controller settings based on vehicle speed and sensor readings.

8. **Display System State:**
    - After each adjustment, the system displays the current vehicle state including engine status, AC status, vehicle speed, room temperature, engine temperature controller state, and engine temperature.

9. **Bonus Requirement:**
    - The project includes a bonus requirement to compile/run specific code related to the engine temperature controller based on a preprocessor directive.

## Implementation:

- The project is implemented in C programming language.
- User interaction is facilitated through the console using printf and scanf functions.
- Conditional statements are utilized to handle user choices and adjust system parameters based on sensor readings.
- Preprocessor directives are employed to selectively compile/run code related to the engine temperature controller based on the bonus requirement.

## Usage:

- Users can clone the repository and compile the source code using a C compiler.
- The executable can be run in a console environment to interact with the Vehicle Control System.

## Contributing:

- Contributors are welcome to suggest improvements, report issues, and submit pull requests to enhance the functionality and usability of the Vehicle Control System.

## License:

- This project is licensed under the [MIT License](https://opensource.org/licenses/MIT), allowing for modification, distribution, and commercial use with proper attribution.
