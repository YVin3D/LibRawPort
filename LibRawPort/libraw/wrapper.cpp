//
//  wrapper.cpp
//  AVCam
//
//  Created by Youssef Victor on 11/23/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include "wrapper.hpp"

extern "C" int getRAWHeight(const char* imagePath) {
    // Let us create an image processor
    LibRaw iProcessor;
    
    // Open the file and read the metadata
    int32_t error = iProcessor.open_file(imagePath);
    if (error != LIBRAW_SUCCESS) {
        fprintf(stderr,"Cannot open %s: %s\n",imagePath,libraw_strerror(error));
    };
    
    // The metadata are accessible through data fields of the class
    printf("Image size: %d x %d\n",iProcessor.imgdata.sizes.width,iProcessor.imgdata.sizes.height);
    
    
    // MARK: GET IMAGE WIDTH
    int height = iProcessor.imgdata.sizes.iheight;
    
    // Finally, let us free the image processor for work with the next image
    iProcessor.recycle();
    return height;
}
