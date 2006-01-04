.TH PERIML 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.na
.nh
.SH NAME
PERIML - 
Draws a labeled perimeter with inward-pointing tick marks.
The directions and lengths of tick marks may be changed by
calling TICKS and/or TICK4.
.SH SYNOPSIS
CALL PERIML (MJRX,MNRX,MJRY,MNRY)
.SH C-BINDING SYNOPSIS
#include <ncarg/ncargC.h>
.sp
void c_periml (int mjrx, int mnrx, int mjry, int mnry)
.SH DESCRIPTION
.IP "MJRX, MNRX, MJRY, and MNRY" 12
(input expressions of type
INTEGER) specify the major and minor divisions of
the horizontal (X) and vertical (Y) axes
of the current viewport. The meanings of these parameters
depend on the current setting of the internal parameter
\'LS\' of SPPS:
.RS
.IP \(bu
If the value of \'LS\' implies that the axis is linear:
MJRX(Y) specifies the number of major divisions of the X(Y)
axis and MNRX(Y) specifies the number of minor divisions
within each major division. In each case, the value
specifies the number of spaces between grid lines or ticks
rather than the number of lines or ticks. Including the
ones at the ends of the axes, there is always one more
major division line or mark than the number of major
divisions specified by MJRX(Y). Similarly, there is always
one less minor division line or tick per major division
than the number of minor divisions per major division
specified by MNRX(Y).
.IP \(bu
If the value of \'LS\' implies that the axis is logarithmic:
Each major division point occurs at a value 10**MJRX(Y)
times the previous point. For example, if the minimum X-axis
value were 3., the maximum X-axis value 3000. and MJRX
1, then the major division points would be 3., 30., 300.,
and 3000. If MNRX(Y).LE.10, there are nine minor divisions
within each major division. For example, between 3. and
30., there would be minor division points at 6., 9., 12., .
\&. . 27. If MNRX(Y).GT.10., minor divisions are omitted.
.RE
.SH C-BINDING DESCRIPTION
The C-binding argument descriptions are the same as the FORTRAN 
argument descriptions.
.SH USAGE
The statement
.RS 3 
.sp
CALL PERIML (MJRX,MNRX,MJRY,MNRY)
.sp
.RE
is equivalent to 
.RS 3
.sp
CALL GRIDAL (MJRX,MNRX,MJRY,MNRY,1,1,5,0.,0.)
.RE
.SH EXAMPLES
Use the ncargex command to see the following relevant
example: 
tgrida.
.SH ACCESS
To use PERIML or c_periml, load the NCAR Graphics libraries ncarg, ncarg_gks,
and ncarg_c, preferably in that order.  
.SH SEE ALSO
Online:
gridall,
gridall_params,
gacolr,
gagetc,
gageti,
gagetr,
gasetc,
gaseti,
gasetr,
grid,
gridal,
gridl,
halfax,
labmod,
perim,
tick4,
ticks,
ncarg_cbind.
.sp
Hardcopy:
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
