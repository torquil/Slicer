// .NAME vtkSlicerFiducialsGUI 
// .SECTION Description
// Main Fiducials GUI and mediator methods for slicer3. 


#ifndef __vtkSlicerFiducialsGUI_h
#define __vtkSlicerFiducialsGUI_h

#include "vtkSlicerBaseGUIWin32Header.h"
#include "vtkSlicerModuleGUI.h"
#include "vtkSlicerModuleLogic.h"
#include "vtkSlicerNodeSelectorWidget.h"
#include "vtkSlicerFiducialsLogic.h"
#include "vtkMRMLFiducialNode.h"
#include "vtkMRMLFiducialListNode.h"

#include "vtkKWFrame.h"
#include "vtkKWPushButton.h"
#include "vtkSlicerVisibilityIcons.h"
#include "vtkKWChangeColorButton.h"

// Description:
// This class implements Slicer's Fiducials GUI
//
//class vtkSlicerFiducialsDisplayWidget;
class vtkKWMultiColumnListWithScrollbars;
class vtkKWPushButton;
class vtkKWMessage;
class vtkSlicerVisibilityIcons;
class vtkKWChangeColorButton;

class VTK_SLICER_BASE_GUI_EXPORT vtkSlicerFiducialsGUI : public vtkSlicerModuleGUI
{
 public:
    // Description:
    // Usual vtk class functions
    static vtkSlicerFiducialsGUI* New (  );
    vtkTypeRevisionMacro ( vtkSlicerFiducialsGUI, vtkSlicerModuleGUI );
    void PrintSelf ( ostream& os, vtkIndent indent );
    
    // Description:
    // Get methods on class members ( no Set methods required. )
    vtkGetObjectMacro ( AddFiducialListButton, vtkKWPushButton);
    vtkGetObjectMacro ( AddFiducialButton, vtkKWPushButton);
    vtkGetObjectMacro ( VisibilityToggle, vtkKWPushButton);
    vtkGetObjectMacro ( VisibilityIcons, vtkSlicerVisibilityIcons);
    vtkGetObjectMacro ( ListColorButton, vtkKWChangeColorButton);
    vtkGetObjectMacro ( Logic, vtkSlicerFiducialsLogic);
    vtkGetObjectMacro ( FiducialListNode, vtkMRMLFiducialListNode );
    
    // Description:
    // API for setting FiducialListNode, Logic and
    // for both setting and observing them.
    
   
    void SetMRMLNode ( vtkMRMLFiducialListNode *node )
        { this->SetMRML ( vtkObjectPointer( &this->FiducialListNode), node ); }
    void SetAndObserveMRMLNode ( vtkMRMLFiducialListNode *node )
        { this->SetMRML ( vtkObjectPointer( &this->FiducialListNode), node ); }
    void SetModuleLogic ( vtkSlicerFiducialsLogic *logic )
    { this->SetLogic ( vtkObjectPointer (&this->Logic), logic ); }
    void SetAndObserveModuleLogic ( vtkSlicerFiducialsLogic *logic )
    { this->SetLogic ( vtkObjectPointer (&this->Logic), logic ); }

    // Description:
    // This method builds the Fiducials module GUI
    virtual void BuildGUI ( ) ;

    // Description:
    // Add/Remove observers on widgets in the GUI
    virtual void AddGUIObservers ( );
    virtual void RemoveGUIObservers ( );

    // Description:
    // Class's mediator methods for processing events invoked by
    // either the Logic, MRML or GUI.
    virtual void ProcessLogicEvents ( vtkObject *caller, unsigned long event, void *callData );
    virtual void ProcessGUIEvents ( vtkObject *caller, unsigned long event, void *callData );
    virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event, void *callData );
    
    // Description:
    // Methods describe behavior at module enter and exit.
    virtual void Enter ( );
    virtual void Exit ( );

    virtual void UpdateElement(int row, int col, char * str);
    virtual void UpdateVTK();

    // Description:
    // Getting and setting the mrml fiducail list node id
    vtkGetStringMacro(FiducialListNodeID);
    vtkSetStringMacro(FiducialListNodeID);

    // Description:
    // Which fiducial list node are we displaying in this gui?
    vtkSlicerNodeSelectorWidget* FiducialListSelectorWidget;
    
    // Description:
    // Set the selected node, the fid list id, and update the widgets
    void SetFiducialListNode(vtkMRMLFiducialListNode *fiducialListNode);
    
 protected:
    vtkSlicerFiducialsGUI ( );
    ~vtkSlicerFiducialsGUI ( );

    // Module logic and mrml pointers
    vtkSlicerFiducialsLogic *Logic;


    vtkMRMLFiducialListNode *FiducialListNode;

    // The ID of the fiducial list node
    char *FiducialListNodeID;
    
    // Widgets for the Fiducials module
    // add a list
    vtkKWPushButton *AddFiducialListButton;
    // add a point
    vtkKWPushButton *AddFiducialButton;
    // list visibility
    vtkKWPushButton *VisibilityToggle;
    vtkSlicerVisibilityIcons *VisibilityIcons;

    // list colour
    vtkKWChangeColorButton *ListColorButton;
    
    // display the points on the list
    vtkKWMultiColumnListWithScrollbars *MultiColumnList;
    // the columns that hold the
    // name, x, y, z, orientation x y z w, selected
    int NumberOfColumns;

private:
    vtkSlicerFiducialsGUI ( const vtkSlicerFiducialsGUI& ); // Not implemented.
    void operator = ( const vtkSlicerFiducialsGUI& ); //Not implemented.
};


#endif
