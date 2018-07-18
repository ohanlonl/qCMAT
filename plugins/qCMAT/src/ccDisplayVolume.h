//##########################################################################
//#                                                                        #
//#                           		 qCMAT								   #
//#					(Coastal Management Analysis Toolbox)			  	   #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU Library General Public License as       #
//#  published by the Free Software Foundation; version 2 of the License.  #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#         COPYRIGHT: Lancaster University Environment Center 2017        #
//#           WRITTEN BY: Liam O'Hanlon & Arthur-Louis Heath               #
//##########################################################################

#ifndef CC_DISPLAY_VOLUME_H
#define CC_DISPLAY_VOLUME_H


//Interface includes
#include "ui_displayVolume.h"
#include "ccStdPluginInterface.h"

//Qt includes
#include <QDialog>
#include <QMainWindow>
#include <QLineEdit>


class ccDisplayVolume : public QDialog, public Ui::displayVolume
{
/*
Display calculated volumes to text window in a QTDialog
*/
	Q_OBJECT

public:
//TODOl fix max slices; const int?
	ccDisplayVolume(QWidget* parent = 0, float[][102] = 0, int = 0, int = 0, ccMainAppInterface* = 0);
protected slots:
	void closeDisplay();
private:
};


#endif // DISPLAY_VOLUME_H