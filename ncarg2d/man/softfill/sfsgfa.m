'\" t
.TH SFSGFA 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.na
.nh
.SH NAME
SFSGFA - (which stands for "SOFTFILL -
Simulate GFA") fills, in one of various ways,
an area of the plotter frame defined by a given set of points;
it is intended to provide a way to use the GKS fill-area routine,
if it works (as is the case in the version of GKS distributed
with NCAR Graphics), or a suitable pattern-fill substitute,
otherwise.  Doing all area fills with SFSGFA has the advantage
that the way in which they are done can then be changed by  
modifying the value of a single internal parameter of Softfill,
named 'TY'.
.SH SYNOPSIS
CALL SFSGFA (XRA, YRA, NRA, DST, NST, IND, NND, ICI)
.SH C-BINDING SYNOPSIS
#include <ncarg/ncargC.h>
.sp
void c_sfsgfa (float *xra, float *yra, int nra, \\
.br
float *dst, 
int nst, int *ind, int nnd, int ici)
.SH DESCRIPTION 
.IP XRA 12
(an input/output array of type REAL, dimensioned NRA or 
greater) contains the X coordinates of the points defining the 
area to be filled, in the user coordinate system. Upon return, 
the contents of XRA will have been converted to the 
fractional coordinate system.
.IP YRA 12
(an input/output array of type REAL, dimensioned NRA or 
greater) contains the Y coordinates of the points defining the 
area to be filled, in the user coordinate system. Upon return, 
the contents of YRA will have been converted to the 
fractional coordinate system.
.IP NRA 12
(an input expression of type INTEGER) is the number of points
defining the area to be filled. NRA must be greater than two.
.IP DST 12
(a scratch array of type REAL, dimensioned NST) is for use 
when fill lines are generated by means of calls to SFWRLD 
and/or SFNORM.
.IP NST 12
(an input expression of type INTEGER) is the length of the 
array DST. NST must be greater than or equal to NRA + NIM, 
where NIM is the largest number of intersection points of any 
fill line with the boundary lines. To be sure DST is large 
enough, use NIM = NRA; in practice, NIM rarely needs to be 
that large. For a convex polygon, for example, NIM = 2.
.IP IND 12 
(a scratch array of type INTEGER, dimensioned NND) is for use 
when fill lines are generated by means of calls to SFWRLD 
and/or SFNORM.
.IP NND 12
(an input expression of type INTEGER) is the length of the 
array IND. It must be greater than or equal to NRA + 2 * NIM, 
where NIM is as defined above.
.IP ICI 12
(an input expression of type INTEGER) is, nominally, 
the fill-area color index to be used. When the internal 
parameter 'TY' has a value other than zero, 
ICI may be used in some other manner. 
.SH C-BINDING DESCRIPTION
The C-binding argument descriptions are the same as the Fortran 
argument descriptions.
.SH USAGE@@@
SFSGFA fills the area defined by the points (XRA(I),YRA(I)),
for I from 1 to NRA. The lines connecting point 1 to point
2, point 2 to point 3, . . ., point NRA-1 to point NRA, and
point NRA to point 1 bound the area to be filled.
.PP
The values of the internal parameter 'TY' (for 'TYPE OF
FILL') and the argument ICI determine how the fill is done.
The function of ICI changes depending on the value of 'TY'.
ICI can determine the fill area color index, the polyline
color index, or the density of the fill pattern.
.IP "'TY' = 0" 12 
This is the default. SFSGFA does color fill by calling GFA.
GFA does either hollow, solid, or pattern fill. Hollow
fill (only boundaries are drawn) is GFA's default, but
you can change the type of fill by calling the GKS
subroutine GSFAIS. Notice that one of the first steps
in the code for the example "sfex02" is to force solid fill by
calling GSFAIS with the argument "1".
.sp
A value of ICI greater than or equal to zero specifies the color index of
the fill area.
.sp
A value of ICI less than zero specifies that the fill area color index
is not to be set before calling GFA; the last call to
the GKS subroutine GSFACI then determines the fill area
color index.
.IP "'TY' = 1" 12 
\&SFSGFA fills the area with parallel lines by calling
SFWRLD.
.sp
A value of ICI greater than or equal to zero specifies the polyline color
index.
.sp
A value of ICI less than zero specifies that the polyline color index is
not to be
set before calling SFWRLD; the last call to the GKS
subroutine GSPLCI determines the polyline color index.
.sp
Parameters 'AN', 'CH', 'DO', and 'SP' further affect
the nature of the fill.
.sp
Note: If 'CH' and 'DO' are set to select dot fill or
character fill, the values of ICI will not affect the
color of the dots or characters. The intended use of
\&'TY' > 0 is to do color fill using colored lines; no
provision is made for the use of colored dots or
colored characters. (The current values of the
polymarker and text color indices are used to determine
the color.)
.IP "'TY' = 2" 12
SFSGFA calls SFWRLD to fill the area with parallel
lines and calls SFNORM to fill the area again with
parallel lines perpendicular to the first set.
.sp
ICI, if zero or greater, specifies the polyline color index.
.sp
A negative value of ICI specifies that the polyline color
index is not to be set before calling SFWRLD; the last
call to the GKS subroutine GSPLCI determines the
polyline color index.
.sp
Parameters 'AN', 'CH', 'DO', and 'SP' further affect
the nature of the fill. See the note above about ICI's
function with 'CH' and 'DO'.
.IP "'TY' = -4, -3, -2, -1" 12
SFSGFA fills the area with line patterns
by calling SFWRLD and/or SFNORM. The absolute value of 'TY'
determines the maximum number of fill-line angles
used in a pattern.
.sp
ICI determines the density of the
lines drawn at each angle.
.sp
Angles Used: When 'TY' has one of the following values,
fill is done by using lines drawn at the angles shown
('AN' is an internal parameter that specifies an angle
in degrees):
.sp
\&'TY'\& \& Angles Used (in Degrees)
.sp
\& -1 \& \& 'AN'
.br
\& -2 \& \& 'AN', 'AN'+90
.br
\& -3 \& \& 'AN', 'AN'+60, 'AN'+120
.br
\& -4 \& \& 'AN', 'AN'+45, 'AN'+90, 'AN'+135
.sp
Line Density: ICI is used to select the density of the lines in
each direction. A zero or negative value of ICI selects a blank
pattern. Positive values of ICI select patterns that increase
in density as the value of ICI increases.  The largest usable
value of ICI is approximately 5*ABS('TY'); beyond that, the
pattern becomes essentially solid. For example, if 'TY' is -4,
20 is about the largest value of ICI that you can use and still
see a pattern.
.sp
For each increase in ICI, fill lines are added at one of the
usable angles. The first time lines are added at a given angle,
they are spaced 32*'SP' units apart.  (The default value of the
internal parameter 'SP' is .00125.) After the first time, each
time lines are added at a given angle, they are added between
the existing lines so that the distance between lines at that
angle is halved. An ICI value that is evenly divisible by the
absolute value of 'TY' yields a pattern that is evenly dense at
all angles. For example, if 'TY' has the value -2, the patterns
associated with the first three values of ICI are formed as
follows: ICI=1 uses lines at the angle 'AN', spaced 32*'SP'
units apart; ICI=2 uses lines at the angles 'AN' and 'AN'+90,
both spaced 32*'SP' units apart; ICI=3 uses lines at the angle
\&'AN', spaced 32*'SP' units apart, and lines at the angle
\&'AN'+90, spaced 16*'SP' units apart.
.PP
For SFSGFA to fill an uncomplicated polygon (one without
holes), XRA and YRA should contain the world coordinates of
the polygon's vertices in the order in which they are
encountered as the boundary of the polygon is traced.
.PP
To leave an unfilled hole in a polygon, do the following:
(1) add the vertices of the hole, in the proper order, to
XRA and YRA; (2) repeat the first vertex of the hole to
close it; (3) repeat the last vertex of the outer polygon
boundary to tie the first point of the hole to the last
point of the polygon's outer boundary.
.PP
To fill what was unfilled and vice versa, do the following:
(1) add the four coordinates of the frame corners; (2)
repeat the coordinates of the first corner of the frame; (3)
repeat the final point of the original polygon. In effect,
this makes what was previously inside, outside, and what was
previously outside, inside.
.PP
When a polygon contains holes, there are connecting lines
between the outer boundary of the polygon and the boundaries
of the holes. When doing software fill (internal parameter
\&'TY' not equal to 0), these connecting lines cause no trouble;
however, when doing solid fill (internal parameter 'TY'= 0),
the hardware fill algorithms will frequently display
unfortunate edge effects along such lines. You can minimize
these effects by using only horizontal or vertical
connecting lines and by ensuring they do not cross any of
the original boundary lines.
.SH EXAMPLES
Use the ncargex command to see the following relevant
examples: cpex04, cpex05, sfex02, tsoftf fsfsgfa.
.SH ACCESS
To use SFSGFA, load the NCAR Graphics libraries ncarg, 
ncarg_gks, ncarg_c, and ncarg_loc, preferably in that order.  To use
c_sfsgfa, load the NCAR Graphics libraries ncargC, 
ncarg_gksC, ncarg, ncarg_gks, ncarg_c, and ncarg_loc, preferably in 
that order.
.SH MESSAGES
See the softfill man page for a description of all Softfill
error messages and/or informational messages.
.SH SEE ALSO
Online: 
softfill, softfill_params, sfgetc, sfgeti, sfgetp, sfgetr,
sfsetc, sfseti, sfsetp, sfsetr, sfwrld, ncarg_cbind
.SH COPYRIGHT
Copyright 1987, 1988, 1989, 1991, 1993 University Corporation
for Atmospheric Research
.br
All Rights Reserved

