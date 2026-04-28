#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#define CFG_TUSB_MCU                OPT_MCU_RP2040

// Only Host
#define CFG_TUH_ENABLED             1
#define BOARD_TUH_RHPORT            0


#define CFG_TUH_DEVICE_MAX          1  // Only one device  
#define CFG_TUH_HUB                 0  // Do not support hubs
#define CFG_TUH_HID                 2  // Number of HID Report Descriptor
#define CFG_TUH_VENDOR              0  

// Buffer settings
#define CFG_TUH_ENUMERATION_BUFSIZE 256
#define CFG_TUH_HID_EPIN_BUFSIZE    64
#define CFG_TU_HID_EPOUT_BUFSIZE    64

#endif