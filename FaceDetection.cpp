#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#define extraHeight 10
#define extraWidth 25

class FaceDetector{
private:
    CvHaarClassifierCascade * pCascade;  // the face detector
    CvMemStorage * pStorage;        // expandable memory buffer
    CvSeq * pFaceRectSeq;               // list of detected faces
    int i;
    
public:
    void initializeFaceDetection();
    int detectFace(IplImage *frame, CvRect* box);
    void endFaceDetection(); 
    FaceDetector();
    ~FaceDetector();
};


FaceDetector:: FaceDetector(){
    pCascade = 0;
    pStorage = 0;
    pStorage = cvCreateMemStorage(0);
    pCascade = (CvHaarClassifierCascade *)cvLoad(("/opt/OpenCV-2.4.0/data/haarcascades/haarcascade_frontalface_default.xml"),0, 0, 0 );
}

FaceDetector::~FaceDetector(){
    if(pCascade) cvReleaseHaarClassifierCascade(&pCascade);
    if(pStorage) cvReleaseMemStorage(&pStorage);
}

int FaceDetector::detectFace(IplImage *frame,CvRect* box)
{
    // initializations
    
    // validate that everything initialized properly
    if( !frame || !pStorage || !pCascade )
    {
        printf("Initialization failed: %s \n",
               (!frame)?  "didn't load image file" :
               (!pCascade)? "didn't load Haar cascade -- "
               "make sure path is correct" :
               "failed to allocate memory for data storage");
        exit(-1);
    }
    
    // detect faces in image
    pFaceRectSeq = cvHaarDetectObjects
    (frame, pCascade, pStorage,
     1.1,                       // increase search scale by 10% each pass
     10,                         // drop groups of fewer than three detections
     CV_HAAR_DO_CANNY_PRUNING,  // skip regions unlikely to contain a face
     cvSize(40,40));              // use XML default for smallest search scale
    
    
    if(pFaceRectSeq->total>0){
        CvRect * r = (CvRect*)cvGetSeqElem(pFaceRectSeq, 0);
        
        //CvPoint pt1 = { r->x+extraWidth, r->y+extraHeight };
        //CvPoint pt2 = { r->x + r->width-extraWidth, r->y + r->height-extraHeight };
        //cvRectangle(frame, pt1, pt2, CV_RGB(0,255,0), 3, 4, 0);
        box->x = r->x + r->width*extraWidth/100;
        box->y = r->y + r->height*extraHeight/100;
        box->height = r->height-2*((extraHeight*r->height)/100);
        box->width = r->width-2*((extraWidth*r->width)/100);
    }
    
    return pFaceRectSeq->total;
    
    
}

