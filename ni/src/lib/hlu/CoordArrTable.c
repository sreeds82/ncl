/*
 *      $Id: CoordArrTable.c,v 1.1 1993-09-15 22:10:11 boote Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1993			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		CoordArrTable.c
 *
 *	Author:		Jeff W. Boote
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Wed Jul 28 11:23:48 MDT 1993
 *
 *	Description:	This class is used to communicate data in the format
 *			of CoordArrTable.
 */
#include <stdio.h>
#include <string.h>
#include <ncarg/hlu/CoordArrTableP.h>

/************************************************************************
*									*
*	CoordArrTable Class declarations				*
*									*
************************************************************************/

/*
 * Resource Declarations
 */

/*
 * Function:	Resource Default Procedures
 *
 * Description:	These proc's are used to determine if the user/program
 *		set the min,max,missing resources or if the object
 *		should compute them.
 *
 * In Args:	
 *		NrmName		name,
 *		NrmClass	class,
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
MissingXSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.missing_x_set = False;
		catl->catfloat.missing_x = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.missing_x_set = False;
		catl->catint.missing_x = 0;
	}
	else
		return FATAL;

	return NOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
MissingYSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.missing_y_set = False;
		catl->catfloat.missing_y = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.missing_y_set = False;
		catl->catint.missing_y = 0;
	}
	else
		return FATAL;

	return NOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
MaxXSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.max_x_set = False;
		catl->catfloat.max_x = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.max_x_set = False;
		catl->catint.max_x = 0;
	}
	else
		return FATAL;

	return NOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
MaxYSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.max_y_set = False;
		catl->catfloat.max_y = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.max_y_set = False;
		catl->catint.max_y = 0;
	}
	else
		return FATAL;

	return NOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
MinXSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.min_x_set = False;
		catl->catfloat.min_x = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.min_x_set = False;
		catl->catint.min_x = 0;
	}
	else
		return FATAL;

	return NOERROR;
}
/*ARGSUSED*/
static NhlErrorTypes
MinYSet
#if	__STDC__
(
	NrmName		name,
	NrmClass	class,
	NhlPointer	base,
	unsigned int	offset
)
#else
(name,class,base,offset)
	NrmName		name;
	NrmClass	class;
	NhlPointer	base;
	unsigned int	offset;
#endif
{
	Layer	l = (Layer)base;

	if(l->base.layer_class == coordArrTableFloatLayerClass){
		CoordArrTableFloatLayer	catl = (CoordArrTableFloatLayer)l;

		catl->catfloat.min_y_set = False;
		catl->catfloat.min_y = 0.0;
	}
	else if(l->base.layer_class == coordArrTableIntLayerClass){
		CoordArrTableIntLayer	catl = (CoordArrTableIntLayer)l;

		catl->catint.min_y_set = False;
		catl->catint.min_y = 0;
	}
	else
		return FATAL;

	return NOERROR;
}

#define	Oset(field)	NhlOffset(CoordArrTableFloatLayerRec,catfloat.field)
static NhlResource fltresources[] = {
	{NhlNctXTable,NhlCctXTable,NhlTGenArray,sizeof(NhlGenArray),
		Oset(xtable),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctYTable,NhlCctYTable,NhlTGenArray,sizeof(NhlGenArray),
		Oset(ytable),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctXTableLengths,NhlCctXTableLengths,NhlTGenArray,
		sizeof(NhlGenArray),
		Oset(xtable_lens),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctYTableLengths,NhlCctYTableLengths,NhlTGenArray,
		sizeof(NhlGenArray),
		Oset(ytable_lens),NhlTImmediate,(NhlPointer)NULL},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(missing_x_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctXMissing,NhlCctXMissing,NhlTFloat,sizeof(float),
		Oset(missing_x),NhlTProcedure,(NhlPointer)MissingXSet},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(missing_y_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctYMissing,NhlCctYMissing,NhlTFloat,sizeof(float),
		Oset(missing_y),NhlTProcedure,(NhlPointer)MissingYSet},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(max_x_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctXMax,NhlCctXMax,NhlTFloat,sizeof(float),
		Oset(max_x),NhlTProcedure,(NhlPointer)MaxXSet},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(max_y_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctYMax,NhlCctYMax,NhlTFloat,sizeof(float),
		Oset(max_y),NhlTProcedure,(NhlPointer)MaxYSet},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(min_x_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctXMin,NhlCctXMin,NhlTFloat,sizeof(float),
		Oset(min_x),NhlTProcedure,(NhlPointer)MinXSet},
	{"no.res","No.res",NhlTBoolean,sizeof(NhlBoolean),
		Oset(min_y_set),NhlTImmediate,(NhlPointer)True},
	{NhlNctYMin,NhlCctYMin,NhlTFloat,sizeof(float),
		Oset(min_y),NhlTProcedure,(NhlPointer)MinYSet}
};
#undef Oset

