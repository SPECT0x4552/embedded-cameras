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
            okay("Camera closed",); 
            return; 
        }


}

#endif // CAMHANDLE_MOCKHELPER_HPP 

