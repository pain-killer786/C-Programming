/* Application.h */
/* We are using #ifndef macro to prevent multiple inclusion of header files*/

#ifndef application_h
#define application_h

/* maximum length of user id and request id */

#define ID_LENGTH 10

/* Maximum length of string used in this project */
/* User name, comment, address etc. */

#define STR_MAX_LENGTH 256

/* All application and user interface related functions*/
/* String which will be used to separate data of each line in given file. */

extern const char * DELIMITER;

/* Start application. */

extern void start_application(void);

/* Show welcome screen of application. */

extern void welcome(void);

/* Show menu for operator with various options. */

extern void render_menu(void);

/* Add new user who want to request for electricity. */

extern void add_user_page(void);

/* Operator can view specific user request done by that user. */

extern void view_user_page(void);

/* Operator can add new request which is requested by specific user. */

extern void add_request_page(void);

/* In futute, if opeator wants to edit request (i.e, change status or enter comments). */

extern void edit_request_page(void);

/* 
    Close application after the opeator completes his work
    input  : Status of application.
    input  : message to display on the screen in the case of erronous exit. 
*/

extern void close_application(int exit_status, const char * message);

/*
    Function which set cursor at X,Y on display 
    input   : X coordinate of the screen.
    input   : Y coordinate of the screen.
*/

extern void gotoxy(int x, int y);

/*
    Function which display message and additional info on screen
    input   : message to be displayed on the screen.
    input   : additional info along with message.
*/

extern void show_dialogue_box(const char * message, const char * info);

#endif /* application_h */