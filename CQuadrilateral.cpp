#include "CQuadrilateral.h"

/// @brief default constructor 
Quadrilateral::Quadrilateral() {

	cout << "Quadrilateral - constructor - default" << endl;

	Init();

} 

/// @brief constructor 
/// sf a struct of type Format with infos on fill color and outline color
Quadrilateral::Quadrilateral(Format sf) {

	

} 

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Quadrilateral::Quadrilateral(const Quadrilateral &o) {
	
	cout << "Quadrilateral - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Quadrilateral::~Quadrilateral() {

	cout << "Quadrilateral - destructor" << endl;
	Reset();

}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
void Quadrilateral::SetSides(float s1, float s2, float s3, float s4) {
	
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
	sides[3] = s4; 
	
	return;

} 

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Quadrilateral& Quadrilateral::operator=(const Quadrilateral &o) { 
	
	Init(o);
	return *this;
	
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Quadrilateral::operator==(const Quadrilateral &o) {

	return false;
}


/// @brief default initialization of the object
void Quadrilateral::Init() {
	
		
	SetSides(0.,0.,0.,0.);
	
		
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Quadrilateral::Init(const Quadrilateral &o) {
	Reset();
	Init();
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
	sides[3] = o.sides[3];
	
}

/// @brief total reset of the object  
void Quadrilateral::Reset() {
	
	sides[0]= sides[1]= sides[2]= sides[3] = 0.;
	
}

/// @brief get the area of the object
/// @return area 
float Quadrilateral::GetArea() {
	
	return Area();

}

/// @brief get the perimeter of the object
/// @return perimeter 
float Quadrilateral::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]+sides[3]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
void Quadrilateral::GetSides(float &s0, float &s1, float &s2, float &s3) {

	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
	s3 = sides[3];

}

/// @brief get the format of the object 
/// @param sf  a struct of type Format to be filled with the format fields
void Quadrilateral::GetFormat(Format &sf) {

} 

/// @brief get the fill color of the object 
/// @param fill fill color 
Color Quadrilateral::GetFill() {
	
	
}

/// @brief get the outline color of the object 
/// @param outline outline color 
Color Quadrilateral::GetOutline() {

	
}


/// @brief set the format of the object 
/// @param sf a struct of type Format filled with the format fields
void Quadrilateral::SetFormat(Format sf) {
	
	
}

/// @brief set the fill color of the object 
/// @param fill fill color 
void Quadrilateral::SetFill(Color fill) {

	
}

/// @brief set the outline color of the object 
/// @param outline outline color 
void Quadrilateral::SetOutline(Color outline) {
	
	
}



/// @brief write an error message 
/// @param string message to be printed
void Quadrilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Quadrilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Quadrilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Quadrilateral --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Quadrilateral::Dump() {
	
	cout << endl;
	cout << "---Quadrilateral---" << endl; 
	cout << endl;
	
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << sides[3] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "------------------" << endl; 
	cout << endl;

}