#define	Oset(field)	NhlOffset(CoordArrTableIntLayerRec,catint.field)
static NhlResource intresources[] = {
	{NhlNctXTable,NhlCctXTable,NhlTGenArray,sizeof(NhlGenArray),
		Oset(xtable),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctYTable,NhlCctYTable,NhlTGenArray,sizeof(NhlGenArray),
		Oset(ytable),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctXTableLengths,NhlCctXTableLengths,NhlTGenArray,
		sizeof(NhlGenArray),
		Oset(xtable_lens),NhlTImmediate,(NhlPointer)NULL},
	{NhlNctYTableLengths,NhlCctYTableLengths,NhlTGenArray,
		sizeof(NhlGenArray),
		Oset(ytable_lens),NhlTImmediate,(NhlPointer)NULL}
};
#undef Oset

#define	Oset(field)	NhlOffset(CoordArrTableLayerRec,cat.field)
static NhlResource resources[] = {
	{NhlNdiType,NhlCdiType,NhlTString,sizeof(NhlString),
		Oset(type_string),NhlTImmediate,(NhlPointer)NULL}
};
#undef Oset

/* base methods */

static NhlErrorTypes CoordArrTableClassPartInitialize(
#if	NhlNeedProto
	LayerClass	lc	/* lc to init	*/
#endif
);

static NhlErrorTypes CoordArrTableClassInitialize(
#if	NhlNeedProto
	void
#endif
);

static NhlErrorTypes CoordArrTableFloatInitialize(
#if	NhlNeedProto
	LayerClass	lc,	/* class	*/
	Layer		req,	/* requested	*/
	Layer		new,	/* new		*/
	_NhlArgList	args,	/* args		*/
	int		nargs	/* nargs	*/
#endif
);

static NhlErrorTypes CoordArrTableInitialize(
#if	NhlNeedProto
	LayerClass	lc,	/* class	*/
	Layer		req,	/* requested	*/
	Layer		new,	/* new		*/
	_NhlArgList	args,	/* args		*/
	int		nargs	/* nargs	*/
#endif
);

static NhlErrorTypes CoordArrTableSetValues(
#if	NhlNeedProto
	Layer		old,		/* old		*/
	Layer		req,		/* requested	*/
	Layer		new,		/* new		*/
	_NhlArgList	args,		/* args to set	*/
	int		nargs		/* nargs	*/
#endif
);

static NhlErrorTypes CoordArrTableDestroy(
#if	NhlNeedProto
	Layer	l	/* layer to destroy	*/
#endif
);

CoordArrTableFloatLayerClassRec coordArrTableFloatLayerClassRec = {
	/* BaseLayerClassPart */
	{
/* class_name			*/	"CoordArrTableFloat",
/* nrm_class			*/	NrmNULLQUARK,
/* layer_size			*/	sizeof(CoordArrTableFloatLayerRec),
/* class_inited			*/	False,
/* superclass			*/	(LayerClass)&objLayerClassRec,

/* resources			*/	fltresources,
/* num_resources		*/	NhlNumber(fltresources),
/* all_resources		*/	NULL,

/* class_part_initialize	*/	NULL,
/* class_initialize		*/	NULL,
/* layer_initialize		*/	CoordArrTableFloatInitialize,
/* layer_set_values		*/	NULL,
/* layer_get_values		*/	NULL,
/* layer_reparent		*/	NULL,
/* layer_destroy		*/	NULL
	},
	/* CoordArrTableFloatLayerPart */
	{
/* foo				*/	NULL
	}
};

