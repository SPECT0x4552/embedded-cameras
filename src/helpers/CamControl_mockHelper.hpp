#ifndef CAMCONTROL_HELPER_HPP
#define CAMCONTROL_HELPER_HPP

#include "CamHandle_mockHelper.hpp"

class CamControl {
    public:    
        CameraControl(CamHandle_Helper& camHandle_helper) : camHandle_helper(camHandle_helper) {}

        void configureCameraExternalTrigger(char *cam_name, int gpio_pin, char *pixel_fmt, int fps) {
            camHandle_helper.open(cam_name); 
            camHandle_helper.configureTriggerPin(gpio_pin, true); 
            camHandle_helper.setPinValue(gpio_pin, false); 

            camHandle_helper.setPixelFormat(pixel_fmt); 
            camHandle_helper.setFramesPerSec(fps); 
        }


    private: 
        CamHandle_Helper& camHandle_helper; 
}

#endif