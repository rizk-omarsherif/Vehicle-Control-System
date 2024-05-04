/*
 ============================================================================
 Name        : vehicle_control_system.c
 Author      : Omar Rizk
 Description : Vehicle Control System
 ============================================================================
 */

// Included Libraries
#include <stdio.h>

/***************************************  BONUS REQUIREMENT  ***************************************/

#define REMOVE 0
#define ADD 1

// Preprocessor Directive to Add or Remove Engine Temperature Controller
#define  WITH_ENGINE_TEMP_CONTROLLER ADD /* Cases:
                                                    -> REMOVE        Remove Engine Temperature Controller
                                                    -> ADD           Add Engine Temperature Controller */


/***************************************  Structure Type Define  ***************************************/

typedef struct // Defining New Structure Type of Name dashboard
{
    // Struct Members Arranged Descendingly to Minimize Space Loss Due To Padding
    float room_temp;
    float engine_temp;
    int   speed;
    char  start_menu_state;
    char  sensor_menu_state;
    char  traffic_light_state;

} dashboard;

/*******************************************  Functions Declaration  *******************************************/

// Function to Display Start Menu
void start_menu(dashboard* car);

// Function to Display Sensors Set Menu
void sensor_set_menu(dashboard* car);

// Function to Read Traffic Light and Take Actions Accordingly
void traffic_light(dashboard* car);

// Function to Read Room Temperature Sensor and Take Action Accordingly
void sensor_room_temp(dashboard* car);

#if WITH_ENGINE_TEMP_CONTROLLER
// Function to Read Engine Temperature Sensor and Take Action Accordingly
void sensor_engine_temp(dashboard* car);
#endif

// Function to Print System Status
void state_print(dashboard* car);


/***********************************  Global Array of Pointers to Functions  ***********************************/

// To Practice Array of Pointers and Pointer to Function

#if WITH_ENGINE_TEMP_CONTROLLER
void (*ptr_fun[6])(dashboard*) ={start_menu,sensor_set_menu,traffic_light,sensor_room_temp,sensor_engine_temp,state_print};
#endif

#if !WITH_ENGINE_TEMP_CONTROLLER
void (*ptr_fun[6])(dashboard*) ={start_menu,sensor_set_menu,traffic_light,sensor_room_temp,NULL,state_print};
#endif

/***************************************  Text Replacements For Readability ***************************************/

#define START_MENU    0  // 0 = Index of function : start_menu         in array of pointers to function ptr_fun
#define SENSOR_MENU   1  // 1 = Index of function : sensor_set_menu    in array of pointers to function ptr_fun
#define TRAFFIC_LIGHT 2  // 2 = Index of function : traffic_light      in array of pointers to function ptr_fun
#define ROOM_TEMP     3  // 3 = Index of function : sensor_room_temp   in array of pointers to function ptr_fun
#define ENGINE_TEMP   4  // 4 = Index of function : sensor_engine_temp in array of pointers to function ptr_fun
#define SYSTEM_STATE  5  // 5 = Index of function : state_print        in array of pointers to function ptr_fun


/***************************************  Global Enumerators  ***************************************/

enum states{ON,OFF};
char engine_state=OFF, ac_state=OFF, engine_temp_control=OFF;

/***********************************************************************************************/
/***************************************  Main Function  ***************************************/
/***********************************************************************************************/

int main(void)
{
    // For printing messages before scanf in eclipse terminal
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // Local Structure to Practice Call by Reference using Structs
    dashboard mycar = {25,100,80};

    // Display Start Menu
    (*ptr_fun[START_MENU])(&mycar);

    // Check If Selected Value from start_menu function is To Terminate Program
    switch (mycar.start_menu_state)
    {
    case 'c':
    case 'C':
        return 0;
    }
}

/*************************************************************************************************************/
/* Function: start_menu                                                                                     **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Displays System Start Menu Then Receives Input From User                      **/
/* Cases -> 'A' or 'a' : Turn The Engine 'ON' Then Display Sensor Set Menu                                  **/
/*          'B' or 'b' : Turn The Engine 'OFF' Then Display The Same Menu Again                             **/
/*          'C' or 'c' : (Evaluated in Main Function) to Terminate The System                               **/
/*************************************************************************************************************/
void start_menu(dashboard* car)
{
    // Display Start Menu For User Until Selected Option is Available
    do {
        printf("\n\na. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n\n");

        // Take Input From User
        scanf(" %c",&car->start_menu_state);
    }
    // Condition To Exit Loop if Selected Value is Available
    while  ( !(( 'a' <= car->start_menu_state && 'c' >= car->start_menu_state ) || ( 'A' <= car->start_menu_state && 'C' >= car->start_menu_state)) );

    // Condition To Take Action To Selected Option by User
    switch (car->start_menu_state )
    {
    case 'a':
    case 'A':
        // Turn Engine 'ON'
        engine_state=ON;
        // Call sensor_menu Function to Display Sensor Set Menu
        (*ptr_fun[SENSOR_MENU])(car);
        break;

    case 'b':
    case 'B':
        // Turn Engine 'OFF'
        engine_state=OFF;
        // Call start_menu Function to Display Start Menu Again
        (*ptr_fun[START_MENU])(car);
        break;
    }

}

