/// \file CDisplay.h
///	\brief class Display: declaration
///
///	Details.
///

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "CRhombus.h"
#include "CRectangle.h"
#include "CQuadrilateral.h"
#define MAX_SHAPES 50

using namespace std;

/// @class Display
/// @brief display that shows shapes by printing their info
class Display {
private:
    /// @brief array that contains shapes
    Quadrilateral* array_forme[MAX_SHAPES];

    /// @name SHAPE ARRAY MANAGEMENT FUNCTIONS
    /// @{
    int Shape_request();
    void AddRectangle(int index);
    void AddRhombus(int index);
    /// @}

public:
    /// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Display();
	Display(const Display &d);
	virtual ~Display();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Display& operator=(const Display &d); 
	bool operator==(const Display &d);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Display &d);																			
	/// @}

    /// @name BASIC FUNCTIONS
    /// @{
    void Get_all();
    void Add_shape();
    void Remove_shape(int index);
    void Remove_all();
    /// @}

    /// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
};

#endif