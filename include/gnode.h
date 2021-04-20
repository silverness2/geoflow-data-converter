//==============================================================================
// Date        : 3/23/21 (SG)
// Description : Stores the location and data value of a GeoFLOW node.
// Copyright   : Copyright 2021. Regents of the University of Colorado.
//               All rights reserved.
//==============================================================================

#ifndef GNODE_H
#define GNODE_H

#include <iostream>
#include <vector>
#include <array>

#include "gtypes.h"

using namespace std;

template <class T>
class GNode
{
public:
     /*!
     * Constructor for initializeing a GeoFLOW node.
     * 
     * @param x cartesian x coordinate
     * @param y cartesian y coordinate
     * @param z cartesian z coordinate
     * @param elemLayerID ID of layer the GeoFLOW element resides on
     */
    GNode(T x, T y, T z, GSIZET elemLayerID)
    {
        // Initialize
        _pos = {{x, y, z}};
        _elemLayerID = elemLayerID;
        _var = T(0);
        _lat = T(0);
        _lon = T(0);
        _radius = T(0);
    }
    ~GNode() {}

    // Access
    array<T, 3> pos() const { return _pos; }
    void pos(const array<T, 3>& pos) { _pos = pos; }
    T lat() const { return _lat; }
    void lat(const T& lat) { _lat = lat; }
    T lon() const { return _lon; }
    void lon(const T& lon) { _lon = lon; }
    T radius() const { return _radius; }
    void radius(const T& radius) { _radius = radius; }
    T var() const { return _var; }
    void var(const T& var) { _var = var; }

    // Print
    void printNode()
    {
        cout << "Node: ";
        cout << "(x, y, z): (" << _pos[0] << ", " 
                               << _pos[1] << ", "
                               << _pos[2] << ") | ";
        cout << "(lat, lon, r): (" << _lat << ", " 
                                   << _lon << ", "
                                   << _radius << ") | ";
        cout << "elemLayerID: (" << _elemLayerID << ") | ";
        cout << "var: (" << _var << ")";
        cout << endl;
    }

private:
    array<T, 3> _pos;    // cartesian coordinate x,y,z of node
    T _lat;              // lat coordinate of node
    T _lon;              // lon coordinate of node
    T _var;              // variable value at node
    T _radius;           // radius of node
    GSIZET _elemLayerID; // element layer index the node resides on
};

#endif