/*************************************************************************************************************/
/* Function: sensor_set_menu                                                                                **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Display Sensor Set Menu Then Receives Input From User                         **/
/* Cases -> 'A' or 'a' : Turn The Engine 'OFF' Then Display System Start Menu                               **/
/*          'B' or 'b' : Calls Traffic Light Function                                                       **/
/*          'C' or 'c' : Calls Room Temperature Sensor Function                                             **/
/*          'D' or 'd' : Calls Engine Temperature Sensor Function                                           **/
/*************************************************************************************************************/
void sensor_set_menu(dashboard* car)
{

    // Display Sensor Set Menu For User Until Selected Option is Available
    do {
        printf("\n\na. Turn off the engine\n");
        printf("b. Set the traffic light color\n");
        printf("c. Set the room temperature\n");
#if WITH_ENGINE_TEMP_CONTROLLER
        printf("d. Set the engine temperature\n");
#endif
        // Take Input From User
        scanf(" %c",&car->sensor_menu_state);
    }
    // Condition To Exit Loop if Selected Value is Available (Using ASCII of Characters)
#if WITH_ENGINE_TEMP_CONTROLLER
    while ( !(( 65 <= car->sensor_menu_state && 68 >= car->sensor_menu_state) || (97 <= car->sensor_menu_state && 100 >= car->sensor_menu_state)) );
#endif

#if !WITH_ENGINE_TEMP_CONTROLLER
    while ( !(( 65 <= car->sensor_menu_state && 67 >= car->sensor_menu_state) || (97 <= car->sensor_menu_state && 99 >= car->sensor_menu_state)) );
#endif

    // Condition To Take Action To Selected Option by User
    switch (car->sensor_menu_state)
    {
    case 'a':
    case 'A':
        // Turn Engine 'OFF'
        engine_state=OFF;
        // Call state_print Function To Display System State
        (*ptr_fun[SYSTEM_STATE])(car);
        // Call start_menu Function To Display Start Menu Again
        (*ptr_fun[START_MENU])(car);
        break;

    case 'b':
    case 'B':
        // Call traffic_light Function to Read Traffic Lights and Take Action Accordingly
        (*ptr_fun[TRAFFIC_LIGHT])(car);
        break;

    case 'c':
    case 'C':
        // Call sensor_room_temp Function to Read Room Temperature and Take Action Accordingly
        (*ptr_fun[ROOM_TEMP])(car);

        break;
#if WITH_ENGINE_TEMP_CONTROLLER
    case 'd':
    case 'D':
        // Call sensor_engine_temp Function to Read Engine Temperatureand Take Action Accordingly
        (*ptr_fun[ENGINE_TEMP])(car);
#endif
    }
}

/*************************************************************************************************************/
/* Function: traffic_light                                                                                  **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Reads Traffic Light Reading and Take Actions Accordingly                      **/
/* Cases -> 'G' or 'g' : Sets Car Speed to 100 KM/H                                                         **/
/*          'O' or 'o' : Sets Car Speed to 30 KM/H                                                          **/
/*                       Turn ON AC if OFF and Set Temperature (By Given Equation)                          **/
/*                       Turn ON Engine Temperature Controller if OFF Set Temperature (By Given Equation)   **/
/*          'R' or 'r' : Set Car Speed to 0 KM/H                                                            **/
/*************************************************************************************************************/
void traffic_light(dashboard* car)
{
    // Input Traffic Light Reading From User ( Camera Reading )
    printf("input traffic light reading:\t");
    scanf(" %c",&car->traffic_light_state);

    // Condition To Take Action To Read Traffic Light Color
    switch (car->traffic_light_state)
    {
    case 'G':
    case 'g':
        // Set Car Speed to 100 KM/H
        car->speed = 100;
        break;
    case 'O':
    case 'o':
        // Set Car Speed to 30 KM/H
        car->speed = 30;

        // Condition To Turn AC 'ON' if Turned 'OFF'
        if (ac_state==OFF)
        {
            // Turn AC 'ON'
            ac_state=ON;

            // Set Room Temperature According to Given Equation
            car->room_temp = (car->room_temp*(float)5/4)+1;
        }
#if WITH_ENGINE_TEMP_CONTROLLER
        // Condition To Turn Engine Temperature Controller 'ON' if Turned 'OFF'
        if (engine_temp_control==OFF)
        {
            // Turn Engine Temperature Controller 'ON'
            engine_temp_control = ON;

            // Set Engine Temperature According to Given Equation
            car->engine_temp = (car->engine_temp*(float)5/4)+1;
        }
#endif
        break;
    case 'R':
    case 'r':
        // Set Car Speed to 0 KM/H ( STOP CAR )
        car->speed = 0;
        break;
    }

    // Call state_print Function To Display System State
    (*ptr_fun[SYSTEM_STATE])(car);

    // Call sensor_set_menu Function to Display Sensor Set Menu Again
    (*ptr_fun[SENSOR_MENU])(car);


}