CoordArrTableIntLayerClassRec coordArrTableIntLayerClassRec = {
	/* BaseLayerClassPart */
	{
/* class_name			*/	"CoordArrTableInt",
/* nrm_class			*/	NrmNULLQUARK,
/* layer_size			*/	sizeof(CoordArrTableIntLayerRec),
/* class_inited			*/	False,
/* superclass			*/	(LayerClass)&objLayerClassRec,

/* resources			*/	intresources,
/* num_resources		*/	NhlNumber(intresources),
/* all_resources		*/	NULL,

/* class_part_initialize	*/	NULL,
/* class_initialize		*/	NULL,
/* layer_initialize		*/	NULL,
/* layer_set_values		*/	NULL,
/* layer_get_values		*/	NULL,
/* layer_reparent		*/	NULL,
/* layer_destroy		*/	NULL
	},
	/* CoordArrTableIntLayerPart */
	{
/* foo				*/	NULL
	}
};

CoordArrTableLayerClassRec coordArrTableLayerClassRec = {
	/* BaseLayerClassPart */
	{
/* class_name			*/	"CoordArrTable",
/* nrm_class			*/	NrmNULLQUARK,
/* layer_size			*/	sizeof(CoordArrTableLayerRec),
/* class_inited			*/	False,
/* superclass			*/	(LayerClass)&dataItemLayerClassRec,

/* resources			*/	resources,
/* num_resources		*/	NhlNumber(resources),
/* all_resources		*/	NULL,

/* class_part_initialize	*/	CoordArrTableClassPartInitialize,
/* class_initialize		*/	CoordArrTableClassInitialize,
/* layer_initialize		*/	CoordArrTableInitialize,
/* layer_set_values		*/	CoordArrTableSetValues,
/* layer_get_values		*/	NULL,
/* layer_reparent		*/	NULL,
/* layer_destroy		*/	CoordArrTableDestroy,

/* child_resources		*/	NULL,

/* layer_draw			*/	NULL,

/* layer_pre_draw		*/	NULL,
/* layer_draw_segonly		*/	NULL,
/* layer_post_draw		*/	NULL,
/* layer_clear			*/	NULL
	},
	/* DataItemLayerClassPart */
	{
/* foo				*/	NULL
	},
	/* CoordArrTableLayerClassPart */
	{
/* foo				*/	NULL
	}
};
	
LayerClass coordArrTableLayerClass = (LayerClass)&coordArrTableLayerClassRec;
LayerClass coordArrTableFloatLayerClass = (LayerClass)&coordArrTableFloatLayerClassRec;
LayerClass coordArrTableIntLayerClass = (LayerClass)&coordArrTableIntLayerClassRec;

static	NrmQuark	floatQ = NrmNULLQUARK;
static	NrmQuark	intQ = NrmNULLQUARK;

/************************************************************************
*	New type converters - added to converter table by		*
*	ClassInitialize							*
************************************************************************/

/*
 * Function:	CvtGenObjToFloatObj
 *
 * Description:	This function is used to convert a Generic CoordArrTable
 *		to a CoordArrTableFloat object.
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	private
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
NhlErrorTypes
CvtGenObjToFloatObj
#if	__STDC__
(
	NrmValue		*from,
	NrmValue		*to,
	NhlConvertArgList	args,
	int			nargs
)
#else
(from,to,args,nargs)
	NrmValue		*from;
	NrmValue		*to;
	NhlConvertArgList	args;
	int			nargs;
#endif
{
	CoordArrTableLayer	catl = NULL;
	CoordArrTableFloatLayer	catfl;

	if(nargs != 0){
		NhlPError(FATAL,E_UNKNOWN,
				"CvtGenObjToFloatObj:Called w/wrong args");
		return FATAL;
	}

	catl = (CoordArrTableLayer)_NhlGetLayer(*(int*)(from->addr));
	if((catl == NULL)||(catl->base.layer_class != coordArrTableLayerClass)){
		NhlPError(FATAL,E_UNKNOWN,
		"CvtGenObjToFloatObj:Called w/ improper \"from\" object");
		return FATAL;
	}

	if(catl->cat.type == floatQ){
		catfl = (CoordArrTableFloatLayer)catl->cat.child;

		return NhlCreate((int*)to->addr,"no.name",
			coordArrTableFloatLayerClass,catl->base.id,
			NhlNctXTable,		catfl->catfloat.xtable,
			NhlNctYTable,		catfl->catfloat.ytable,
			NhlNctXTableLengths,	catfl->catfloat.xtable_lens,
			NhlNctYTableLengths,	catfl->catfloat.ytable_lens,
			NhlNctXMissing,		catfl->catfloat.missing_x,
			NhlNctYMissing,		catfl->catfloat.missing_y,
			NhlNctXMax,		catfl->catfloat.max_x,
			NhlNctYMax,		catfl->catfloat.max_y,
			NhlNctXMin,		catfl->catfloat.min_x,
			NhlNctYMin,		catfl->catfloat.min_y,
			NULL);
	}

	NhlPError(FATAL,E_UNKNOWN,"Unable to convert???");

	return FATAL;
}

/************************************************************************
*									*
*	Methode definitions						*
*									*
************************************************************************/


