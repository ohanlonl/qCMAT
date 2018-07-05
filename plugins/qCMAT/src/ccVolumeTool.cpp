//##########################################################################
//#                                                                        #
//#                CLOUDCOMPARE PLUGIN: qCMAT                              #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                             COPYRIGHT: Lancaster University            #
//#                                                                        #
//##########################################################################


#include "displayVolume.h"
#include "ccVolumeTool.h"
#include "ccHObject.h"
#include "SimpleCloud.h"
#include "ui_ccVolumeTool.h"
//#include "ccCropTool.h"

#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <CloudSamplingTools.h>
#include <string>
#include <QOpenGLWidget>


//ccLib
#include <Delaunay2dMesh.h>
#include <PointProjectionTools.h>
#include <ccProgressDialog.h>
#include <ccGLWidget.h>
#include <ccColorTypes.h>


//cute <3
#include <QMessageBox>
#include <QSettings>
#include <QLineEdit>
#include <QSurfaceFormat>
#include <QFileDialog>
//#include <genericPointAction>

ccVolumeTool::ccVolumeTool(QWidget* parent)
	: QDialog(parent, Qt::Tool)
	, Ui::ccVolumeTool()

{
	setupUi(this);

	connect( SaveCloudCont,	SIGNAL(clicked()), this, SLOT( saveCloudContours() ));
	connect( CalcContours,	SIGNAL(clicked()), this, SLOT( contourVolume() ));
	connect( LoadCFile,	SIGNAL(clicked()), this, SLOT( readCSVContours() ));
	connect( DisplayVolume,	SIGNAL(clicked()), this, SLOT( displayVolmes() ));
	connect( CalcLoadFile,	SIGNAL(clicked()), this, SLOT( loadContVolume() ));
	//connect( CalcVolButton,	SIGNAL(clicked()), this, SLOT( testConsole()));
	//connect( pushButton_3,	SIGNAL(clicked()), this, SLOT( testConsole()));
	connect( saveButton,	SIGNAL(clicked()), this, SLOT( saveVolume())); //presumably save
	//connect( pushButton_1,	SIGNAL(clicked()), this, SLOT( testConsole()));
	/**connect(unionPushButton,	SIGNAL(clicked()), this, SLOT(unionSelected()));
	connect( viewPushButton,	SIGNAL(clicked()), this, SLOT( cancelButtonClicked() ));
	connect(interPushButton,	SIGNAL(clicked()), this, SLOT(intersectSelected()));
	connect(diffPushButton,		SIGNAL(clicked()), this, SLOT(diffSelected()));
	connect(symDiffPushButton,	SIGNAL(clicked()), this, SLOT(symDiffSelected()));
	connect(swapToolButton,		SIGNAL(clicked()), this, SLOT(swap()));**/
}

