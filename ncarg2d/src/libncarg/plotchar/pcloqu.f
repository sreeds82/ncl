C
C $Id: pcloqu.f,v 1.2 1994-03-09 23:23:46 kennison Exp $
C
      SUBROUTINE PCLOQU (XPOS,YPOS,CHRS,SIZE,ANGD,CNTR)
C
C This routine provides an alternate entry point for the high-quality
C character-drawing routine; the name has the standard prefix "PC".
C
        CHARACTER CHRS*(*)
C
        CALL PLCHLQ (XPOS,YPOS,CHRS,SIZE,ANGD,CNTR)
        IF (ICFELL('PCLOQU',1).NE.0) RETURN
C
        RETURN
C
      END
