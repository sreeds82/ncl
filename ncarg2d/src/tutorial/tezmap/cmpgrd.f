C
C	$Id: cmpgrd.f,v 1.2 1993-01-13 23:16:28 haley Exp $
C
C
C Open GKS, Turn Clipping off
C
      CALL OPNGKS 
C
C INVOKE DEMO DRIVER
C
      CALL CMPGRD
C
C     DEACTIVATE AND CLOSE WORKSTATION, CLOSE GKS.
C
      CALL CLSGKS

      STOP
      END

      SUBROUTINE CMPGRD 
C
C CMPGRD demonstrates drawing grid lines, and use of MAPINT
C
	REAL PLIM1(2), PLIM2(2), PLIM3(2), PLIM4(2)

	DATA PLIM1 /0.,0./
	DATA PLIM2 /0.,0./
	DATA PLIM3 /0.,0./
	DATA PLIM4 /0.,0./
C
C Set up color table
C
	CALL COLOR
C
C Draw Continental, political outlines in magenta
C
        CALL MAPSTC ('OU - OUTLINE DATASET SELECTOR','PO')
        CALL MAPSTI ('C5 - CONTINENTAL OUTLINE COLOR',5)
        CALL MAPSTI ('C7 - COUNTRY OUTLINE COLOR',5)
C
C Draw grid lines and limb line in green
C
	CALL MAPSTI ('C2 - GRID COLOR',2)
	CALL MAPSTI ('C4 - LIMB COLOR',2)
C
C Draw labels and perimeter in white
C
	CALL MAPSTI ('C1 - PERIMETER COLOR',1)
        CALL MAPSTI ('C3 - LABEL COLOR',1)
C
C Set up satellite projection
C
	CALL MAPROJ ('SV',40.,-50.,0.)
	CALL MAPSTR ('SA - SATELLITE DISTANCE',5.)
        CALL MAPSET ('MA',PLIM1,PLIM2,PLIM3,PLIM4)
C
C Set grid spacing to 10 degrees, and anchor grid curve at 10 degree 
C intervals.
C
	CALL MAPSTR ('GR - GRID SPACING',10.)
	CALL MAPSTR ('GD - GRID DISTANCE',10.)
C
C Initialize Maps.
C
        CALL MAPINT
C
C Draw the latitiude and longitude lines
C
	CALL MAPGRD
C
C Advance the frame.
C
        CALL FRAME
C
C Done.
C
        RETURN
	END
      SUBROUTINE COLOR
C
C     BACKGROUND COLOR
C The background is white here for better visibility on paper
      CALL GSCR(1,0,1.,1.,1.)
C
C     FORGROUND COLORS
	CALL GSCR(1,1,.7,0.,0.)
	CALL GSCR(1,2,0.,.7,0.)
	CALL GSCR(1,3,.7,.4,0.)
	CALL GSCR(1,4,.3,.3,.7)
	CALL GSCR(1,5,.7,0.,.7)
	CALL GSCR(1,6,0.,.7,.7)
	CALL GSCR(1,7,0.,0.,0.)

	RETURN
	END
