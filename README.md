# Pico BLE Keyboard Adapter

This project aims to create an adapter that converts a USB keyboard into a wireless Bluetooth Low Energy (BLE) keyboard using the Raspberry Pi Pico.

The design is intentionally kept as simple as possible.

## Requirements

- Raspberry Pi Pico SDK installed  
- The SDK is expected to be located at:

```
~/.pico-sdk
```

## Build Instructions

Set the SDK path:

```
export PICO_SDK_PATH=~/.pico-sdk
```

Build the project:

```
mkdir build
cd build
cmake ..
make
```