#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Camera configuration tests

#include "CamControl_mockHelper.hpp"


#define GPIO_PIN                15
#define PIXEL_FORMAT      "YUYV"
#define  FPS                         60  
#define CAM_NAME           "/dev/video0"


/* 
    Test fixture for camera control
*/
struct CamControlFixture {
    CamControl_mockHelper cam_control; 

    CamControlFixture() : cam_control(cam_handle) {
        cam_handle.open(); 
    }

    ~CamControlFixture() {
        cam_handle.close(); 
    }

}; 

/* 
    TEST SUITE START
*/
BOOST_FIXTURE_TEST_SUITE(CamControlTestSuite, CamControlFixture)

BOOST_AUTO_TEST_CASE(TestCamConfiguration) {
    /* 
        Hard-coded dummy data. Fine for writing test cases. Refactored after
    */
    int gpio_pin = GPIO_PIN; 
    char *pixel_format = PIXEL_FORMAT; 
    int fps = FPS; 

    /* 
        Behavior verifications START
    */

    // Camera configuration testing
    BOOST_CHECK_NO_THROW(cam_control.configureCameraExternalTrigger(CAM_NAME, GPIO_PIN, PIXEL_FORMAT, FPS) ); 

}

BOOST_AUTO_TEST_SUITE_END()