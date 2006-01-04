.\"
.\"	$Id: gpolymarker.m,v 1.14 2006-01-04 00:13:06 haley Exp $
.\"
.TH GPOLYMARKER 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
gpolymarker (Polymarker) - the polymarker output primitive draws selected
symmetric symbols to mark user-specified coordinate positions.
.SH SYNOPSIS
#include <ncarg/gks.h>
.sp
void gpolymarker(const Gpoint_list *point_list);
.SH DESCRIPTION
.IP point_list.num_points 12
(Gint, Input) - The number of markers to be drawn.  Must be greater than zero.
.IP point_list.points 12
(Gpoint *, Input) - The X and Y coordinates of the point_list.num_points 
markers to be drawn, in world coordinates.
.SH USAGE
By default, the polymarker type is an asterisk. To 
select other polymarker types and attributes, see the man
page for gset_marker_type(3NCARG).
.sp
Note that the coordinate pairs must be in world coordinates and not
user coordinates.  Among other things, this means that the log scaling
and mirror-imaging features available via the c_set call and the SPPS
functions for drawing dots and markers are not applicable here.
.SH ACCESS
To use the GKS C-binding routines, load the ncarg_gks and
ncarg_c libraries.
.SH SEE ALSO
Online: 
.BR gset_marker_type(3NCARG),
.BR gset_marker_size(3NCARG),
.BR gset_colr_rep(3NCARG),
.BR gset_marker_colr_ind(3NCARG),
.BR ginq_marker_type(3NCARG),
.BR ginq_marker_size(3NCARG),
.BR ginq_marker_colr_ind(3NCARG),
.BR point(3NCARG),
.BR points(3NCARG),
.BR ngdots(3NCARG),
.BR gks(3NCARG),
.BR ncarg_gks_cbind(3NCARG)
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
