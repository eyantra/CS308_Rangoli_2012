2012 - CS308  Group 13 :Rangoli Project README 
================================================

Group Info:
------------
+   ROHITH S(09005052)
+   MANOHAR T (09005053)
+   ANUSH V (09005055)
+   MANOJ AZAD (09005074)

Extension Of
------------
Rangoli Project (see references)
Project Description
-------------------

Rangoli Bot as the name suggests is used in recreating rangoli patterns in an image onto a paper. Best used with color powders.

A C file Rang.c in code folder should be compiled using AVR Studio with inclusion of various header files provided in folder Header Files

The generated hex file in default folder is loaded i.e., burned on ATmega2560 .

Then scilab is opened in the directory of scilab code and is run in the following manner.First loading svip in scilab.Then run 

inputImageProcessing_2.sce followed by negativeFeedbackSystem.sce .


Technologies Used
-------------------

+   Embedded C
+   Scilab
+   Xbee
+   OpenCV

Installation Instructions
=========================

Dependencies:

scilab 4.0 (http://www.scilab.org)
OpenCV 1.0 (http://sourceforge.net/projects/opencvlibrary)
SIVP toolbox ( http://atoms.scilab.org/toolboxes/IPD/2.0)
ipd.zip file needs to be extracted in cotrib folder of scilab 4.0 (e.g., C:/Program Files/scilab-4.0/contrib)

Firstly Scilab Image and Video Processing (SIVP) toolbox needs to be loaded in the scilab environment. Directory has to be changed where the scilab codes are. Command is chdir("C:/Program Files/scilab-4.0/Embedded") if the codes are in Embedded folder. "siseli.dll" needs to be kept in same directory. After this "inputImageProcessing.sce" code needs to be executed. Command is "exec("inputImageProcessing.sce"). Finally "negativeFeedbackSystem.sce" needs to be executed. Command is exec(""negativeFeedbackSystem.sce").


References
===========

+ [Rangoli Bot](http://www.e-yantra.org/home/projects-wiki/item/172-rangoli-making-robot-using-firebirdv-atmega2560)
