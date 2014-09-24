#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxUI.h"
#include "ofxDOF.h"
#include "MotionDetector.h"
#include "ModelFace.h"

enum destructionMode{
    MODEL_DESTRUCT_TOP = 0,
    MODEL_DESTRUCT_BOTTOM,
    MODEL_DESTRUCT_OPPOSITE
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void guiEvent(ofxUIEventArgs &e);
    
    bool dislodge(MotionDetector& mD,
                  std::vector<ModelFace>& modelFaces,
                  std::vector<ModelFace>& otherModelFaces,
                  bool bRemoveFromTop,
                  bool bModel1);
    
    bool allFacesSettled();
    
    void initMeshFaces();
    void resetCamera();
    ofVec3f getPointInBoundingBox();
    
    int nearestFaceIndex;
    int modelDistance;
    int destructMode;
    
    float startCameraFOV;
    float startCameraAspectRatio;
    float startCameraNearClip;
    float startCameraFarClip;
    float cameraDistance;
    float cameraXOrbit;
    float cameraYOrbit;
    float modelY;
    
    bool isPaused;
    bool bShowBoundingBox;
    bool bBoundingBoxChanged;
    bool bDOFEnabled;
    bool bDrawDOFFocusAssist;
    bool bMD1UseLiveVideo;
    bool bMD2UseLiveVideo;
    bool bAllFacesDislodged1;
    bool bAllFacesDislodged2;
    bool bDestroyTop1;
    bool bDestroyTop2;
    bool bFacesWaiting;
    
    ofVec3f nearestVertex;
    
    std::vector<ModelFace> model1Faces;
    std::vector<ModelFace> model2Faces;
    
    ofMesh model1Mesh;
    ofMesh model2Mesh;
    
    ofBoxPrimitive boundingBox;
    
    ofEasyCam camera;
    ofMaterial material;
    ofLight dLight;
    
    ofxAssimpModelLoader model;
    ofxUIScrollableCanvas *gui;
    ofxDOF depthOfField;
    
    MotionDetector mD1;
    MotionDetector mD2;
};