void ccVolumeTool::saveCloudContours(){
	//Color and save cloud contours
	//we need to map contours to rgb colors
	ccPointCloud* contouredCloud = new ccPointCloud();
	//typecast main cloud
	ccPointCloud* oldCloud = ccHObjectCaster::ToPointCloud(mainCloud);

	//check error
	if(noSlices == 0){
		//no data calculated
		return;
	}
	//create a noSlices large array of rgb's
//TODO; figure our rgb type; make array of rgb's	
	float contourColors[noSlices][3]; //one each for r g and b
	//calculate a color for each clice
	for(int i = 0; i < noSlices; i++){
		//generate a num between 0 and 1 and multiply them with MAX of scale
		//this is our total number
		//static Rgb hsl2rgb(float H, float S, float L), we HSL nao
		/*
			float H = (i * (360.0 / noSlices));
			float S = 100;
			float L = 50;

			H /= 360;
			float q = L < 0.5f ? L * (1.0f + S) : L + S - L * S;
			float p = 2 * L - q;

			float r = hue2rgb(p, q, H + 1.0f / 3.0f);
			float g = hue2rgb(p, q, H);
			float b = hue2rgb(p, q, H - 1.0f / 3.0f);
		*/
		contourColors[i][0] = (int) 155.0 + sqrt(i * (100.0 * 100 / noSlices)); //(int) i * (255.0 / noSlices);
		contourColors[i][1] = (int) ( (255.0) * i / noSlices);
		contourColors[i][2] = 0;
		
		//contourColors[i][0] = (int) ((255.0 / noSlices) * i);
		//contourColors[i][1] = (int) (((255.0 / noSlices) / 2) * i) + 120;
		//contourColors[i][2] = (int) ((255.0 / noSlices) * i);



	}
	//for each point in cloud
	contouredCloud->reserveThePointsTable(oldCloud->size());
	contouredCloud->reserveTheRGBTable();	

		//for each point in the cloud
	for(int i = 0; i < oldCloud->size(); i++){
		//get point point
		CCVector3 tempVect;
		oldCloud->getPoint(i, tempVect); //get point values
		//check what contours scalar fits in
		//for each contour
		bool setPointFlag = false;
		//go though each contour
		for(int j = 0; j < noSlices; j++){
			if(tempVect[2] >= sliceInfo[j][1] && tempVect[2] < sliceInfo[j][2]){
				contouredCloud->addRGBColor(contourColors[j][0], contourColors[j][1], contourColors[j][2]); //add same crap for testing purposes
				contouredCloud->addPoint(tempVect);
				setPointFlag = true;
				break;
			}
		}
		if(!setPointFlag){
			contouredCloud->addRGBColor(oldCloud->getPointColor(i)); //add same crap for testing purposes	
			contouredCloud->addPoint(tempVect);
		}
		//copy cloud with different color
		//default color if not in any contour (black?)

		//add scalar (colorType r, colorType g, colorType b);
		//contouredCloud->addRGBColor(contourColors[i][0], contourColors[i][1], contourColors[i][2]); //add same crap for testing purposes
		
		//(unsigned pointIndex, const colorType* col)
		//contouredCloud->setPointColor(i, colorType::red );
	//if(contouredCloud->hasColors()){
	//	m_app->dispToConsole("Cloud has colors!");
	//}
	}
	//save cloud to DB_tree ->addToDB(ccHObject* obj, bool updateZoom = false, bool autoExpandDBTree = true, bool checkDimensions = false, bool autoRedraw = true) = 0;
	//contouredCloud->unallocateColors();
	//contouredCloud->showSFColorsScale(true); //display colors from the getgo
	contouredCloud->setCurrentDisplayedScalarField(0);
	//mainCloud->addChild(contouredCloud, 24, -1);
	m_app->addToDB(contouredCloud, /*updateZoom*/ false, /*autoExpandDBTree*/  true, /*checkDimensions*/ true, /*autoRedraw*/true);


}


void ccVolumeTool::readCSVContours(){
	//read contours from a file and calculate those volumes
	QString fileName = QFileDialog::getOpenFileName(this, "Load contours (.csv)", "", "Load contours(*.csv);;All Files (*)");
	//check to see dialog wasn't cancelled / we actualy have a file
	if(fileName.size() == 0){
	    	//user cancelled or didnt enter a filename
	    	return;
	    }
	//stick the fies name in the text box
	    CFileName->setText(fileName);
}
<<<<<<< HEAD
=======

void loadCSVcontours(){
	/**	QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save contours"), "",
        tr("Save contours(*.csv);;All Files (*)"));**/
}
>>>>>>> 88ff4c73dffacf95739e4c78890dbd803ea741b6

