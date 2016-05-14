/*
   BOOL.H v1.0.1.3
   Benedict W. Hazel
   18th January 2012
*/

#ifndef _bool_h
#define _bool_h

#define _FALSE 0
#define _TRUE 1

#ifdef BOOL_FORTRAN
    typedef unsigned int LOGICAL;
    #define FALSE _FALSE
    #define TRUE _TRUE
    #define STR_FALSE "F"
    #define STR_TRUE "T"
#elif defined BOOL_JAVA
    typedef unsigned int boolean;
    #define false _FALSE
    #define true _TRUE
    #define STR_FALSE "false"
    #define STR_TRUE "true"
#elif defined BOOL_OBJC
    typedef unsigned int BOOL;
    #define NO _FALSE
    #define YES _TRUE
    #define STR_FALSE "NO"
    #define STR_TRUE "YES"
#elif defined BOOL_VB
    typedef unsigned int Boolean;
    #define False _FALSE
    #define True _TRUE
    #define STR_FALSE "False"
    #define STR_TRUE "True"
#else
    typedef unsigned int bool;
    #define false _FALSE
    #define true _TRUE
    #define STR_FALSE "false"
    #define STR_TRUE "true"
#endif

#define BLSTR(boolean) (boolean ? STR_TRUE : STR_FALSE)
#define BLINT(boolean) (boolean ? _TRUE : _FALSE)

#endif
