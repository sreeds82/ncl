/*
 *      $Id: attrinfogrid.h,v 1.3 1999-11-03 20:29:23 dbrown Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1996			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		attrinfogrid.h
 *
 *	Author:		David I. Brown
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Mon Feb 10 13:59:32 MST 1997
 *
 *	Description:	
 */
#ifndef	_NG_ATTRINFOGRID_H
#define	_NG_ATTRINFOGRID_H

#include <ncarg/ngo/go.h>

#ifndef _NCL_H_
#include <ncarg/ncl/defs.h>
#include <ncarg/ncl/NclDataDefs.h>
#include <ncarg/ncl/ApiRecords.h>
#include <ncarg/ncl/NclApi.h>
#define _NCL_H_
#endif

/*
 * Public api
 */

typedef struct _NgAttrInfoGrid
{
        Widget			grid;
        NhlBoolean		headline_on;
        Dimension		height;
} NgAttrInfoGrid;



NgAttrInfoGrid *NgCreateAttrInfoGrid
(
	int			go_id,
        Widget			parent,
        NrmQuark 		qfileref,
        NclApiDataList		*dlist
        );

NhlErrorTypes NgUpdateAttrInfoGrid
(
        NgAttrInfoGrid		*attr_info_grid,
        NrmQuark		qfileref,
        NclApiDataList		*dlist
        );

void NgDestroyAttrInfoGrid
(
        NgAttrInfoGrid		*attr_info_grid
        );
        

#endif	/* _NG_ATTRINFOGRID_H */
