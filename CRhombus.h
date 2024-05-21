/*! \file CRhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/


#ifndef RHOMBUS_H
#define RHOMBUS_H

#include<iostream>

#include "CQuadrilateral.h"

using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus : public Quadrilateral
{
protected:

	float diagL;
	float diagS;
	
	/// @name PURE VIRTUAL FUNCTIONS - IMPLEMENTATION
	/// @{
	float Area();
	/// @}

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus();
	Rhombus(float dL, float dS); 
	Rhombus(float dL, float dS, Format sf);
	Rhombus(const Rhombus &r);
	
	~Rhombus();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus &r); 
	bool operator==(const Rhombus &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Rhombus &r);							
	void Reset();												
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDiagL(float d);
	void SetDiagS(float d);
	void SetDim(float dL, float dS);
	
	void GetDim(float &dL, float &dS);
	float GetDiagL();
	float GetDiagS();
	float GetSide();	
	/// @}
	
	/// @name PURE VIRTUAL FUNCTIONS - IMPLEMENTATION
	/// @{
	void Drawing();
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif