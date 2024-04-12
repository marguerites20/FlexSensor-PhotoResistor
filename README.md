# FlexSensor-PhotoResistor

This project interfaces both a Flex Sensor and a Photoresistor on the Arduino Uno, using C programming. Both Arduino IDE and C code are included for the interfaces.

---

## Flex Sensor

**Introduction:**  
Flex sensors are flexible devices that change resistance based on the amount of bending they experience. They typically consist of a layer of conductive ink deposited on a flexible substrate. As the sensor bends, the conductive particles within the ink separate, increasing the resistance along the sensor's length. This change in resistance can be measured and used to determine the degree of bending.

**Datasheet:**  
- [Flex Sensor Datasheet](https://www.sparkfun.com/datasheets/Sensors/Flex/flex22.pdf)  
![Flex Sensor](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/810422f2-584c-49a0-aa4f-f394cb02c3e5)

Flex sensors have a layer of conductive ink on one side, and as the sensor bends, the particles separate, increasing the resistance.

- Flat Resistance: 25 kΩ
- Max Bend Resistance: 125 kΩ
- Cost: $10.80/unit

![Flex Sensor Image](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/68bdbe76-3e5a-489e-87c5-1f6c567287f9)

**Potential Applications:**
- Prosthetics
- Robotics
- VR equipment

**Interface Diagram:**
![Flex Sensor Interface Diagram](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/831caffc-bcc0-4ec1-bcfd-e73711961660)

### DEMO
[Flex Sensor Demo](https://youtube.com/shorts/1NMFAQ1FsDk)  
This demo shows the flex sensor bending, and the LED decreasing in brightness to increasing degrees of bend.

**Why Macros Were Not Used:**  
In the `FlexSensor.c` code, macros from the `IO_Macros.h` file were not used for interfacing the Flex Sensor due to compatibility issues or conflicts with existing code or macros. Instead, direct register manipulation and bit masking were utilized to configure pin directions and read analog values. While macros can provide abstraction and improve code readability, in this case, relying on direct register manipulation offered better compatibility with the existing codebase and avoided potential conflicts with other macros or configurations.

---

## Photoresistor

**Introduction:**  
Photoresistors, also known as light-dependent resistors (LDRs), are devices whose resistance changes in response to light intensity. They consist of a semiconductive material that becomes more conductive when exposed to light and less conductive in darkness. This change in conductivity alters the resistance of the material, which can be measured and used for various applications.

**Datasheet:**  
- [Photoresistor Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/LightImaging/SEN-09088.pdf)  
![Photoresistor](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/7463fe23-b0e6-4b47-b8d1-0c6859656632)

Photoresistors have a semiconductive surface. Electrons start to move when light is shone on the material, changing the conductivity and then the resistance.

- Light Resistance: 8-20 kΩ
- Dark Resistance: 1 MΩ
- Cost: $1.10/unit

![Photoresistor Image](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/a537ebcd-1bd4-4c1e-a473-658043cf4d55)

**Potential Applications:**
- Solar Panels
- Street Lights
- Smartphone screens

**Interface Diagram:**
![Photoresistor Interface Diagram](https://github.com/marguerites20/FlexSensor-PhotoResistor/assets/93600413/59f05fc5-91e5-464a-afca-02a69c76bfc6)

### DEMO
[Photoresistor Demo](https://www.youtube.com/shorts/9hsHc4YJ9Aw)  
This demo shows the LED turning off when the photocell detects little or no light, and the LED turning on when the photocell senses ambient light.

The challenge of this project was to interface the photocell in C. In the `Photocell.C` code, macros were used to abstract pin configurations and register manipulations, enhancing code readability and maintainability. By defining macros such as `PinMode`, `DigitalWrite`, and `DigitalRead`, the code becomes more expressive and closely resembles the syntax used in popular development platforms like the Arduino IDE. This abstraction hides the complexities of direct AVR register manipulation, making it easier for developers to understand and modify the code. Additionally, macros provide a centralized location to manage pin configurations, reducing the risk of errors and inconsistencies. However, the use of macros can introduce overhead and complexity, especially in larger projects with many macros. Macros may also require additional documentation to explain their purpose and usage. Despite these drawbacks, the benefits of improved code readability and maintainability often outweigh the cons, making macros a valuable tool in embedded systems development.


 
