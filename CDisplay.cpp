/// \file CDisplay.cpp
///	\brief class Display: implementation of the functions
///
///	Details.
///

#include "CDisplay.h"

/// @brief default constructor
Display::Display()
{
    cout << "Costruttore di default - Display" << endl;

    Init();
}

/// @brief copy constructor
/// @param d reference to the object that should be copied
Display::Display(const Display &d)
{
    cout << "Costruttore di copia - Display" << endl;

    Init(d);
}

/// @brief destructor
Display::~Display()
{
    cout << "Distruttore - Display" << endl;

    Remove_all();
}

/// @brief overload of operator =
/// @param d reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator 
Display& Display::operator=(const Display &d)
{
    cout << "Display - operator =" << endl;

	Init(d);
	
	return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return always false 
bool Display::operator==(const Display &d)
{
    return false;
}

/// @brief default initialization of the object
void Display::Init()
{
    for (int i = 0; i < MAX_SHAPES; i++)
        array_forme[i] = NULL;
}	

/// @brief initialization of the object as a copy of an object
/// @param d reference to the object that should be copied
void Display::Init(const Display &d)
{
    for (int i = 0; i < MAX_SHAPES; i++)
        array_forme[i] = d.array_forme[i]; 
}	

/// @brief prints all the shapes contained in the display
void Display::Get_all()
{
    for(int i=0; i<MAX_SHAPES; i++)
    {
        cout << i << " - ";
        if (array_forme[i] == NULL)
        {   
            cout << "Empty shape" << endl;
            continue;
        }
        array_forme[i]->Drawing();
    }
}

/// @brief adds a shape to the display
void Display::Add_shape()
{
    for(int i = 0; i < MAX_SHAPES; i++)
    {
        if (array_forme[i] == NULL)
        {
            int scelta = Shape_request();
            switch (scelta)
            {
                case 1:
                    AddRectangle(i);
                    break;
                case 2:
                    AddRhombus(i);
                    break;
                default:
                    WarningMessage("Scelta non valida");
                    break;
            }
            return;
        }
    }
    WarningMessage("Display pieno");
}

/// @brief removes a shape from the display
/// @param index index of the array
void Display::Remove_shape(int index)
{
    if (array_forme[index] == NULL)
    {
        WarningMessage("Forma non esistente");
        return;
    }
    delete(array_forme[index]);
    array_forme[index] = NULL;
}

/// @brief removes all shapes from the display
void Display::Remove_all()
{
    for(int i=0; i<MAX_SHAPES; i++)
    {
        if (array_forme[i] == NULL)
            continue;
        delete(array_forme[i]);
        array_forme[i] = NULL;
    }
}

/// @brief write an error message 
/// @param string message to be printed
void Display::ErrorMessage(const char *string)
{
	cout << endl << "ERROR -- Display --";
	cout << string << endl;
} 

/// @brief write a warning message 
/// @param string message to be printed
void Display::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- Display --";
	cout << string << endl;
}

/// @brief for debugging: all about the object
void Display::Dump()
{
    cout << "--------------DISPLAY-----------------" << endl;
    cout << "Contenuto:" << endl;
    Get_all();
}

/// @brief asks the user which shape to add
/// @return choice of the shape
int Display::Shape_request()
{
    int scelta;
    cout << "Quale forma vuoi inserire?" << endl;
    cout << "1 - Rettangolo" << endl;
    cout << "2 - Rombo" << endl;

    scanf("%i", &scelta);

    return scelta;
}

/// @brief to add a rectangle to the array
/// @param index index of the array
void Display::AddRectangle(int index)
{
    Rectangle* NewRect;
    NewRect=new(Rectangle);
    array_forme[index] = NewRect;

    float base=0, altezza=0;
    int fill = 0, outline = 0;

    cout << "Inserisci la base del rettangolo: ";
    scanf("%f", &base);
    NewRect->SetWidth(base);

    cout << "Inserisci l'altezza del rettangolo: ";
    scanf("%f", &altezza);
    NewRect->SetHeight(altezza);

    cout << "Colori:" << endl;
    cout << "0 - Nero" << endl;
    cout << "1 - Bianco" << endl;
    cout << "2 - Rosso" << endl;
    cout << "3 - Verde" << endl;
    cout << "4 - Blu" << endl;

    cout << "Inserisci lo sfondo del rettangolo: ";
    scanf("%d", &fill);
    NewRect->SetFill((Color)fill);

    cout << "Inserisci il bordo del rettangolo: ";
    scanf("%d", &outline);
    NewRect->SetOutline((Color)outline);
}

/// @brief to add a rhombus to the array
/// @param index index of the array
void Display::AddRhombus(int index)
{
    Rhombus* NewRhomb;
    NewRhomb=new(Rhombus);
    array_forme[index] = NewRhomb;

    float diagL=0, diagS=0;
    int fill = 0, outline = 0;

    cout << "Inserisci la diagonale maggiore del rombo: ";
    scanf("%f", &diagL);
    NewRhomb->SetDiagL(diagL);

    cout << "Inserisci la diagonale minore del rombo: ";
    scanf("%f", &diagS);
    NewRhomb->SetDiagS(diagS);

    cout << "Colori:" << endl;
    cout << "0 - Nero" << endl;
    cout << "1 - Bianco" << endl;
    cout << "2 - Rosso" << endl;
    cout << "3 - Verde" << endl;
    cout << "4 - Blu" << endl;

    cout << "Inserisci lo sfondo del rombo: ";
    scanf("%d", &fill);
    NewRhomb->SetFill((Color)fill);

    cout << "Inserisci il bordo del rombo: ";
    scanf("%d", &outline);
    NewRhomb->SetOutline((Color)outline);
}