/*
 * Function:	CoordArrTableClassInitialize
 *
 * Description:	This function does one time initialization needed by the
 *		CoordArrTableClass.
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
CoordArrTableClassInitialize
#if	__STDC__
(
	void
)
#else
()
#endif
{
	NhlErrorTypes	ret = NOERROR;

	floatQ = NrmStringToQuark(NhlTFloat);
	intQ = NrmStringToQuark(NhlTInteger);

	ret = NhlRegisterConverter(
			coordArrTableLayerClass->base_class.class_name,
			coordArrTableFloatLayerClass->base_class.class_name,
			CvtGenObjToFloatObj,NULL,0,False,NULL);

	return ret;
}

/*
 * Function:	CoordArrTableClassPartInitialize
 *
 * Description:	This function is used to init the cat_class part of the layer
 *		class record of this class and of all sub-classes.
 *
 * In Args:	
 *		LayerClass	lc	pointer to class structure
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
static NhlErrorTypes
CoordArrTableClassPartInitialize
#if	__STDC__
(
	LayerClass	lc	/* pointer to class structure	*/
)
#else
(lc)
	LayerClass	lc;	/* pointer to class structure	*/
#endif
{
	NhlErrorTypes		ret, lret;

	ret = _NhlRegisterChildClass(lc,coordArrTableFloatLayerClass,True,
								False,NULL);
	lret = _NhlRegisterChildClass(lc,coordArrTableIntLayerClass,True,
								False,NULL);
	return MIN(lret,ret);
}

/*
 * Function:	CoordArrTableFloatInitialize
 *
 * Description:	This function initializes an instance of a CoordArrTableFloat
 *		class object.
 *
 * In Args:	
 *	LayerClass	lc,	class
 *	Layer		req,	requested
 *	Layer		new,	new
 *	_NhlArgList	args,	args
 *	int		nargs	nargs
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
CoordArrTableFloatInitialize
#if	__STDC__
(
	LayerClass	lc,	/* class	*/
	Layer		req,	/* requested	*/
	Layer		new,	/* new		*/
	_NhlArgList	args,	/* args		*/
	int		nargs	/* nargs	*/
)
#else
(lc,req,new,args,nargs)
	LayerClass	lc;	/* class	*/
	Layer		req;	/* requested	*/
	Layer		new;	/* new		*/
	_NhlArgList	args;	/* args		*/
	int		nargs;	/* nargs	*/
