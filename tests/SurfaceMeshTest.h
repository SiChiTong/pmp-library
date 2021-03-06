//=============================================================================
// Copyright (C) 2011-2019 The pmp-library developers
//
// This file is part of the Polygon Mesh Processing Library.
// Distributed under the terms of the MIT license, see LICENSE.txt for details.
//
// SPDX-License-Identifier: MIT
//=============================================================================
#pragma once
//=============================================================================

#include "gtest/gtest.h"

#include <pmp/SurfaceMesh.h>
#include <vector>

class SurfaceMeshTest : public ::testing::Test
{
public:
    pmp::SurfaceMesh mesh;
    pmp::Vertex v0,v1,v2,v3;
    pmp::Face f0;
    using Point = pmp::Point;

    void add_triangle()
    {
        v0 = mesh.add_vertex(Point(0,0,0));
        v1 = mesh.add_vertex(Point(1,0,0));
        v2 = mesh.add_vertex(Point(0,1,0));
        f0 = mesh.add_triangle(v0,v1,v2);
    }

    void add_quad()
    {
        v0 = mesh.add_vertex(Point(0,0,0));
        v1 = mesh.add_vertex(Point(1,0,0));
        v2 = mesh.add_vertex(Point(1,1,0));
        v3 = mesh.add_vertex(Point(0,1,0));
        f0 = mesh.add_quad(v0,v1,v2,v3);
    }
};
