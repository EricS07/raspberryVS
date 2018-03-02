#include <stdio.h>

#include <cv.h> // Include the OpenCV library
#include <highgui.h> // Include interfaces for video capturing

int main()
{
    cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
    CvCapture* capture =cvCreateCameraCapture(-1);
    if (!capture){
        printf("Error. Cannot capture.");
    }
    else{
        cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);

        while (1){
            IplImage* frame = cvQueryFrame(capture);
            if(!frame){
                printf("Error. Cannot get the frame.");
                break;
            }
        cvShowImage("Window",frame);
        cvWaitKey(300);
        }
        cvReleaseCapture(&capture);
        cvDestroyWindow("Window");
    }
    return 0;
}
