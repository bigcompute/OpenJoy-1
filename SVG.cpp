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

#include "SVG.hpp"

#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <climits>

//namespace com {
//namespace ibhe {

// SVG Utility functions
SVGLimits2D SVGFindRange
(const std::vector<SVGVector2d>& points) {
    SVGLimits2D limits;
    auto& min = limits.min;
    auto& max = limits.max;
    
    for (auto& p : points) {
        if (isnan(p.x) || isnan(p.y)) {
            continue;
        }
        min.x = (p.x<min.x) ? (p.x) : (min.x);
        min.y = (p.y<min.y) ? (p.y) : (min.y);
        max.x = (p.x>max.x) ? (p.x) : (max.x);
        max.y = (p.y>max.y) ? (p.y) : (max.y);
    }
    
    return limits;
}

// SVG Style
std::string SVGStyle::toString() const {
    std::stringstream ss;
    ss<<"style=\"";
    for (auto& p : properties) {
        ss<<p.first<<":"<<p.second<<";";
    }
    ss<<"\"";
    return ss.str();
}

// SVG Color
SVGColor::SVGColor(Defaults color)
:red(0), green(0), blue(0), transparent(false)
{
    switch (color) {
        case AQUA:    red = 0; green = 255; blue = 255; break;
        case BLACK:   red = 0; green = 0; blue = 0; break;
        case BLUE:    red = 0; green = 0; blue = 255; break;
        case BROWN:   red = 164; green = 42; blue = 42; break;
        case CYAN:    red = 0; green = 255; blue = 255; break;
        case FUCHSIA: red = 255; green = 0; blue = 255; break;
        case GREEN:   red = 0; green = 128; blue = 0; break;
        case LIME:    red = 0; green = 255; blue = 0; break;
        case MAGENTA: red = 255; green = 0; blue = 255; break;
        case ORANGE:  red = 255; green = 165; blue = 0; break;
        case PURPLE:  red = 128; green = 0; blue = 128; break;
        case RED:     red = 255; green = 0; blue = 0; break;
        case SILVER:  red = 192; green = 192; blue = 192; break;
        case WHITE:   red = 255; green = 255; blue = 255; break;
        case YELLOW:  red = 255; green = 255; blue = 0; break;
        case NONE:    transparent = true; break;
        default:      transparent = true; break;
    }
}

std::string SVGColor::toString() const {
    std::stringstream ss;
    if (transparent) {
        ss<<"none";
    } else {
        ss<<"rgb("<<red<<","<<green<<","<<blue<<")";
    }
    return ss.str();
}

// SVG Pont
std::string SVGVector2d::toString() const {
    std::stringstream ss;
    ss<<x<<","<<y;
    return ss.str();
}

// SVG Polyline
SVGPolyline::SVGPolyline(SVGColor stroke, long strokeWidth, SVGColor fill)
:stroke(stroke), strokeWidth(strokeWidth), fill(fill) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

SVGPolyline::SVGPolyline() :stroke(SVGColor(SVGColor::BLACK)), strokeWidth(1),
fill(SVGColor(SVGColor::NONE)) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

void SVGPolyline::add(double x, double y) {
    points.push_back(SVGVector2d(x,y));
}

std::string SVGPolyline::toString() const {
    std::stringstream ss;
    ss<<"<polyline points=\"";
    for (auto& p : points) {
        ss<<p.toString()<<" ";
    }
    ss<<"\" ";
    ss<<SVGStyle::toString()<<" />";
    return ss.str();
}

// SVG Polygon
SVGPolygon::SVGPolygon(SVGColor stroke, long strokeWidth, SVGColor fill)
:stroke(stroke), strokeWidth(strokeWidth), fill(fill) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

SVGPolygon::SVGPolygon() :stroke(SVGColor(SVGColor::BLACK)), strokeWidth(1),
fill(SVGColor(SVGColor::NONE)) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}


void SVGPolygon::add(double x, double y) {
    points.push_back(SVGVector2d(x,y));
}

std::string SVGPolygon::toString() const {
    std::stringstream ss;
    ss<<"<polygon points=\"";
    for (auto& p : points) {
        ss<<p.toString()<<" ";
    }
    ss<<"\" ";
    ss<<SVGStyle::toString()<<" />";
    return ss.str();
}

// SVG Path
SVGPath::SVGPath(SVGColor stroke, long strokeWidth, SVGColor fill)
:stroke(stroke), strokeWidth(strokeWidth), fill(fill) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

SVGPath::SVGPath() :stroke(SVGColor(SVGColor::BLACK)), strokeWidth(1),
fill(SVGColor(SVGColor::NONE)) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

std::string SVGPath::codeStr(CommandCode code) const {
    switch (code) {
        case M:  return "M";
        case L:  return "L";
        default: return "";
    }
}

std::string SVGPath::toString() const {
    std::stringstream ss;
    ss<<"<path d=\"";
    for (auto& p : commands) {
        ss<<codeStr(p.first)<<p.second.toString()<<" ";
    }
    ss<<"\" ";
    ss<<SVGStyle::toString()<<" />";
    return ss.str();
}

