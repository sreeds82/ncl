/*
 *      $Id: XyPlot.c,v 1.29 1995-01-11 00:46:57 boote Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1992			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		XyPlot.c
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Wed Dec 30 13:46:21 MST 1992
 *
 *	Description:	Source for XyPlot hlu.
 */
#include <stdio.h>
#include <math.h>
#include <ncarg/hlu/XyPlotP.h>
#include <ncarg/hlu/ConvertersP.h>
#include <ncarg/hlu/FortranP.h>
#include <ncarg/hlu/TickMark.h>
#include <ncarg/hlu/Title.h>
#include <ncarg/hlu/TransObjI.h>
#include <ncarg/hlu/IrregularType2TransObj.h>
#include <ncarg/hlu/LogLinTransObj.h>
#include <ncarg/hlu/Workstation.h>
#include <ncarg/hlu/CoordArrTableFloatP.h>

typedef enum _CallType{
	DATACHANGE,
	CREATE,
	SET
} _NhlCallType;

/*
 * Resource Default Functions.
 */
/*
 * Functions:	[Comp,Set][XMin,XMax,Top,Bottom]
 *
 * Description:	These functions are used so the XyPlot object can tell if the
 *		user set the left,right,top,and bottom resources or if it
 *		should use the min/max data values.
 *
 * In Args:	
 *		NrmName		name,
 *		NrmClass	cname,
 *		NhlPointer	base,
 *		unsigned int	offset
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
CompXMin
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.comp_x_min_set = False;
	xyplot->xyplot.compute_x_min = False;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
SetXMin
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.x_min_set = False;
	xyplot->xyplot.x_min = 1.0;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
CompXMax
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.comp_x_max_set = False;
	xyplot->xyplot.compute_x_max = False;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
SetXMax
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.x_max_set = False;
	xyplot->xyplot.x_max = 2.0;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
CompYMax
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.comp_y_max_set = False;
	xyplot->xyplot.compute_y_max = False;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
SetYMax
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.y_max_set = False;
	xyplot->xyplot.y_max = 2.0;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
CompYMin
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.comp_y_min_set = False;
	xyplot->xyplot.compute_y_min = False;

	return NhlNOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
SetYMin
#if	NhlNeedProto
(
	NrmName		name,
	NrmClass	cname,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,cname,base,offset)
	NrmName		name;
	NrmClass	cname;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	NhlXyPlotLayer	xyplot = (NhlXyPlotLayer)base;

	xyplot->xyplot.y_min_set = False;
	xyplot->xyplot.y_min = 1.0;

	return NhlNOERROR;
}

#define	Oset(field)	NhlOffset(NhlXyDataDepLayerRec,xydata.field)
static NhlResource data_resources[] = {

/* Begin-documented-resources */

	{NhlNxyColor,NhlCxyColor,NhlTColorIndex,sizeof(NhlColorIndex),
		Oset(color),NhlTImmediate,(NhlPointer)NhlFOREGROUND,0,NULL},
	{NhlNxyColors,NhlCxyColors,NhlTColorIndexGenArray,sizeof(NhlGenArray),
		Oset(colors),NhlTImmediate,(NhlPointer)NULL,0,
						(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoColor,NhlCxyMonoColor,NhlTBoolean,sizeof(NhlBoolean),
		Oset(mono_color),NhlTImmediate,(NhlPointer)False,0,NULL},

	{NhlNxyDashPattern,NhlCxyDashPattern,NhlTDashIndex,sizeof(NhlDashIndex),
		Oset(dash),NhlTImmediate,(NhlPointer)NhlSOLIDLINE,0,NULL},
	{NhlNxyDashPatterns,NhlCxyDashPatterns,NhlTDashIndexGenArray,
		sizeof(NhlGenArray), Oset(dashes),NhlTImmediate,
		(NhlPointer)NULL, 0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoDashPattern,NhlCxyMonoDashPattern,NhlTBoolean,
		sizeof(NhlBoolean),Oset(mono_dash),NhlTImmediate,
		(NhlPointer)False,0,NULL},

	{NhlNxyMarkerMode, NhlCxyMarkerMode,NhlTMarkerMode,
		sizeof(NhlMarkerMode),Oset(marker_mode),NhlTImmediate,
		(NhlPointer)NhlNOMARKERS,0,(NhlFreeFunc)NULL},
	{NhlNxyMarkerModes, NhlCxyMarkerModes,NhlTMarkerModeGenArray,
		sizeof(NhlGenArray),Oset(marker_modes),NhlTImmediate,
		(NhlPointer)NULL,0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoMarkerMode,NhlCxyMonoMarkerMode,NhlTBoolean,
		sizeof(NhlBoolean),Oset(mono_marker_mode),NhlTImmediate,
		(NhlPointer)False,0,NULL},

	{NhlNxyMarker, NhlCxyMarker,NhlTMarkerIndex,sizeof(NhlMarkerIndex),
		Oset(marker),NhlTImmediate,(NhlPointer)0,0,NULL},
	{NhlNxyMarkers, NhlCxyMarkers,NhlTMarkerIndexGenArray,
		sizeof(NhlGenArray), Oset(markers),NhlTImmediate,
		(NhlPointer)NULL, 0, (NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoMarker,NhlCxyMonoMarker,NhlTBoolean,
		sizeof(NhlBoolean),Oset(mono_marker),NhlTImmediate,
		(NhlPointer)False,0,NULL},

	{NhlNxyMarkerColor, NhlCxyMarkerColor,NhlTColorIndex,
		sizeof(NhlColorIndex),Oset(marker_color),NhlTImmediate,
		(NhlPointer)NhlFOREGROUND,0,(NhlFreeFunc)NULL},
	{NhlNxyMarkerColors, NhlCxyMarkerColors,NhlTColorIndexGenArray,
		sizeof(NhlGenArray),Oset(marker_colors),NhlTImmediate,
		(NhlPointer)NULL,0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoMarkerColor,NhlCxyMonoMarkerColor,NhlTBoolean,
		sizeof(NhlBoolean),Oset(mono_marker_color),NhlTImmediate,
		(NhlPointer)False,0,NULL},

	{NhlNxyMarkerSizeF, NhlCxyMarkerSizeF,NhlTFloat,
		sizeof(float), Oset(marker_size),NhlTString,
		".01", 0, (NhlFreeFunc)NULL},
	{NhlNxyMarkerSizes, NhlCxyMarkerSizes,NhlTFloatGenArray,
		sizeof(NhlGenArray), Oset(marker_sizes),NhlTImmediate,
		(NhlPointer)NULL, 0, (NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyMonoMarkerSize,NhlCxyMonoMarkerSize,NhlTBoolean,
		sizeof(NhlBoolean),Oset(mono_marker_size),NhlTImmediate,
		(NhlPointer)False,0,NULL},

	{NhlNxyLabelMode,NhlCxyLabelMode,NhlTLineLabelMode,
		sizeof(NhlLineLabelMode),
		Oset(label_mode),NhlTImmediate,(NhlPointer)NhlNOLABELS,
		0,NULL},
	{NhlNxyExplicitLabels,NhlCxyExplicitLabels,NhlTStringGenArray,
		sizeof(NhlGenArray),Oset(labels),NhlTImmediate,
		(NhlPointer)NULL,0,(NhlFreeFunc)NhlFreeGenArray}

/* End-documented-resources */

};
#undef Oset

#define	Oset(field)	NhlOffset(NhlXyPlotLayerRec,xyplot.field)
static NhlResource resources[] = {

/* Begin-documented-resources */

	{NhlNxyCurveData,NhlCxyCurveData,_NhlTDataList,sizeof(NhlGenArray),
		Oset(curve_data),NhlTImmediate,NULL,0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyCurveThicknessF,NhlCxyCurveThicknessF,NhlTFloat,sizeof(float),
		Oset(curve_thickness),NhlTString,"1.0",0,NULL},
	{NhlNxyXStyle,NhlCxyXStyle,NhlTTickMarkStyles,sizeof(NhlTickMarkStyles),
		Oset(x_style),NhlTImmediate,(NhlPointer)NhlLINEAR,0,NULL},
	{NhlNxyXIrrTensionF,NhlCxyXIrrTensionF,NhlTFloat,sizeof(float),
		Oset(x_tension),NhlTString,"2.0",0,NULL},
	{NhlNxyYStyle,NhlCxyYStyle,NhlTTickMarkStyles,sizeof(NhlTickMarkStyles),
		Oset(y_style),NhlTImmediate,(NhlPointer)NhlLINEAR,0,NULL},
	{NhlNxyYIrrTensionF,NhlCxyYIrrTensionF,NhlTFloat,sizeof(float),
		Oset(y_tension),NhlTString,"2.0",0,NULL},

	{NhlNxyXIrregularPoints,NhlCxyXIrregularPoints,NhlTFloatGenArray,
		sizeof(NhlPointer), Oset(x_irregular_points),NhlTImmediate,
		(NhlPointer)NULL,0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyYIrregularPoints,NhlCxyYIrregularPoints,NhlTFloatGenArray,
		sizeof(NhlPointer), Oset(y_irregular_points),NhlTImmediate,
		(NhlPointer)NULL,0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyXReverse,NhlCxyXReverse,NhlTBoolean,sizeof(NhlBoolean),
		Oset(x_reverse),NhlTImmediate,False,0,NULL},
	{NhlNxyYReverse,NhlCxyYReverse,NhlTBoolean,sizeof(NhlBoolean),
		Oset(y_reverse),NhlTImmediate,False,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),Oset(comp_x_min_set),
		NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(comp_x_max_set),NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(comp_y_max_set),NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(comp_y_min_set),NhlTImmediate,(NhlPointer)True,0,NULL},

	{NhlNxyComputeXMin,NhlCxyComputeXMin,NhlTBoolean,sizeof(NhlBoolean),
		Oset(compute_x_min),NhlTProcedure,(NhlPointer)CompXMin,0,NULL},
	{NhlNxyComputeXMax,NhlCxyComputeXMax,NhlTBoolean,sizeof(NhlBoolean),
		Oset(compute_x_max),NhlTProcedure,(NhlPointer)CompXMax,0,NULL},
	{NhlNxyComputeYMax,NhlCxyComputeYMax,NhlTBoolean,sizeof(NhlBoolean),
		Oset(compute_y_max),NhlTProcedure,(NhlPointer)CompYMax,0,NULL},
	{NhlNxyComputeYMin,NhlCxyComputeYMin,NhlTBoolean,sizeof(NhlBoolean),
		Oset(compute_y_min),NhlTProcedure,(NhlPointer)CompYMin,0,NULL},

	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(x_min_set),NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(x_max_set),NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(y_max_set),NhlTImmediate,(NhlPointer)True,0,NULL},
	{"no.res","no.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(y_min_set),NhlTImmediate,(NhlPointer)True,0,NULL},

	{NhlNxyXMinF,NhlCxyXMinF,NhlTFloat,sizeof(float),
		Oset(x_min),NhlTProcedure,(NhlPointer)SetXMin,0,NULL},
	{NhlNxyXMaxF,NhlCxyXMaxF,NhlTFloat,sizeof(float),
		Oset(x_max),NhlTProcedure,(NhlPointer)SetXMax,0,NULL},
	{NhlNxyYMaxF,NhlCxyYMaxF,NhlTFloat,sizeof(float),
		Oset(y_max),NhlTProcedure,(NhlPointer)SetYMax,0,NULL},
	{NhlNxyYMinF,NhlCxyYMinF,NhlTFloat,sizeof(float),
		Oset(y_min),NhlTProcedure,(NhlPointer)SetYMin,0,NULL},

	{NhlNxyTitles,NhlCxyTitles,NhlTBoolean,sizeof(NhlBoolean),
		Oset(titles),NhlTImmediate,(NhlPointer)True,0,NULL},
	{NhlNxyXAlternate,NhlCxyXAlternate,NhlTAlternatePlace,
		sizeof(NhlAlternatePlace),
		Oset(x_alternate),NhlTImmediate,(NhlPointer)NhlNONE,0,NULL},
	{NhlNxyYAlternate,NhlCxyYAlternate,NhlTAlternatePlace,
		sizeof(NhlAlternatePlace),
		Oset(y_alternate),NhlTImmediate,(NhlPointer)NhlNONE,0,NULL},
	{NhlNxyYAlternateCoords,NhlCxyYAlternateCoords,NhlTFloatGenArray,
		sizeof(NhlGenArray),Oset(y_alternate_coords),NhlTImmediate,NULL,
		0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyXAlternateCoords,NhlCxyXAlternateCoords,NhlTFloatGenArray,
		sizeof(NhlGenArray),Oset(x_alternate_coords),NhlTImmediate,NULL,
		0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyXOriginalCoords,NhlCxyXOriginalCoords,NhlTFloatGenArray,
		sizeof(NhlGenArray),Oset(x_original_coords),NhlTImmediate,NULL,
		0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyYOriginalCoords,NhlCxyYOriginalCoords,NhlTFloatGenArray,
		sizeof(NhlGenArray),Oset(y_original_coords),NhlTImmediate,NULL,
		0,(NhlFreeFunc)NhlFreeGenArray},
	{NhlNxyDashSegmentLengthF,NhlCxyDashSegmentLengthF,NhlTFloat,
		sizeof(float),Oset(dash_segment_length),NhlTString,".15",
		0,NULL},
	{NhlNxyLineLabelFontHeightF,NhlCxyLineLabelFontHeightF,NhlTFloat,
		sizeof(float), Oset(line_label_font_height),NhlTString,".01",
		0,NULL},

/* End-documented-resources */


/*
* Title resources of special importance are intercepted here
*/
	{NhlNtiMainOffsetXF,NhlCtiMainOffsetYF,NhlTFloat,sizeof(float),
		Oset(ti_main_offset_x),NhlTString,"0.0",0,NULL},
	{NhlNtiXAxisOffsetXF,NhlCtiXAxisOffsetYF,NhlTFloat,sizeof(float),
		Oset(ti_x_axis_offset_x),NhlTString,"0.0",0,NULL},
	{NhlNtiYAxisOffsetYF,NhlCtiXAxisOffsetYF,NhlTFloat,sizeof(float),
		Oset(ti_y_axis_offset_y),NhlTString,"0.0",0,NULL},
	{NhlNtiXAxisPosition,NhlCtiXAxisPosition,NhlTTitlePositions,
		sizeof(NhlTitlePositions),Oset(ti_x_axis_position),
		NhlTImmediate,(NhlPointer)NhlCENTER, 0,NULL},
	{NhlNtiYAxisPosition,NhlCtiYAxisPosition,NhlTTitlePositions,
		sizeof(NhlTitlePositions), Oset(ti_y_axis_position),
		NhlTImmediate,(NhlPointer)NhlCENTER, 0,NULL},
	{NhlNtiMainPosition,NhlCtiMainPosition,NhlTTitlePositions,
		sizeof(NhlTitlePositions), Oset(ti_main_position),
		NhlTImmediate,(NhlPointer)NhlCENTER,0,NULL},
};
#undef Oset


/* base methods */

static NhlErrorTypes XyDataSetValues(
#if	NhlNeedProto
        NhlLayer,          /* old */
        NhlLayer,          /* reference */
        NhlLayer,          /* new */
        _NhlArgList,    /* args */
        int             /* num_args*/
#endif
);

static NhlErrorTypes XyPlotSetValues(
#if	NhlNeedProto
        NhlLayer,          /* old */
        NhlLayer,          /* reference */
        NhlLayer,          /* new */
        _NhlArgList,    /* args */
        int             /* num_args*/
#endif
);

static NhlErrorTypes XyDataGetValues(
#if	NhlNeedProto
        NhlLayer	l,
        _NhlArgList	args,
        int		nargs
#endif
);

static NhlErrorTypes XyPlotGetValues(
#if	NhlNeedProto
        NhlLayer	l,
        _NhlArgList	args,
        int		nargs
#endif
);

static NhlErrorTypes XyDataInitialize(
#if	NhlNeedProto
        NhlLayerClass,     /* cname */
        NhlLayer,          /* req */
        NhlLayer,          /* new */
        _NhlArgList,    /* args */
        int             /* num_args */
#endif
);

static NhlErrorTypes XyPlotInitialize(
#if	NhlNeedProto
        NhlLayerClass,     /* cptr */
        NhlLayer,          /* req */
        NhlLayer,          /* new */
        _NhlArgList,    /* args */
        int             /* num_args */
#endif
);

static NhlErrorTypes XyPlotClassPartInitialize(
#if	NhlNeedProto
	NhlLayerClass	lc
#endif
);

static NhlErrorTypes XyDataClassInitialize(
#if	NhlNeedProto
	void
#endif
);

static NhlErrorTypes XyPlotClassInitialize(
#if	NhlNeedProto
	void
#endif
);

static NhlErrorTypes XyPlotDestroy(
#if	NhlNeedProto
        NhlLayer           /* inst */
#endif
);

static NhlErrorTypes XyPlotDraw(
#if	NhlNeedProto
        NhlLayer   /* layer */
#endif
);

/* 
* View Methods
*/

static NhlErrorTypes XyPlotGetBB(
#if	NhlNeedProto
        NhlLayer          /* instance */,
        NhlBoundingBox * /*thebox*/
#endif
);

/*
* Transform Methods
*/

static NhlErrorTypes XyPlotDataToNDC(
#if	NhlNeedProto
	NhlLayer		/* plot */,
	float*		/* x */,
	float*		/* y */,
	int		/* n */,
	float*		/* xout */,
	float*		/* yout */,
	float*		/*xmissing*/,
	float*		/*ymissing*/,
	int*		/*status*/,
	float*		/*out_of_range*/
#endif
);

static NhlErrorTypes XyPlotNDCToData(
#if	NhlNeedProto
	NhlLayer		/* plot */,
	float*		/* x */,
	float*		/* y */,
	int		/* n */,
	float*		/* xout */,
	float*		/* yout */,
	float*		/*xmissing*/,
	float*		/*ymissing*/,
	int*		/*status*/,
	float*		/*out_of_range*/
#endif
);

static NhlErrorTypes XyPlotUpdateData(
#if	NhlNeedProto
	NhlDataCommLayer	new,
	NhlDataCommLayer	old
#endif
);

static NhlErrorTypes CheckValues(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);

static NhlErrorTypes InternalizePointers(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);

static NhlErrorTypes ComputeDataExtents(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);

static NhlErrorTypes SetUpTransObjs(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);

static NhlErrorTypes SetUpTicks(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);
static NhlErrorTypes SetUpTitles(
#if	NhlNeedProto
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
#endif
);

static NhlErrorTypes DrawCurves(
#if	NhlNeedProto
	NhlXyPlotLayer	xlayer
#endif
);

NhlXyDataDepLayerClassRec NhlxyDataDepLayerClassRec = {
	/* base_class */
        {
/* class_name			*/	"xyDataDepLayerClass",
/* nrm_class			*/	NrmNULLQUARK,
/* layer_size			*/	sizeof(NhlXyDataDepLayerRec),
/* class_inited			*/	False,
/* superclass			*/	(NhlLayerClass)
						&NhldataSpecLayerClassRec,

/* layer_resources		*/	data_resources,
/* num_resources		*/	NhlNumber(data_resources),
/* all_resources		*/	NULL,

/* class_part_initialize	*/	NULL,
/* class_initialize		*/	XyDataClassInitialize,
/* layer_initialize		*/	XyDataInitialize,
/* layer_set_values		*/	XyDataSetValues,
/* layer_set_values_hook	*/	NULL,
/* layer_get_values		*/	XyDataGetValues,
/* layer_reparent		*/	NULL,
/* layer_destroy		*/	NULL
	},
	/* dataspec_class */
	{
/* foo				*/	0
	},
	/* xydatadep_class */
	{
/* foo				*/	0
	}
};

NhlXyPlotLayerClassRec NhlxyPlotLayerClassRec = {
	/* base_class */
        {
/* class_name                   */      "xyPlotLayerClass",
/* nrm_class                    */      NrmNULLQUARK,
/* layer_size                   */      sizeof(NhlXyPlotLayerRec),
/* class_inited                 */      False,
/* superclass                   */      (NhlLayerClass)
						&NhldataCommLayerClassRec,

/* layer_resources              */      resources,
/* num_resources                */      NhlNumber(resources),
/* all_resources		*/	NULL,

/* class_part_initialize        */      XyPlotClassPartInitialize,
/* class_initialize             */      XyPlotClassInitialize,
/* layer_initialize             */      XyPlotInitialize,
/* layer_set_values             */      XyPlotSetValues,
/* layer_set_values_hook	*/	NULL,
/* layer_get_values             */      XyPlotGetValues,
/* layer_reparent               */      NULL,
/* layer_destroy                */      XyPlotDestroy,

/* child_resources              */      NULL,

/* layer_draw                   */      XyPlotDraw,

/* layer_pre_draw               */      NULL,
/* layer_draw_segonly           */      NULL,
/* layer_post_draw              */      NULL,
/* layer_clear                  */      NULL
        },
	/* view_class */
	{
/* segment_workstation		*/	-1,
/* get_bb			*/	XyPlotGetBB
	},
	/* trans_class */
	{
/* overlay_capability 		*/	_tfNotOverlayCapable,
/* data_to_ndc			*/	XyPlotDataToNDC,
/* ndc_to_data			*/	XyPlotNDCToData,
/* data_polyline		*/	NULL,
/* ndc_polyline			*/	NULL
	},
	/* datacomm_class */
	{
/* data_offsets			*/	NULL,
/* update_data			*/	XyPlotUpdateData
	},
	/* xyplot_class */
	{
/* foo				*/	NULL
	}
};

NhlLayerClass NhlxyDataDepLayerClass =
				(NhlLayerClass)&NhlxyDataDepLayerClassRec;
NhlLayerClass NhlxyPlotLayerClass = (NhlLayerClass)&NhlxyPlotLayerClassRec;

/*
 * Function:	nhlfxydatadepclass
 *
 * Description:	fortran ref to this class
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	global Fortran
 * Returns:	NhlLayerClass
 * Side Effect:	
 */
NhlLayerClass
_NHLCALLF(nhlfxydatadeplayerclass,NHLFXYDATADEPLAYERCLASS)
#if	NhlNeedProto
(
	void
)
#else
()
#endif
{
	return NhlxyDataDepLayerClass;
}

/*
 * Function:	nhlfxyplotclass
 *
 * Description:	fortran ref to this class
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	global Fortran
 * Returns:	NhlLayerClass
 * Side Effect:	
 */
NhlLayerClass
_NHLCALLF(nhlfxyplotlayerclass,NHLFXYPLOTLAYERCLASS)
#if	NhlNeedProto
(
	void
)
#else
()
#endif
{
	return NhlxyPlotLayerClass;
}

static NrmQuark	Qfloat = NrmNULLQUARK;
static NrmQuark Qint = NrmNULLQUARK;
static NrmQuark Qstring = NrmNULLQUARK;

static NrmQuark QXirreg = NrmNULLQUARK;
static NrmQuark QYirreg = NrmNULLQUARK;
static NrmQuark QXalt = NrmNULLQUARK;
static NrmQuark QYalt = NrmNULLQUARK;
static NrmQuark QXorig = NrmNULLQUARK;
static NrmQuark QYorig = NrmNULLQUARK;

static NrmQuark Qcolors = NrmNULLQUARK;
static NrmQuark Qdpatterns = NrmNULLQUARK;
static NrmQuark Qmarkmodes = NrmNULLQUARK;
static NrmQuark Qmarkers = NrmNULLQUARK;
static NrmQuark Qmarksizes = NrmNULLQUARK;
static NrmQuark Qmarkercolors = NrmNULLQUARK;
static NrmQuark Qlabels = NrmNULLQUARK;

/*
 * Function:	XyDataClassInitialize
 *
 * Description:	init quark for latter use.
 *
 * In Args:	
 *		void
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
static NhlErrorTypes
XyDataClassInitialize
#if	NhlNeedProto
(
	void
)
#else
()
#endif
{
	_NhlEnumVals	lblmode[] = {
		{NhlNOLABELS,	"nolabels"},
		{NhlLETTERED,	"lettered"},
		{NhlCUSTOM,	"custom"}
	};

	_NhlEnumVals    mkrmode[] = {
		{NhlNOMARKERS, "nomarkers"},
		{NhlMARKERSONLY, "markersonly"},
		{NhlMARKLINES, "marklines"}
	};

	_NhlRegisterEnumType(NhlTLineLabelMode,lblmode,NhlNumber(lblmode));
	_NhlRegisterEnumType(NhlTMarkerMode,mkrmode,NhlNumber(mkrmode));
	Qint = NrmStringToQuark(NhlTInteger);
	Qstring = NrmStringToQuark(NhlTString);

	Qcolors = NrmStringToQuark(NhlNxyColors);
	Qdpatterns = NrmStringToQuark(NhlNxyDashPatterns);
	Qmarkmodes = NrmStringToQuark(NhlNxyMarkerModes);
	Qmarkers = NrmStringToQuark(NhlNxyMarkers);
	Qmarksizes = NrmStringToQuark(NhlNxyMarkerSizes);
	Qmarkercolors = NrmStringToQuark(NhlNxyMarkerColors);
	Qlabels = NrmStringToQuark(NhlNxyExplicitLabels);

	return NhlNOERROR;
}

/*
 * Function:	XyPlotClassInitialize
 *
 * Description:	Add type converters for types added to support this class.
 *
 * In Args:	NhlNONE
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	ErrorConditions
 *
 * Side Effects:	NhlNONE
 */
static NhlErrorTypes
XyPlotClassInitialize
#if	NhlNeedProto
(
	void
)
#else
()
#endif
{
	_NhlEnumVals	altplace[] = {
		{NhlNONE,	"none"},
		{NhlLEFTAXIS,	"leftaxis"},
		{NhlRIGHTAXIS,	"rightaxis"},
		{NhlTOPAXIS,	"topaxis"},
		{NhlBOTTOMAXIS,	"bottomaxis"}
	};


	Qfloat = NrmStringToQuark(NhlTFloat);
	_NhlRegisterEnumType(NhlTAlternatePlace,altplace,NhlNumber(altplace));

	QXirreg = NrmStringToQuark(NhlNxyXIrregularPoints);
	QYirreg = NrmStringToQuark(NhlNxyYIrregularPoints);
	QXalt = NrmStringToQuark(NhlNxyXAlternateCoords);
	QYalt = NrmStringToQuark(NhlNxyYAlternateCoords);
	QXorig = NrmStringToQuark(NhlNxyXOriginalCoords);
	QYorig = NrmStringToQuark(NhlNxyYOriginalCoords);

	return NhlNOERROR;
}

/*
 * Function:	XyPlotClassPartInitialize
 *
 * Description:	This function initializes fields in the NhlXyPlotLayerClassPart
 *		that can not be done by static initialization.
 *		Takes care of calling _NhlRegisterChildClass for the title
 *		and the tick mark objects. This needs to be done so resource
 *		forwarding can work. All Title resources are forwarded with
 *		the exception of the Offset*F resources. 
 *		The tick mark object has several resources blocked. These 
 *		resources all have dependencies to the tm**Style resources.
 *		Since these dependencies exist all of the resouces must be
 *		set in the same SetValues or Create calls. Therefore they
 *		are blocked and storage exists, in the XyPlot Object instance
 *		record, for these resources. The primary reason for blocking
 *		these resouces is the tm**Style resources. These are controled
 *		by the XyPlot so that both of the x axis and the y axis can
 *		have correct transformation.
 *
 * In Args:	
 *		NhlLayerClass	lc	NhlLayer Class to init
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
static NhlErrorTypes
XyPlotClassPartInitialize
#if	NhlNeedProto
(
	NhlLayerClass	lc	/* NhlLayer Class to init	*/
)
#else
(lc)
	NhlLayerClass	lc;	/* NhlLayer Class to init	*/
