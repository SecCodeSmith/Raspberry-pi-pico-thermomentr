# Raspberry Pi Pico Thermometer

This project demonstrates how to build a thermometer using the Raspberry Pi Pico microcontroller and LM35 temperature sensors. It displays temperature readings on a 16x2 LCD and uses LEDs to indicate temperature ranges. This was my first project using the Raspberry Pi Pico with the C++ SDK.

## Features

- **Temperature Measurement**: Utilizes two LM35 temperature sensors to measure ambient temperature.
- **Visual Display**: Shows temperature readings on a 16x2 LCD screen.
- **LED Indicators**: Five LEDs provide visual cues for different temperature ranges.

## Components Required

- **Raspberry Pi Pico**
- **5 LEDs**
- **Resistors**: 1.5kΩ and 0.1Ω
- **16x2 LCD Display** (JUS-19732)
- **2 LM35DZ NS Temperature Sensors**
- **Connecting Wires**

## Circuit Layout

The project involves connecting the LM35 sensors and LEDs to the Raspberry Pi Pico, and interfacing the LCD display via I2C.

### Display Connection

The 16x2 LCD is connected to the Raspberry Pi Pico using I2C communication.

## Software Setup

### Dependencies

Clone the necessary repositories and update submodules:

```bash
cd ..
git clone -b 1.4.0 --recursive https://github.com/raspberrypi/pico-sdk.git
git clone --recursive https://github.com/martinkooij/pi-pico-LCD
cd Raspberry-pi-pico-thermomentr
git submodule update --init --recursive
```

### Compilation

Create a build directory and compile the project:

```bash
mkdir build
cd build
cmake ..
cmake --build . -j
```

## Usage

1. **Connect the Components**:
   - Assemble the circuit as per the layout.
2. **Upload the Firmware**:
   - Connect the Raspberry Pi Pico to your computer while holding the BOOTSEL button to enter USB mass storage mode.
   - Copy the generated `.uf2` file from the `build` directory to the Pico's storage.
3. **Observe the Output**:
   - The LCD will display the current temperature readings.
   - LEDs will light up corresponding to the measured temperature range.