#endif
{
	char			*error_lead = "CoordArrTableFloatInitialize";
	CoordArrTableFloatLayer	ncat = (CoordArrTableFloatLayer)new;
	NhlErrorTypes		ret=NOERROR;
	NhlGenArray		gen, gen2;

	/*
	 * insure accuracy, and copy YTable and YTableLengths
	 */
	if((ncat->catfloat.ytable == NULL) ||
					(ncat->catfloat.ytable_lens == NULL)){
		NhlPError(FATAL,E_UNKNOWN,"%s:%s and %s must be specified",
				error_lead,NhlNctYTable,NhlNctYTableLengths);
		return FATAL;
	}
	gen = ncat->catfloat.ytable;
	gen2 = ncat->catfloat.ytable_lens;
	if((gen->len_dimensions != NULL) || (gen2->len_dimensions != NULL)){
		NhlPError(FATAL,E_UNKNOWN,
				"%s:%s and %s must one dimensional arrays",
				error_lead,NhlNctYTable,NhlNctYTableLengths);
		return FATAL;
	}
	if(gen->num_dimensions != gen2->num_dimensions){
		NhlPError(FATAL,E_UNKNOWN,
			"%s:%s and %s must be arrays of the same length",
				error_lead,NhlNctYTable,NhlNctYTableLengths);
		return FATAL;
	}
	ncat->catfloat.ytable = _NhlCopyGenArray(gen,True);
	ncat->catfloat.ytable_lens = _NhlCopyGenArray(gen2,True);

	/*
	 * insure accuracy, and copy XTable and XTableLengths
	 */
	if((ncat->catfloat.xtable != NULL) &&
					(ncat->catfloat.xtable_lens != NULL)){
		gen = ncat->catfloat.xtable;
		gen2 = ncat->catfloat.xtable_lens;
		if((gen->len_dimensions != NULL) ||
						(gen2->len_dimensions != NULL)){
			NhlPError(WARNING,E_UNKNOWN,
			"%s:%s and %s must one dimensional arrays:ignoring",
				error_lead,NhlNctXTable,NhlNctXTableLengths);
			ncat->catfloat.xtable = NULL;
			ncat->catfloat.xtable_lens = NULL;
		}
		else if(gen->num_dimensions != gen2->num_dimensions){
			NhlPError(FATAL,E_UNKNOWN,
		"%s:%s and %s must be arrays of the same length:ignoring",
				error_lead,NhlNctXTable,NhlNctXTableLengths);
			ncat->catfloat.xtable = NULL;
			ncat->catfloat.xtable_lens = NULL;
		}
		else{
			ncat->catfloat.xtable = _NhlCopyGenArray(gen,True);
			ncat->catfloat.xtable_lens =_NhlCopyGenArray(gen2,True);
		}
	}
	else if((ncat->catfloat.xtable != NULL) ||
					(ncat->catfloat.xtable_lens != NULL)){
		NhlPError(FATAL,E_UNKNOWN,
			"%s:%s and %s must be set together:ignoring",
				error_lead,NhlNctXTable,NhlNctXTableLengths);
		ncat->catfloat.xtable = NULL;
		ncat->catfloat.xtable_lens = NULL;
	}

	/*
	 * Set Max's and Min's
	 */
	if(!ncat->catfloat.max_x_set || !ncat->catfloat.min_x_set){
		int	*lens,i,j;
		float	**xvals,xmax,xmin;

		if(ncat->catfloat.xtable != NULL){

			xvals = (float**)ncat->catfloat.xtable->data;
			xmax = xmin = **xvals;
			lens = (int*)ncat->catfloat.xtable_lens->data;
			for(i=0;i < ncat->catfloat.xtable->num_dimensions;i++){
				float	*xvect;

				xvect = xvals[i];
				for(j=0;j < lens[i];j++){
					xmax = MAX(xvect[j],xmax);
					xmin = MIN(xvect[j],xmin);
				}
			}

		}
		else{
			xmax = xmin = 1.0;
			lens = (int*)ncat->catfloat.ytable_lens->data;
			for(i=0;i<ncat->catfloat.ytable_lens->num_dimensions;
									i++)
				xmax = MAX(xmax,lens[i]);
		}

		if(!ncat->catfloat.max_x_set)
			ncat->catfloat.max_x = xmax;
		if(!ncat->catfloat.min_x_set)
			ncat->catfloat.min_x = xmin;
	}

	if(!ncat->catfloat.max_y_set || !ncat->catfloat.min_y_set){
		int	*lens,i,j;
		float	**yvals,ymax,ymin;
		yvals = (float**)ncat->catfloat.ytable->data;
		ymax = ymin = **yvals;
		lens = (int*)ncat->catfloat.ytable_lens->data;
		for(i=0;i < ncat->catfloat.ytable->num_dimensions;i++){
			float	*yvect;

			yvect = yvals[i];
			for(j=0;j < lens[i];j++){
				ymax = MAX(yvect[j],ymax);
				ymin = MIN(yvect[j],ymin);
			}
		}

		if(!ncat->catfloat.max_y_set)
			ncat->catfloat.max_y = ymax;
		if(!ncat->catfloat.min_y_set)
			ncat->catfloat.min_y = ymin;
	}

	return ret;
}

