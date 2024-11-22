#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Camera
#include <boost/test/unit_test.hpp>

#include "CamControl_mockHelper.hpp"
#include "GPIO_mockHelper.hpp"
#include "I2C_mockHelper.hpp"

/* 
    Test fixture for camera control
*/
struct CamControlFixture {
    CamControl_mockHelper camc_helper; 
    GPIO_mockHelper gpio_helper; 
    I2C_mockHelper i2c_helper; 

    CamControlFixture() : camControl(gpio_helper, i2c_helper) {
        gpio_helper.init(); 
        i2c_helper.init(); 
    }

    ~CamControlFixture() {
        gpio_helper.cleanup();
        i2c_helper.cleanup(); 
    }
}; 

/* 
    TEST SUITE BEGIN
*/