void ccVolumeTool::loadContVolume(){

// debugging stuff
//	m_app->dispToConsole("Im here");
//	usleep(50000);

	//get file name
	QString fileName = CFileName->text();
	//open file stream
	std::ifstream contFile;
	//report potential errors
	contFile.open(fileName.toStdString());


	std::string line = ""; //empty variable to read line into
	//remove the first line
    std::vector<std::string> numbers;

	if(contFile.fail()){
		//TODO: think of a less patronizing error message
		m_app->dispToConsole("Error reading file, maybe it isn't there?");
		return;
	}
	getline(contFile, line);
	if(contFile.eof() || line == ""){
		m_app->dispToConsole("Error reading file, maybe it isn't there?");
		contFile.close();
		return;
	}

	//assume format [id] [bottom] [top] ...

	//getline(contFile, line);//crop the first line
	//count the number of slices, if we reach max slices, then complain and exit
	noSlices = 0;

//TODO: might be nicer with a for loop
	
	//Count selected entities


	while(true){
		//check for EOF
		getline(contFile, line);

		//if not split it up

	    //convert line to char*

	    numbers = split( line.c_str(), std::string(",") );
		//m_app->dispToConsole(QString::fromStdString(numbers[0] + "  Hi there  " + numbers[1] ));
		//calculate volumes
		//int bottom = numbers[0];
		//int top = numbers[1];
		sliceInfo[noSlices][1] = std::strtof(numbers[1].c_str(),0);
		sliceInfo[noSlices][2] = std::strtof(numbers[2].c_str(),0);
		//normalize and calculate volume || ugy hack, why isnt the first column relevant?
		ccPointCloud* tempCloud = normalizeCloud(ccHObjectCaster::ToPointCloud(mainCloud), std::strtof(numbers[1].c_str(),0), std::strtof(numbers[2].c_str(),0));
		sliceInfo[noSlices][0] = volumeBetweenHeights(sliceInfo[noSlices][1], sliceInfo[noSlices][2], tempCloud);
//	    m_app->dispToConsole(QString::fromStdString("[0]: " + numbers[0] + " [1]: " + numbers[1] + "[2]: " +  numbers[2]));

		noSlices++;

		if(contFile.eof() || line == ""){
			//next read would fail!
			contFile.close();
			return;
		}
		//check if we filled the array
		if(noSlices == MAX_SLICES){
			m_app->dispToConsole("Maximum number of contours reached, exiting");
			contFile.close();
			return;
		}
		//finish adding slice


	}

	//report errors

	//calculate volumes / store contour internally

	//close file
	contFile.close();
}

//TODO: calculate based on contours for file
/*
	std::ifstream volsFile;
  	if(! volsFile.open((fileName.toStdString() + ".csv").c_str())){
  		//error opening the file, kindly remind the user they messed up
  		m_app->dispToConsole("Error loading file! Are you sure it exists?" );
  		return;
  	}
*/

void ccVolumeTool::saveVolume(){
		//RELIES ON: float volumes[][3], int noSlices
		//Save the volumes into a file

		//get desired destination file
	    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save contours"), "",
        tr("Save contours(*.csv);;All Files (*)"));

	    if(fileName.size() == 0){
	    	//user cancelled or didnt enter a filename
	    	return;
	    }
		std::ofstream volsFile;
  		volsFile.open((fileName.toStdString() + ".csv").c_str(), std::ios::trunc);
  		//add header line
//probs wont end up doing that
		volsFile << "[Slice no.],[Bottom],[Top],[Volume]" << std::endl;
  		//add lines of text
  		for(int i = 0; i < noSlices; i++){
  			//generate the string
  			std::string entry = std::to_string(i) + "," + std::to_string(sliceInfo[i][1]) + "," + std::to_string(sliceInfo[i][2]) + "," + std::to_string(sliceInfo[i][0]);
  			//write string
  			volsFile << entry << std::endl;
  		}
  		//clean up
 //TODO: tons of error checking
  		volsFile.close();
  		m_app->dispToConsole(QString::fromStdString("Saved file: " + fileName.toStdString() + ".csv"));
}


void ccVolumeTool::testConsole(){
	m_app->dispToConsole("Hi there from testConsole()!");
}


