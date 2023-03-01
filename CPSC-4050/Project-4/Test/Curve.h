#ifndef CURVE_H_INCLUDED
#define CURVE_H_INCLUDED

#pragma warning(disable : 4786)

#include <vector>
#include <iostream>
#include <string>

#include "Point.h"

class CurveEvaluator;

//using namespace std;

class Curve {
public:

    Curve();

    float evaluateCurveAt(const float x) const;

    void toStream(std::ostream &output_stream) const;

    void fromStream(std::istream &input_stream);

protected:
    void init(float fStartYValue = 0.0f);

    void reevaluate() const;

    // this must be called when a control point is added
    void sortControlPoints() const;

    const CurveEvaluator *m_pceEvaluator;

    mutable std::vector<Point> m_ptvCtrlPts;
    mutable std::vector<Point> m_ptvEvaluatedCurvePts;
    mutable bool m_bDirty;

    float m_fMaxX;
    bool m_bWrap;
    bool m_bAdaptive;
    double m_dTension;
};

std::ostream &operator<<(std::ostream &output_stream, const Curve &curve_data);

std::istream &operator>>(std::istream &input_stream, Curve &curve_data);

#endif // CURVE_H_INCLUDED