/*************************************************************************************************************/
/* Function: sensor_room_temp                                                                               **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Read Room Temperature Sensor and Take Action Accordingly                      **/
/* Cases -> Temperature is Smaller than 10 c : Turn AC ON and Set Temperature to 20 c                       **/
/*          Temperature is Bigger  than 30 c : Turn AC ON and Set Temperature to 20 c                       **/
/*          ANYTHING ELSE                    : Turn AC OFF                                                  **/
/*************************************************************************************************************/
void sensor_room_temp(dashboard* car)
{
    // Input Room Temperature Reading From User ( Sensor Reading )
    printf("input temperature sensor reading:\t\t");
    scanf("%f",&car->room_temp);

    // Condition to Check if Temperatre is Below 10c or Above 30c
    if ( (car->room_temp < 10) || (car->room_temp>30) )
    {
        // Turn AC 'ON'
        ac_state=ON;

        // Set Room Temperature to 20c
        car->room_temp=20;
    }
    else
    {
        //Turn AC 'OFF'
        ac_state=OFF;
    }

    // Call state_print Function To Display System State
    (*ptr_fun[SYSTEM_STATE])(car);

    // Call sensor_set_menu Function to Display Sensor Set Menu Again
    (*ptr_fun[SENSOR_MENU])(car);
}

/*************************************************************************************************************/
/* Function: sensor_engine_temp                                                                             **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Read Room Temperature Sensor and Take Action Accordingly                      **/
/* Cases -> Temperature is Smaller than 100 c : Turn Temperature Controller ON and Set Temperature to 125 c **/
/*          Temperature is Bigger  than 150 c : Turn Temperature Controller ON and Set Temperature to 125 c **/
/*          ANYTHING ELSE                     : Turn Temperature Controller OFF                             **/
/*************************************************************************************************************/
#if WITH_ENGINE_TEMP_CONTROLLER
void sensor_engine_temp(dashboard* car)
{
    // Input Engine Temperature Reading From User ( Sensor Reading )

    printf("input engine temperature sensor reading:\t\t");
    scanf("%f",&car->engine_temp);

    // Condition to Check if Temperatre is Below 100c or Above 150c

    if ( (car->engine_temp<100) || (car->engine_temp>150) )
    {
        // Turn Engine Temperature Controller 'ON'
        engine_temp_control=ON;

        // Set Engine Temperature to 125c
        car->engine_temp = 125;
    }
    else
    {
        // Turn Engine Temperature Controller 'OFF'
        engine_temp_control=OFF;
    }

    // Call state_print Function To Display System State
    (*ptr_fun[SYSTEM_STATE])(car);

    // Call sensor_set_menu Function to Display Sensor Set Menu Again
    (*ptr_fun[SENSOR_MENU])(car);
}
#endif

/*************************************************************************************************************/
/* Function: state_print                                                                                    **/
/* Input Parameters: Pointer to Structure of Type dashboard                                                 **/
/* Returns: Nothing                                                                                         **/
/* Description: This Function Displays All System Status on Screen                                          **/
/*************************************************************************************************************/
void state_print(dashboard* car)
{
    // Print Engine status
    (engine_state == ON)?  printf("\nEngine : ON \n") : printf("\nEngine : OFF \n");

    // Print AC status
    (ac_state == ON)?      printf("AC : ON \n")         : printf("AC : OFF \n");

    // Print vehicle speed
    printf("Vehicle Speed = %d KM/H\n",car->speed);

    // Print room temperature
    printf("Room Temperature = %.1f c",car->room_temp);

#if WITH_ENGINE_TEMP_CONTROLLER
    // Print engine temperature control status (if WITH_ENGINE_TEMP_CONTROLLER is defined)
    (engine_temp_control == ON)? printf("\nEngine Temperature Control : ON \n") : printf("\nEngine Temperature Control : OFF \n");

    // Print engine temperature (if WITH_ENGINE_TEMP_CONTROLLER is defined)
    printf("Engine Temperature = %.1f c",car->engine_temp);
#endif
}
