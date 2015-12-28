Gesture Library Project Overview

Goal: 	
  Create a library and api that interprets movements of from the 
  STM32F4 Discovery Board 

Features:
  1. Recognize following gestures in a 2D plane:
     a. Right
     b. Left
     c. Up
     d. Down

Future Plans:
  1. Recognize following gestures:
     a. Forward
     b. Backward
     c. Diagonal (2D)
     d. Diagonal (3D)
     e. Circles
     f. Arcs
  2. Allow user configuration through api
     a. Wait time for gesture
     b. Save custom gestures

Design Overview:
  1. STM32 Driver
     a. Check for existing driver for accelerometer on STM32 Discovery
        Board
     b. Create one if driver doesn't exist or if driver is insufficient
  2. Gesture Library
     a. Takes in output from STM32 Driver and outputs most likely
        simple shape 
  3. API
     a. Has functions to recognize combinations of shapes
     b. Allows user to configure settings
     c. Allows user to create custom gestures

Notes:
  1. Possble accelerometer library [here] (http://stm32f4-discovery.com/2014/09/library-35-lis302dl-or-lis3dsh-accelerometer/)