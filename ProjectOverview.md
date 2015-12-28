<h1>Gesture Library Project Overview </h1>

<h2>Goal:</h2>	

  Create a library and api that interprets movements of from the 
  STM32F4 Discovery Board 

<h2>Features:</h2>

1. Recognize following gestures in a 2D plane:
  
    * Right
    * Left
    * Up
    * Down

<h2>Future Plans:</h2>

1. Recognize following gestures:

    * Forward
    * Backward
    * Diagonal (2D)
    * Diagonal (3D)
    * Circles
    * Arcs

2. Allow user configuration through api
    * Wait time for gesture
    * Save custom gestures

<h2>Design Overview:</h2>

1. STM32 Driver
    * Check for existing driver for accelerometer on STM32 Discovery Board
    * Create one if driver doesn't exist or if driver is insufficient

2. Gesture Library
    * Takes in output from STM32 Driver and outputs most likely simple shape 
  
3. API
    * Has functions to recognize combinations of shapes
    * Allows user to configure settings
    * Allows user to create custom gestures

<h2>Notes:</h2>

  1. Possble accelerometer library [here] (http://stm32f4-discovery.com/2014/09/library-35-lis302dl-or-lis3dsh-accelerometer/)
