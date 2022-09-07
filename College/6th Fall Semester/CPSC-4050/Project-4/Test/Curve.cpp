#include "Curve.h"
#include <functional>
#include <cmath>

Curve::Curve() :
        m_pceEvaluator(nullptr),
        m_bWrap(false),
        m_bDirty(true),
        m_bAdaptive(false),
        m_dTension(1.0f),
        m_fMaxX(1.0f) {
    init();
}

void Curve::init(const float fStartYValue /* = 0.0f */) {
    m_ptvCtrlPts.emplace_back(m_fMaxX * (1.0f / 3.0f), fStartYValue);
    m_ptvCtrlPts.emplace_back(m_fMaxX * (2.0f / 3.0f), fStartYValue);
}

void Curve::toStream(std::ostream &output_stream) const {
    output_stream << m_ptvCtrlPts.size() << std::endl;

    for (std::vector<Point>::const_iterator control_point_iterator = m_ptvCtrlPts.begin();
         control_point_iterator != m_ptvCtrlPts.end(); ++control_point_iterator) {
        output_stream << *control_point_iterator;
    }

    output_stream << m_fMaxX << std::endl;

    output_stream << m_bWrap << std::endl;
}

void Curve::fromStream(std::istream &isInputStream) {
    int iCtrlPtCount;

    isInputStream >> iCtrlPtCount;

    m_ptvCtrlPts.resize(iCtrlPtCount);

    for (int iCtrlPt = 0; iCtrlPt < iCtrlPtCount; ++iCtrlPt) {
        isInputStream >> m_ptvCtrlPts[iCtrlPt];
    }

    isInputStream >> m_fMaxX;

    isInputStream >> m_bWrap;

    m_bDirty = true;
}

float Curve::evaluateCurveAt(const float x) const {
    reevaluate();

    float value = 0.0f;

    if (m_ptvEvaluatedCurvePts.size() == 1)
        return m_ptvEvaluatedCurvePts[0].y;

    if (m_ptvEvaluatedCurvePts.size() > 1) {
        std::vector<Point>::iterator first_point = m_ptvEvaluatedCurvePts.begin();
        std::vector<Point>::iterator last_point = m_ptvEvaluatedCurvePts.end() - 1;

        bool evaluate_point_to_left_of_range = (first_point->x > x);
        bool evaluate_point_to_right_of_range = (last_point->x < x);

        if (evaluate_point_to_left_of_range) {
            value = first_point->y;
        } else if (evaluate_point_to_right_of_range) {
            value = last_point->y;
        } else {
            std::vector<Point>::iterator point_one_iterator = first_point;

            while ((point_one_iterator + 1)->x < x) {
                ++point_one_iterator;
#ifdef _DEBUG
                assert(point_one_iterator != last_point);
#endif // _DEBUG
            }

            std::vector<Point>::iterator point_two_iterator = point_one_iterator + 1;

#ifdef _DEBUG
            assert(point_one_iterator != m_ptvEvaluatedCurvePts.end());
            assert(point_two_iterator != m_ptvEvaluatedCurvePts.end());
#endif // _DEBUG

            Point point_one = *point_one_iterator;
            Point point_two = *point_two_iterator;

            if (point_one.x == point_two.x)
                value = point_one.y;
            else {
                float slope = (point_two.y - point_one.y) / (point_two.x - point_one.x);
                value = (x - point_one.x) * slope + point_one.y;
            }
        }
    }

    return value;
}

//void Curve::sortControlPoints() const {
//    std::sort(m_ptvCtrlPts.begin(),
//              m_ptvCtrlPts.end(),
//              PointSmallerXCompare());
//}

void Curve::reevaluate() const {
//    if (m_bDirty) {
//        if (m_pceEvaluator) {
//            std::sort(m_ptvEvaluatedCurvePts.begin(),
//                      m_ptvEvaluatedCurvePts.end(),
//                      PointSmallerXCompare());
//
//            m_bDirty = false;
//        }
//    }
}


std::ostream &operator<<(std::ostream &output_stream, const Curve &curve_data) {
    curve_data.toStream(output_stream);
    return output_stream;
}

std::istream &operator>>(std::istream &isInputStream, Curve &curve_data) {
    curve_data.fromStream(isInputStream);
    return isInputStream;
}
