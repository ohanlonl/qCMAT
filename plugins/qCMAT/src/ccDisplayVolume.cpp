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

//Include header
#include "ccDisplayVolume.h"
//qCMAT include for close method
#include "ccVolumeTool.h"
//stdlib includes
#include <string>
//Qt includes
#include <QString>

ccDisplayVolume::ccDisplayVolume(QWidget* parent, float volumes[][102], int noSlices, int noClouds, ccMainAppInterface* app)
	: QDialog(parent, Qt::Tool)
	, Ui::displayVolume()
{
	/*
	Set up UI, connect QObjects and generate/display text for window from volumes array in the following format:
	
	| [Slice no.] | [Bottom] | [Top] | [Cloud name 0] | [Cloud Name 2]  | ...
	| 0			  |	val		 |	val	 |	val			  |		val			| ...
	| 1			  |	val		 |	val	 |	val			  |		val			| ...
	| ...		  |	...		 |	...	 |	...			  |	...				| ...

	Arguments:
		app: ccMainAppInterface* -> Pointer to main app interface  
		volumes : float[][max slices] -> 2d array holding volumes of each slice (2nd dim) for each cloud (1st dim)
		noSlices : int -> number of countours per cloud stored in volume
		noClouds : int -> number of clouds whose volumes are stored in volumes
	*/

	setupUi(this);

	m_app = app;

	//Connects
	connect( cancelButton, SIGNAL(rejected()), this, SLOT( closeDisplay() ));

	/* Assumption: assumes array is full, if not it will output 0 */

	//Write number of contours calculated	
	Text->append(QString::fromStdString( std::to_string(noSlices) + " contours"));

	//string to generate text in; first line has format of output
	std::string str = "[Slice no.]  ;  [bottom]  |  [top] ";

	//for each cloud
	for(int i = 0; i < noClouds; i++){
		//add cloud name to format line
		str += " | " + (m_app->getSelectedEntities()[i]->getName().toStdString());
	}

	//Print format line
	Text->append(QString::fromStdString(str));

	//for each contour
	for(int i = 0; i < noSlices; i++){
		//declare output sting, add Slice no. top and botom to it
		std::string bottom =  std::to_string(volumes[i][0]);
		std::string top = std::to_string(volumes[i][1]);
		std::string output = std::to_string(i + 1) + "; "+ bottom.substr(0, bottom.length() - 3) + " | " + top.substr(0, top.length() - 3);

		//for each cloud
		for(int j = 0; j < noClouds; j++){
			//round to 3 decimal places; avoid changing volumes
			std::string str = std::to_string(volumes[i][j+2]);
			output += " | " + str.substr(0, str.length() - 3);
		}

		//Display output string
		Text->append(QString::fromStdString( output));
	}
}

void ccDisplayVolume::closeDisplay(){
	/* Close the display */
	this->close();
	//reopen previoud dialog
		ccVolumeTool volt(m_app->getMainWindow());
		volt.initializeTool(m_app);
		volt.exec();
}