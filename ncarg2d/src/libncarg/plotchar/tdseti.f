C
C $Id: tdseti.f,v 1.2 1994-03-09 23:24:26 kennison Exp $
C
      SUBROUTINE TDSETI (PNAM,IVAL)
C
      CHARACTER*(*) PNAM
C
C The subroutine TDSETI may be used to set TDPACK parameters which have
C values of type INTEGER.
C
C Just convert it into a call to the routine TDSETR.
C
      CALL TDSETR (PNAM,REAL(IVAL))
      IF (ICFELL('TDSETI',1).NE.0) RETURN
C
C Done.
C
      RETURN
C
      END
