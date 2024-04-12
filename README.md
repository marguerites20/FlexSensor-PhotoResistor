# FlexSensor-PhotoResistor

This project interfaces both a Flex Sensor and a Photoresistor on the Arduino Uno, using C programming. Both Arduino IDE and C code are included for the interfaces.

---

## Flex Sensor

### Introduction
Flex sensors are flexible devices capable of changing resistance in response to bending. Typically composed of a conductive ink layer on a flexible substrate, these sensors exhibit increased resistance as they bend.

### Datasheet
- [Flex Sensor Datasheet](https://www.sparkfun.com/datasheets/Sensors/Flex/flex22.pdf)  

![Flex Sensor](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/810422f2-584c-49a0-aa4f-f394cb02c3e5)

- Flat Resistance: 25 kΩ
- Max Bend Resistance: 125 kΩ
- Price: $10.80/unit

![Flex Sensor Image](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/68bdbe76-3e5a-489e-87c5-1f6c567287f9)

### Potential Applications
- Prosthetics
- Robotics
- VR equipment

### Components
- Flex Sensor
- LED
- Wires
- Arduino Uno R3
- Resistors

### Interface Diagram
![Flex Sensor Interface Diagram](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/831caffc-bcc0-4ec1-bcfd-e73711961660)

#### DEMO
[Flex Sensor Demo](https://youtube.com/shorts/1NMFAQ1FsDk)  
This demo showcases the LED decreasing in brightness in response to increasing degrees of bend of the flex sensor.

### Why Macros Were Not Used
In the `FlexSensor.c` code, macros from the `IO_Macros.h` file were not utilized for interfacing the Flex Sensor due to compatibility issues or conflicts with existing code or macros. Direct register manipulation and bit masking were instead employed to configure pin directions and read analog values. While macros can enhance code readability, in this instance, relying on direct register manipulation provided better compatibility with the existing codebase and avoided potential conflicts.

---

## Photoresistor

### Introduction
Photoresistors, or light-dependent resistors (LDRs), exhibit changes in resistance based on light intensity. Composed of a semiconductive material, these resistors become more conductive when exposed to light and less conductive in darkness.

### Components
- Photoresistor
- LED
- Wires
- Arduino Uno R3
- Resistors

### Datasheet
- [Photoresistor Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/LightImaging/SEN-09088.pdf)  

![Photoresistor](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/7463fe23-b0e6-4b47-b8d1-0c6859656632)

- Light Resistance: 8-20 kΩ
- Dark Resistance: 1 MΩ
- Price: $1.10/unit

![Photoresistor Image](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/a537ebcd-1bd4-4c1e-a473-658043cf4d55)

### Potential Applications
- Solar Panels
- Street Lights
- Smartphone screens

### Interface Diagram
![Photoresistor Interface Diagram](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/59f05fc5-91e5-464a-afca-02a69c76bfc6)

#### DEMO
[Photoresistor Demo](https://www.youtube.com/shorts/9hsHc4YJ9Aw)  
This demo illustrates the LED turning off when the photocell detects very little or no light, and the LED turning on when the photocell senses ambient light.

---

## Installation Instructions with AVR Toolchain

To compile and upload the programs to your AVR microcontroller, you'll need to set up the AVR toolchain on your system. Follow the steps below to download and install the necessary software:

1. **Download AVRDUDE:**
   - Visit the following link: [AVR-GCC Toolchain Installation Guide](https://tinusaur.com/guides/avr-gcc-toolchain/)
   - Follow the instructions provided to download and install AVRDUDE on your system. It's recommended to use a Windows system for ease of use.

2. **Verify Installation:**
   - Once the installation is complete, open your command prompt.
   - Type the following commands to check if you have installed the software correctly:
     ```
     avr-gcc -v
     avrdude -v
     avr-objcopy -V
     ```

### Compilation Process

Follow these steps to compile and upload the programs to your AVR microcontroller:

1. **Navigate to Source Code Directory:**
   - Change the directory in your command prompt to where you have downloaded the source code files.

2. **Identify COM Port:**
   - Check the COM port on which your Arduino is programmed. Make a note of this port number.

3. **Compile Source Code:**
   - Type the following command to compile the source code:
     ```
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o photocell.o photocell.c
     ```

4. **Link Object Files:**
   - Type the following command to link the object files:
     ```
     c:\avr-gcc-11.1.0\bin\avr-gcc.exe -mmcu=atmega328p photocell.o -o photocell
     ```

5. **Create HEX File:**
   - Type the following command to create the HEX file:
     ```
     c:\avr-gcc-11.1.0\bin\avr-objcopy.exe -O ihex -R .eeprom photocell photocell.hex
     ```

