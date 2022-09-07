#ifndef _H__CATMULL_ROM_H
#define _H__CATMULL_ROM_H

#include "Curve.h"

class CatmullRom : public Curve {
public:
    CatmullRom();

    ~CatmullRom() override;

protected:
    void pointAdd() override;

protected:
    Vector interpolate(double u, const Vector &P0, const Vector &P1, const Vector &P2, const Vector &P3);
};

#endif