#ifndef CAMHANDLE_MOCKHELPER_HPP
#define CAMHANDLE_MOCKHELPER_HPP
#include <iostream>

#define okay(message, ...)                  printf("[+] " message "\n", ##__VA_ARGS__)
#define error(message, ...)                  printf("[-] " message "\n", ##__VA_ARGS__)
#define info(message, ...)                    printf("[*] " message "\n", ##__VA_ARGS__)

#define MOCK_HANDLE                     5
#define DEV_NAME                              "/dev/video0"

class MockCamHandle {
    public: 
        void open(char *device_name) {
            if(device_name != DEV_NAME) {
                return; 
            }
            okay("Camera opened, handle : %d", MOCK_HANDLE); 
        }

        void close(char *device_name) {
            if(device_name != DEV_NAME) {
                error("Invalid device name : %s", device_name); 
                return; 
            }
            okay("Camera closed"); 
            return; 
        }

        void configureTriggerPin(int pin, int mode) {
            if(pin != 17 || mode != 3) {
                error("Invalid pin or invalid pin mode");  
                return; 
            }
            okay("External trigger pin configured : %d", pin); 
            okay("External trigger pin mode configured to INPUT : %d", mode); 
        }

        void setPinValue(int pin, int mode) {
            if(pin != 17 || mode < 0 || mode > 1) {
                error("Invalid parameters"); 
                return; 
            }

            okay("PIN set to state : %d (0-LOW, 1-HIGH)", mode); 
        }

        void setPixelFormat(char *format) {
            if(format != "YUYV") {
                error("Expected pixel format YUYV, got %s", format);
                return;  
            }
            okay("Pixel format set to %s", format); 
        }

        void setFramesPerSec(int count) {
            if(count % 30 || count <= 0 || count > 60) {
                error("Invalid FPS argument : %d", count); 
                info("Accepting multiples of 30"); 
                return; 
            }
            okay("FPS set to : %d", count); 
        }


}; 

#endif // CAMHANDLE_MOCKHELPER_HPP 

