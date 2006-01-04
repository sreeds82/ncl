.\"
.\"	$Id: ginq_char_up_vec.m,v 1.14 2006-01-04 00:13:03 haley Exp $
.\"
.TH GINQ_CHAR_UP_VEC 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
ginq_char_up_vec (Inquire character up vector) - retrieves the current value of
the character up vector.
.SH SYNOPSIS
#include <ncarg/gks.h>
.sp
void ginq_char_up_vec(Gint *err_ind, Gvec *char_up_vec);
.SH DESCRIPTION
.IP err_ind 12
(Output) - If the inquired values cannot be returned correctly,
a non-zero error indicator is returned in err_ind, otherwise a zero is returned.
Consult "User's Guide for NCAR GKS-0A Graphics" for a description of the
meaning of the error indicators.
.IP char_up_vec.delta_x 12
(Gfloat, Output) -  Gives the X world coordinate of a the up vector.
.IP char_up_vec.delta_y 12
(Gfloat, Output) - Gives the Y world coordinate of a the up vector.
.SH USAGE
The up vector is that vector formed by the two coordinate points
(0.,0.) and (char_up_vec.delta_x,char_up_vec.delta_y).  See gset_char_up_vec
for more details on the meaning of the character up vector.
.SH ACCESS
To use the GKS C-binding routines, load the ncarg_gks and
ncarg_c libraries.
.SH SEE ALSO
Online: 
.BR gtext(3NCARG),
.BR gset_text_path(3NCARG),
.BR gset_text_align(3NCARG),
.BR gset_text_font_prec(3NCARG),
.BR gset_char_ht(3NCARG),
.BR gset_char_space(3NCARG),
.BR gset_char_up_vec(3NCARG),
.BR gset_char_expan(3NCARG),
.BR gset_colr_rep(3NCARG),
.BR gset_text_colr_ind(3NCARG),
.BR ginq_text_path(3NCARG),
.BR ginq_text_align(3NCARG),
.BR ginq_text_font_prec(3NCARG),
.BR ginq_char_ht(3NCARG),
.BR ginq_char_space(3NCARG),
.BR ginq_char_expan(3NCARG),
.BR plotchar(3NCARG),
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
