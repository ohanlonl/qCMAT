
//Include guard for DUMMY_FEAT_H
#ifndef EXTRACT_PROFILE_H
#define EXTRACT_PROFILE_H

//Necessery includes, the header for the Ui code generated by Qt and the interface through
//witch to communicate with the main program
#include "ui_extractProfile.h"
#include "ccStdPluginInterface.h"

//std includes
#include <vector>

#include <ccPickingListener.h>

//Include the Qt features used
#include <QMainWindow>
#include <QDialog>

//qCC includes NO LONGER ON CCPOINTPICKINGINTERFACE
//#include <ccPointPickingGenericInterface.h>
//#include <ccPointListPickingDlg.h>

#include <ccPickingHub.h>
#include <ccGLWindow.h>
#include <ccPointCloud.h>
#include <ccOverlayDialog.h>

class ccExtractProfile :  public ccOverlayDialog,  public ccPickingListener, public Ui::extractProfile
{
	Q_OBJECT //Important; lets Qt know to edit this code

public:
	//Constructor and Destructor declarations
	ccExtractProfile(ccPickingHub* pickingHub ,QWidget* parent = 0, ccMainAppInterface* = 0);
	~ccExtractProfile();
	//declaration of the main app interface
	ccMainAppInterface* m_app;

protected slots:
	//close tool
	void closeDisplay();
	void plotProfiles();

private:

        void onItemPicked(const ccPickingListener::PickedItem& pi);
        void pointPicked(ccHObject* entity, unsigned itemIdx, int x, int y, const CCVector3& P);

	//number of points picked (0, 1 or 2)
	unsigned noPointsPicked = 0;

	//number of clouds
	int noClouds = 0;

	//info for points defining line along witch to plot profile
	CCVector3 point1;
	CCVector3 point2;

	//Variables for line equation
	//direction vector coords
	//float l = 0; float m = 0; float n = 0;
	CCVector3 dv;
	//starting point coords are equal to point1

	//inherited from ccPointPickingGenericInterface
	void processPickedPoint(ccPointCloud* cloud, unsigned pointIndex, int x, int y);
//TODO: move to ccCMATTools
	double distancePointToLine(CCVector3, CCVector3, CCVector3);




};

#endif //Include guard for EXTRACT_PROFILE_H
