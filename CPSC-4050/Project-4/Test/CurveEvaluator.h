#ifndef INCLUDED_CURVE_EVALUATOR_H
#define INCLUDED_CURVE_EVALUATOR_H

#include "Curve.h"

class CurveEvaluator {
public:
    virtual ~CurveEvaluator();

    virtual void evaluateCurve(const std::vector<Point> &control_points,
                               std::vector<Point> &evaluated_curve_points,
                               const float &animation_length,
                               const bool &wrap_control_points,
                               const bool &adaptive_control_points,
                               const double &tension_control_points) const = 0;
};


#endif
