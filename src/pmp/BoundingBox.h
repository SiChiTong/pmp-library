//=============================================================================
// Copyright (C) 2013-2019 The pmp-library developers
//
// This file is part of the Polygon Mesh Processing Library.
// Distributed under the terms of the MIT license, see LICENSE.txt for details.
//
// SPDX-License-Identifier: MIT
//=============================================================================
#pragma once
//=============================================================================

#include <pmp/Types.h>

//=============================================================================

namespace pmp {

//=============================================================================

//! \addtogroup core core
//!@{

//! Simple class for representing a bounding box
class BoundingBox
{

public:
    //! construct infinite/invalid bounding box
    BoundingBox()
        : min_(std::numeric_limits<Scalar>::max()),
          max_(-std::numeric_limits<Scalar>::max())
    {
    }

    //! construct from min and max points
    BoundingBox(const Point& min, const Point& max) : min_(min), max_(max) {}

    //! add point to bbox
    BoundingBox& operator+=(const Point& p)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (p[i] < min_[i])
                min_[i] = p[i];
            else if (p[i] > max_[i])
                max_[i] = p[i];
        }
        return *this;
    }

    //! add two bboxes
    BoundingBox& operator+=(const BoundingBox& bb)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (bb.min_[i] < min_[i])
                min_[i] = bb.min_[i];
            if (bb.max_[i] > max_[i])
                max_[i] = bb.max_[i];
        }
        return *this;
    }

    //! get min point
    Point& min() { return min_; }

    //! get max point
    Point& max() { return max_; }

    //! get center point
    Point center() const { return 0.5f * (min_ + max_); }

    //! indicate if bbox is empty
    bool is_empty() const
    {
        return (max_[0] < min_[0] || max_[1] < min_[1] || max_[2] < min_[2]);
    }

    //! get size of the bbox
    Scalar size() const { return is_empty() ? 0.0 : distance(max_, min_); }

private:
    Point min_, max_;
};

//=============================================================================
//!@}
//=============================================================================
} // namespace pmp
//=============================================================================
