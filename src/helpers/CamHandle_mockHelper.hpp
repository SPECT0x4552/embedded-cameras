#ifndef CAMHANDLE_MOCKHELPER_HPP
#define CAMHANDLE_MOCKHELPER_HPP

#include <iostream>

class MockCamHandle {
    public: 
        int open(char *device_name) {
            if(device_name != "/dev/vide0") {
                return 1; 
            }
            std::cout << "Camera opened" << std::endl; 
        }
}

#endif