//store a copy of m_app
void ccVolumeTool::initializeTool(ccMainAppInterface* app)
{
	m_app = app; //store copy of app


	//do calculations regarding cloud height
		//chop up cloud based on user input
		//get the height of the whole cloud
		noClouds = m_app->getSelectedEntities().size();



	ccHObject* cloud = m_app->getSelectedEntities()[0];
	ccBBox cBox = cloud->getOwnBB();
	CCVector3f cMin = cBox.minCorner();
	CCVector3f cMax = cBox.maxCorner();

	for(int i = 0; i < noClouds; i++){
	//for each cloud
	//well need z coordinates from bbox min and max
			//get coresponding ccBBox
			cloud = m_app->getSelectedEntities()[i];
			cBox = cloud->getOwnBB();
			//if max higher
			if(cBox.minCorner()[2] < cMin[2]){
				//new min corner
				cMin = cBox.minCorner();
			}
			//if max higher
			if(cBox.maxCorner()[2] > cMax[2]){
				//new min corner
				cMax = cBox.maxCorner();
			}

		}	
		height = cMax[2] - cMin[2];



		//initialize main cloud
		const std::vector<ccHObject*> clouds = m_app->getSelectedEntities();
//TODO: Add code for handling multiple clouds
		mainCloud = clouds[0];
		//Count the number of selected clouds




//TESTING CODE
//This now works! m_app->dispToConsole(std::to_string(height).c_str());
		std::string message = std::to_string(cMin[2]) + " - " + std::to_string(cMax[2]) + " : " + std::to_string(height) + " tot.";
		//display default value to the user
			heightDisplay->setText(QString::fromStdString(message));
			topInput->setText(QString::fromStdString(std::to_string(cMax[2])));
			bottomInput->setText(QString::fromStdString(std::to_string(cMin[2])));
}

/*void ccVolumeTool::contourPoints(const CCVector3& vec, ScalarType& scal){
	//if point not in contour
	if(vec[2] < sliceBottom || vec[2] > sliceTop){
		//remove point
//TODO, make this a delete not a tripple 0, although does it honestly matter? --> it might for the volume algorithm at the 00 chunk
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
		scal = 0;
	}
}*/


void ccVolumeTool::processClouds(){
	/*
	Loop through selected entities and calculate the volume based on user parameters,
	then display or save it appropriatly
	*/

//TODO: Assumtion is that theyre all legit clouds
	const std::vector<ccHObject*> clouds = m_app->getSelectedEntities();
//TODO: Add code for handling multiple clouds
	mainCloud = clouds[0];
	//chop up cloud based on user input
		//get the height of the whole cloud

		//display it to the user somehow

		//query size of users section

	volumeBetweenHeights( 0, 0 , ccHObjectCaster::ToPointCloud(mainCloud));
}

void ccVolumeTool::displayVolmes(){
	//open the display
		displayVolume volt(m_app->getMainWindow(), sliceInfo, noSlices, noClouds);
		//volt.initializeTool(m_app); //don't forget to pass contours as an argument
		volt.exec();
}



void ccVolumeTool::contourVolume(){

		//get users chunk size
		userBottom = maxBottom;
		userTop = maxTop;
		userBottom = bottomInput->text().toFloat();
		userTop = topInput->text().toFloat();
		//get number of slices
		noSlices = noSliceInput->text().toFloat();
		//make sure its legit
		//if(userTop > maxTop || userBottom < maxBottom){
		//	m_app->dispToConsole("Error, chosen contrours not in cloud!");
		//	return;
		//}
		//calculate the size of each chunk
//TODO assume top is positive
		if(userBottom > 0){
		height = userTop - userBottom;
		} else {
		height = userTop + userBottom * -1;
		}
		sliceSize = height / noSlices;
		//for each slice
		for(int i = 0; i < noSlices; i++){
			//save top and bottom
			sliceTop = userBottom + (i + 1) * sliceSize;
			sliceBottom = userBottom + i * sliceSize;
			sliceInfo[i][0] = sliceBottom;		//Bottom of slice
			sliceInfo[i][1] = sliceTop;	//Top of slice
			//type cast mainCloud
			//cainCloud = ccHObjectCaster::ToGenericPointCloud(mainCloud);
			//assign it to the normalized version of our cloud
//TESTING: for the sake of them sick tests stick it in the pointCloud
			//calculate volume of the new cloud

			//for each slice
			for(int j = 0; j < noClouds; j++){
				ccPointCloud* tempCloud = normalizeCloud(ccHObjectCaster::ToPointCloud((m_app->getSelectedEntities())[j] ), sliceBottom, sliceTop);
				sliceInfo[i][j + 2] = volumeBetweenHeights(sliceInfo[i][0], sliceInfo[i][1], tempCloud);
			}
			//report and save it

			//get rid of memory
		}
}


