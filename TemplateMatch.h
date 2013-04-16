//
//  TemplateMatch.h
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Final_This_Willbe_TemplateMatch_h
#define Final_This_Willbe_TemplateMatch_h

#include <opencv/cv.h>
#include <opencv/highgui.h>

class TemplateMatcher{
    
private:
    IplImage* imgResult;
    IplImage* imgTemplate;
    double min_val;
    double max_val;
    CvPoint min, max;
    
public:
    TemplateMatcher();
    double matchTemplate(IplImage* image,CvPoint* center);
    void Initializer(IplImage* image,IplImage** tempImage);
};

#endif
