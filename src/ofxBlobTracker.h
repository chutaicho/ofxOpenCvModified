/*
 *  ofxBlobTracker.h
 *
 *  reference source : http://nuicode.com/projects/ccv
 *  k-nearest neighbor algorithm : http://en.wikipedia.org/wiki/K-nearest_neighbor_algorithm
 *  
 *  @version 1.0 - 01/2010
 *  @version 2.0 - 08/2014
 *  
 */

#pragma once 

#include <list>
#include <map>
#include "ofxCvContourFinder.h"

class ofxBlobTracker
{
public:
    ofxBlobTracker() : IDCounter(0), _tracked(false){};
    ~ofxBlobTracker(){};
    
    void track(ofxCvContourFinder* newBlobs);
    
    std::vector<ofxCvBlob>  trackedBlobs;
    
private:
    int trackKnn(ofxCvContourFinder* newBlobs, ofxCvBlob *track, int k, double thresh = 0);
    
    int	 IDCounter; // counter of last blob
    bool _tracked;
};