ccPointCloud* ccVolumeTool::normalizeCloud(ccPointCloud* cloud, float bottom, float top){
	//remember to pass this method a memeber
	//forEach(genericPointAction &  anAction)
	//cloud->forEach( ccVolumeTool::contourPoints );
	ccPointCloud* tempCloud = new ccPointCloud();
	//copy all points, but wait! normalize where z isnt within the slice boundries
	//make some space for all the new points
//TODO dont assume top is positive
	if(bottom < 0){
		bottom += bottom;
		top += bottom;
	}
	tempCloud->reserveThePointsTable(cloud->size());
		//for each point in the cloud
	for(int i = 0; i < cloud->size(); i++){
		//get that point
		CCVector3 tempVect;
		cloud->getPoint(i, tempVect); //get point values
		//modify z coordinates if necessery
		if(tempVect[2] < bottom){ //if below
			tempVect[2] = bottom;
		} else if(tempVect[2] > top){
			tempVect[2] = top;
		}
		//add it to the new cloud
//TODO make + - bottom more elegant
		//remove bottom of cloud from z coord
		tempVect[2] -= bottom;
		tempCloud->addPoint(tempVect);
	}
	//at this point, our boi point cloud should be full and normalized
	return tempCloud;

}



float ccVolumeTool::volumeBetweenHeights(float bottom, float top, ccPointCloud* theCloud){
	//get a list of all the clouds i guess | Assume its just one Cloud selected and given as argument
		//for now ignore min and max limits
	//start off by just displaying the volume
		//Fool! You thought that would be easy!

	//make a volume tool object, dont display it
	//force set all the settings and then call its calculate method

	//store the result of the volume computation
	ReportInfo result;
	ccRasterGrid grid;

	//specify grid step, 0.5 seems sensible
	float gridStep = 0.1;

	ccBBox gridBBox = theCloud->getOwnBB();
	//get grid width and height
	unsigned& gridWidth = *(new unsigned);
	unsigned& gridHeight = *(new unsigned);

	//get volume box size
	ccBBox box = ccBBox();

	ccRasterGrid::ComputeGridSize(2, gridBBox, gridStep, gridWidth, gridHeight);

	//std::cerr << "Width : " << gridHeight << std::endl;

	//projection type
	/*
	enum ProjectionType {	PROJ_MINIMUM_VALUE			= 0,
							PROJ_AVERAGE_VALUE			= 1,
							PROJ_MAXIMUM_VALUE			= 2,
							INVALID_PROJECTION_TYPE		= 255,
	};
	*/



	ComputeVolume(
			grid, //raster grid
			0,  //ground
			ccHObjectCaster::ToGenericPointCloud(theCloud),	//cieling
			gridBBox,		//grid box
			2,			//vert dimension, assume z
			gridStep,			//grid step
			gridWidth,		//grid width
			gridHeight,			//grid height
			ccRasterGrid::ProjectionType::PROJ_AVERAGE_VALUE,					//projection type
			ccRasterGrid::EmptyCellFillOption::LEAVE_EMPTY,			//fill ground empty cells strat
			ccRasterGrid::EmptyCellFillOption::LEAVE_EMPTY,			//fill ciel empty cells strat
			result,			//report info into result
			0.0 ,			//ground height
			0.0 ,			//ciel height
			m_app->getMainWindow()		//parent widget
			);

	//Print the computed volume
	m_app->dispToConsole(std::to_string(result.volume).c_str());

	return result.volume;
}


