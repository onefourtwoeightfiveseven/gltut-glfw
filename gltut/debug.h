//
//  debug.h
//  gltut-glfw
//
//  Created by Ricardo Sánchez-Sáez on 15/08/2013.
//  Copyright (c) 2013 rsanchezsaez. All rights reserved.
//

#ifndef gltut_glfw_debug_h
#define gltut_glfw_debug_h

#ifdef DEBUB

bool printOpenGLError(const char* file,
                      const int line,
                      const char* extraInformation,
                      bool exitOnError)
{
    
    GLenum errorCode;
    bool errorHappened = false;
    
    errorCode = glGetError();
    if (errorCode != GL_NO_ERROR)
    {
        printf("glError in file %s:%d: OpenGL Error 0x%x\n",
               file, line, errorCode);
        if (extraInformation != NULL)
        {
            printf("  %s\n", extraInformation);
        }
        errorHappened = true;
        
        if ( exitOnError )
        {
            exit(EXIT_FAILURE);
        }
        
    }
    
    return errorHappened;
}

bool printOpenGLError()
{
    return printOpenGLError(__FILE__, __LINE__, NULL, false);
}

#else

#define printOpenGLError() ;

#endif

#endif
