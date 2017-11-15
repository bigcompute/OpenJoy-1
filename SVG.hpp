//
//  Licensed to the Apache Software Foundation (ASF) under one or more
//  contributor license agreements.  See the NOTICE file distributed with
//  this work for additional information regarding copyright ownership.
//  The ASF licenses this file to You under the Apache License, Version 2.0
//  (the "License"); you may not use this file except in compliance with
//  the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

// A portable library for generating simple vector graphics (SVG)

//namespace com {
//namespace ibhe {

#ifndef SVG_HPP
#define SVG_HPP

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <map>

//SVG macros
#define SVG_MIN std::numeric_limits<double>::min()
#define SVG_MAX std::numeric_limits<double>::max()

//SVG Style: provide style with properties
struct SVGStyle {
    std::map<std::string, std::string> properties;
    
    std::string toString() const;
};

//SVG Color
struct SVGColor {
    long red;
    long green;
    long blue;
    bool transparent;
    
    //List of colors
    enum Defaults {NONE=0, AQUA, BLACK, BLUE, BROWN, CYAN, FUCHSIA,
        GREEN, LIME, MAGENTA, ORANGE, PURPLE, RED, SILVER, WHITE, YELLOW};
    
    SVGColor(long red, long green, long blue)
    :red(red), green(green), blue(blue), transparent(false) {}
    SVGColor() :red(0), green(0), blue(0), transparent(false) {}
    SVGColor(Defaults color);
    
    std::string toString() const;
};

//SVG Point
struct SVGVector2d {
    double x;
    double y;
    
    SVGVector2d(double x, double y) :x(x), y(y) {};
    SVGVector2d() :x(0.), y(0.) {};
    
    // Operators
    SVGVector2d& operator+= (const SVGVector2d& u);
    SVGVector2d& operator-= (const SVGVector2d& u);
    SVGVector2d& operator*= (double c);
    
    std::string toString() const;
    
    bool valid() const;
};
SVGVector2d operator+ (const SVGVector2d& u, const SVGVector2d& v);
SVGVector2d operator- (const SVGVector2d& u, const SVGVector2d& v);
SVGVector2d operator- (const SVGVector2d& u);
SVGVector2d operator* (const SVGVector2d& u, double c);
SVGVector2d operator* (double c, const SVGVector2d& u);

inline SVGVector2d& SVGVector2d::operator+= (const SVGVector2d& u) {
    x += u.x;
    y += u.y;
    return *this;
}

inline SVGVector2d& SVGVector2d::operator-= (const SVGVector2d& u) {
    x -= u.x;
    y -= u.y;
    return *this;
}

inline SVGVector2d operator- (const SVGVector2d& u) {
    return SVGVector2d(-u.x, -u.y);
}

inline SVGVector2d& SVGVector2d::operator*= (double c) {
    x *= c;
    y *= c;
    return *this;
}

inline SVGVector2d operator+ (const SVGVector2d& u, const SVGVector2d& v) {
    return SVGVector2d(u.x+v.x, u.y+v.y);
}

inline SVGVector2d operator- (const SVGVector2d& u, const SVGVector2d& v) {
    return SVGVector2d(u.x-v.x, u.y-v.y);
}

inline SVGVector2d operator* (const SVGVector2d& u, double c) {
    return SVGVector2d(u.x*c, u.y*c);
}

inline SVGVector2d operator* (double c, const SVGVector2d& u) {
    return SVGVector2d(u.x*c, u.y*c);
}

inline SVGVector2d SVGElemProduct(const SVGVector2d& u, const SVGVector2d& v) {
    return SVGVector2d(u.x*v.x, u.y*v.y);
}

inline SVGVector2d SVGElemRatio(const SVGVector2d& u, const SVGVector2d& v) {
    return SVGVector2d(u.x/v.x, u.y/v.y);
}

inline bool SVGVector2d::valid() const {
    return (!isnan(x)) && (!isnan(y));
}

//SVG Polyline: subclass of SVGStyle
struct SVGPolyline : SVGStyle {
    std::vector<SVGVector2d> points;
    
    SVGColor fill;
    SVGColor stroke;
    long     strokeWidth;
    
    SVGPolyline(SVGColor stroke, long strokeWidth, SVGColor fill);
    SVGPolyline();
    
    void add(double x, double y);
    std::string toString() const;
};

//SVG Polygon: subclass of SVGStyle
struct SVGPolygon : SVGStyle {
    std::vector<SVGVector2d> points;
    
    SVGColor fill;
    SVGColor stroke;
    long     strokeWidth;
    
    SVGPolygon(SVGColor stroke, long strokeWidth, SVGColor fill);
    SVGPolygon();
    
    void add(double x, double y);
    std::string toString() const;
};

//SVG Path: subclass of SVGStyle
struct SVGPath : SVGStyle {
    enum CommandCode {
        M=0, L
    };
    
    std::vector<std::pair<CommandCode, SVGVector2d>> commands;
    
    SVGColor fill;
    SVGColor stroke;
    long     strokeWidth;
    
