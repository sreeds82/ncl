.\"
.\"	$Id: ginq_name_open_seg.m,v 1.1 1993-03-21 01:30:27 haley Exp $
.\"
.TH GINQ_NAME_OPEN_SEG 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
ginq_name_open_seg (Inquire name of open segment) - returns the name of the currently
open segment.
.SH SYNOPSIS
#include <ncarg/gks.h>
.sp
void ginq_name_open_seg(Gint *err_ind, Gint *name_open_seg);
.SH DESCRIPTION
.IP err_ind 12
(Output) - If the GKS state is SGOP (segment open), 
then err_ind is returned as "0"; otherwise err_ind is returned as "4".
.IP name_open_seg 12
(Output) - If the GKS state is SGOP (segment open), then 
name_open_seg is returned as the number of the currently open segment; otherwise
name_open_seg is undefined.
.SH ACCESS
To use the GKS C-binding routines, load the ncarg_gksC, ncarg_gks, ncarg_c,
and ncarg_loc libraries.
.SH SEE ALSO
Online: 
.BR geval_tran_matrix(3NCARG),
.BR gaccum_tran_matrix(3NCARG),
.BR gclose_seg(3NCARG),
.BR gcreate_seg(3NCARG),
.BR gcopy_seg_ws(3NCARG),
.BR gdel_seg(3NCARG),
.BR ginq_set_seg_names(3NCARG),
.BR gset_seg_tran(3NCARG),
.BR gks(3NCARG),
.BR ncarg_gks_cbind(3NCARG)
.sp
Hardcopy: 
"User's Guide for NCAR GKS-0A Graphics"
.SH COPYRIGHT
Copyright 1987, 1988, 1989, 1991, 1993 University Corporation
for Atmospheric Research
.br
All Rights Reserved
