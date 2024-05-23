#include<iostream>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CDisplay.h"

int main() {
	Display pippo;
	int scelta=0;
	int rem_shape=0;

	cout << "Cosa vuoi fare?" << endl;
	cout << "1 - Visualizzare tutte le forme" << endl;
	cout << "2 - Aggiungere forme" << endl;
	cout << "3 - Rimuovere forma" << endl;
	cout << "4 - Rimuovere tutte le forme" << endl;
	cout << "0 - Esci dal programma" << endl;

	scanf("%d", &scelta);

	while (scelta != 0)
	{
		switch(scelta)
		{
			case 1:
				pippo.Get_all();
				break;
			case 2:
				pippo.Add_shape();
				break;
			case 3:
				pippo.Get_all();
				cout << "Che forma vuoi rimuovere?" << endl;
				scanf("%d", &rem_shape);
				if(rem_shape < 0 || rem_shape > 49)
				{
					pippo.WarningMessage("Indice non valido");
					break;
				}
				pippo.Remove_shape(rem_shape);
				break;
			case 4:
				pippo.Remove_all();
				break;
			default:
				cout << "Scelta non valida" << endl;
				break;
		}
		cout << "?";
		scanf("%d", &scelta);
	}
}