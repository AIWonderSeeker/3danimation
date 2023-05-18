
Xianci Tang[g-number: G00798675]
Project 1

Requirements Implemented:
1.1-  yes, the parser function "plyload()" in modelerui.cxx,it will call plyloader::load in plyloader.cpp to load data into 3 global vectors in plyloader.h; data is saved in memory
1.2-  yes, draw all triangles based on data saved, code in TWOModel::draw() method of twomodels.cpp
1.3 - yes, press button t on keyboard will switch two models; I added a case for FL_SHORTCUT in ModelerView::handle(int event) to deal with that
2.1-  yes, it is a moving arm composed of 11 primitive shapes :4 sphere, 1 box, 2 small slim cylinder, 2 big cylinder, 2 small boxes; greater than four levels of hierarchy
2.2-  yes, sliders can  move whole arm along x, y, z (X,Y,Z), adjust two levels of height(H1,H2), adjust arm base angle(Cylinder_TURN), adjust lower_arm angle(Lower_Arm_TILT), upper_arm angle (Upper_Arm_TILT)
2.3-  yes, when arm base (Cylinder_TURN) rotate, the lower_arm and upper_arm are tied to rotate as well; when lower arm angle(Lower_Arm_TILT) move, upper arm is be tied to move as well.
2.4 - yes, click menu option 'Animate' checkbox