C
C $Id: pakssp.f,v 1.4 2001-08-16 23:12:50 kennison Exp $
C
C                Copyright (C)  2000
C        University Corporation for Atmospheric Research
C                All Rights Reserved
C
C This file is free software; you can redistribute it and/or modify
C it under the terms of the GNU General Public License as published
C by the Free Software Foundation; either version 2 of the License, or
C (at your option) any later version.
C
C This software is distributed in the hope that it will be useful, but
C WITHOUT ANY WARRANTY; without even the implied warranty of
C MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
C General Public License for more details.
C
C You should have received a copy of the GNU General Public License
C along with this software; if not, write to the Free Software
C Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
C USA.
C
      REAL FUNCTION PAKSSP (ANG)
C
C FUNCTION TO CONVERT DMS PACKED ANGLE INTO SECONDS OF ARC.
C
      IMPLICIT REAL (A-Z)
      INTEGER I
      DIMENSION CODE(2)
      COMMON /ERRMZ0/ IERR
        INTEGER IERR
      SAVE   /ERRMZ0/
      COMMON /PRINZ0/ IPEMSG,IPELUN,IPPARM,IPPLUN
        INTEGER IPEMSG,IPELUN,IPPARM,IPPLUN
      SAVE   /PRINZ0/
      DATA CODE /1000000.0E0,1000.0E0/
      DATA ZERO,ONE /0.0E0,1.0E0/
      DATA C1,C2 /3600.0E0,60.0E0/
      DATA TOL /1.0E-4/
C
C SEPARATE DEGREE FIELD.
C
      FACTOR = ONE
      IF (ANG .LT. ZERO) FACTOR = - ONE
      SEC = ABS(ANG)
      TMP = CODE(1)
      I = INT ((SEC / TMP) + TOL)
      IF (I .GT. 360) GO TO 020
      DEG = I
C
C SEPARATE MINUTES FIELD.
C
      SEC = SEC - DEG * TMP
      TMP = CODE(2)
      I = INT ((SEC / TMP) + TOL)
      IF (I .GT. 60) GO TO 020
      MIN = I
C
C SEPARATE SECONDS FIELD.
C
      SEC = SEC - MIN * TMP
      IF (SEC .GT. C2) GO TO 020
      SEC = FACTOR * (DEG * C1 + MIN * C2 + SEC)
      GO TO 040
C
C ERROR DETECTED IN DMS FORM.
C
  020 WRITE (IPELUN,2000) ANG
 2000 FORMAT (/' ERROR PAKSSP'/
     .         ' ILLEGAL DMS FIELD =',F15.3)
      STOP 16
C
  040 PAKSSP = SEC
C
      RETURN
      END
