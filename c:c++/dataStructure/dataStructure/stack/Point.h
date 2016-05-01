//
//  Point.h
//  dataStructure
//
//  Created by 杨 on 16/1/7.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#ifndef Point_h
#define Point_h
class Point
{
public:
    Point(int x,int y)
    {
        this->x  = x;
        this->y = y;
    }
    Point(const Point   &p)
    {
        this->x = p.x;
        this->y = p.y;
    }
//    Point operator+(const Point p1,const Point p2)
//    {
//        Point p(0,0);
//        p.x = p1.x + p2.x;
//        p.y = p1.y + p2.y;
//        return p;
//    }
    
    int x,y;
};

#endif /* Point_h */