    SVGPath(SVGColor stroke, long strokeWidth, SVGColor fill);
    SVGPath();
    
    //Command code string
    std::string codeStr(CommandCode code) const;
    
    //Currently support only move to and line to
    void moveTo(const SVGVector2d& u);
    void lineTo(const SVGVector2d& u);
    
    std::string toString() const;
};

inline void SVGPath::moveTo(const SVGVector2d& u) {
    commands.push_back({M, u});
}

inline void SVGPath::lineTo(const SVGVector2d& u) {
    commands.push_back({L, u});
}

//SVG Circle: subclass of SVGStyle
struct SVGCircle : SVGStyle {
    double cx;
    double cy;
    double r;
    
    SVGColor fill;
    SVGColor stroke;
    long     strokeWidth;
    
    SVGCircle
    (double cx, double cy, double r,
     SVGColor stroke, long strokeWidth, SVGColor fill);
    SVGCircle(double cx, double cy, double r);
    
    std::string toString() const;
};

//SVG Text: subclass of SVGStyle
struct SVGText : SVGStyle {
    double x;
    double y;
    std::string text;
    
    SVGColor    fill;
    double      fontSize;
    std::string fontFamily;
    
    SVGText(double x, double y, const std::string& text,
            SVGColor fill, double fontSize, const std::string& fontFamily);
    SVGText(double x, double y, const std::string& text);
    
    std::string toString() const;
};


//SVG Document
struct SVGDocument {
    double width;
    double height;
    
    SVGDocument(double width, double height) :width(width), height(height) {};
    SVGDocument() :width(0.), height(0.) {};
    
    std::string printStart() const;
    std::string printEnd() const;
    
    void printToFile(const std::string& filepath) const;
    std::string toString() const;
    
};

//SVG Transform
struct SVGAxis;
struct SVGTransform2D {
    SVGVector2d offset;
    SVGVector2d scale;
    
    SVGTransform2D(SVGVector2d offset, SVGVector2d scale)
    :offset(offset), scale(scale) {};
    SVGTransform2D() :offset(0,0), scale(1,1) {}
    
    SVGVector2d applyOn(const SVGVector2d& u) const;
    void setWith(double width, double height, const SVGAxis& xaxis, const SVGAxis& yaxis);
};

inline SVGVector2d SVGTransform2D::applyOn(const SVGVector2d& u) const {
    return SVGElemProduct(scale, u-offset);
}

//SVG plot limits
struct SVGLimits2D {
    SVGVector2d min;
    SVGVector2d max;
    
    SVGLimits2D(SVGVector2d min, SVGVector2d max) :min(min), max(max) {}
    SVGLimits2D() :min({SVG_MAX,SVG_MAX}), max({-SVG_MAX,-SVG_MAX}) {}
    
    bool valid() const;
    void setDefault();
};

inline bool SVGLimits2D::valid() const {
    return min.x != SVG_MAX && min.y != SVG_MAX &&
           max.x != -SVG_MAX && max.y != -SVG_MAX;
}

inline void SVGLimits2D::setDefault() {
    min = {0,0};
    max = {1,1};
}

//SVG Utility functions
SVGLimits2D SVGFindRange(const std::vector<SVGVector2d>& points);

// Get axis
struct SVGAxis {
    double min;
    double max;
    double spacing;
    long   npts;
    
    SVGAxis(double min, double max);
    SVGAxis():min(0), max(1), spacing(0.1), npts(11) {}
    
    static double roundPositiveUpper(double x);
    static double roundPositiveLower(double x);
};

//SVG Standalone plot
struct SVGPlot2D : SVGDocument {
    enum LineStyle {
        LINEAR = 0, SEMILOGX, SEMILOGY, LOGLOG
    };
    
    enum PlotState {
        START = 0, END
    };
    
    // In user space
    std::vector<SVGVector2d> points;
    LineStyle style;
    SVGTransform2D transform;
    SVGAxis xaxis;
    SVGAxis yaxis;
    
    // Plot margin, default is 50
    double margin = 50.;
    
    SVGPlot2D
    (double plotWidth, double plotHeight,
     std::vector<double> x, std::vector<double> y,
     LineStyle style);
    
    void printToFile(const std::string& filepath) const;
    std::string toString() const;
    // Flip the coordinate so that origin at the lower left corner
    SVGVector2d flipCoord(const SVGVector2d& u) const;
    // Set coordinate with margin offset
    SVGVector2d marginOffset(const SVGVector2d& u) const;
    // Print xaxis, yaxis
    std::string printXAxis() const;
    std::string printYAxis() const;
};

inline SVGVector2d SVGPlot2D::flipCoord(const SVGVector2d& u) const {
    return SVGVector2d(u.x, height-2*margin-u.y);
}

inline SVGVector2d SVGPlot2D::marginOffset(const SVGVector2d& u) const {
    return SVGVector2d(u.x+margin, u.y+margin);
}


//}
//}



#endif /* defined(SVG_HPP) */
