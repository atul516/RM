// GLContour.h: interface for the CGLContour class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLCONTOUR_H__8E92F5AF_D733_47BA_9E52_F27D16391E2B__INCLUDED_)
#define AFX_GLCONTOUR_H__8E92F5AF_D733_47BA_9E52_F27D16391E2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include "Contour.h"

class CGLContour : public CContour, public GLWidget{
private:
    double rightX;
    double topY;
    double bottomY;
    double leftX;
public:
    CGLContour(std::vector< coordinates >);
    virtual ~CGLContour();
    virtual inline void ExportLine(int iPlane,int x1, int y1, int x2, int y2);
    void setX();
    void setY();
protected:
    void paintGL();
};

inline void CGLContour::ExportLine(int iPlane,int x1, int y1, int x2, int y2)
{
    std::cout << x1 << " " << y1 << "        " << x2 << " " << y2 << "\n";
    glColor3f(1.0f-iPlane/(float)GetNPlanes(),0,iPlane/(float)GetNPlanes());
    glBegin(GL_LINES);
    glVertex2f((GLfloat)(m_pLimits[0]+x1*m_dDx),(GLfloat)(m_pLimits[2]+y1*m_dDy));
    glVertex2f((GLfloat)(m_pLimits[0]+x2*m_dDx),(GLfloat)(m_pLimits[2]+y2*m_dDy));
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    glVertex2f((GLfloat)(m_pLimits[0]+x1*m_dDx),(GLfloat)(m_pLimits[2]+y1*m_dDy));
    glVertex2f((GLfloat)(m_pLimits[0]+x2*m_dDx),(GLfloat)(m_pLimits[2]+y2*m_dDy));
    glEnd();
}

#endif // !defined(AFX_GLCONTOUR_H__8E92F5AF_D733_47BA_9E52_F27D16391E2B__INCLUDED_)
