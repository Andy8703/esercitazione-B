#include<iostream>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"

const int LISTL=6; 

Quadrilateral* quadList[LISTL];

void Show() {
	
	int i; 
	
	for (i=0; i<LISTL; i++)
		quadList[i]->Drawing();
	
}


int main() {

	 
	Format f1, f2;
	
	f1.fill = r;
	f1.outline = b; 
	f2.fill = g;
	f2.outline = w;
	
	Rectangle rectA(10,5);
	Rectangle rectB(3,7,f1);
	Rectangle rectC = rectA;

	Rhombus rhoA(6,2,f2);
	Rhombus rhoB = rhoA;
	Rhombus rhoC(4,3);
		
	quadList[0]= &rectA;
	quadList[1]= &rectB;
	quadList[2]= &rectC;
	quadList[3]= &rhoA;
	quadList[4]= &rhoB;
	quadList[5]= &rhoC;

	Show();
	
	rectA.SetFill(g);
	rhoC.SetOutline(r);
	rhoA=rhoC;
	rectB.SetFormat(f2);
	
	Show();


	return 0;

}