#endif
{
	NhlErrorTypes ret = NhlNOERROR;
	NhlErrorTypes lret = NhlNOERROR;

	/*
	 * Register children objects
	 */
	lret = _NhlRegisterChildClass(lc,NhltitleLayerClass,False,False,
			NhlNtiMainOffsetXF,
        		NhlNtiXAxisOffsetXF, 
        		NhlNtiYAxisOffsetYF, 
        		NhlNtiXAxisPosition, 
        		NhlNtiYAxisPosition, 
        		NhlNtiMainPosition,
			NULL);

	ret = _NhlRegisterChildClass(lc,NhltickMarkLayerClass,False,False,
			NhlNtmXBDataLeftF,NhlNtmXBDataRightF,NhlNtmXTDataRightF,
			NhlNtmXTDataLeftF,NhlNtmYLDataTopF,NhlNtmYLDataBottomF,
			NhlNtmYRDataTopF,NhlNtmYRDataBottomF,NhlNtmYLStyle, 
			NhlNtmYRStyle,NhlNtmXBStyle,NhlNtmXTStyle,
			NhlNtmXBIrregularPoints,NhlNtmXTIrregularPoints,
			NhlNtmYLIrregularPoints,NhlNtmYRIrregularPoints,
			NhlNtmXBIrrTensionF,NhlNtmXTIrrTensionF,
			NhlNtmYLIrrTensionF,NhlNtmYRIrrTensionF,
			NULL);

	ret = MIN(ret,lret);

	/*
	 * Register Data Resources
	 */

	lret = _NhlRegisterDataRes((NhlDataCommLayerClass)lc,NhlNxyCurveData,
			NhlxyDataDepLayerClass,NhlcoordArrTableFloatLayerClass,
									NULL);
	return MIN(lret,ret);
}

/*
 * Function:	XyPlotChanges
 *
 * Description:	called by setvalues and initialize to do all the common things.
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
static NhlErrorTypes
XyPlotChanges
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	NhlErrorTypes	ret1 = NhlNOERROR;
	NhlErrorTypes	ret2 = NhlNOERROR;


	ret1 = InternalizePointers(xnew,xold,calledfrom);
	if(ret1 < NhlWARNING)
		return ret1;

	ret2 = CheckValues(xnew,xold,calledfrom);
	if(ret2 < NhlWARNING)
		return ret2;
	ret1 = MIN(ret1,ret2);

	ret2 = ComputeDataExtents(xnew,xold,calledfrom);
	if(ret2 < NhlWARNING)
		return ret2;
	ret1 = MIN(ret1,ret2);

	if(xnew->xyplot.data_ranges_set){
		ret2 = SetUpTransObjs(xnew,xold,calledfrom);
		if(ret2 < NhlWARNING)
			return(ret2);
		ret1 = MIN(ret1,ret2);
	}

	ret2 = SetUpTicks(xnew,xold,calledfrom);
	if(ret2 < NhlWARNING)
		return(ret2);
	ret1 = MIN(ret1,ret2);

	ret2 = SetUpTitles(xnew,xold,calledfrom);
	if(ret2 < NhlWARNING)
		return(ret2);
	ret1 = MIN(ret1,ret2);

	return ret1;

}

/*
 * Function:	XyDataInitialize
 *
 * Description:	Initializes the XyData Dependent class instance.
 *
 * In Args:	
 *		NhlLayerClass	class,
 *		NhlLayer		req,
 *		NhlLayer		new,
 *		_NhlArgList	args,
 *		int		num_args
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
XyDataInitialize
#if	NhlNeedProto
(
	NhlLayerClass	cptr,
	NhlLayer		req,
	NhlLayer		new,
	_NhlArgList	args,
	int		num_args
)
#else
(cptr,req,new,args,num_args)
        NhlLayerClass      cptr;
        NhlLayer           req;
        NhlLayer           new;
        _NhlArgList     args;
        int             num_args;
#endif
{
	NhlXyDataDepLayer	dnew = (NhlXyDataDepLayer)new;
	char		*error_lead = "XyDataInitialize";
	NhlGenArray	gen;
	NhlErrorTypes	ret = NhlNOERROR;

	if(dnew->xydata.colors != NULL){
		gen = dnew->xydata.colors;
		if((gen->typeQ == Qint) && (gen->size == sizeof(int)) &&
						(gen->num_dimensions == 1)){
			dnew->xydata.colors = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyColors);

			dnew->xydata.colors = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.dashes != NULL){
		gen = dnew->xydata.dashes;
		if((gen->typeQ == Qint) && (gen->size == sizeof(int)) &&
						(gen->num_dimensions == 1)){
			dnew->xydata.dashes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyDashPatterns);

			dnew->xydata.dashes = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_modes != NULL){
		gen = dnew->xydata.marker_modes;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_modes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkerModes);

			dnew->xydata.marker_modes = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.markers != NULL){
		gen = dnew->xydata.markers;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.markers = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkers);

			dnew->xydata.markers = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_sizes != NULL){
		gen = dnew->xydata.marker_sizes;
		if((gen->size == sizeof(float)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_sizes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic float array: ignoring",
					error_lead,NhlNxyMarkerSizes);

			dnew->xydata.marker_sizes = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_colors != NULL){
		gen = dnew->xydata.marker_colors;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_colors = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkerColors);

			dnew->xydata.marker_colors = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.labels != NULL){
		gen = dnew->xydata.labels;
		if((gen->typeQ == Qstring) &&(gen->size == sizeof(NhlString)) &&
						(gen->num_dimensions == 1)){

			dnew->xydata.labels = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:%s must be set with a generic NhlString array: ignoring",
					error_lead,NhlNxyExplicitLabels);

			dnew->xydata.labels = NULL;
			ret = MIN(ret,NhlWARNING);
		}
	}

	return ret;
}

/*
 * Function:	XyPlotInitialize
 *
 * Description: 
 *
 * In Args: 	class	objects layer_class
 *		req	instance record of requested values
 *		new	instance record of new object
 *		args	list of resources and values for reference
 *		num_args 	number of elements in args.
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:	state change in GKS due to mapping transformations.
 */
