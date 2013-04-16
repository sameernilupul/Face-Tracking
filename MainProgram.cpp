
#include <iostream>
#include "FaceDetection.h"
#include "Text.h"
#include "CropImage.h"
#include "TemplateMatch.h"
#include "MainProgram.h"

#define percent 50
#define name "Display"
#define minprob 0.9500
#define maxprob 0.9900


Main::Main(){
    capture = cvCaptureFromCAM( CV_CAP_ANY );
    if ( !capture ) {
        fprintf( stderr, "ERROR: capture is NULL \n" );
        getchar();
        exit(-1);
    }
    frame = cvQueryFrame( capture );
    resized = cvCreateImage( cvSize((int)((frame->width*percent)/100) , (int)((frame->height*percent)/100) ),frame->depth, frame->nChannels);
    box = cvRect(0,0,1,1);
    initialized = false;
    prob =0;
    //averageProb =0;
    
    center = cvPoint(0, 0);
    cvResize(frame, resized);
    cvNamedWindow( name );
}

Main::~Main(){
    cvDestroyWindow(name);
    //cvReleaseImage(&frame);
    cvReleaseCapture(&capture);
    //cvReleaseImage(&resized);
}

void Main::mainLoop(){
    
    frame = cvQueryFrame( capture );
    cvResize(frame, resized);
    
	while(detector.detectFace(resized,&box)==0)
	{
		frame = cvQueryFrame( capture );
		cvResize(frame, resized);
	}
    
    while(1){
        frame = cvQueryFrame( capture );
        cvResize(frame, resized);
        
        if(!initialized){
            detector.detectFace(resized,&box);
            cropImage(resized, &imgTemplate, box);
            tempMatcher.Initializer(resized,&imgTemplate);
            initialized = true;
        }
        //printf("main loop\n");
        if(initialized){
            prob = tempMatcher.matchTemplate(resized, &center);
			for(int i=0;i<4;i++)
			{
				averageProb[i]=averageProb[i+1];
			}
			averageProb[4]=prob;
			prob=0;
			for(int i=0;i<5;i++)
			{
				prob+=averageProb[i];
			}
			prob/=5;
            count++;
            if(prob<minprob ||(prob>maxprob && count > 5) || count > 1000){
				printf("Point %lf\n =",prob);
                initialized = false;
				count=0;
            }
            
			cvRectangle(resized, cvPoint(center.x, center.y), cvPoint(center.x+box.width, center.y+box.height), cvScalar(100));
            sprintf(text, "X = %d  Y = %d ", center.x,center.y);
            textWriter.printText(resized,text, cvPoint(center.x,center.y));
            sprintf(text, "Prob = %lf", prob);
            textWriter.printText(resized,text, cvPoint(100,100));
            cvShowImage(name, resized);
        }
        
        if( cvWaitKey( 15 )==27 ) 
            break;
    }
        
}
