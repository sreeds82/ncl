/*
 *      $Id: app.h,v 1.11 1999-02-23 03:56:42 dbrown Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1996			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		app.h
 *
 *	Author:		Jeff W. Boote
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Wed Jul 24 12:04:46 MDT 1996
 *
 *	Description:	
 */
#ifndef	_NG_APPMGR_H
#define	_NG_APPMGR_H

#include <ncarg/hlu/BaseP.h>
#include <ncarg/ngo/ngo.h>

#define Ng_SELECTED_WORK	"_NgSelectedWork"

#define NgNappName			"ngappName"
#define NgCappName			"ngAppName"
#define NgNappClass			"ngappClass"
#define NgCappClass			"ngAppClass"
#define NgNappAppId			"ngappAppId"
#define NgCappAppId			"ngAppAppId"
#define	NgNappNclState			"ngappNclState"
#define	NgCappNclState			"NgAppNclState"
#define	NgNappWksState			"ngappWksState"
#define	NgCappWksState			"NgAppWksState"

extern NhlClass NgappMgrClass;

/*
 * Public api
 */

extern void NgAppRun(
	int	appmgrid
);

extern void NgAppQuit(
	int	appmgrid
);

/*
 * Work proc's should return True if they are "done", and False if
 * they need to be called again.
 */
typedef NhlBoolean (*NgWorkProc)(
	NhlPointer	cdata
);

extern void NgAddWorkProc(
	int		appmgrid,
	NgWorkProc	work_proc,
	NhlPointer	cdata
);

extern void NgAddPriorityWorkProc(
	int		appmgrid,
	NgWorkProc	work_proc,
	NhlPointer	cdata
);

extern void NgRemoveWorkProc(
	int		appmgrid,
	NgWorkProc	work_proc,
	NhlPointer	cdata
);

/*
 * The NgCBWP functions allow you to add a callback function to an NhlLayer
 * that doesn't actually get executed until ncl is finished executing -
 * it actually gets executed from the WorkProc interface.  The
 * NgCBWPCopyFunc is executed when the actual callback is executed - it is
 * used to copy the cbdata - it should return False if it is unable to copy
 * the data, or if it determines that the actual callback shouldn't be called.
 * It should use the pointer to NhlArgVal to return a copy of the cbdata.
 * The cb_func that is added is actually called with
 * the copy that was returned from the NgCBWPCopyFunc from a WorkProc.
 * The NgCBWPCopyFunc is only necessary if the callback list's
 * cbdata.ptrval is used.  If copy_func is NULL, then a simple assignment
 * of the NhlArgVal's is done.  The NgCBWPFreeFunc is used to free
 * any value allocated from the NgCBWPCopyFunc.  It will be called
 * after the cb_func is called.  It will also be called in the event
 * that the NgCBWP is destroyed before all WorkProc's have actually
 * executed, but after an actual callback list has executed to allocate
 * a cbdata.  (It is possible to have your callback routine called after
 * the object that reported it has actually been destroyed - if you don't
 * want that to happen, then install an _NhlCBobjDestroy callback for
 * the object that calls NgCBWPDestroy on the NgCBWP.)
 */
typedef struct NgCBWPRec NgCBWPRec, *NgCBWP;

typedef NhlBoolean (*NgCBWPCopyFunc)(
	NhlArgVal	cbdata,
	NhlArgVal	udata,
	NhlArgVal	*ret
);

typedef void (*NgCBWPFreeFunc)(
	NhlArgVal	cbdata
);

extern NgCBWP NgCBWPAdd(
	int		appmgrid,
	NgCBWPCopyFunc	copy_func,
	NgCBWPFreeFunc	free_func,
	NhlLayer	l,
	NhlString	cbname,
	NhlArgVal	sel,
	_NhlCBFunc	cb_func,
	NhlArgVal	udata
);

extern void NgCBWPDestroy(
	NgCBWP		cbwp
);

extern int NgAppGetID(
	void
);

extern void NgAppAddGO(
	int	appid,
	int	goid
);

extern void NgAppRemoveGO(
	int	appid,
	int	goid
);

/*
 * The return value of the enumerate function indicates if you want the
 * NgAppEnumerateGO to continue or not. (i.e. if you return True, the
 * next goid will have the enumerate function called on it, if you return
 * False, the enumeration terminates, and NgAppEnumerateGO returns.
 */

typedef NhlBoolean (*NgAppGOEnumFunc)(
	int		goid,
	NhlPointer	udata
);

extern void NgAppEnumerateGO(
	int		appid,
	NgAppGOEnumFunc	enumerate,
	NhlPointer	udata
);

NhlErrorTypes
NgAppSetSelectedWork(
	int		appid,
        NhlString	symbol_name
        );


extern int NgAppGetSelectedWork(
	int		appid,
	NhlBoolean      create,
        NhlBoolean	*created
        );

extern void NgAppGrabFocus(
	int	appid,
	int	goid
);

extern void NgAppReleaseFocus(
	int	appid,
	int	goid
);

typedef struct NgAppGoChangeRec NgAppGoChangeRec, *NgAppGoChange;
typedef enum _NgAppGoChangeType{
	NgAppGoAdd,
	NgAppGoRemove
} NgAppGoChangeType;

struct NgAppGoChangeRec{
	NgAppGoChangeType	reason;
	int			goid;
};

#define	NgCBAppGoChange	"CBAppGoChange"	/* cbdata.ptrval is NgAppGoChange */

typedef void *NgWksState;

#endif	/* _NG_APPMGR_H */
