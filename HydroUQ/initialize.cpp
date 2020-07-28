/*********************************************************************************
**
** Copyright (c) 2020 University of California, Berkeley
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** 1. Redistributions of source code must retain the above copyright notice, this
** list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright notice, this
** list of conditions and the following disclaimer in the documentation and/or other
** materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its contributors may
** be used to endorse or promote products derived from this software without specific
** prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
** SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGE.
**
***********************************************************************************/

// Contributors:
// Ajay B Harish, Post-Doc @ SimCenter, UC Berkeley
// Dr. Frank McKenna, CTO of SimCenter, UC Berkeley
// Prof. Sanjay Govindjee, Director of SimCenter, UC Berkeley

//*********************************************************************************
// In this routines related to all parts of initialization
//*********************************************************************************

//*********************************************************************************
// Include user headers
//*********************************************************************************
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfaceframe.h"

//*************************************************************************************
//Initialize the optionmap that relates the stack to be opened to the simulation type
//*************************************************************************************
void MainWindow::initialize()
{
    //Set the stacked widget to zero window
    ui->OptionsStack->setCurrentIndex(0);
    treeflag = 1;

    // Initialize the string list from tree options
    optiontree << "Project details" << "Bathymetry" << "SW-CFD interface" << "Buildings" << "Floating bodies";
    optiontree << "Meshing" << "Materials";
    optiontree  << "Initial conditions" << "Boundary conditions";
    optiontree << "Basic" << "Advanced" << "Submit to TACC";

    // Set the options for stacked widget
    // Map for options
    optionmap.setZero(12,8);


    optionmap(0,0) = 0;// Project page
    optionmap(1,0) = 1; // Bathymetry
    optionmap(2,0) = 2; // SW-CFD interface
    optionmap(3,0) = 3; // Buildings
    optionmap(4,0) = 4; // Floating bodies
    optionmap(5,0) = 5; // Meshing
    optionmap(6,0) = 6; // Materials
    optionmap(7,0) = 7; // Initial conditions
    optionmap(8,0) = 8; // Boundary conditions

    // Advanced solver settings
    optionmap(9,0) = 0; // Select simtype
    optionmap(9,1) = 20; // CFD to resolve SW (with SW results)
    optionmap(9,2) = 20; // CFD to resolve SW (simlibrary results)
    optionmap(9,3) = 20; // CFD using bathymetry data
    optionmap(9,4) = 20; // CFD of wave flume
    optionmap(9,5) = 20; // CFD using STL
    optionmap(9,6) = 20; // CFD using maps
    optionmap(9,7) = 20; // CFD using surrogate

    // Submission to TACC settings
    optionmap(10,0) = 0; // Select simtype
    optionmap(10,1) = 21; // CFD to resolve SW (with SW results)
    optionmap(10,2) = 21; // CFD to resolve SW (simlibrary results)
    optionmap(10,3) = 21; // CFD using bathymetry data
    optionmap(10,4) = 21; // CFD of wave flume
    optionmap(10,5) = 21; // CFD using STL
    optionmap(10,6) = 21; // CFD using maps
    optionmap(10,7) = 21; // CFD using surrogate

    // Post-processing settings
    optionmap(11,0) = 0; // Select simtype
    optionmap(11,1) = 22; // CFD to resolve SW (with SW results)
    optionmap(11,2) = 22; // CFD to resolve SW (simlibrary results)
    optionmap(11,3) = 22; // CFD using bathymetry data
    optionmap(11,4) = 22; // CFD of wave flume
    optionmap(11,5) = 22; // CFD using STL
    optionmap(11,6) = 22; // CFD using maps
    optionmap(11,7) = 22; // CFD using surrogate

    // SW-CFD Interface
    ui->Btn_BB_UploadFile->hide();
    ui->Btn_BB_Previous->setDisabled(true);
    ui->SWg_BB_Interface->insertWidget(0,new InterfaceFrame("Untitled"));
    ui->SWg_BB_Interface->setCurrentIndex(0);

    // Other
    ui->Btn_EA_UploadMesh->hide();
    ui->Btn_HB_NorthUploadFile->hide();
    ui->Btn_HB_SouthUploadFile->hide();
    ui->Btn_HB_EastUploadFile->hide();
    ui->Btn_HB_WestUploadFile->hide();
    ui->Btn_HB_Previous->setDisabled(true);
    ui->Btn_HC_EntryUploadFile->hide();
    ui->Btn_HC_ExitUploadFile->hide();
    ui->Btn_HC_Previous->setDisabled(true);
    ui->Btn_IA_UploadFiles->hide();

    // Hide Boundary condition elements (SW solutions)
    // North
    ui->Btn_HB_NorthUploadFile->hide();
    ui->Cmb_HB_NorthWaveType->hide();
    ui->Lbl_HB_NorthPara->hide();
    ui->Led_HB_NorthPara->hide();
    ui->Lbl_HB_NorthU->hide();
    ui->Led_HB_NorthUx->hide();
    ui->Led_HB_NorthUy->hide();
    ui->Led_HB_NorthUz->hide();
    ui->Lbl_HB_NorthOrigin->hide();
    ui->Led_HB_NorthOriginX->hide();
    ui->Led_HB_NorthOriginY->hide();
    ui->Led_HB_NorthOriginZ->hide();
    ui->Lbl_HB_NorthVec->hide();
    ui->Led_HB_NorthVecX->hide();
    ui->Led_HB_NorthVecY->hide();
    ui->Led_HB_NorthVecZ->hide();
    ui->Lbl_HB_NorthPres->hide();
    ui->Led_HB_NorthPres->hide();
    // South
    ui->Btn_HB_SouthUploadFile->hide();
    ui->Cmb_HB_SouthWaveType->hide();
    ui->Lbl_HB_SouthPara->hide();
    ui->Led_HB_SouthPara->hide();
    ui->Lbl_HB_SouthU->hide();
    ui->Led_HB_SouthUx->hide();
    ui->Led_HB_SouthUy->hide();
    ui->Led_HB_SouthUz->hide();
    ui->Lbl_HB_SouthOrigin->hide();
    ui->Led_HB_SouthOriginX->hide();
    ui->Led_HB_SouthOriginY->hide();
    ui->Led_HB_SouthOriginZ->hide();
    ui->Lbl_HB_SouthVec->hide();
    ui->Led_HB_SouthVecX->hide();
    ui->Led_HB_SouthVecY->hide();
    ui->Led_HB_SouthVecZ->hide();
    ui->Lbl_HB_SouthPres->hide();
    ui->Led_HB_SouthPres->hide();
    // East
    ui->Btn_HB_EastUploadFile->hide();
    ui->Cmb_HB_EastWaveType->hide();
    ui->Lbl_HB_EastPara->hide();
    ui->Led_HB_EastPara->hide();
    ui->Lbl_HB_EastU->hide();
    ui->Led_HB_EastUx->hide();
    ui->Led_HB_EastUy->hide();
    ui->Led_HB_EastUz->hide();
    ui->Lbl_HB_EastOrigin->hide();
    ui->Led_HB_EastOriginX->hide();
    ui->Led_HB_EastOriginY->hide();
    ui->Led_HB_EastOriginZ->hide();
    ui->Lbl_HB_EastVec->hide();
    ui->Led_HB_EastVecX->hide();
    ui->Led_HB_EastVecY->hide();
    ui->Led_HB_EastVecZ->hide();
    ui->Lbl_HB_EastPres->hide();
    ui->Led_HB_EastPres->hide();
    // West
    ui->Btn_HB_WestUploadFile->hide();
    ui->Cmb_HB_WestWaveType->hide();
    ui->Lbl_HB_WestPara->hide();
    ui->Led_HB_WestPara->hide();
    ui->Lbl_HB_WestU->hide();
    ui->Led_HB_WestUx->hide();
    ui->Led_HB_WestUy->hide();
    ui->Led_HB_WestUz->hide();
    ui->Lbl_HB_WestOrigin->hide();
    ui->Led_HB_WestOriginX->hide();
    ui->Led_HB_WestOriginY->hide();
    ui->Led_HB_WestOriginZ->hide();
    ui->Lbl_HB_WestVec->hide();
    ui->Led_HB_WestVecX->hide();
    ui->Led_HB_WestVecY->hide();
    ui->Led_HB_WestVecZ->hide();
    ui->Lbl_HB_WestPres->hide();
    ui->Led_HB_WestPres->hide();

    // Hide Boundary conditions (Flume)
    // Entry
    ui->Btn_HC_EntryUploadFile->hide();
    ui->Cmb_HC_EntryWaveType->hide();
    ui->Lbl_HC_EntryPara->hide();
    ui->Led_HC_EntryPara->hide();
    ui->Lbl_HC_EntryU->hide();
    ui->Led_HC_EntryUx->hide();
    ui->Led_HC_EntryUy->hide();
    ui->Led_HC_EntryUz->hide();
    ui->Lbl_HC_EntryOrigin->hide();
    ui->Led_HC_EntryOriginX->hide();
    ui->Led_HC_EntryOriginY->hide();
    ui->Led_HC_EntryOriginZ->hide();
    ui->Lbl_HC_EntryVec->hide();
    ui->Led_HC_EntryVecX->hide();
    ui->Led_HC_EntryVecY->hide();
    ui->Led_HC_EntryVecZ->hide();
    ui->Lbl_HC_EntryPres->hide();
    ui->Led_HC_EntryPres->hide();
    // Exit
    ui->Btn_HC_ExitUploadFile->hide();
    ui->Cmb_HC_ExitWaveType->hide();
    ui->Lbl_HC_ExitPara->hide();
    ui->Led_HC_ExitPara->hide();
    ui->Lbl_HC_ExitU->hide();
    ui->Led_HC_ExitUx->hide();
    ui->Led_HC_ExitUy->hide();
    ui->Led_HC_ExitUz->hide();
    ui->Lbl_HC_ExitOrigin->hide();
    ui->Led_HC_ExitOriginX->hide();
    ui->Led_HC_ExitOriginY->hide();
    ui->Led_HC_ExitOriginZ->hide();
    ui->Lbl_HC_ExitVec->hide();
    ui->Led_HC_ExitVecX->hide();
    ui->Led_HC_ExitVecY->hide();
    ui->Led_HC_ExitVecZ->hide();
    ui->Lbl_HC_ExitPres->hide();
    ui->Led_HC_ExitPres->hide();

    // Set pages to one
    ui->SWg_BB_Interface->setCurrentIndex(0);
    ui->SWg_HB_BConditions->setCurrentIndex(0);
    ui->SWg_HC_BConditions->setCurrentIndex(0);
}