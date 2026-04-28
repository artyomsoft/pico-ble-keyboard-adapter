#ifndef HOG_KEYBOARD_H
#define HOG_KEYBOARD_H

extern void btstack_start(void);
extern void send_hid_report(const uint8_t* report, size_t len);
#endif