float ccVolumeTool::ComputeVolume(	ccRasterGrid& grid,
										ccGenericPointCloud* ground,
										ccGenericPointCloud* ceil,
										const ccBBox& gridBox,
										unsigned char vertDim,
										double gridStep,
										unsigned gridWidth,
										unsigned gridHeight,
										ccRasterGrid::ProjectionType projectionType,
										ccRasterGrid::EmptyCellFillOption groundEmptyCellFillStrategy,
										ccRasterGrid::EmptyCellFillOption ceilEmptyCellFillStrategy,
										ccVolumeTool::ReportInfo& reportInfo,
										double groundHeight,
										double ceilHeight,
										QWidget* parentWidget)
{
	if (	gridStep <= 1.0e-8
		||	gridWidth == 0
		||	gridHeight == 0
		||	vertDim > 2)
	{
		assert(false);
		ccLog::Warning("[Volume] Invalid input parameters");
		return -1;
	}

	if (!ground && !ceil)
	{
		assert(false);
		ccLog::Warning("[Volume] No valid input cloud");
		return -1;
	}

	if (!gridBox.isValid())
	{
		ccLog::Warning("[Volume] Invalid bounding-box");
		return -1;
	}

	//grid size
	unsigned gridTotalSize = gridWidth * gridHeight;
	if (gridTotalSize == 1)
	{
		if (parentWidget && QMessageBox::question(parentWidget, "Unexpected grid size", "The generated grid will only have 1 cell! Do you want to proceed anyway?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
			return -1;
	}
	else if (gridTotalSize > 10000000)
	{
		if (parentWidget && QMessageBox::question(parentWidget, "Big grid size", "The generated grid will have more than 10.000.000 cells! Do you want to proceed anyway?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
			return -1;
	}

	//memory allocation
	CCVector3d minCorner = CCVector3d::fromArray(gridBox.minCorner().u);
	if (!grid.init(gridWidth, gridHeight, gridStep, minCorner))
	{
		//not enough memory
		m_app->dispToConsole("Something went terribly wrong!");
		return -1;
	}
//TODO: FIgure out htis progress dialog thing
	//progress dialog
	QScopedPointer<ccProgressDialog> pDlg(0);
	if (parentWidget)
	{
		pDlg.reset(new ccProgressDialog(true, parentWidget));
	}

	ccRasterGrid groundRaster;
	if (ground)
	{
		if (!groundRaster.init(gridWidth, gridHeight, gridStep, minCorner))
		{
			//not enough memory
			m_app->dispToConsole("Looks like your a bit short on memory!");
			return -1;
		}

		if (groundRaster.fillWith(	ground,
									vertDim,
									projectionType,
									groundEmptyCellFillStrategy == ccRasterGrid::INTERPOLATE,
									ccRasterGrid::INVALID_PROJECTION_TYPE,
									pDlg.data()))
		{
			groundRaster.fillEmptyCells(groundEmptyCellFillStrategy, groundHeight);
			ccLog::Print(QString("[Volume] Ground raster grid: size: %1 x %2 / heights: [%3 ; %4]").arg(groundRaster.width).arg(groundRaster.height).arg(groundRaster.minHeight).arg(groundRaster.maxHeight));
		}
		else
		{
			return -1;
		}
	}

	//ceil
	ccRasterGrid ceilRaster;
	if (ceil)
	{
		if (!ceilRaster.init(gridWidth, gridHeight, gridStep, minCorner))
		{
			//not enough memory
		m_app->dispToConsole("Looks like your a bit short on memory!");
		return -1;
		}

		if (ceilRaster.fillWith(ceil,
								vertDim,
								projectionType,
								ceilEmptyCellFillStrategy == ccRasterGrid::INTERPOLATE,
								ccRasterGrid::INVALID_PROJECTION_TYPE,
								pDlg.data()))
		{
			ceilRaster.fillEmptyCells(ceilEmptyCellFillStrategy, ceilHeight);
			ccLog::Print(QString("[Volume] Ceil raster grid: size: %1 x %2 / heights: [%3 ; %4]").arg(ceilRaster.width).arg(ceilRaster.height).arg(ceilRaster.minHeight).arg(ceilRaster.maxHeight));
		}
		else
		{
			return -1;
		}
	}

	//update grid and compute volume
	{
		if (pDlg)
		{
			pDlg->setMethodTitle(QObject::tr("Volume computation"));
			pDlg->setInfo(QObject::tr("Cells: %1 x %2").arg(grid.width).arg(grid.height));
			pDlg->start();
			pDlg->show();
			QCoreApplication::processEvents();
		}
		CCLib::NormalizedProgress nProgress(pDlg.data(), grid.width * grid.height);

		size_t ceilNonMatchingCount = 0;
		size_t groundNonMatchingCount = 0;
		size_t cellCount = 0;

		//at least one of the grid is based on a cloud
		grid.nonEmptyCellCount = 0;
		for (unsigned i = 0; i < grid.height; ++i)
		{
			for (unsigned j = 0; j < grid.width; ++j)
			{
				ccRasterCell& cell = grid.rows[i][j];

				bool validGround = true;
				cell.minHeight = groundHeight;
				if (ground)
				{
					cell.minHeight = groundRaster.rows[i][j].h;
					validGround = std::isfinite(cell.minHeight);
				}

				bool validCeil = true;
				cell.maxHeight = ceilHeight;
				if (ceil)
				{
					cell.maxHeight = ceilRaster.rows[i][j].h;
					validCeil = std::isfinite(cell.maxHeight);
				}

				if (validGround && validCeil)
				{
					cell.h = cell.maxHeight - cell.minHeight;
					cell.nbPoints = 1;

					reportInfo.volume += cell.h;
					if (cell.h < 0)
					{
						reportInfo.removedVolume -= cell.h;
					}
					else if (cell.h > 0)
					{
						reportInfo.addedVolume += cell.h;
					}
					reportInfo.surface += 1.0;
					++grid.nonEmptyCellCount; //= matching count
					++cellCount;
				}
				else
				{
					if (validGround)
					{
						++cellCount;
						++groundNonMatchingCount;
					}
					else if (validCeil)
					{
						++cellCount;
						++ceilNonMatchingCount;
					}
					cell.h = std::numeric_limits<double>::quiet_NaN();
					cell.nbPoints = 0;
				}

				cell.avgHeight = (groundHeight + ceilHeight) / 2;
				cell.stdDevHeight = 0;

				if (pDlg && !nProgress.oneStep())
				{
					ccLog::Warning("[Volume] Process cancelled by the user");
					return -1;
				}
			}
		}
		grid.validCellCount = grid.nonEmptyCellCount;

		//count the average number of valid neighbors
		{
			size_t validNeighborsCount = 0;
			size_t count = 0;
			for (unsigned i = 1; i < grid.height - 1; ++i)
			{
				for (unsigned j = 1; j < grid.width - 1; ++j)
				{
					ccRasterCell& cell = grid.rows[i][j];
					if (cell.h == cell.h)
					{
						for (unsigned k = i - 1; k <= i + 1; ++k)
						{
							for (unsigned l = j - 1; l <= j + 1; ++l)
							{
								if (k != i || l != j)
								{
									ccRasterCell& otherCell = grid.rows[k][l];
									if (std::isfinite(otherCell.h))
									{
										++validNeighborsCount;
									}
								}
							}
						}

						++count;
					}
				}
			}

			if (count)
			{
				reportInfo.averageNeighborsPerCell = static_cast<double>(validNeighborsCount) / count;
			}
		}

		reportInfo.matchingPrecent = static_cast<float>(grid.validCellCount * 100) / cellCount;
		reportInfo.groundNonMatchingPercent = static_cast<float>(groundNonMatchingCount * 100) / cellCount;
		reportInfo.ceilNonMatchingPercent = static_cast<float>(ceilNonMatchingCount * 100) / cellCount;
		float cellArea = static_cast<float>(grid.gridStep * grid.gridStep);
		reportInfo.volume *= cellArea;
		reportInfo.addedVolume *= cellArea;
		reportInfo.removedVolume *= cellArea;
		reportInfo.surface *= cellArea;
	}

	grid.setValid(true);

	return reportInfo.volume;
}


//Helper fuction to do some splitting
std::vector<std::string> split(const char *phrase, std::string delimiter){
    std::vector<std::string> list;
    std::string s = std::string(phrase);
    s = s + ","; //Ugly hack
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return list;
}


static float hue2rgb(float m1, float m2, float hue)
	{
	if (hue < 0)
		hue += 1.0f;
	else if (hue > 1.0f)
		hue -= 1.0f;

	if (6 * hue < 1.0f)
		return m1 + (m2 - m1) * hue * 6;
	else if (2 * hue < 1.0f)
		return m2;
	else if (3 * hue < 2.0f)
		return m1 + (m2 - m1) * (4.0f - hue * 6);
	else
		return m1;
}