/*ARGSUSED*/
static NhlErrorTypes
XyPlotInitialize
#if	NhlNeedProto
(
	NhlLayerClass	cptr,
	NhlLayer		req,
	NhlLayer		new,
	_NhlArgList	args,
	int		num_args
)
#else
(cptr,req,new,args,num_args)
        NhlLayerClass      cptr;
        NhlLayer           req;
        NhlLayer           new;
        _NhlArgList     args;
        int             num_args;
#endif
{
	NhlXyPlotLayer	xnew = (NhlXyPlotLayer)new;

	xnew->xyplot.ticks = NULL;
	xnew->xyplot.ttitles = NULL;
	xnew->xyplot.thetrans = NULL;
	xnew->xyplot.data_ranges_set = False;
	xnew->xyplot.check_ranges = True;

	return XyPlotChanges((NhlXyPlotLayer)new,NULL,CREATE);
}

/*
 * Function:	XyDataSetValues
 *
 * Description:	Initializes the XyData Dependent class instance.
 *
 * In Args:	
 *		NhlLayerClass	class,
 *		NhlLayer		req,
 *		NhlLayer		new,
 *		_NhlArgList	args,
 *		int		num_args
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
XyDataSetValues
#if	NhlNeedProto
(
	NhlLayer		old,
	NhlLayer		reference,
	NhlLayer		new,
	_NhlArgList	args,
	int		num_args
)
#else
(old,reference,new,args,num_args)
	NhlLayer		old;
	NhlLayer		reference;
	NhlLayer		new;
	_NhlArgList	args;
	int		num_args;
#endif
{
	NhlXyDataDepLayer	dnew = (NhlXyDataDepLayer)new;
	NhlXyDataDepLayer	dold = (NhlXyDataDepLayer)old;
	char		*error_lead = "XyDataInitialize";
	NhlGenArray	gen;
	NhlErrorTypes	ret = NhlNOERROR;

	if(dnew->xydata.colors != dold->xydata.colors){
		gen = dnew->xydata.colors;
		if((gen->typeQ == Qint) && (gen->size == sizeof(int)) &&
						(gen->num_dimensions == 1)){
			dnew->xydata.colors = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyColors);

			dnew->xydata.colors = dold->xydata.colors;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.dashes != dold->xydata.dashes){
		gen = dnew->xydata.dashes;
		if((gen->typeQ == Qint) && (gen->size == sizeof(int)) &&
						(gen->num_dimensions == 1)){
			dnew->xydata.dashes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyDashPatterns);

			dnew->xydata.dashes = dold->xydata.dashes;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_modes != dold->xydata.marker_modes){
		gen = dnew->xydata.marker_modes;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_modes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkerModes);

			dnew->xydata.marker_modes = dold->xydata.marker_modes;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.markers != dold->xydata.markers){
		gen = dnew->xydata.markers;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.markers = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkers);

			dnew->xydata.markers = dold->xydata.markers;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_sizes != dold->xydata.marker_sizes){
		gen = dnew->xydata.marker_sizes;
		if((gen->size == sizeof(float)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_sizes = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic float array: ignoring",
					error_lead,NhlNxyMarkerSizes);

			dnew->xydata.marker_sizes = dold->xydata.marker_sizes;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.marker_colors != dold->xydata.marker_colors){
		gen = dnew->xydata.marker_colors;
		if((gen->size == sizeof(int)) && (gen->num_dimensions == 1)){
			dnew->xydata.marker_colors = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a 1-dim generic int array: ignoring",
					error_lead,NhlNxyMarkerColors);

			dnew->xydata.marker_colors = dold->xydata.marker_colors;
			ret = MIN(ret,NhlWARNING);
		}
	}

	if(dnew->xydata.labels != dold->xydata.labels){
		gen = dnew->xydata.labels;
		if((gen->typeQ == Qstring) &&(gen->size == sizeof(NhlString)) &&
						(gen->num_dimensions == 1)){

			dnew->xydata.labels = _NhlCopyGenArray(gen,True);
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:%s must be set with a generic NhlString array: ignoring",
					error_lead,NhlNxyExplicitLabels);

			dnew->xydata.labels = dold->xydata.labels;
			ret = MIN(ret,NhlWARNING);
		}
	}

	return ret;
}

/*
 * Function:	XyPlotSetValues
 *
 * Description: 
 *
 * In Args:	old	copy of old instance record
 *		reference	requested instance record
 *		new	new instance record	
 *		args 	list of resources and values for reference
 *		num_args	number of elements in args.
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	ErrorConditions
 *
 * Side Effects:
 */
/*ARGSUSED*/
static NhlErrorTypes
XyPlotSetValues
#if	NhlNeedProto
(
	NhlLayer		old,
	NhlLayer		reference,
	NhlLayer		new,
	_NhlArgList	args,
	int		num_args
)
#else
(old,reference,new,args,num_args)
	NhlLayer		old;
	NhlLayer		reference;
	NhlLayer		new;
	_NhlArgList	args;
	int		num_args;
#endif
{
	NhlXyPlotLayer xnew = (NhlXyPlotLayer)new;
	NhlXyPlotLayer xold = (NhlXyPlotLayer)old;
	float deltax,deltay;

	/*
	 * POSSIBLE DIV0 Problem???
	 */
	deltax = xnew->view.width/xold->view.width;
	deltay = xnew->view.height/xold->view.height;

	if((xnew->view.width != xold->view.width) &&
		(xnew->xyplot.line_label_font_height ==
			xold->xyplot.line_label_font_height)){

		xnew->xyplot.line_label_font_height =
				deltay * xnew->xyplot.line_label_font_height;
	}
	if((xnew->view.width != xold->view.width) &&
		(xnew->xyplot.dash_segment_length ==
			xold->xyplot.dash_segment_length)){

		xnew->xyplot.dash_segment_length =
				deltax * xnew->xyplot.dash_segment_length;
	}

	return XyPlotChanges(xnew,xold,SET);
}