// SVG Circle
SVGCircle::SVGCircle
(double cx, double cy, double r,
 SVGColor stroke, long strokeWidth, SVGColor fill)
: cx(cx), cy(cy), r(r), stroke(stroke), strokeWidth(strokeWidth), fill(fill) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

SVGCircle::SVGCircle(double cx, double cy, double r)
: cx(cx), cy(cy), r(r), stroke(SVGColor(SVGColor::BLACK)),
strokeWidth(1), fill(SVGColor(SVGColor::NONE)) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["stroke"] = stroke.toString();
    properties["stroke-width"] = std::to_string(strokeWidth);
}

std::string SVGCircle::toString() const {
    std::stringstream ss;
    ss<<"<circle cx=\""<<cx<<"\" ";
    ss<<"cy=\""<<cy<<"\" ";
    ss<<"r=\""<<r<<"\" ";
    ss<<SVGStyle::toString()<<" />";
    return ss.str();
}

// SVG Text
SVGText::SVGText
(double x, double y, const std::string& text,
 SVGColor fill, double fontSize, const std::string& fontFamily)
:x(x), y(y), text(text), fontSize(fontSize), fontFamily(fontFamily) {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["font-size"] = std::to_string(fontSize);
    properties["font-family"] = fontFamily;
}

SVGText::SVGText(double x, double y, const std::string& text)
:x(x), y(y), text(text), fontSize(10), fontFamily("Verdana") {
    // Generate properties
    properties["fill"]   = fill.toString();
    properties["font-size"] = std::to_string(fontSize);
    properties["font-family"] = fontFamily;
}

std::string SVGText::toString() const {
    std::stringstream ss;
    ss<<"<text x=\""<<x<<"\" ";
    ss<<"y=\""<<y<<"\" ";
    ss<<SVGStyle::toString()<<" >";
    ss<<text<<"</text>";
    return ss.str();
}

// SVG Document
std::string SVGDocument::printStart() const {
    std::stringstream ss;
    ss<<"<?xml version=\"1.0\" standalone=\"no\"?>\n";
    ss<<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
    ss<<"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    ss<<"<svg height=\""<<height<<"\" width=\""<<width<<"\"";
    ss<<" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
    return ss.str();
}

std::string SVGDocument::printEnd() const {
    std::stringstream ss;
    ss<<"</svg>\n\n";
    return ss.str();
}

std::string SVGDocument::toString() const {
    std::stringstream ss;
    ss<<printStart()<<"\n";
    ss<<printEnd()<<"\n";
    return ss.str();
}

void SVGDocument::printToFile(const std::string& filepath) const {
    std::ofstream os(filepath);
    if (!os.is_open()) {
        return;
    }
    os<<toString();
    os.close();
}

//SVG Limits
void SVGTransform2D::setWith
(double width, double height, const SVGAxis& xaxis, const SVGAxis& yaxis) {
    offset = SVGVector2d(xaxis.min, yaxis.min);
    scale  = SVGElemRatio
    (SVGVector2d(width, height), SVGVector2d
     (xaxis.max-xaxis.min, yaxis.max-yaxis.min));
}

//SVG Plot 2d
SVGPlot2D::SVGPlot2D
(double plotWidth, double plotHeight,
 std::vector<double> x, std::vector<double> y, LineStyle style)
:margin(50.), style(style) {
    width  = plotWidth+margin*2;
    height = plotHeight+margin*2;
    
    if (x.size() != y.size()) {
        std::cout<<"SVG: function dimension not match!"<<std::endl;
        return;
    }
    // Ignore 0 and negative for log function
    for (long i=0; i<x.size(); i++) {
        switch (style) {
            case LINEAR:
                points.push_back(SVGVector2d(x[i], y[i]));
                break;
                
            case SEMILOGX:
                if (x[i] > 0) {
                    points.push_back(SVGVector2d(log10(x[i]), y[i]));
                } else {
                    points.push_back(SVGVector2d(nan(""), nan("")));
                    std::cout<<"SVG: negative or zero ignored!"<<std::endl;
                }
                break;
                
            case SEMILOGY:
                if (y[i] > 0) {
                    points.push_back(SVGVector2d(x[i], log10(y[i])));
                } else {
                    points.push_back(SVGVector2d(nan(""), nan("")));
                    std::cout<<"SVG: negative or zero ignored!"<<std::endl;
                }
                break;
                
            case LOGLOG:
                if (x[i] > 0 && y[i] > 0) {
                    points.push_back(SVGVector2d(log10(x[i]), log10(y[i])));
                } else {
                    points.push_back(SVGVector2d(nan(""), nan("")));
                    std::cout<<"SVG: negative or zero ignored!"<<std::endl;
                }
                break;
                
            default:
                style = LINEAR;
                points.push_back(SVGVector2d(x[i], y[i]));
                break;
        }
    }
    // Create x range and y range
    auto limits = SVGFindRange(points);
    if (!limits.valid()) {
        limits.setDefault();
    }
    // Adjust axis
    xaxis = SVGAxis(limits.min.x, limits.max.x);
    yaxis = SVGAxis(limits.min.y, limits.max.y);
    
    // Calculate transformation
    transform.setWith(width-2*margin, height-2*margin, xaxis, yaxis);
}

