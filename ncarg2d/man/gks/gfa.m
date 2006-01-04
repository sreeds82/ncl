.\"
.\"	$Id: gfa.m,v 1.13 2006-01-04 00:12:54 haley Exp $
.\"
.TH GFA 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
GFA (Fill area) - output primitive for filling polygonal areas.
.SH SYNOPSIS
CALL GFA (N, X, Y)
.SH C-BINDING SYNOPSIS
#include <ncarg/gks.h>
.sp
void gfill_area(const Gpoint_list *point_list);
.SH DESCRIPTION
.IP N 12
(Integer, Input) - The number of points in the polygon 
to be filled.  N must be greater than two.
.IP "X (N)" 12
(Real Array, Integer) - The X world coordinates of the polygon.
.IP "Y (N)" 12
(Real Array, Integer) - The Y world coordinates of the polygon.
.SH USAGE
The area to be filled is delimited by the sequence of
straight line segments connecting the successive 
points  (X(1), Y(1)), (X(2), Y(2)), ..., 
(X(N), Y(N)). The last point in the polygon is 
connected to the first point with a straight line 
segment in the case that (X(N), Y(N)) does not equal (X(l), Y(l)).
.sp
Given a polygon whose edges cross each other, it 
becomes ambiguous as to what constitutes the "inside" 
of the polygon.  The algorithm used in GKS is as 
follows: for a given point, draw a ray
starting at that point and going to infinity in any
direction; if the number of intersections between the ray and 
the polygon is odd, the point is within the polygon,
otherwise it is outside.  If the straight line passes 
through a polygon vertex tangentially, the intersection count 
is not affected.  If a point is within the polygon, it 
is included in the area to be filled.
.sp
Several interior styles (hollow, solid, and various hatch patterns)
can be selected.  See the man pages for gsfais and gsfasi for these.
.sp
Note well: By default in GKS, the interior fill style is hollow,
or no fill. If you call GFA and do not get a filled
interior as you expected, you will probably need to call 
GSFAIS to set the fill style to something other than "hollow".
.SH ACCESS
To use GKS routines, load the NCAR GKS-0A library 
ncarg_gks.
.SH SEE ALSO
Online: 
gsfais, gsfasi, gscr, gsfaci, gqfais, gqfasi, gfill_area
.sp
Hardcopy: 
User's Guide for NCAR GKS-0A Graphics;
NCAR Graphics Fundamentals, UNIX Version
.SH COPYRIGHT
Copyright (C) 1987-2006
.br
University Corporation for Atmospheric Research
.br

This documentation is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this software; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
USA.