/*
 * Function:	XyDataGetValues
 *
 * Description:	
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
static NhlErrorTypes
XyDataGetValues
#if	NhlNeedProto
(
	NhlLayer	l,
	_NhlArgList	args,
	int		nargs
)
#else
(l,args,nargs)
	NhlLayer	l;
	_NhlArgList	args;
	int		nargs;
#endif
{
	char			func[] = "XyDataGetValues";
	NhlXyDataDepLayerPart	*xyp = &((NhlXyDataDepLayer)l)->xydata;
	int			i;
	NhlGenArray		ga;
	NhlString		res_name;

	for(i=0;i<nargs;i++){
		ga = NULL;
		res_name = NULL;

		if(args[i].quark == Qcolors){
			ga = xyp->colors;
		}
		if(args[i].quark == Qdpatterns){
			ga = xyp->dashes;
		}
		if(args[i].quark == Qmarkmodes){
			ga = xyp->marker_modes;
		}
		if(args[i].quark == Qmarkers){
			ga = xyp->markers;
		}
		if(args[i].quark == Qmarksizes){
			ga = xyp->marker_sizes;
		}
		if(args[i].quark == Qmarkercolors){
			ga = xyp->marker_colors;
		}
		if(args[i].quark == Qlabels){
			ga = xyp->labels;
		}

		if(ga != NULL){
			*((NhlGenArray *)args[i].value.ptrval) =
						_NhlCopyGenArray(ga,True);
			if(!*(NhlGenArray *)args[i].value.ptrval){
				NhlPError(NhlWARNING,ENOMEM,
					"%s:Unable to retrieve %s",func,
					NrmQuarkToString(args[i].quark));
			}
		}
	}
}

/*
 * Function:	XyPlotGetValues
 *
 * Description:	
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
static NhlErrorTypes
XyPlotGetValues
#if	NhlNeedProto
(
	NhlLayer	l,
	_NhlArgList	args,
	int		nargs
)
#else
(l,args,nargs)
	NhlLayer	l;
	_NhlArgList	args;
	int		nargs;
#endif
{
	char			func[] = "XyPlotGetValues";
	NhlXyPlotLayerPart	*xyp = &((NhlXyPlotLayer)l)->xyplot;
	int			i;
	NhlGenArray		ga;
	NhlString		res_name;

	for(i=0;i<nargs;i++){
		ga = NULL;
		res_name = NULL;

		if(args[i].quark == QXirreg){
			ga = xyp->x_irregular_points;
		}
		if(args[i].quark == QYirreg){
			ga = xyp->y_irregular_points;
		}
		if(args[i].quark == QXalt){
			ga = xyp->x_alternate_coords;
		}
		if(args[i].quark == QYalt){
			ga = xyp->y_alternate_coords;
		}
		if(args[i].quark == QXorig){
			ga = xyp->x_original_coords;
		}
		if(args[i].quark == QYorig){
			ga = xyp->y_original_coords;
		}

		if(ga != NULL){
			*((NhlGenArray *)args[i].value.ptrval) =
						_NhlCopyGenArray(ga,True);
			if(!*(NhlGenArray *)args[i].value.ptrval){
				NhlPError(NhlWARNING,ENOMEM,
					"%s:Unable to retrieve %s",func,
					NrmQuarkToString(args[i].quark));
			}
		}
	}
}

/*
 * Function:	DrawCurves
 *
 * Description:	
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
static NhlErrorTypes
DrawCurves
#if	NhlNeedProto
(
	NhlXyPlotLayer	xlayer
)
#else
(xlayer)
	NhlXyPlotLayer	xlayer;
#endif
{
	int			i,j;
	int			num_data;
	int			current_letter = 0;
	NhlErrorTypes		ret = NhlNOERROR;
	NhlErrorTypes		ret1 = NhlNOERROR;
	char			buffer[80];
	int			upordownflag = 1;
	NhlCoordArrTableFloatLayer	datal;
	NhlXyDataDepLayer		dataspec;
	_NhlDataNodePtr		*datalist = NULL;
	NhlBoolean		new;

	for(i = 0; i< 80; i++)
		buffer[i] = '\0';

	ret = _NhlActivateWorkstation((NhlLayer)xlayer->base.wkptr);	
	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,
"DrawCurves:Could not activate workstation no data curves will be drawn");
		return(NhlFATAL);
	}
	ret1 = MIN(ret,ret1);

	ret = _NhlSetTrans((NhlLayer)xlayer->xyplot.thetrans,(NhlLayer)xlayer);
	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,
	"DrawCurves:Could not set transformation no data curves will be drawn");
		return(NhlFATAL);
	}
	ret1 = MIN(ret,ret1);

	num_data = _NhlGetDataInfo(xlayer->xyplot.curve_data,&datalist);
	if(num_data <= 0){
		xlayer->xyplot.data_ranges_set = False;
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotDraw:%s resource problem",
							NhlNxyCurveData);
		return NhlFATAL;
	}

	NhlVASetValues(xlayer->base.wkptr->base.id,
		NhlNwkLineThicknessF,	xlayer->xyplot.curve_thickness,
		NhlNwkLineLabelFontHeightF,
					xlayer->xyplot.line_label_font_height,
		NULL);

	for(i=0;i < num_data;i++){
		float		**yvalues;
		float		**xvalues;
		int		*len_yvalues;
		int		*len_xvalues;
		NhlBoolean	impx;
		NhlBoolean	impy;
		int		*ctable=NULL;
		int		len_ctable=0;
		int		*dashtable=NULL;
		int		len_dashtable=0;
		int		num_curves=0;
		NhlString	*labeltable=NULL;
		int		len_labeltable =0;
		NhlMarkerMode	*markermodetable=NULL;
		int		len_markermodetable= 0;
		int		*markertable=NULL;
		int		len_markertable= 0;
		float		*markersizetable=NULL;
		float		len_markersizetable= 0;
		int		*markercolortable= NULL;
		int		len_markercolortable;

		/*
		 * Retrieve Data Information
		 */
		datal=(NhlCoordArrTableFloatLayer)_NhlGetDataSet(datalist[i],&new);
		if(datal == NULL){
			xlayer->xyplot.data_ranges_set = False;
			NhlPError(NhlFATAL,NhlEUNKNOWN,"Data Problem???");
			return NhlFATAL;
		}
		if(datal->flt.ytable != NULL){
			yvalues = (float**)datal->flt.ytable->data;
			len_yvalues = (int*)datal->flt.ytable_lens->data;
			num_curves = datal->flt.ytable->len_dimensions[0];
			impy = False;
		}
		else{
			yvalues = NULL;
			len_yvalues = NULL;
			impy = True;
		}
		if(datal->flt.xtable != NULL){
			xvalues = (float**)datal->flt.xtable->data;
			len_xvalues = (int*)datal->flt.xtable_lens->data;
			impx = False;
			if(impy)
				num_curves =
				datal->flt.xtable->len_dimensions[0];
			else
				num_curves =
					MIN(num_curves,
				datal->flt.xtable->len_dimensions[0]);
		}
		else{
			xvalues = NULL;
			len_xvalues = NULL;
			impx = True;
			if(impy){
				NhlPError(NhlWARNING,NhlEUNKNOWN,
					"Data has implied X and implied Y?");
				continue;
			}
		}

		/*
		 * Retrieve Data Specific information
		 */
		dataspec = (NhlXyDataDepLayer)datalist[i]->dataspec;

		/*
		 * colors
		 */
		if(dataspec->xydata.colors != NULL &&
						!dataspec->xydata.mono_color){
			ctable = (int*)dataspec->xydata.colors->data;
			len_ctable =dataspec->xydata.colors->len_dimensions[0];
		}
		else
			len_ctable = 0;

		/*
		 * dash patterns
		 */
		if(dataspec->xydata.dashes != NULL &&
						!dataspec->xydata.mono_dash){
			dashtable = (int*)dataspec->xydata.dashes->data;
			len_dashtable =
				dataspec->xydata.dashes->len_dimensions[0];
		}
		else
			len_dashtable = 0;

		/*
		 * marker mode
		 */
		if(dataspec->xydata.marker_modes != NULL &&
					!dataspec->xydata.mono_marker_mode){
			markermodetable = (NhlMarkerMode*)
					dataspec->xydata.marker_modes->data;
			len_markermodetable =
			dataspec->xydata.marker_modes->len_dimensions[0];
		}
		else
			len_markermodetable= 0;

		/*
		 * Markers
		 */
		if(dataspec->xydata.markers != NULL &&
					!dataspec->xydata.mono_marker){
			markertable = (NhlMarkerIndex*)
						dataspec->xydata.markers->data;
			len_markertable =
				dataspec->xydata.markers->len_dimensions[0];
		}
		else
			len_markertable = 0;

		/*
		 * Marker Color
		 */
		if(dataspec->xydata.marker_colors != NULL &&
					!dataspec->xydata.mono_marker_color){
			markercolortable = (NhlColorIndex*)
					dataspec->xydata.marker_colors->data;
			len_markercolortable =
			dataspec->xydata.marker_colors->len_dimensions[0];
		}
		else
			len_markercolortable = 0;

		/*
		 * Marker Size
		 */
		if(dataspec->xydata.marker_sizes != NULL &&
					!dataspec->xydata.mono_marker_size){
			markersizetable = (float*)
					dataspec->xydata.marker_sizes->data;
			len_markersizetable =
			dataspec->xydata.marker_sizes->len_dimensions[0];
		}
		else
			len_markersizetable = 0;

		/*
		 * labels
		 */
		if(dataspec->xydata.labels != NULL){
			labeltable = (NhlString*)dataspec->xydata.labels->data;
			len_labeltable =dataspec->xydata.labels->len_dimensions[0];
		}
		else
			len_labeltable = 0;

		for(j=0;j < num_curves;j++){
			float		*yvect=NULL;
			float		*xvect=NULL;
			NhlDashIndex	dpattern;
			NhlColorIndex	color;
			NhlColorIndex	marker_color;
			NhlMarkerIndex	marker;
			float		marker_size;
			NhlMarkerMode	marker_mode;
			NhlString	label=NULL;
			int		tint;
			int		npts;
			NhlBoolean	curve_impy = False;
			NhlBoolean	curve_impx = False;
			float		xtmp,ytmp;
			int		status;
			float 		out_of_range;

			if(!impy && !impx){
				xvect = xvalues[j];
				yvect = yvalues[j];
				npts = MIN(len_yvalues[j],len_xvalues[j]);
			}
			else if(!impx){
				xvect = xvalues[j];
				npts = len_xvalues[j];
			}
			else if(!impy){
				yvect = yvalues[j];
				npts = len_yvalues[j];
			}
			else{
				NhlPError(NhlWARNING,NhlEUNKNOWN,
					"Data has implied X and implied Y?");
				break;
			}

			if(xvect == NULL)
				curve_impx = True;

			if(yvect == NULL)
				curve_impy = True;

			/****************
			* Set Color	*
			****************/
			if(j < len_ctable)
				color = ctable[j];
			else
				color = dataspec->xydata.color;

			/****************
			* Set Dash	*
			****************/
			if(j < len_dashtable)
				dpattern = dashtable[j];
			else
				dpattern = dataspec->xydata.dash;

			/****************
                        * Set Markers   *
			****************/
			if(j < len_markermodetable) 
				marker_mode = markermodetable[j];
			else 
				marker_mode = dataspec->xydata.marker_mode;
		
			if(j < len_markertable)
				marker = markertable[j];
			else
				marker = dataspec->xydata.marker;

			if(j < len_markercolortable)
				marker_color = markercolortable[j];
			else if(dataspec->xydata.marker_color != -1)
				marker_color = dataspec->xydata.marker_color;
			else 
				marker_color = color;
	
			if(j < len_markersizetable)
				marker_size = markersizetable[j];
			else 
				marker_size = dataspec->xydata.marker_size ;

			/****************
			 * Set Label	*
			 ***************/
			/*
			 * clear buffer
			 */
			for(tint = strlen(buffer) - 1; tint >= 0;tint--)
				buffer[tint] = '\0';
			switch(dataspec->xydata.label_mode) {
				case NhlNOLABELS:
					label = NULL;
				break;
				case NhlCUSTOM:	
					if(j < len_labeltable)
						label = labeltable[j];
					else{
						sprintf(buffer,"%s%d",
							dataspec->base.name,
									j+1);
						label = buffer;
					}
				break;
				case NhlLETTERED:
					buffer[0] =
					(char)((int)'A' + current_letter % 26);
					current_letter++;
					buffer[1] = '\0';
					label = buffer;
				break;
			}

			NhlVASetValues(xlayer->base.wkptr->base.id,
				NhlNwkLineColor,	color,
				NhlNwkDashPattern,	dpattern,
				NhlNwkLineDashSegLenF,
					xlayer->xyplot.dash_segment_length,
				NhlNwkLineLabel,	label,
				NULL);

			_NhlSetLineInfo(xlayer->base.wkptr,(NhlLayer)xlayer);

			if(marker_mode != NhlNOMARKERS) {
				NhlVASetValues(xlayer->base.wkptr->base.id,
					NhlNwkMarkerIndex,marker,
					NhlNwkMarkerSizeF,marker_size,
					NhlNwkMarkerColor,marker_color,NULL);
				_NhlSetMarkerInfo(xlayer->base.wkptr,
							(NhlLayer)xlayer);
			}


			upordownflag = 1;

			if(!curve_impx && !curve_impy){
				/* both vectors exist */
				if(datal->flt.missing_x_set &&
					datal->flt.missing_y_set){
					float	xmiss=datal->flt.missing_x;
					float	ymiss=datal->flt.missing_y;
					int 	status;

					for(tint=0;tint < npts;tint++){
						if((xvect[tint] == xmiss) ||
							(yvect[tint] == ymiss))
							upordownflag = 1;
						else{
							if(marker_mode != 
								NhlMARKERSONLY){
							_NhlDataLineTo(
							xlayer->xyplot.thetrans,
								(NhlLayer)xlayer,
								xvect[tint],
								yvect[tint],
								upordownflag);
							}
							if(marker_mode != 
								NhlNOMARKERS){

								XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&(xvect[tint]),
								&(yvect[tint]),
								1,
								&xtmp,
								&ytmp,
								&xmiss,
								&ymiss,
								&status,
								&out_of_range);
								_NhlWorkstationMarker(
									xlayer->base.wkptr,
									&xtmp,
									&ytmp,
									1
								);
							}
							

							upordownflag = 0;
						}
					}
				}
				else if(datal->flt.missing_x_set){
					float	xmiss=datal->flt.missing_x;

					for(tint=0;tint < npts;tint++){
						if(xvect[tint] == xmiss)
							upordownflag = 1;
						else{
							if(marker_mode != 
								NhlMARKERSONLY){
								_NhlDataLineTo(
								xlayer->xyplot.thetrans,
									(NhlLayer)xlayer,
									xvect[tint],
									yvect[tint],
									upordownflag);
							}
							if(marker_mode != 
								NhlNOMARKERS){

								XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&(xvect[tint]),
								&(yvect[tint]),
								1,
								&xtmp,
								&ytmp,
								&xmiss,
								NULL,
								&status,
								&out_of_range);
								_NhlWorkstationMarker(
									xlayer->base.wkptr,
									&xtmp,
									&ytmp,
									1
								);
							}

								upordownflag = 0;
						}
					}
				}
				else if(datal->flt.missing_y_set){
					float	ymiss=datal->flt.missing_y;

					for(tint=0;tint < npts;tint++){
						if(yvect[tint] == ymiss)
							upordownflag = 1;
						else{
							if(marker_mode != 
								NhlMARKERSONLY){
								_NhlDataLineTo(
								xlayer->xyplot.thetrans,
									(NhlLayer)xlayer,
									xvect[tint],
									yvect[tint],
									upordownflag);
							}

							if(marker_mode != 
								NhlNOMARKERS){

								XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&(xvect[tint]),
								&(yvect[tint]),
								1,
								&xtmp,
								&ytmp,
								NULL,
								&ymiss,
								&status,
								&out_of_range);
								_NhlWorkstationMarker(
									xlayer->base.wkptr,
									&xtmp,
									&ytmp,
									1
								);
							}
							upordownflag = 0;
						}
					}
				}
				else{
					for(tint=0;tint < npts;tint++){
						if(marker_mode != 
							NhlMARKERSONLY){
							_NhlDataLineTo(
								xlayer->xyplot.thetrans,
								(NhlLayer)xlayer,
								xvect[tint],
								yvect[tint],
								upordownflag);
						}
						if(marker_mode != 
							NhlNOMARKERS){

							XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&(xvect[tint]),
								&(yvect[tint]),
								1,
								&xtmp,
								&ytmp,
								NULL,
								NULL,
								&status,
								&out_of_range);
							_NhlWorkstationMarker(
								xlayer->base.wkptr,
								&xtmp,
								&ytmp,
								1
							);
						}
						upordownflag = 0;
					}
				}
			}
			else if(curve_impx && curve_impy){
				/* both vectors implied */
				for(tint=0;tint < npts;tint++){
					if(marker_mode != NhlMARKERSONLY){
						_NhlDataLineTo(xlayer->xyplot.thetrans,
							(NhlLayer)xlayer,
							(float)(tint+1),
							(float)(tint+1),
							upordownflag);
					}

					if(marker_mode != NhlNOMARKERS){
						xtmp = (float)(tint+1);
						ytmp = (float)(tint+1);
						XyPlotDataToNDC(
							(NhlLayer)xlayer,
							&xtmp,
							&ytmp,
							1,
							&xtmp,
							&ytmp,
							NULL,
							NULL,
							&status,
							&out_of_range);
						_NhlWorkstationMarker(
							xlayer->base.wkptr,
								&xtmp,
								&ytmp,
								1
							);
					}
					upordownflag = 0;
				}
			}
			else if(curve_impx){
				if(datal->flt.missing_y_set){
					float	ymiss=datal->flt.missing_y;
					for(tint=0;tint < npts;tint++){
						if(yvect[tint] == ymiss)
							upordownflag = 1;
						else{
							if(marker_mode != NhlMARKERSONLY){
								_NhlDataLineTo(
								xlayer->xyplot.thetrans,
									(NhlLayer)xlayer,
									(float)(tint+1),
									yvect[tint],
									upordownflag);
							}
							if(marker_mode != NhlNOMARKERS){
								xtmp = (float)(tint+1);
								XyPlotDataToNDC(
									(NhlLayer)xlayer,
									&xtmp,
									&(yvect[tint]),
									1,
									&xtmp,
									&ytmp,
									NULL,
									&ymiss,
									&status,
									&out_of_range);
								_NhlWorkstationMarker(
								xlayer->base.wkptr,
									&xtmp,
									&ytmp,
									1
								);
							}
							

							upordownflag = 0;
						}
					}
				}
				else{
					for(tint=0;tint < npts;tint++){
						if(marker_mode != NhlMARKERSONLY) {
						_NhlDataLineTo(
							xlayer->xyplot.thetrans,
							(NhlLayer)xlayer,
							(float)(tint+1),
							yvect[tint],
							upordownflag);
						}
						if(marker_mode != NhlNOMARKERS){
							xtmp = (float)(tint+1);
							XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&xtmp,
								&(yvect[tint]),
								1,
								&xtmp,
								&ytmp,
								NULL,
								NULL,
								&status,
								&out_of_range);
							_NhlWorkstationMarker(
								xlayer->base.wkptr,
								&xtmp,
								&ytmp,
								1
							);
						}

						upordownflag = 0;
					}
				}
			}
			else if(curve_impy){
				if(datal->flt.missing_x_set){
					float	xmiss=datal->flt.missing_x;
					for(tint=0;tint < npts;tint++){
						if(xvect[tint] == xmiss)
							upordownflag = 1;
						else{
							if(marker_mode != NhlMARKERSONLY) {
								_NhlDataLineTo(
								xlayer->xyplot.thetrans,
									(NhlLayer)xlayer,
									xvect[tint],
									(float)(tint+1),
									upordownflag);
							}
							if(marker_mode != NhlNOMARKERS){
								ytmp = (float)(tint+1);
								XyPlotDataToNDC(
									(NhlLayer)xlayer,
									&(xvect[tint]),
									&ytmp,
									1,
									&xtmp,
									&ytmp,
									&xmiss,
									NULL,
									&status,
									&out_of_range);
								_NhlWorkstationMarker(
									xlayer->base.wkptr,
									&xtmp,
									&ytmp,
									1
								);
							}

							upordownflag = 0;
						}
					}
				}
				else{
					for(tint=0;tint < npts;tint++){
						if(marker_mode != NhlMARKERSONLY) {
							_NhlDataLineTo(
								xlayer->xyplot.thetrans,
								(NhlLayer)xlayer,
								xvect[tint],
								(float)(tint+1),
								upordownflag);
						}
						if(marker_mode != NhlNOMARKERS){
							ytmp = (float)(tint+1);
							XyPlotDataToNDC(
								(NhlLayer)xlayer,
								&(xvect[tint]),
								&ytmp,
								1,
								&xtmp,
								&ytmp,
								NULL,
								NULL,
								&status,
								&out_of_range);
							_NhlWorkstationMarker(
								xlayer->base.wkptr,
								&xtmp,
								&ytmp,
								1
							);
						}

						upordownflag = 0;
					}
				}
			}
		}
		/*
		 * This is called here so lastd is called for the last line.
		 */
		_NhlWorkstationLineTo(xlayer->base.wkptr,1.0,1.0,1);
	}


	ret = _NhlDeactivateWorkstation(xlayer->base.wkptr);	
	if(ret < ret1)
		ret1 = ret;
	return(ret);
	
}

/*
 * Function:	XyPlotDraw
 *
 * Description:	Draw method for the XyPlot object. This function calls 
 *		NhlDraw for the TickMarks and the Titles and then calls 
 *		DrawCurves to set up and call AUTOGRAPH. 
 *
 * In Args:	layer	XyPlot instance
 *
 * Out Args:	NhlNONE
 *
 * Return Values: Error Conditions
 *
 * Side Effects: NhlNONE
 */	

static NhlErrorTypes XyPlotDraw
#if	NhlNeedProto
(NhlLayer layer)
#else
(layer)
        NhlLayer layer;
#endif
{
	NhlXyPlotLayer	xlayer = (NhlXyPlotLayer) layer;
	NhlErrorTypes ret1 = NhlNOERROR;
	NhlErrorTypes ret = NhlNOERROR;

/*
* Should probably have resource for letting user draw curves on
* top of or below Ticks
*/

	if((!xlayer->xyplot.data_ranges_set) ||
					(xlayer->xyplot.thetrans == NULL)){
		NhlPError(NhlFATAL,NhlEUNKNOWN,
				"XyPlotDraw:Data Must be set before Drawing");
		return NhlFATAL;
	}

	ret = DrawCurves(xlayer);
	if(ret < NhlWARNING)
		return ret;
	ret1 = MIN(ret,ret1);

	if(xlayer->xyplot.titles && xlayer->xyplot.ttitles){
		ret = NhlDraw(xlayer->xyplot.ttitles->base.id);
		if(ret < NhlWARNING)
			return ret;
		ret1 = MIN(ret,ret1);
	}

	if(xlayer->xyplot.ticks){
		ret = NhlDraw(xlayer->xyplot.ticks->base.id);
		ret1 = MIN(ret,ret1);
	}

	return ret1;
}


/*
 * Function:	XyPlotDataToNDC
 *
 * Description: This is the Data to NDC method of the transform class. It
 *		maps data to normalized device coordinates using the XyPlot
 *		object's TransObj which is referenced through 
 *		xplot->xyplot.thetrans . The tranformation is set using 
 *		_NhlSetTrans and then mapped using the TranObjs method entry
 *		points _NhlDataToWin and then _NhlWinToNDC. This is the 
 *		standard way in which plot objects will present their 
 *		data transformation funtions to the user. Having these
 *		functions call the TransObj instead of haveing the user call
 *		it directly is to facilitate the eventual support of overlays
 * 		These will require the plot object to intercede in the 
 *		data tranformation progress.
 *
 * In Args:	plot	instance record
 *		x	array of x axis values in data coordinates
 * 		y	array of y axis values in data coordinates
 *		n	number of elements
 *		xout	storage provided for output x ndc vals
 *		yout	storage provided for output y ndc vals
 *		xmissing	holds value of missing value in x if NULL
 *				no missing value
 *		ymissing	holds value of missing value in y if NULL
 *				no missing value
 *
 * Out Args:	xout	does not allocate storage
 *		yout	does not allocate storage
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:	NhlNONE
 */
