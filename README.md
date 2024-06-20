# Dual-Microcontroller-Image-Display-System-with-Bootloader
## <code style="color : red">Introduction</code> 
- The primary objective of this project is to display an image on a TFT screen using two microcontrollers. The first microcontroller contains the application, which runs the code and controls the overall functionality of the system. The second microcontroller contains the bootloader, which is responsible for loading new firmware onto the application microcontroller. 
- The TFT screen is connected to the bootloader microcontroller and is responsible for displaying the image. The communication between the two microcontrollers is established through a serial connection.

 
 ## <code style="color : red">Working Principle</code>
- The two microcontrollers work together to display the image on the TFT screen. The application microcontroller contains the code that controls the overall functionality of the system.
- The bootloader microcontroller is responsible for loading new firmware onto the application microcontroller. The TFT screen is connected to the bootloader microcontroller and is responsible for displaying the image.
- The communication between the two microcontrollers is established through a serial connection. The application microcontroller sends a request to the bootloader microcontroller to load new firmware, if necessary, and then sends the image data to be displayed on the TFT screen.
- The bootloader microcontroller receives the request, loads the new firmware onto the application microcontroller, and then sends the image data to the TFT screen.

 ## <code style="color : red">Hardware Components</code>
The following hardware components are required for this project:
1.	Two microcontrollers - one for the application and the other for the bootloader.
2.	A TFT screen.
3.	Serial communication interface - UART or SPI.
4.	Power supply - 5V DC.
 ## <code style="color : red">Documents</code>
 - [00- STM32f401CC Specifications.pdf](https://github.com/user-attachments/files/15908707/00-.STM32f401CC.Specifications.pdf)
 - [01- ST M4 Programming Manual.pdf](https://github.com/user-attachments/files/15908709/01-.ST.M4.Programming.Manual.pdf)
 - [02- Register Description.pdf](https://github.com/user-attachments/files/15908717/02-.Register.Description.pdf)
  ## <code style="color : red">Simulation</code> 
  

