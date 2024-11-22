#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Camera
#include <boost/test/unit_test.hpp>

#include "CamControl_mockHelper.hpp"
#include "GPIO_mockHelper.hpp"
#include "I2C_mockHelper.hpp"

#define CAM_MODE            "EXTERNAL-TRIGGER"
#define GPIO_PIN                15