static NhlErrorTypes XyPlotDataToNDC
#if	NhlNeedProto
(NhlLayer plot,float* x,float* y,int n,float* xout,float* yout,float* xmissing,float* ymissing,int* status,float* out_of_range)
#else
(plot,x,y,n,xout,yout,xmissing,ymissing, status, out_of_range)
	NhlLayer		plot;
	float*		x;
	float*		y;
	int		n;
	float*		xout;
	float*		yout;
	float*		xmissing;
	float*		ymissing;
	int*		status;
	float*		out_of_range;
#endif
{
	NhlXyPlotLayer xplot = (NhlXyPlotLayer)plot;
	NhlErrorTypes ret = NhlNOERROR;
	NhlErrorTypes ret1 = NhlNOERROR;
	int mystatus =0;

	 ret = _NhlSetTrans(xplot->xyplot.thetrans,plot);
	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotDataToNDC: A NhlFATAL error occured while setting the tranformation of XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if( ret < ret1 )
		ret1 = ret; 

	NhlVAGetValues(xplot->xyplot.thetrans->base.id,
		NhlNtrOutOfRangeF,out_of_range,NULL);
	

	ret = _NhlDataToWin(xplot->xyplot.thetrans,plot,x,y,n,xout,yout,
		&mystatus,xmissing,ymissing);
	if(ret < NhlWARNING){
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotNDCToData: A NhlFATAL error occured while transforming input to window, XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if( ret < ret1)
		ret1 = ret;
	if(mystatus)
		*status = 1;
/*
* out of range is now missing value since by definition all missing values are
* replace with the out_of_range value
*/
	ret = _NhlWinToNDC(xplot->xyplot.thetrans,plot,xout,yout,n,xout,yout,
		&mystatus,out_of_range,out_of_range);

	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotNDCToData: A NhlFATAL error occured while transforming from window to NDC, XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if( ret < ret1)
		ret1 = ret;

	if(mystatus)
		*status = 1;

	return(ret1);

}
/*
 * Function:	XyPlotNDCToData
 *
 * Description:	Transform objects NDC to Data method for the XyPlot. 
 *		Takes one or more x,y pairs of NDC points and converts them
 *		into their respective data values.
 *
 * In Args:	plot 	instance record pointer
 *		x	array of x ndc vals to convert
 *		y	array of y ndc vals to convert
 *		n	number of elements in x,y,xout and yout
 *	 	xout	storage provided by user for conversion output
 *		yout	storage provided by user for conversion output
 *		xmissing  missing values in x input
 *		ymissing  missing values in y input
 *
 * Out Args:	xout	but does not allocate storage
 *		yout	but does not allocate storage
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:	 NhlNONE
 */
static NhlErrorTypes XyPlotNDCToData
#if	NhlNeedProto
(NhlLayer plot,float* x,float* y,int n,float* xout,float* yout,float *xmissing,float *ymissing,int* status, float* out_of_range)
#else
(plot,x,y,n,xout,yout,xmissing,ymissing,status,out_of_range)
	NhlLayer		plot;
	float*		x;
	float*		y;
	int		n;
	float*		xout;
	float*		yout;
	float*		xmissing;
	float*		ymissing;
	int*		status;
	float*		out_of_range;
#endif
{
	NhlXyPlotLayer xplot = (NhlXyPlotLayer)plot;
	int mystatus = 0;
	NhlErrorTypes ret = NhlNOERROR;
	NhlErrorTypes ret1 = NhlNOERROR;

	ret = _NhlSetTrans(xplot->xyplot.thetrans,plot);
	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotNDCToData: A NhlFATAL error occured while setting the tranformation of XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if(ret < ret1)
		ret1 = ret;


	NhlVAGetValues(xplot->xyplot.thetrans->base.id,
		NhlNtrOutOfRangeF,out_of_range,NULL);

	ret = _NhlNDCToWin(xplot->xyplot.thetrans,plot,x,y,n,xout,yout,
		&mystatus,xmissing,ymissing);
	if(ret < NhlWARNING){
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotNDCToData: A NhlFATAL error occured while transforming input to window, XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if(ret < ret1)
		ret1 = ret;


	if(mystatus)	
		*status = 1; 


	mystatus = 0;
	ret = _NhlWinToData(xplot->xyplot.thetrans,plot,xout,yout,n,xout,yout,
		&mystatus,out_of_range,out_of_range);
	if(ret < NhlWARNING) {
		NhlPError(NhlFATAL,NhlEUNKNOWN,"XyPlotNDCToData: A NhlFATAL error occured while transforming from window to data, XyPlot object: %s , cannot continue",plot->base.name);
		return(ret);
	} else if(ret < ret1)
		ret1 = ret;

	if(mystatus)	
		*status = 1; 

	return(ret1);

}


/*
 * Function:	XyPlotDestroy
 *
 * Description:	Calls NhlDestroy for the TickMarks, Titles and the TransObj
 *		Calls NhlFree for the fields:
 *		*_values
 *		*_final_values
 *		curve_line_labels
 *		curve_colors
 *		curve_lengths
 *		curve_dashes
 *		*_irregular_points
 *		dummy_array
 *		*_alternate_coords
 *		*_original_coords
 *
 * In Args:	inst		instance record pointer
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	ErrorConditions
 *
 * Side Effects:	NhlNONE
 */
static NhlErrorTypes XyPlotDestroy
#if	NhlNeedProto
(NhlLayer inst)
#else
(inst)
NhlLayer inst;
#endif
{
	NhlXyPlotLayer xinst = (NhlXyPlotLayer)inst;
	NhlErrorTypes ret = NhlNOERROR;
	NhlErrorTypes ret1 = NhlNOERROR;


	if(xinst->xyplot.ticks != NULL)
		ret = _NhlDestroyChild(xinst->xyplot.ticks->base.id,inst);

	if(xinst->xyplot.ttitles != NULL)
		ret1 = _NhlDestroyChild(xinst->xyplot.ttitles->base.id,inst);
	ret = MIN(ret,ret1);

	if(xinst->xyplot.thetrans != NULL)
		ret1 = NhlDestroy(xinst->xyplot.thetrans->base.id);
	ret = MIN(ret,ret1);

	NhlFreeGenArray(xinst->xyplot.x_irregular_points);
	NhlFreeGenArray(xinst->xyplot.y_irregular_points);

	NhlFreeGenArray(xinst->xyplot.x_original_coords);
	NhlFreeGenArray(xinst->xyplot.x_alternate_coords);
	NhlFreeGenArray(xinst->xyplot.y_alternate_coords);
	NhlFreeGenArray(xinst->xyplot.y_original_coords);
	
	return(ret1);
}

/*
 * Function:	XyPlotGetBB
 *
 * Description: Calls NhlGetBB on the TickMark object and the Title object
 *
 * In Args:	instance 	object instance record
 *		thebox		data structure, provided by the user to
 *				hold boudning box information.
 *
 * Out Args:	NhlNONE
 *
 * Return Values:  Error Conditions
 *
 * Side Effects:   NhlNONE.
 */
static NhlErrorTypes XyPlotGetBB
#if	NhlNeedProto
(NhlLayer instance, NhlBoundingBox* thebox)
#else
(instance,thebox)
	NhlLayer instance;
	NhlBoundingBox *thebox;
#endif
{
	NhlXyPlotLayer xinst = (NhlXyPlotLayer)instance;
	NhlErrorTypes ret = NhlNOERROR;

	if(xinst->xyplot.ticks != NULL) {
		ret = _NhlGetBB(xinst->xyplot.ticks,thebox);
		if(ret < NhlWARNING) 
			return(ret);
	}
	
	if(xinst->xyplot.ttitles != NULL) {
		return(MIN(ret,_NhlGetBB(xinst->xyplot.ttitles,thebox)));
	} else {
		return(ret);
	}
}

/*
 * Function:	XyPlotUpdateData
 *
 * Description:	This function is called whenever the data pointed to by the
 *		data resources change.  This function needs to check if
 *		this specific data resource changed - it may have been another
 *		data resource in a sub/super class.
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
static NhlErrorTypes
XyPlotUpdateData
#if	NhlNeedProto
(
	NhlDataCommLayer	new,
	NhlDataCommLayer	old
)
#else
(new,old)
	NhlDataCommLayer	new;
	NhlDataCommLayer	old;
#endif
{
	NhlXyPlotLayer		xl = (NhlXyPlotLayer)new;
	NhlXyPlotLayer		xlold = (NhlXyPlotLayer)old;
	NhlErrorTypes		ret1=NhlNOERROR,ret2=NhlNOERROR;

	ret2 = ComputeDataExtents(xl,xlold,DATACHANGE);
	if(ret2 < NhlWARNING)
		return ret2;
	ret1 = MIN(ret1,ret2);

	if(xl->xyplot.data_ranges_set){
		ret2 = SetUpTransObjs(xl,xlold,DATACHANGE);
		if(ret2 < NhlWARNING)
			return(ret2);
		ret1 = MIN(ret1,ret2);
	}

	ret2 = SetUpTicks(xl,xlold,DATACHANGE);
	if(ret2 < NhlWARNING)
		return(ret2);
	ret1 = MIN(ret1,ret2);

	ret2 = SetUpTitles(xl,xlold,DATACHANGE);
	if(ret2 < NhlWARNING)
		return(ret2);
	ret1 = MIN(ret1,ret2);

	return ret1;
}

/*
 * Function:	CheckExtent
 *
 * Description:	This function is used by CheckValues to check the extent
 *		resources.
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
static NhlErrorTypes
CheckExtent
#if	NhlNeedProto
(
	NhlBoolean	extent_change,
	NhlBoolean	compute_change,
	NhlBoolean	*compute_value,
	NhlString	comp_res,
	NhlString	extent_res,
	NhlString	error_lead
)
#else
(extent_change,compute_change,compute_value,comp_res,extent_res,error_lead)
	NhlBoolean	extent_change;
	NhlBoolean	compute_change;
	NhlBoolean	*compute_value;
	NhlString	comp_res;
	NhlString	extent_res;
	NhlString	error_lead;
#endif
{
	NhlErrorTypes	ret = NhlNOERROR;

	if(extent_change && *compute_value){
		*compute_value = False;

		if(compute_change){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:Setting %s to False because %s was specified",
						error_lead,comp_res,extent_res);
			ret = NhlWARNING;
		}
	}

	return ret;
}


/*
 * Function:	CheckValues
 *
 * Description:	This function makes sure the following resources agree.
 *			style
 *			alt_coords
 *			compute_extents
 *
 * In Args:
 *		NhlXyPlotLayer	xnew,
 *		NhlXyPlotLayer	xold,
 *		_NhlCallType	calledfrom
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:
 */
static NhlErrorTypes
CheckValues
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	char*		error_lead;
	NhlErrorTypes	ret = NhlNOERROR, lret = NhlNOERROR;

	if(calledfrom == CREATE)
		error_lead = "XyPlotInitialize";
	else
		error_lead = "XyPlotSetValues";

	/*
	 * take care of style resources
	 */
	if((xnew->xyplot.x_style == NhlIRREGULAR) &&
				(xnew->xyplot.x_irregular_points == NULL)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s: cannot be NhlIRREGULAR unless %s is set:setting %s to NhlLINEAR",
			NhlNxyXStyle,NhlNxyXIrregularPoints,NhlNxyXStyle);

		xnew->xyplot.x_style = NhlLINEAR;
		ret = MIN(ret,NhlWARNING);
	}
	if((xnew->xyplot.y_style == NhlIRREGULAR) &&
				(xnew->xyplot.y_irregular_points == NULL)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s: cannot be NhlIRREGULAR unless %s is set:setting %s to NhlLINEAR",
			NhlNxyYStyle,NhlNxyYIrregularPoints,NhlNxyYStyle);

		xnew->xyplot.y_style = NhlLINEAR;
		ret = MIN(ret,NhlWARNING);
	}

	/*
	 * Alternate Coord's are not yet implimented - so make sure x_alternate
	 * and y_alternate are set to NhlNONE.
	 * (Eventually this part should check and make sure the coord arrays
	 * exist if x_alternate and y_alternate are not = to NhlNONE)
	 */
	if(xnew->xyplot.x_alternate != NhlNONE){
		xnew->xyplot.x_alternate = NhlNONE;
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s only supports a value of NhlNONE at this time",
						error_lead,NhlNxyXAlternate);
		ret = MIN(ret,NhlWARNING);
	}
	if(xnew->xyplot.y_alternate != NhlNONE){
		xnew->xyplot.y_alternate = NhlNONE;
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s only supports a value of NhlNONE at this time",
						error_lead,NhlNxyYAlternate);
		ret = MIN(ret,NhlWARNING);
	}

	/*
	 * Check Extents - left right top bottom
	 */

	if(calledfrom == CREATE){
		lret = CheckExtent(xnew->xyplot.x_min_set,
			xnew->xyplot.comp_x_min_set,&xnew->xyplot.compute_x_min,
			NhlNxyComputeXMin,NhlNxyXMinF,error_lead);
		ret = MIN(lret,ret);

		lret = CheckExtent(xnew->xyplot.x_max_set,
			xnew->xyplot.comp_x_max_set,&xnew->xyplot.compute_x_max,
			NhlNxyComputeXMax,NhlNxyXMaxF,error_lead);
		ret = MIN(lret,ret);

		lret = CheckExtent(xnew->xyplot.y_max_set,
			xnew->xyplot.comp_y_max_set,&xnew->xyplot.compute_y_max,
			NhlNxyComputeYMax,NhlNxyYMaxF,error_lead);
		ret = MIN(lret,ret);

		lret = CheckExtent(xnew->xyplot.y_min_set,
			xnew->xyplot.comp_y_min_set,&xnew->xyplot.compute_y_min,
			NhlNxyComputeYMin,NhlNxyYMinF,error_lead);
		ret = MIN(lret,ret);
	}
	else{
		lret = CheckExtent((xold->xyplot.x_min!=xnew->xyplot.x_min),
			xnew->xyplot.compute_x_min,&xnew->xyplot.compute_x_min,
			NhlNxyComputeXMin,NhlNxyXMinF,error_lead);
		ret = MIN(lret,ret);

		lret = CheckExtent((xold->xyplot.x_max!=xnew->xyplot.x_max),
			xnew->xyplot.compute_x_max,&xnew->xyplot.compute_x_max,
			NhlNxyComputeXMax,NhlNxyXMaxF,error_lead);
		ret = MIN(lret,ret);

		lret = CheckExtent((xold->xyplot.y_max!=xnew->xyplot.y_max),
			xnew->xyplot.compute_y_max,&xnew->xyplot.compute_y_max,
			NhlNxyComputeYMax,NhlNxyYMaxF,error_lead);
		ret = MIN(lret,ret);

		lret=CheckExtent((xold->xyplot.y_min!=xnew->xyplot.y_min),
			xnew->xyplot.compute_y_min,&xnew->xyplot.compute_y_min,
			NhlNxyComputeYMin,NhlNxyYMinF,error_lead);
		ret = MIN(lret,ret);

	}

	if(!xnew->xyplot.compute_x_min && xnew->xyplot.x_min_set &&
		(xnew->xyplot.x_style == NhlLOG) && (xnew->xyplot.x_min <= 0)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s is NhlLOG:%s can't be <= 0.0:Setting %s to True",
			error_lead,NhlNxyXStyle,NhlNxyXMinF,NhlNxyComputeXMin);

		xnew->xyplot.compute_x_min = True;
		ret = MIN(ret,NhlWARNING);
	}

	if(!xnew->xyplot.compute_x_max && xnew->xyplot.x_max_set &&
		(xnew->xyplot.x_style == NhlLOG) && (xnew->xyplot.x_max <= 0)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s is NhlLOG:%s can't be <= 0.0:Setting %s to True",
			error_lead,NhlNxyXStyle,NhlNxyXMaxF,NhlNxyComputeXMax);

		xnew->xyplot.compute_x_max = True;
		ret = MIN(ret,NhlWARNING);
	}

	if(!xnew->xyplot.compute_x_min && xnew->xyplot.x_min_set &&
		!xnew->xyplot.compute_x_max && xnew->xyplot.x_max_set &&
		(xnew->xyplot.x_max < xnew->xyplot.x_min)){

		float tfloat;
		NhlPError(NhlWARNING,NhlEUNKNOWN,"%s:%s is < %s: Swapping",
					error_lead,NhlNxyXMaxF,NhlNxyXMinF);
		tfloat = xnew->xyplot.x_max;
		xnew->xyplot.x_max = xnew->xyplot.x_min;
		xnew->xyplot.x_min = tfloat;
	}

	if(!xnew->xyplot.compute_y_min && xnew->xyplot.y_min_set &&
		(xnew->xyplot.y_style == NhlLOG) && (xnew->xyplot.y_min <= 0)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s is NhlLOG:%s can't be <= 0.0:Setting %s to True",
			error_lead,NhlNxyYStyle,NhlNxyYMinF,NhlNxyComputeYMin);

		xnew->xyplot.compute_y_min = True;
		ret = MIN(ret,NhlWARNING);
	}

	if(!xnew->xyplot.compute_y_max && xnew->xyplot.y_max_set &&
		(xnew->xyplot.y_style == NhlLOG) && (xnew->xyplot.y_max <= 0)){
		NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s is NhlLOG:%s can't be <= 0.0:Setting %s to True",
			error_lead,NhlNxyYStyle,NhlNxyYMaxF,NhlNxyComputeYMax);

		xnew->xyplot.compute_y_max = True;
		ret = MIN(ret,NhlWARNING);
	}

	if(!xnew->xyplot.compute_y_min && xnew->xyplot.y_min_set &&
		!xnew->xyplot.compute_y_max && xnew->xyplot.y_max_set &&
		(xnew->xyplot.y_max < xnew->xyplot.y_min)){

		float tfloat;
		NhlPError(NhlWARNING,NhlEUNKNOWN,"%s:%s is < %s: Swapping",
					error_lead,NhlNxyYMaxF,NhlNxyYMinF);
		tfloat = xnew->xyplot.y_max;
		xnew->xyplot.y_max = xnew->xyplot.y_min;
		xnew->xyplot.y_min = tfloat;
	}

	if((calledfrom == SET) &&
		((xold->xyplot.x_style != xnew->xyplot.x_style) ||
		(xold->xyplot.y_style != xnew->xyplot.y_style))){

		xnew->xyplot.check_ranges = True;
	}

	return ret;
}

