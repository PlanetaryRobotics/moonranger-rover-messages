/****************************************************************
 * 
 * @file 		moonranger_msg_strings.h
 * 
 * @brief 		Header file specifying macros to use in order to create a string of a certain color on output console
 * 
 * @version 	1.0
 * @date 		12/06/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/
#ifndef _moonranger_output_strings_h_
#define _moonranger_output_strings_h_

#define ESCAPE    "\033["
#define TERMINATE "m"
/* Reset color back to normal with ANSI color codes */
#define RESET "0"    TERMINATE
#define END   ESCAPE RESET

/* Define ANSI color codes for strings */
#define RED            "31" TERMINATE
#define RED_BOLD       "1;" RED
#define GREEN          "32" TERMINATE
#define GREEN_BOLD     "1;" GREEN
#define YELLOW         "33" TERMINATE
#define YELLOW_BOLD    "1;" YELLOW
#define BLUE           "34" TERMINATE
#define BLUE_BOLD      "1;" BLUE
#define MAGENTA        "35" TERMINATE
#define MAGENTA_BOLD   "1;" MAGENTA
#define CYAN           "36" TERMINATE
#define CYAN_BOLD      "1;" CYAN


/* Define macros to process different color strings */
#define RED_STRING(string)          ESCAPE RED          string END
#define RED_BOLD_STRING(string)     ESCAPE RED_BOLD     string END
#define GREEN_STRING(string)        ESCAPE GREEN        string END
#define GREEN_BOLD_STRING(string)   ESCAPE GREEN_BOLD   string END
#define YELLOW_STRING(string)       ESCAPE YELLOW       string END
#define YELLOW_BOLD_STRING(string)  ESCAPE YELLOW_BOLD  string END
#define BLUE_STRING(string)         ESCAPE BLUE         string END
#define BLUE_BOLD_STRING(string)    ESCAPE BLUE_BOLD    string END
#define MAGENTA_STRING(string)      ESCAPE MAGENTA      string END
#define MAGENTA_BOLD_STRING(string) ESCAPE MAGENTA_BOLD string END
#define CYAN_STRING(string)         ESCAPE CYAN         string END
#define CYAN_BOLD_STRING(string)    ESCAPE CYAN_BOLD    string END

#endif //_moonranger_output_strings_h_ header