#ifndef CAMCONTROL_HELPER_HPP
#define CAMCONTROL_HELPER_HPP

#include "CamHandle_mockHelper.hpp"

class CamControl {
    public:    
        CamControl(MockCamHandle& camHandle_helper) : camHandle_helper(camHandle_helper) {}

        void configureCameraExternalTrigger(char *cam_name, int gpio_pin, int gpio_state, char *pixel_fmt, int fps) {
            camHandle_helper.configureTriggerPin(gpio_pin, 3); 
            camHandle_helper.setPinValue(gpio_pin, 0); 
            camHandle_helper.setPixelFormat(pixel_fmt); 
            camHandle_helper.setFramesPerSec(fps); 
        }


    private: 
        MockCamHandle& camHandle_helper; 
}; 

#endif

