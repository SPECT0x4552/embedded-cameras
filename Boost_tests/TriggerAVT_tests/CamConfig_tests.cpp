#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Camera configuration tests
#include <boost/test/unit_test.hpp>

#include "CamControl_mockHelper.hpp"
#include "CamHandle_mockHelper.hpp"


struct CameraControlFixture {
    MockCamHandle camHandle_helper; 
    CamControl cameraControl; 

    CameraControlFixture() : cameraControl(camHandle_helper) {
        camHandle_helper.open("/dev/video0"); 
    }

    ~CameraControlFixture() {
        camHandle_helper.close("/dev/video0");  
    }
}; 

// TEST SUITE START

BOOST_FIXTURE_TEST_SUITE(CamControlTestSuite, CameraControlFixture)

BOOST_AUTO_TEST_CASE(ConfigureExternalTriggerMode) {
    int gpio = 17; 
    char *pixel_fmt = "YUYV"; 
    int fps = 60; 

    BOOST_REQUIRE_NO_THROW(cameraControl.configureCameraExternalTrigger("/dev/video0", gpio, 1, pixel_fmt, fps)); 
}

BOOST_AUTO_TEST_SUITE_END()