/*
 * Function:	InternalizePointers
 *
 * Description:	This function checks the irregular_points resources and the
 *		style resources to make sure they agree.
 *		This function allocates memory for the alternate_coords stuff.
 *		This function allocates memory for the title strings.
 *
 * In Args:
 *		NhlXyPlotLayer	xnew,
 *		NhlXyPlotLayer	xold,
 *		_NhlCallType	calledfrom
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:
 */
static NhlErrorTypes
InternalizePointers
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	char		*error_lead;
	NhlGenArray	gen;
	NhlBoolean	skip_x_irreg_pts = False, skip_y_irreg_pts = False;
	NhlBoolean	free_x_irreg = False, free_y_irreg = False;
	NhlBoolean	skip_x_alt_coord = False, skip_y_alt_coord = False;
	NhlBoolean	free_x_alt_coord = False, free_y_alt_coord = False;
	NhlBoolean	skip_x_orig_coord = False, skip_y_orig_coord = False;
	NhlBoolean	free_x_orig_coord = False, free_y_orig_coord = False;
	NhlErrorTypes	ret = NhlNOERROR;

	if(calledfrom == SET) {
		error_lead = "XyPlotSetValues";
	} else {
		error_lead = "XyPlotInitialize";
	}

	/*
	 * take care of irregular_points
	 */
	if(calledfrom == SET){
		if(xold->xyplot.x_irregular_points !=
						xnew->xyplot.x_irregular_points)
			free_x_irreg = True;
		else
			skip_x_irreg_pts = True;
		if(xold->xyplot.y_irregular_points !=
						xnew->xyplot.y_irregular_points)
			free_y_irreg = True;
		else
			skip_y_irreg_pts = True;
	}

	if((xnew->xyplot.x_irregular_points != NULL) && !skip_x_irreg_pts) {
		gen = (NhlGenArray)xnew->xyplot.x_irregular_points;
		if((gen->typeQ != Qfloat) || (gen->size != sizeof(float)) ||
		(gen->num_dimensions != 1) || (gen->len_dimensions[0] < 3)){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:%s must be a 1 dim float array with a min of 3 elements: resetting",
					error_lead,NhlNxyXIrregularPoints);

			if(calledfrom == SET)
				xnew->xyplot.x_irregular_points =
						xold->xyplot.x_irregular_points;
			else
				xnew->xyplot.x_irregular_points = NULL;

			free_x_irreg = False;
			ret = MIN(ret,NhlWARNING);
		}
		else{
			float	*tarr;

			xnew->xyplot.x_irregular_points =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.x_irregular_points == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
			tarr = (float*)gen->data;
			xnew->xyplot.x_irreg_min =
				MIN(tarr[0],tarr[gen->len_dimensions[0]-1]);
			xnew->xyplot.x_irreg_max =
				MAX(tarr[0],tarr[gen->len_dimensions[0]-1]);
			xnew->xyplot.check_ranges = True;
		}
	}
	if(free_x_irreg)
		NhlFreeGenArray(xold->xyplot.x_irregular_points);

	if((xnew->xyplot.y_irregular_points != NULL) && !skip_y_irreg_pts){
		gen = (NhlGenArray)xnew->xyplot.y_irregular_points;
		if((gen->typeQ != Qfloat) || (gen->size != sizeof(float)) ||
		(gen->num_dimensions != 1) || (gen->len_dimensions[0] < 3)){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:%s must be a 1 dim float array with a min of 3 elements: ignoring",
					error_lead,NhlNxyYIrregularPoints);

			if(calledfrom == SET)
				xnew->xyplot.y_irregular_points =
						xold->xyplot.y_irregular_points;
			else
				xnew->xyplot.y_irregular_points = NULL;

			free_y_irreg = False;
			ret = MIN(ret,NhlWARNING);
		}
		else{
			float	*tarr;

			xnew->xyplot.y_irregular_points =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.y_irregular_points == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
			tarr = (float*)gen->data;
			xnew->xyplot.y_irreg_min =
				MIN(tarr[0],tarr[gen->len_dimensions[0]-1]);
			xnew->xyplot.y_irreg_max =
				MAX(tarr[0],tarr[gen->len_dimensions[0]-1]);
			xnew->xyplot.check_ranges = True;
		}
	}
	if(free_y_irreg)
		NhlFreeGenArray(xold->xyplot.y_irregular_points);

	/*
	 * take care of alt coords and orig coords
	 */
	if(calledfrom == SET){
		if(xold->xyplot.x_alternate_coords !=
						xnew->xyplot.x_alternate_coords)
			free_x_alt_coord = True;
		else
			skip_x_alt_coord = True;

		if(xold->xyplot.y_alternate_coords !=
						xnew->xyplot.y_alternate_coords)
			free_y_alt_coord = True;
		else
			skip_y_alt_coord = True;

		if(xold->xyplot.x_original_coords !=
						xnew->xyplot.x_original_coords)
			free_x_orig_coord = True;
		else
			skip_x_orig_coord = True;

		if(xold->xyplot.y_original_coords !=
						xnew->xyplot.y_original_coords)
			free_y_orig_coord = True;
		else
			skip_y_orig_coord = True;
	}

	if((xnew->xyplot.x_alternate_coords != NULL) && !skip_x_alt_coord){
		gen = (NhlGenArray)xnew->xyplot.x_alternate_coords;
		if((gen->typeQ != Qfloat) || (gen->size != sizeof(float)) ||
						(gen->num_dimensions != 1)){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s must be set with a 1-dim float array: ignoring",
					error_lead,NhlNxyXAlternateCoords);

			if(calledfrom == SET)
				xnew->xyplot.x_alternate_coords =
						xold->xyplot.x_alternate_coords;
			else
				xnew->xyplot.x_alternate_coords = NULL;
			free_x_alt_coord = False;

			ret = MIN(ret,NhlWARNING);
		}
		else{
			xnew->xyplot.x_alternate_coords =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.x_alternate_coords == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
		}
	}
	if(free_x_alt_coord)
		NhlFreeGenArray(xold->xyplot.x_alternate_coords);

	if((xnew->xyplot.y_alternate_coords != NULL) && !skip_y_alt_coord){
		gen = (NhlGenArray)xnew->xyplot.y_alternate_coords;
		if((gen->typeQ == Qfloat) && (gen->size == sizeof(float)) &&
						(gen->num_dimensions == 1)){
			xnew->xyplot.y_alternate_coords =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.y_alternate_coords == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
			"%s:%s must be set with a 1-dim float array: ignoring",
					error_lead,NhlNxyYAlternateCoords);

			if(calledfrom == SET)
				xnew->xyplot.y_alternate_coords =
						xold->xyplot.y_alternate_coords;
			else
				xnew->xyplot.y_alternate_coords = NULL;
			free_y_alt_coord = False;

			ret = MIN(ret,NhlWARNING);
		}
	}
	if(free_y_alt_coord)
		NhlFreeGenArray(xold->xyplot.y_alternate_coords);

	if((xnew->xyplot.x_original_coords != NULL) && !skip_x_orig_coord){
		gen = (NhlGenArray)xnew->xyplot.x_original_coords;
		if((gen->typeQ == Qfloat) && (gen->size == sizeof(float)) &&
						(gen->num_dimensions == 1)){
			xnew->xyplot.x_original_coords =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.x_original_coords == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a generic 1-dim float array: ignoring",
					error_lead,NhlNxyXOriginalCoords);

			if(calledfrom == SET)
				xnew->xyplot.x_original_coords =
						xold->xyplot.x_original_coords;
			else
				xnew->xyplot.x_original_coords = NULL;
			free_x_orig_coord = False;

			ret = MIN(ret,NhlWARNING);
		}
	}
	if(free_x_orig_coord)
		NhlFreeGenArray(xold->xyplot.x_original_coords);

	if((xnew->xyplot.y_original_coords != NULL) && !skip_y_orig_coord){
		gen = (NhlGenArray)xnew->xyplot.y_original_coords;
		if((gen->typeQ == Qfloat) && (gen->size == sizeof(float)) &&
						(gen->num_dimensions == 1)){
			xnew->xyplot.y_original_coords =
						_NhlCopyGenArray(gen,True);
			if(xnew->xyplot.y_original_coords == NULL){
				NhlPError(NhlFATAL,ENOMEM,NULL);
				return NhlFATAL;
			}
		}
		else{
			NhlPError(NhlWARNING,NhlEUNKNOWN,
		"%s:%s must be set with a generic float array: ignoring",
					error_lead,NhlNxyYOriginalCoords);

			if(calledfrom == SET)
				xnew->xyplot.y_original_coords =
						xold->xyplot.y_original_coords;
			else
				xnew->xyplot.y_original_coords = NULL;
			free_y_orig_coord = False;

			ret = MIN(ret,NhlWARNING);
		}
	}
	if(free_y_orig_coord)
		NhlFreeGenArray(xold->xyplot.y_original_coords);

	return ret;
}

/*
 * Function:	ComputeDataExtents
 *
 * Description:	
 *
 * In Args:
 *
 * Out Args:
 *
 * Return Values:
 *
 * Side Effects:
 */
static NhlErrorTypes
ComputeDataExtents
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else 
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	_NhlDataNodePtr		*datalist = NULL;
	int			num_data,i;
	NhlBoolean		new;
	NhlCoordArrTableFloatLayer	datal = NULL;
	char			*error_lead;
	NhlErrorTypes		ret = NhlNOERROR;

	if(calledfrom == CREATE){
		error_lead = "XyPlotInitialize";
		if(xnew->xyplot.curve_data == NULL){
			xnew->xyplot.data_ranges_set = False;
			return NhlNOERROR;
		}
	}
	else if(calledfrom == SET){
		error_lead = "XyPlotSetValues";
	}
	else if(calledfrom == DATACHANGE){
		error_lead = "XyPlotUpdateData";
	}
	else{
		NhlPError(NhlFATAL,NhlEUNKNOWN,"BadCall");
		return NhlFATAL;
	}

	if((calledfrom == CREATE) || (calledfrom == DATACHANGE) ||
			(xnew->xyplot.curve_data != xold->xyplot.curve_data)){

		xnew->xyplot.data_ranges_set = True;
		xnew->xyplot.check_ranges = True;

		num_data = _NhlGetDataInfo(xnew->xyplot.curve_data,&datalist);
		if(num_data <= 0){
			xnew->xyplot.data_ranges_set = False;
			return NhlNOERROR;
		}

		/*
		 * Data Conversion Happens Here if anywhere.
		 */
		datal=(NhlCoordArrTableFloatLayer)_NhlGetDataSet(datalist[0],&new);
		if(datal == NULL){
			xnew->xyplot.data_ranges_set = False;
			NhlPError(NhlFATAL,NhlEUNKNOWN,"Data Problem???");
			return NhlFATAL;
		}

		xnew->xyplot.x_data_min = datal->flt.min_x;
		xnew->xyplot.x_data_max = datal->flt.max_x;
		xnew->xyplot.y_data_min = datal->flt.min_y;
		xnew->xyplot.y_data_max = datal->flt.max_y;


		for(i=1;i < num_data;i++){
			datal=(NhlCoordArrTableFloatLayer)
					_NhlGetDataSet(datalist[i],&new);
			if(datal == NULL){
				xnew->xyplot.data_ranges_set = False;
				NhlPError(NhlFATAL,NhlEUNKNOWN,"Data Problem???");
				return NhlFATAL;
			}
			xnew->xyplot.x_data_min =
			MIN(xnew->xyplot.x_data_min,datal->flt.min_x);
			xnew->xyplot.x_data_max =
			MAX(xnew->xyplot.x_data_max,datal->flt.max_x);
			xnew->xyplot.y_data_min =
			MIN(xnew->xyplot.y_data_min,datal->flt.min_y);
			xnew->xyplot.y_data_max =
			MAX(xnew->xyplot.x_data_max,datal->flt.max_y);
		}
	}

	if(xnew->xyplot.check_ranges){

		/*
		 * Set Initial default for left,right,top,bottom
		 * (should only happen if user didn't set it themself, and it
		 * will only be used if the compute resources are False.)
		 *
		 * Also set if compute resources are true.
		 */
		if(!xnew->xyplot.x_min_set || xnew->xyplot.compute_x_min){
			xnew->xyplot.x_min = xnew->xyplot.x_data_min;
			xnew->xyplot.x_min_set = True;
		}
		if(!xnew->xyplot.x_max_set || xnew->xyplot.compute_x_max){
			xnew->xyplot.x_max = xnew->xyplot.x_data_max;
			xnew->xyplot.x_max_set = True;
		}
		if(!xnew->xyplot.y_min_set || xnew->xyplot.compute_y_min){
			xnew->xyplot.y_min = xnew->xyplot.y_data_min;
			xnew->xyplot.y_min_set = True;
		}
		if(!xnew->xyplot.y_max_set || xnew->xyplot.compute_y_max){
			xnew->xyplot.y_max = xnew->xyplot.y_data_max;
			xnew->xyplot.y_max_set = True;
		}

		/*
		 * Make sure data extents will work in a NhlLOG trans, if NhlLOG
		 * is specified.
		 */
		if((xnew->xyplot.x_data_min <= 0.0) &&
						(xnew->xyplot.x_style == NhlLOG)){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:The Minimuim X value is <= 0.0 NhlLOG invalid:Changing %s to NhlLINEAR",
						error_lead,NhlNxyXStyle);
			ret = MIN(ret,NhlWARNING);
			xnew->xyplot.x_style = NhlLINEAR;
		}
		if((xnew->xyplot.y_data_min <= 0.0) &&
						(xnew->xyplot.y_style == NhlLOG)){
			NhlPError(NhlWARNING,NhlEUNKNOWN,
	"%s:The Minimuim Y value is <= 0.0 NhlLOG invalid:Changing %s to NhlLINEAR",
						error_lead,NhlNxyYStyle);
			ret = MIN(ret,NhlWARNING);
			xnew->xyplot.y_style = NhlLINEAR;
		}

		/*
		 * Make sure data extents will work in an NhlIRREGULAR trans,
		 * if NhlIRREGULAR is specifed.
		 */
		if(xnew->xyplot.x_style == NhlIRREGULAR){
			if(xnew->xyplot.x_min < xnew->xyplot.x_irreg_min){

				if(!xnew->xyplot.compute_x_min){
					NhlPError(NhlWARNING,NhlEUNKNOWN,
				"%s:%s is not defined by %s: Setting to %f",
						error_lead,NhlNxyXMinF,
						NhlNxyXIrregularPoints,
						xnew->xyplot.x_irreg_min);
					ret = MIN(ret,NhlWARNING);
				}
				xnew->xyplot.x_min = xnew->xyplot.x_irreg_min;
			}
			if(xnew->xyplot.x_max > xnew->xyplot.x_irreg_max){

				if(!xnew->xyplot.compute_x_max){
					NhlPError(NhlWARNING,NhlEUNKNOWN,
				"%s:%s is not defined by %s: Setting to %f",
						error_lead,NhlNxyXMaxF,
						NhlNxyXIrregularPoints,
						xnew->xyplot.x_irreg_max);
					ret = MIN(ret,NhlWARNING);
				}
				xnew->xyplot.x_max = xnew->xyplot.x_irreg_max;
			}
		}
		if(xnew->xyplot.y_style == NhlIRREGULAR){
			if(xnew->xyplot.y_min < xnew->xyplot.y_irreg_min){

				if(!xnew->xyplot.compute_y_min){
					NhlPError(NhlWARNING,NhlEUNKNOWN,
				"%s:%s is not defined by %s: Setting to %f",
						error_lead,NhlNxyYMinF,
						NhlNxyYIrregularPoints,
						xnew->xyplot.y_irreg_min);
					ret = MIN(ret,NhlWARNING);
				}
				xnew->xyplot.y_min = xnew->xyplot.y_irreg_min;
			}
			if(xnew->xyplot.y_max > xnew->xyplot.y_irreg_max){

				if(!xnew->xyplot.compute_y_max){
					NhlPError(NhlWARNING,NhlEUNKNOWN,
				"%s:%s is not defined by %s: Setting to %f",
						error_lead,NhlNxyYMaxF,
						NhlNxyYIrregularPoints,
						xnew->xyplot.y_irreg_max);
					ret = MIN(ret,NhlWARNING);
				}
				xnew->xyplot.y_max = xnew->xyplot.y_irreg_max;
			}
		}

		xnew->xyplot.check_ranges = False;
	}

	return ret;
}


