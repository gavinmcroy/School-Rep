//
// Created by Gavin Taylor Mcroy on 11/28/21.
//

#ifndef TEST_SUBDIVISIONCURVE_H
#define TEST_SUBDIVISIONCURVE_H

#ifndef _SUBDIVISION_H_
#define _SUBDIVISION_H_

#include <vector>
#include "Point.h"

class SubdivisionCurveEvaluator {
public:
    SubdivisionCurveEvaluator() {
        Mask = 0.5;
    }

    void evaluateCurve(const std::vector<Point> &ptvCtrlPts,
                       std::vector<Point> &ptvEvaluatedCurvePts,
                       const float &fAniLength,
                       const bool &bWrap,
                       const bool &bAdaptive,
                       const double &dTension) const;

private:
    float Mask;
};

#endif


#endif //TEST_SUBDIVISIONCURVE_H
