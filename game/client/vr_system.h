#include "openvr.h"
#ifndef VRSYSTEM_H
#define VRSYSTEM_H
//-----------------------------------------------------------------------------
//  OpenVR Globals
//-----------------------------------------------------------------------------

//openvr related
typedef struct {
    vr::VRActionHandle_t handle;
    char fullname[256];
    char type[256];
    char* name;
}action;
typedef struct {
    vr::VRActionSetHandle_t handle;
    char name[256];
}actionSet;
vr::IVRSystem*          g_pSystem = NULL;
vr::IVRInput*           g_pInput = NULL;
vr::TrackedDevicePose_t g_poses[vr::k_unMaxTrackedDeviceCount];
actionSet               g_actionSets[16];
int                     g_actionSetCount = 0;
vr::VRActiveActionSet_t g_activeActionSets[16];
int                     g_activeActionSetCount = 0;
action                  g_actions[64];
int                     g_actionCount = 0;

//other
float                   g_horizontalFOV = 0;
float                   g_verticalFOV = 0;
float                   g_aspectRatio = 0;
float                   g_horizontalOffset = 0;
float                   g_verticalOffset = 0;
float                   g_calculatedHorizontalOffset = 0;
float                   g_calculatedVerticalOffset = 0;
#endif