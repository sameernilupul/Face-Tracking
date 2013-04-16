//
//  FaceDetection.h
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Final_This_Willbe_FaceDetection_h
#define Final_This_Willbe_FaceDetection_h

#include <opencv/cv.h>
#include <opencv/highgui.h>

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


#endif