/*
 * Function:	SetUpTransObjs
 *
 * Description: Creates, Sets and Destroys the main tranformation object
 *		for the XyPlot. For log and linear plots the tranformation
 *		object is not destroyed when changes in rsources affecting
 *		the tranformation are changed (i.e. data extents). However,
 *		IrregularType2TransObjs have to be freed whenever the 
 *		data extent increases but not when it decreases.  The 
 *		LogLinTransObjs are only destroyed when the style is switched
 *		from log or linear to irregular.  This function uses two 
 *		switch statements to switch through the 25 possible combinations
 *		of (XStyle, YStyle). This is needed since one tranformation 
 *		object handles both x and y axis. The only real tricks here
 *		happen when either XStyle or YStyle is NhlIRREGULAR and the other
 *		is not. When this happens an IrregularTransObj is created 
 *		and one of the IrregularTranObj is "fooled" into a linear
 *		or log tranformation. This is facilitated for log axis by 
 *		a resource that instructs the IrragularTransObj to take
 *		the logs of the input values and create an approximation of
 *		the logs of the data values.
 *
 * In Args:	xnew	new instance record
 *		xold	old instance record if calledfrom == SET
 *		calledfrom  set to CREATE or SET
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:	Objects created and destroyed.
 */
static NhlErrorTypes
SetUpTransObjs
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else 
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	NhlSArg		sargs[30];
	int		nargs = 0;
	char		buffer[_NhlMAXRESNAMLEN];
	int		tmpid;
	float		tmpcoords[3];
	char		*error_lead=NULL;
	NhlLayerClass	trans_class = NULL;
	NhlGenArray	gen;
	NhlXyPlotLayerPart	*newxy = &xnew->xyplot;
	NhlXyPlotLayerPart	*oldxy=NULL;

/*
 * Now create main transformation object
 */	
	if(calledfrom == CREATE){
		error_lead = "XyPlotInitialize";
	}
	else{
		oldxy = &xold->xyplot;

		if(calledfrom == SET){
			error_lead = "XyPlotSetValues";
		}
		else if (calledfrom == DATACHANGE){
		/*
		 * If we are coming from UpdateData - The only resources that
		 * could have changed are min and max - if they haven't changed
		 * return immediately.
		 */
			if((newxy->x_min == oldxy->x_min) &&
				(newxy->x_max == oldxy->x_max) &&
				(newxy->y_min == oldxy->y_min) &&
				(newxy->y_max == oldxy->y_max)){
				return NhlNOERROR;
			}
			error_lead = "XyPlotUpdateData";
		}
	}

	/*
	 * If a new trans object needs to be created, do this.
	 */
	if(	(newxy->thetrans == NULL)
		||
		(calledfrom == CREATE)
		||
		(	(	(newxy->x_style == NhlIRREGULAR) ||
				(newxy->y_style == NhlIRREGULAR)
			) &&
			!oldxy->have_irreg_trans
		)
		||
		(	(newxy->x_style != NhlIRREGULAR) &&
			(newxy->y_style != NhlIRREGULAR) &&
			oldxy->have_irreg_trans
		)
									){

		if(newxy->thetrans != NULL){
			(void)NhlDestroy(newxy->thetrans->base.id);
			newxy->thetrans = NULL;
		}

		sprintf(buffer,"%s",xnew->base.name);
		strcat(buffer,".Trans");

		newxy->fake_x = newxy->fake_y = False;

		if(newxy->y_style == NhlIRREGULAR){

			trans_class = NhlirregularType2TransObjLayerClass;
			newxy->have_irreg_trans = True;

			gen = newxy->y_irregular_points;
			NhlSetSArg(&sargs[nargs++],NhlNtrYCoordPoints,
								gen->data);
			NhlSetSArg(&sargs[nargs++],NhlNtrYNumPoints,
							gen->len_dimensions[0]);
			NhlSetSArg(&sargs[nargs++],NhlNtrYTensionF,
							newxy->y_tension);

			if(newxy->x_style == NhlIRREGULAR){

				gen = newxy->x_irregular_points;
				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
								gen->data);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,
							gen->len_dimensions[0]);
				NhlSetSArg(&sargs[nargs++],NhlNtrXTensionF,
							newxy->x_tension);
			}
			else{

				newxy->fake_x = True;
				newxy->fake_x_min = tmpcoords[0] = newxy->x_min;
				newxy->fake_x_max = tmpcoords[2] = newxy->x_max;

				if(newxy->x_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->x_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
					NhlSetSArg(&sargs[nargs++],
							NhlNtrXUseLog,True);
				}

				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,3);

			}
		}
		/*
		 * Y is not IRREG
		 */
		else{
			if(newxy->x_style == NhlIRREGULAR){

				trans_class = NhlirregularType2TransObjLayerClass;
				newxy->have_irreg_trans = True;

				gen = newxy->x_irregular_points;
				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
								gen->data);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,
							gen->len_dimensions[0]);
				NhlSetSArg(&sargs[nargs++],NhlNtrXTensionF,
							newxy->x_tension);

				newxy->fake_y = True;
				newxy->fake_y_min = tmpcoords[0] = newxy->y_min;
				newxy->fake_y_max = tmpcoords[2] = newxy->y_max;

				if(newxy->y_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->y_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
					NhlSetSArg(&sargs[nargs++],
							NhlNtrYUseLog,True);
				}

				NhlSetSArg(&sargs[nargs++],NhlNtrYCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrYNumPoints,3);

			}
			/*
			 * X is not IRREG
			 */
			else{
				trans_class = NhllogLinTransObjLayerClass;
				newxy->have_irreg_trans = False;

				if(newxy->x_style == NhlLOG)
					NhlSetSArg(&sargs[nargs++],NhlNtrXLog,
									True);
				if(newxy->y_style == NhlLOG)
					NhlSetSArg(&sargs[nargs++],NhlNtrYLog,
									True);

			}
		}
		NhlSetSArg(&sargs[nargs++],NhlNtrXMinF,newxy->x_min);
		NhlSetSArg(&sargs[nargs++],NhlNtrXMaxF,newxy->x_max);
		NhlSetSArg(&sargs[nargs++],NhlNtrYMinF,newxy->y_min);
		NhlSetSArg(&sargs[nargs++],NhlNtrYMaxF,newxy->y_max);

		NhlSetSArg(&sargs[nargs++],NhlNtrXReverse,newxy->x_reverse);
		NhlSetSArg(&sargs[nargs++],NhlNtrYReverse,newxy->y_reverse);

		(void)NhlALCreate(&tmpid,buffer,trans_class,xnew->base.id,
								sargs,nargs);

		newxy->thetrans = _NhlGetLayer(tmpid);
		if(newxy->thetrans == NULL){
			NhlPError(NhlFATAL,NhlEUNKNOWN,
				"%s:Unable to continue without transformation",
								error_lead);
			return NhlFATAL;
		}

		return NhlNOERROR;
	}

	/*
	 * SetValues/UpdateData in existing trans object
	 */

	/*
	 * if we are tricking an irreg object into being a log or lin - take
	 * care of setting the transformation.
	 */
	if(newxy->have_irreg_trans){
		if(newxy->fake_x){
			if(newxy->x_style == NhlIRREGULAR){
				newxy->fake_x = False;
				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
					newxy->x_irregular_points->data);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,
				newxy->x_irregular_points->len_dimensions[0]);
				NhlSetSArg(&sargs[nargs++],NhlNtrXTensionF,
							newxy->x_tension);
			}
			else if((newxy->x_style != oldxy->x_style) ||
				(newxy->x_min < newxy->fake_x_min) ||
				(newxy->x_max > newxy->fake_x_max)){

				newxy->fake_x_min = tmpcoords[0] = newxy->x_min;
				newxy->fake_x_max = tmpcoords[2] = newxy->x_max;
				if(newxy->x_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->x_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
				}
				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,3);
			}
		}
		else {
			if(newxy->x_style != NhlIRREGULAR){
				newxy->fake_x = True;
				newxy->fake_x_min = tmpcoords[0] = newxy->x_min;
				newxy->fake_x_max = tmpcoords[2] = newxy->x_max;
				if(newxy->x_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->x_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
				}
				NhlSetSArg(&sargs[nargs++],NhlNtrXCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrXNumPoints,3);

			}
		}
		if(newxy->fake_y){
			if(newxy->y_style == NhlIRREGULAR){
				newxy->fake_y = False;
				NhlSetSArg(&sargs[nargs++],NhlNtrYCoordPoints,
					newxy->y_irregular_points->data);
				NhlSetSArg(&sargs[nargs++],NhlNtrYNumPoints,
				newxy->y_irregular_points->len_dimensions[0]);
				NhlSetSArg(&sargs[nargs++],NhlNtrYTensionF,
							newxy->y_tension);
			}
			else if((newxy->y_style != oldxy->y_style) ||
				(newxy->y_min < newxy->fake_y_min) ||
				(newxy->y_max > newxy->fake_y_max)){

				newxy->fake_y_min = tmpcoords[0] = newxy->y_min;
				newxy->fake_y_max = tmpcoords[2] = newxy->y_max;
				if(newxy->y_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->y_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
				}
				NhlSetSArg(&sargs[nargs++],NhlNtrYCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrYNumPoints,3);
			}
		}
		else {
			if(newxy->y_style != NhlIRREGULAR){
				newxy->fake_y = True;
				newxy->fake_y_min = tmpcoords[0] = newxy->y_min;
				newxy->fake_y_max = tmpcoords[2] = newxy->y_max;
				if(newxy->y_style == NhlLINEAR){
					tmpcoords[1] =
						(tmpcoords[0]+tmpcoords[2])/2.0;
				}
				else if(newxy->y_style == NhlLOG){
					tmpcoords[1] =
					(float)pow(10.0,(log10(tmpcoords[0]) +
						log10(tmpcoords[2])) / 2.0);
				}
				NhlSetSArg(&sargs[nargs++],NhlNtrYCoordPoints,
								tmpcoords);
				NhlSetSArg(&sargs[nargs++],NhlNtrYNumPoints,3);

			}
		}
	}
		
	if(newxy->x_min != oldxy->x_min)
		NhlSetSArg(&sargs[nargs++],NhlNtrXMinF,newxy->x_min);
	if(newxy->x_max != oldxy->x_max)
		NhlSetSArg(&sargs[nargs++],NhlNtrXMaxF,newxy->x_max);
	if(newxy->y_min != oldxy->y_min)
		NhlSetSArg(&sargs[nargs++],NhlNtrYMinF,newxy->y_min);
	if(newxy->y_max != oldxy->y_max)
		NhlSetSArg(&sargs[nargs++],NhlNtrYMaxF,newxy->y_max);

	if(newxy->x_reverse != oldxy->x_reverse)
		NhlSetSArg(&sargs[nargs++],NhlNtrXReverse,newxy->x_reverse);
	if(newxy->y_reverse != oldxy->y_reverse)
		NhlSetSArg(&sargs[nargs++],NhlNtrYReverse,newxy->y_reverse);

	if(newxy->x_style != oldxy->x_style){
		if(newxy->have_irreg_trans)
			NhlSetSArg(&sargs[nargs++],NhlNtrXUseLog,
						(newxy->x_style == NhlLOG));
		else
			NhlSetSArg(&sargs[nargs++],NhlNtrXLog,
						(newxy->x_style == NhlLOG));
	}

	if(newxy->y_style != oldxy->y_style){
		if(newxy->have_irreg_trans)
			NhlSetSArg(&sargs[nargs++],NhlNtrYUseLog,
						(newxy->y_style == NhlLOG));
		else
			NhlSetSArg(&sargs[nargs++],NhlNtrYLog,
						(newxy->y_style == NhlLOG));
	}

	return NhlALSetValues(newxy->thetrans->base.id,sargs,nargs);
}

/*
 * Function:	SetUpTicks
 *
 * Description:	Takes care of setting resources for TickMarks. It is at
 *		this time that the resources, that are blocked by the
 *		_NhlRegisterChildClass call in XyPlotClassInitialize, are set.
 *		_NhlVACreateChild is used to create tick marks. _NhlVACreateChild
 *		is only called once and SetValues is used at all other times
 *		even when a change of style happens. This function could've
 *		been a lot shorter if there had been an argument list 
 *		interface to Create and SetValues when I built it. The args
 *		list interface would have require only one SetValues and
 *		one Create call. Since only the variable args function
 *		interface was available separate calls for each style
 *		needed to be made. Each call has only slight differences
 *		in resources but require separate calls none the less.
 *		After each create or set a getvalues is done to make sure
 *		that the resources held by the XyPlot object have the same
 *		values as the tick mark child.
 *		
 *		When Alternate axis control is implemented this will be
 *		the function to compute the mapping functions and configure
 *		the tick mark object.
 *
 * In Args:	xnew	new instance record
 *		xold	old instance record if calledfrom == SET
 *		calledfrom  either SET or CREATE
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects:	New objects created or reconfigured.
 */