std::string SVGPlot2D::toString() const {
    std::stringstream ss;
    ss<<printStart()<<"\n";
    // Create image border
    SVGPolygon border(SVGColor(SVGColor::RED), 1, SVGColor(SVGColor::NONE));
    {
        border.add(margin, margin);
        border.add(width-margin, margin);
        border.add(width-margin, height-margin);
        border.add(margin, height-margin);
    }
    ss<<border.toString()<<"\n";
    // Create path
    SVGPath path(SVGColor(SVGColor::LIME), 1, SVGColor(SVGColor::NONE));
    {
        PlotState state = END;
        for (auto& p : points) {
            if (state == END) {
                if (p.valid()) {
                    path.moveTo(marginOffset(flipCoord(transform.applyOn(p))));
                    state = START;
                } else {
                    state = END;
                }
            } else if (state == START) {
                if (p.valid()) {
                    path.lineTo(marginOffset(flipCoord(transform.applyOn(p))));
                    state = START;
                } else {
                    state = END;
                }
            }
        }
    }
    ss<<path.toString()<<"\n";
    ss<<printXAxis();
    ss<<printYAxis();
    ss<<printEnd()<<"\n";
    return ss.str();
}

void SVGPlot2D::printToFile(const std::string& filepath) const {
    std::ofstream os(filepath);
    if (!os.is_open()) {
        return;
    }
    os<<toString();
    os.close();
}

std::string SVGPlot2D::printXAxis() const {
    std::stringstream ss;
    for (long i=0; i<xaxis.npts; i++) {
        SVGVector2d p = {i*(width-2*margin)/(double)(xaxis.npts-1), 0};
        p = marginOffset(flipCoord(p));
        SVGCircle circ
        (p.x, p.y, 3, SVGColor(SVGColor::NONE),
         1, SVGColor(SVGColor::BLACK));
        ss<<circ.toString();
        ss<<"\n";
        {
            double value = xaxis.min+i*xaxis.spacing;
            char loc[100];
            if (style == LINEAR || style == SEMILOGY) {
                std::sprintf(loc, "%g", value);
            } else {
                std::sprintf(loc, "10E%g", value);
            }
            
            SVGText text(p.x-5, p.y+15, loc, SVGColor(SVGColor::BLACK), 10, "Verdana");
            ss<<text.toString();
        }
        ss<<"\n";
    }
    return ss.str();
}

std::string SVGPlot2D::printYAxis() const {
    std::stringstream ss;
    for (long i=0; i<yaxis.npts; i++) {
        SVGVector2d p = {0, i*(height-2*margin)/(double)(yaxis.npts-1)};
        p = marginOffset(flipCoord(p));
        SVGCircle circ
        (p.x, p.y, 3, SVGColor(SVGColor::NONE),
         1, SVGColor(SVGColor::BLACK));
        ss<<circ.toString();
        ss<<"\n";
        {
            double value = yaxis.min+i*yaxis.spacing;
            char loc[100];
            if (style == LINEAR || style == SEMILOGX) {
                std::sprintf(loc, "%g", value);
            } else {
                std::sprintf(loc, "10E%g", value);
            }
            std::string locStr = loc;
            SVGText text(p.x-10-locStr.size()*5, p.y+5, locStr,
                         SVGColor(SVGColor::BLACK), 10, "Verdana");
            ss<<text.toString();
        }
        ss<<"\n";
    }
    return ss.str();
}

// SVG Axis
SVGAxis::SVGAxis(double min, double max) {
    if (min > max) {
        SVGAxis();
    }
    if (min > 0) {
        min = roundPositiveLower(min);
    } else {
        min = -roundPositiveUpper(-min);
    }
    if (max > 0) {
        max = roundPositiveUpper(max);
    } else {
        max = -roundPositiveLower(-max);
    }
    double diff = max-min;
    long   n = floor(log10(diff));
    double a = diff / pow(10, n);
    if (1 <= a && a < 2) {
        spacing = 0.2*pow(10, n);
    } else if (2 <= a && a < 5) {
        spacing = 0.5*pow(10, n);
    } else {
        spacing = pow(10, n);
    }
    long nmin = floor(min/spacing);
    long nmax = ceil(max/spacing);
    this->min = nmin*spacing;
    this->max = nmax*spacing;
    this->npts = (nmax-nmin)+1;
}

double SVGAxis::roundPositiveUpper(double x) {
    if (x <= 0) {
        return x;
    }
    long   n = floor(log10(x));
    double a = x / pow(10, n);
    double b = ceil(a*100)*0.01;
    return b*pow(10, n);
}

double SVGAxis::roundPositiveLower(double x) {
    if (x <= 0) {
        return x;
    }
    long   n = floor(log10(x));
    double a = x / pow(10, n);
    double b = floor(a*100)*0.01;
    return b*pow(10, n);
}

//}
//}