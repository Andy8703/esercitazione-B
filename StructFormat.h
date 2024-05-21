/*! \file StructFormat.h
	\brief Declaration of the struct Format

	Details.
*/


/// @enum Color
/// @brief the set of available colors
/// blacK, White, Red, Green, Blue
enum Color {k,w,r,g,b};

/// @struct Format
/// @brief parameters setting the drawing format of the shape 
struct Format {
	Color fill; // fill color 
	Color outline; // outline color
	
};