/*
 * Function:	CoordArrTableInitialize
 *
 * Description:	This function initializes an instance of a CoordArrTable
 *		class object.
 *
 * In Args:	
 *	LayerClass	lc,	class
 *	Layer		req,	requested
 *	Layer		new,	new
 *	_NhlArgList	args,	args
 *	int		nargs	nargs
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
CoordArrTableInitialize
#if	__STDC__
(
	LayerClass	lc,	/* class	*/
	Layer		req,	/* requested	*/
	Layer		new,	/* new		*/
	_NhlArgList	args,	/* args		*/
	int		nargs	/* nargs	*/
)
#else
(lc,req,new,args,nargs)
	LayerClass	lc;	/* class	*/
	Layer		req;	/* requested	*/
	Layer		new;	/* new		*/
	_NhlArgList	args;	/* args		*/
	int		nargs;	/* nargs	*/
#endif
{
	char			*error_lead = "CoordArrTableInitialize";
	CoordArrTableLayer	ncat = (CoordArrTableLayer)new;
	LayerClass		child_class;
	int			tchild;
	char			name[MAXRESNAMLEN];
	NhlErrorTypes		ret;

	if(ncat->cat.type_string == NULL){
		NhlPError(FATAL,E_UNKNOWN,
		"%s:The %s resource must be specified to create a %s object",
				error_lead,NhlNdiType,_NhlClassName(lc));

		return FATAL;
	}

	ncat->cat.type = NrmStringToQuark(ncat->cat.type_string);
	ncat->cat.type_string = NULL;

	/*
	 * Create the correct child...
	 */
	strcpy(name,ncat->base.name);
	if(ncat->cat.type == floatQ){
		child_class = coordArrTableFloatLayerClass;
		strcat(name,".FLT");
	}
	else if(ncat->cat.type == intQ){
		child_class = coordArrTableIntLayerClass;
		strcat(name,".INT");
	}

	ret = _NhlCreateChild(&tchild,name,child_class,new,NULL);

	ncat->cat.child = _NhlGetLayer(tchild);

	return ret;
}

/*
 * Function:	CoordArrTableSetValues
 *
 * Description:	...
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
/*ARGSUSED*/
static NhlErrorTypes
CoordArrTableSetValues
#if	__STDC__
(
	Layer		old,		/* old		*/
	Layer		req,		/* requested	*/
	Layer		new,		/* new		*/
	_NhlArgList	args,		/* args to set	*/
	int		nargs		/* nargs	*/
)
#else
(old,req,new,args,nargs)
	Layer		old;		/* old		*/
	Layer		req;		/* requested	*/
	Layer		new;		/* new		*/
	_NhlArgList	args;		/* args to set	*/
	int		nargs;		/* nargs	*/
#endif
{
	char			*error_lead = "CoordArrTableSetValues";
	CoordArrTableLayer	ncat = (CoordArrTableLayer)new;

	if(ncat->cat.type_string != NULL){
		NhlPError(WARNING,E_UNKNOWN,
			"%s:%s is setable only at create time - ignoring!",
							error_lead,NhlNdiType);
		ncat->cat.type_string = NULL;
	}

	return	NOERROR;
}

/*
 * Function:	CoordArrTableDestroy
 *
 * Description:	This function free's any memory that has been allocated
 *		on behalf of this instance of the CoordArrTableLayerClass.
 *
 * In Args:	Layer	l
 *
 * Out Args:	
 *
 * Scope:	static
 * Returns:	NhlErrorTypes
 * Side Effect:	
 */
static NhlErrorTypes
CoordArrTableDestroy
#if	__STDC__
(
	Layer	l	/* layer to destroy	*/
)
#else
(l)
	Layer	l;	/* layer to destroy	*/
#endif
{
	CoordArrTableLayer	catl = (CoordArrTableLayer)l;

	if(catl->cat.child != NULL)
		return _NhlDestroyChild(catl->cat.child->base.id,l);

	return NOERROR;
}

/************************************************************************
*									*
*	Private API for sub-classes					*
*									*
************************************************************************/

/* none yet */

/************************************************************************
*									*
*	Public API							*
*									*
************************************************************************/

/* none yet */