/*ARGSUSED*/
static NhlErrorTypes
SetUpTicks
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
)
#else 
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	char		buffer[_NhlMAXRESNAMLEN];
	int		tmpid;
	char		*error_lead;
	NhlSArg		sargs[30];
	int		nargs=0;
	NhlXyPlotLayerPart	*newxy = &xnew->xyplot;
	NhlXyPlotLayerPart	*oldxy = NULL;
	NhlErrorTypes	ret=NhlNOERROR;

	if(calledfrom == CREATE){
		error_lead = "XyPlotInitialize";
	}
	else{
		oldxy = &xold->xyplot;

		if(calledfrom == SET){
			error_lead = "XyPlotSetValues";
		}
		else if(calledfrom == DATACHANGE){
		/*
		 * If we are coming from UpdateData - The only resources that
		 * could have changed are min and max - if they haven't changed
		 * return immediately.
		 */
			if((newxy->x_min == oldxy->x_min) &&
				(newxy->x_max == oldxy->x_max) &&
				(newxy->y_min == oldxy->y_min) &&
				(newxy->y_max == oldxy->y_max)){
				return NhlNOERROR;
			}
			error_lead = "XyPlotUpdateData";
		}
		else{
			NhlPError(NhlFATAL,NhlEUNKNOWN,"Bad Call");
			return NhlFATAL;
		}
	}
/*
 * Now deal with creating/changing values in the child ticks
 */
	if(xnew->xyplot.ticks == NULL){
		/*
		 * Create the tickmark object.
		 */
		strcpy(buffer,xnew->base.name);
		strcat(buffer,".Ticks");

		NhlSetSArg(&sargs[nargs++],NhlNvpXF,xnew->view.x);
		NhlSetSArg(&sargs[nargs++],NhlNvpYF,xnew->view.y);
		NhlSetSArg(&sargs[nargs++],NhlNvpWidthF,xnew->view.width);
		NhlSetSArg(&sargs[nargs++],NhlNvpHeightF,xnew->view.height);
		NhlSetSArg(&sargs[nargs++],NhlNtmXBDataLeftF,
				(newxy->x_reverse?newxy->x_max:newxy->x_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmXBDataRightF,
				(!newxy->x_reverse?newxy->x_max:newxy->x_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmXTDataLeftF,
				(newxy->x_reverse?newxy->x_max:newxy->x_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmXTDataRightF,
				(!newxy->x_reverse?newxy->x_max:newxy->x_min));

		NhlSetSArg(&sargs[nargs++],NhlNtmYLDataTopF,
				(!newxy->y_reverse?newxy->y_max:newxy->y_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmYLDataBottomF,
				(newxy->y_reverse?newxy->y_max:newxy->y_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmYRDataTopF,
				(!newxy->y_reverse?newxy->y_max:newxy->y_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmYRDataBottomF,
				(newxy->y_reverse?newxy->y_max:newxy->y_min));
		NhlSetSArg(&sargs[nargs++],NhlNtmXBStyle,newxy->x_style);
		NhlSetSArg(&sargs[nargs++],NhlNtmXTStyle,newxy->x_style);
		NhlSetSArg(&sargs[nargs++],NhlNtmYLStyle,newxy->y_style);
		NhlSetSArg(&sargs[nargs++],NhlNtmYRStyle,newxy->y_style);
		NhlSetSArg(&sargs[nargs++],NhlNtmXBIrrTensionF,
							newxy->x_tension);
		NhlSetSArg(&sargs[nargs++],NhlNtmXTIrrTensionF,
							newxy->x_tension);
		NhlSetSArg(&sargs[nargs++],NhlNtmYLIrrTensionF,
							newxy->y_tension);
		NhlSetSArg(&sargs[nargs++],NhlNtmYRIrrTensionF,
							newxy->y_tension);

		if(newxy->x_irregular_points != NULL){
			NhlSetSArg(&sargs[nargs++],NhlNtmXBIrregularPoints,
					newxy->x_irregular_points);
			NhlSetSArg(&sargs[nargs++],NhlNtmXTIrregularPoints,
					newxy->x_irregular_points);
		}

		if(newxy->y_irregular_points != NULL){
			NhlSetSArg(&sargs[nargs++],NhlNtmYLIrregularPoints,
					newxy->y_irregular_points);
			NhlSetSArg(&sargs[nargs++],NhlNtmYRIrregularPoints,
					newxy->y_irregular_points);
		}

		ret = _NhlALCreateChild(&tmpid,buffer,NhltickMarkLayerClass,
						(NhlLayer)xnew,sargs,nargs);
		newxy->ticks = _NhlGetLayer(tmpid);
		if(newxy->ticks == NULL){
			NhlPError(NhlFATAL,NhlEUNKNOWN,
			"%s:Unable to Create TickMark Object",error_lead);
			return NhlFATAL;
		}
		return ret;
	}
	else{
		tmpid = xnew->xyplot.ticks->base.id;

		if(xold->view.x != xnew->view.x)
			NhlSetSArg(&sargs[nargs++],NhlNvpXF,xnew->view.x);
		if(xold->view.y != xnew->view.y)
			NhlSetSArg(&sargs[nargs++],NhlNvpYF,xnew->view.y);
		if(xold->view.width != xnew->view.width)
			NhlSetSArg(&sargs[nargs++],NhlNvpWidthF,
							xnew->view.width);
		if(xold->view.height != xnew->view.height)
			NhlSetSArg(&sargs[nargs++],NhlNvpHeightF,
							xnew->view.height);

		if((oldxy->x_reverse != newxy->x_reverse) ||
			(oldxy->x_min != newxy->x_min) ||
			(oldxy->x_max != newxy->x_max)){

			NhlSetSArg(&sargs[nargs++],NhlNtmXBDataLeftF,
				(newxy->x_reverse?newxy->x_max:newxy->x_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmXBDataRightF,
				(!newxy->x_reverse?newxy->x_max:newxy->x_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmXTDataLeftF,
				(newxy->x_reverse?newxy->x_max:newxy->x_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmXTDataRightF,
				(!newxy->x_reverse?newxy->x_max:newxy->x_min));
		}
		if(oldxy->x_tension != newxy->x_tension) {
			NhlSetSArg(&sargs[nargs++],NhlNtmXBIrrTensionF,
							newxy->x_tension);
			NhlSetSArg(&sargs[nargs++],NhlNtmXTIrrTensionF,
							newxy->x_tension);
		}
		if(oldxy->y_tension != newxy->y_tension) {
			NhlSetSArg(&sargs[nargs++],NhlNtmYLIrrTensionF,
							newxy->y_tension);
			NhlSetSArg(&sargs[nargs++],NhlNtmYRIrrTensionF,
							newxy->y_tension);
		}
		if((oldxy->y_reverse != newxy->y_reverse) ||
			(oldxy->y_min != newxy->y_min) ||
			(oldxy->y_max != newxy->y_max)){

			NhlSetSArg(&sargs[nargs++],NhlNtmYLDataTopF,
				(!newxy->y_reverse?newxy->y_max:newxy->y_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmYLDataBottomF,
				(newxy->y_reverse?newxy->y_max:newxy->y_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmYRDataTopF,
				(!newxy->y_reverse?newxy->y_max:newxy->y_min));
			NhlSetSArg(&sargs[nargs++],NhlNtmYRDataBottomF,
				(newxy->y_reverse?newxy->y_max:newxy->y_min));
		}

		if(oldxy->x_style != newxy->x_style){
			NhlSetSArg(&sargs[nargs++],NhlNtmXBStyle,
								newxy->x_style);
			NhlSetSArg(&sargs[nargs++],NhlNtmXTStyle,
								newxy->x_style);
		}
		if(oldxy->y_style != newxy->y_style){
			NhlSetSArg(&sargs[nargs++],NhlNtmYLStyle,
								newxy->y_style);
			NhlSetSArg(&sargs[nargs++],NhlNtmYRStyle,
								newxy->y_style);
		}

		if(oldxy->x_irregular_points != newxy->x_irregular_points){
			if(newxy->x_irregular_points != NULL){
			NhlSetSArg(&sargs[nargs++],NhlNtmXBIrregularPoints,
					newxy->x_irregular_points);
			NhlSetSArg(&sargs[nargs++],NhlNtmXTIrregularPoints,
					newxy->x_irregular_points);
			}
			else{
			NhlSetSArg(&sargs[nargs++],NhlNtmXBIrregularPoints,
									NULL);
			NhlSetSArg(&sargs[nargs++],NhlNtmXTIrregularPoints,
									NULL);
			}
		}

		if(oldxy->y_irregular_points != newxy->y_irregular_points){
			if(newxy->y_irregular_points != NULL){
			NhlSetSArg(&sargs[nargs++],NhlNtmYLIrregularPoints,
					newxy->y_irregular_points);
			NhlSetSArg(&sargs[nargs++],NhlNtmYRIrregularPoints,
					newxy->y_irregular_points);
			}
			else{
			NhlSetSArg(&sargs[nargs++],NhlNtmYLIrregularPoints,
									NULL);
			NhlSetSArg(&sargs[nargs++],NhlNtmYRIrregularPoints,
									NULL);
			}
		}
		return _NhlALSetValuesChild(tmpid,(NhlLayer)xnew,sargs,nargs);
	}
}

/*
 * Function:	SetUpTitles
 *
 * Description: Sets and Creates Title object. _NhlVACreateChild is used to
 *		create the titles.  The title resources *OffsetXF and *OffsetYF
 *		are intercepted by the XyPlot object so adjustments can be
 *		made to make sure that the titles are centered over the
 *		XyPlot's viewport but do not overlap with tick mark labels.
 *		The adjusted values are added to any user supplied values
 *		to obtain the correct location of the title. The resources
 *		for configuring which side of the plot a title goes and in
 *		which position it goes are also intercepted so that the
 *		offset values can be computed.
 *
 *
 * In Args:	xnew 	new instance record
 *		xold	old instance record
 *
 * Out Args:	NhlNONE
 *
 * Return Values:	Error Conditions
 *
 * Side Effects: Objects created or states changed. 	
 */
/*ARGSUSED*/
static NhlErrorTypes SetUpTitles
#if	NhlNeedProto
(
	NhlXyPlotLayer	xnew,
	NhlXyPlotLayer	xold,
	_NhlCallType	calledfrom
) 
#else 
(xnew,xold,calledfrom)
	NhlXyPlotLayer	xnew;
	NhlXyPlotLayer	xold;
	_NhlCallType	calledfrom;
#endif
{
	NhlXyPlotLayerPart	*oldxy = NULL;
	NhlXyPlotLayerPart	*newxy = &xnew->xyplot;
	int		tmpid = -1;
	NhlBoundingBox	abox;
	char		buffer[_NhlMAXFNAMELEN];
	float		xtmp,ytmp,widthtmp,heighttmp;
	char		*error_lead;
	NhlErrorTypes	ret = NhlNOERROR;

	if(calledfrom == CREATE){
		error_lead = "XyPlotInitialize";
	}
	else{
		oldxy = &xold->xyplot;

		if(calledfrom == SET){
			error_lead = "XyPlotSetValues";
		}
		else if(calledfrom == DATACHANGE){
		/*
		 * If we are coming from UpdateData - The only resources that
		 * could have changed are min and max - if they haven't changed
		 * return immediately.
		 */
			if((newxy->x_min == oldxy->x_min) &&
				(newxy->x_max == oldxy->x_max) &&
				(newxy->y_min == oldxy->y_min) &&
				(newxy->y_max == oldxy->y_max)){
				return NhlNOERROR;
			}
			error_lead = "XyPlotUpdateData";
		}
		else{
			NhlPError(NhlFATAL,NhlEUNKNOWN,"Bad Call");
			return NhlFATAL;
		}
	}

	if(xnew->xyplot.ticks != NULL)
		NhlGetBB(xnew->xyplot.ticks->base.id,&abox);
	else
		NhlGetBB(xnew->base.id,&abox);
	xtmp = abox.l;
	ytmp = abox.t;
	widthtmp = abox.r - abox.l;
	heighttmp = abox.t - abox.b;
	
	switch(xnew->xyplot.ti_main_position) {
	case NhlCENTER:
		xnew->xyplot.real_main_offset_x = xnew->xyplot.ti_main_offset_x
			+ ((xnew->view.x + xnew->view.width/2.0)
			- (xtmp + widthtmp/2.0));
		break;
	case NhlLEFT:
		xnew->xyplot.real_main_offset_x = xnew->xyplot.ti_main_offset_x 
			+ (xnew->view.x - xtmp);
		break;
	case NhlRIGHT:
		xnew->xyplot.real_main_offset_x = xnew->xyplot.ti_main_offset_x
			+ ((xnew->view.x + xnew->view.width) 
			- (xtmp + widthtmp));
		break;
	}
	switch(xnew->xyplot.ti_x_axis_position) {
	case NhlCENTER:
		xnew->xyplot.real_x_axis_offset_x = 
			xnew->xyplot.ti_x_axis_offset_x 
			+ ((xnew->view.x + xnew->view.width/2.0)
			- (xtmp + widthtmp/2.0));
		break;
	case NhlLEFT:
		xnew->xyplot.real_x_axis_offset_x = 
			xnew->xyplot.ti_x_axis_offset_x 
			+ (xnew->view.x - xtmp);
		break;
	case NhlRIGHT:
		xnew->xyplot.real_x_axis_offset_x = 
			xnew->xyplot.ti_x_axis_offset_x 
			+ ((xnew->view.x + xnew->view.width) 
			- (xtmp + widthtmp));
		break;
	}
	switch(xnew->xyplot.ti_y_axis_position) {
	case NhlCENTER:
		xnew->xyplot.real_y_axis_offset_y = 
			xnew->xyplot.ti_y_axis_offset_y 
			+ ((xnew->view.y - xnew->view.height/2.0)
			- (ytmp - heighttmp/2.0));
		break;
	case NhlTOP:
		xnew->xyplot.real_y_axis_offset_y = 
			xnew->xyplot.ti_y_axis_offset_y 
			+ (xnew->view.y - ytmp);
		break;
	case NhlBOTTOM:
		xnew->xyplot.real_y_axis_offset_y = 
			xnew->xyplot.ti_y_axis_offset_y 
			+ ((xnew->view.y - xnew->view.height) 
			- (ytmp - heighttmp));
		break;
	}


	if((calledfrom == CREATE) || (xnew->xyplot.ttitles == NULL)){	
		strcpy(buffer,xnew->base.name);
		strcat(buffer,".Title");
		ret = _NhlVACreateChild(&tmpid,buffer,NhltitleLayerClass,(NhlLayer)xnew,
			NhlNvpXF,xtmp,
			NhlNvpYF,ytmp,
			NhlNvpWidthF,widthtmp,
			NhlNvpHeightF,heighttmp,
			NhlNtiMainOffsetXF,xnew->xyplot.real_main_offset_x,
			NhlNtiYAxisOffsetYF,xnew->xyplot.real_y_axis_offset_y,
			NhlNtiXAxisOffsetXF,xnew->xyplot.real_x_axis_offset_x,
			NhlNtiXAxisPosition,xnew->xyplot.ti_x_axis_position,
			NhlNtiYAxisPosition,xnew->xyplot.ti_y_axis_position,
			NhlNtiMainPosition,xnew->xyplot.ti_main_position,
			NULL);
	} else {
		tmpid = xnew->xyplot.ttitles->base.id;
		ret = _NhlVASetValuesChild(tmpid,
			(NhlLayer)xnew,
			NhlNvpXF,xtmp,
			NhlNvpYF,ytmp,
			NhlNvpWidthF,widthtmp,
			NhlNvpHeightF,heighttmp,
			NhlNtiMainOffsetXF,xnew->xyplot.real_main_offset_x,
			NhlNtiYAxisOffsetYF,xnew->xyplot.real_y_axis_offset_y,
			NhlNtiXAxisOffsetXF,xnew->xyplot.real_x_axis_offset_x,
			NhlNtiXAxisPosition,xnew->xyplot.ti_x_axis_position,
			NhlNtiYAxisPosition,xnew->xyplot.ti_y_axis_position,
			NhlNtiMainPosition,xnew->xyplot.ti_main_position,
			NULL);
	}
	if((tmpid > -1)||(ret >= NhlWARNING)) {
		xnew->xyplot.ttitles = _NhlGetLayer(tmpid);
		return(ret);
	} else {
		NhlPError(NhlFATAL,NhlEUNKNOWN,"%s: Could not create Titles",error_lead);
		return(NhlFATAL);
	} 
}
