.\"
.\"	$Id: ginq_set_seg_names.m,v 1.1 1993-03-21 01:30:35 haley Exp $
.\"
.TH GINQ_SET_SEG_NAMES 3NCARG "March 1993" UNIX "NCAR GRAPHICS"
.SH NAME
ginq_set_seg_names (Inquire set of segment names in use) - Retrieves what segment
names are currently in use.
.SH SYNOPSIS
#include <ncarg/gks.h>
.sp
void ginq_set_seg_names(Gint num_elems_appl_list, Gint start_pos, Gint *err_ind, Gint_list *seg_names, Gint *length_list);
.SH DESCRIPTION
.IP num_elems_appl_list 12
(Input) - The number of elements in the application list you wish to request.
.IP start_pos 12
(Input) - The first set member requested.
.IP err_ind 12
(Output) - If the GKS state is WSOP (workstation open), WSAC
(workstation active), or SGOP (segment open), 
then err_ind is returned as "0"; otherwise err_ind is returned as "7".
.IP length_list 12
(Output) - The number of segment names that are currently in use.
.IP seg_names->num_ints 12
(Output) - The number of segment names returned.
.IP seg_names->ints 12
(Output) - If the GKS state is WSOP (workstation open), WSAC
(workstation active), or SGOP (segment open), and if start_pos is larger than
zero, then seg_names->ints is returned as the list of segment names starting
with element "start_pos" and ending with element 
"start_pos + num_elems_appl_list - 1"; otherwise seg_names->num_ints is 
undefined.
.SH USAGE
For NCAR GKS, segment names are integers between 0 and 99 inclusive
(see the man page for gcreate_seg(3NCARG)).
.sp
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
.BR ginq_name_open_seg(3NCARG),
.BR gdel_seg(3NCARG),
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
