 #include <stdio.h>

#include <cv.h> // Include the OpenCV library
#include <highgui.h> // Include interfaces for video capturing

int main(){
	//crea finestra su cui visualizzare l'immagine
    cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
    //inizializzo la telecamera.
    CvCapture* capture =cvCreateCameraCapture(-1);
    //in caso venga inizializzato male, esco.
    if (!capture){
        printf("Error. Cannot capture.");
    }else{
		//Creo una finestra dove visualizzare l'immagine.
        cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
		//catturo l'immagine
        IplImage* frame = cvQueryFrame(capture);
        //in caso di errore
        if(!frame){
			printf("Error. Cannot get the frame.");
        	exit(0);
        }
        //
        cvShowImage("Window",frame);
		cvWaitKey(3000);
		if(!cvSaveImage("img.jpg",frame,0)) printf("Could not save: %s\n","img.jpg");
        cvReleaseCapture(&capture);
        cvDestroyWindow("Window");
    }
    return 0;
}
