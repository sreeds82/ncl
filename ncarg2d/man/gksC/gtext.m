.\"
.\"	$Id: gtext.m,v 1.1 1993-03-21 01:32:17 haley Exp $
.\"
.TH GTEXT 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
gtext (Text) - The basic output primitive for drawing text.  A number 
of attribute setting routines are available for selecting the size, font, 
precision, orientation, color, character spacing, etc.
.SH SYNOPSIS
void gtext(const Gpoint *text_pos, const char *char_string);
.SH DESCRIPTION
.IP text_pos 12
(Input) The x and y world coordinates of the text alignment of the first 
character 
in char_string.
.IP char_string 12
(Input) The characters to be drawn.
.SH ACCESS
To use the GKS C-binding routines, load the ncarg_gksC, ncarg_gks, ncarg_c,
and ncarg_loc libraries.
.SH SEE ALSO
Online: 
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
.BR ginq_char_up_vec(3NCARG),
.BR ginq_char_expan(3NCARG),
.BR plotchar(3NCARG),
.BR gks(3NCARG),
.BR ncarg_gks_cbind(3NCARG)
.sp
Hardcopy: 
"User's Guide for NCAR GKS-0A Graphics"
.SH COPYRIGHT
(c) Copyright 1987, 1988, 1989, 1991, 1993 University Corporation
for Atmospheric Research
.br
All Rights Reserved
