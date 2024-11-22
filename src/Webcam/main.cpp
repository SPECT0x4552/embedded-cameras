#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv) {
    
    // open the default video camera
    VideoCapture cap(0); 

    if(cap.isOpened() == false) {
        cout << "Cannot open the video camera" << endl; 
        return -1; 
    }


    double d_width = cap.get(CAP_PROP_FRAME_WIDTH); 
    double d_height = cap.get(CAP_PROP_FRAME_HEIGHT); 

    cout << "Resolution of the video : " << d_width << " x " << d_height << endl; 

    string window_name = "Webcam feed"; 

    namedWindow(window_name); 

    while(true) {
        Mat frame; 

        bool b_success = cap.read(frame); // Read a new frame from the video

        // If frames cannot be captured, we will break the while loop
        if(b_success == false) {
            cout << "Video camera disconnected" << endl; 
            cin.get(); 
            break; 
        }
        // show the frame in the created window
        imshow(window_name, frame); 


        // wait for 10ms until any key is pressed

        // if esc is pressed, break the while loop 

        if(waitKey(10) == 27) {
            cout << "ESC pressed, stopping video" << endl; 
            break; 
        }
    }

    return 0; 
}