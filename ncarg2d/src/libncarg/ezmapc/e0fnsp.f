C
C $Id: e0fnsp.f,v 1.4 2001-08-16 23:12:41 kennison Exp $
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
      REAL FUNCTION E0FNSP (ECCNTS)
C
C This function computes the constant E0.
C
      IMPLICIT REAL (A-Z)
      DATA QUART,ONE,ONEQ,THREE,SIXT /0.25E0,1.0E0,1.25E0,3.0E0,16.0E0/
C
      E0FNSP = ONE - QUART * ECCNTS * (ONE + ECCNTS / SIXT *
     .         (THREE + ONEQ * ECCNTS))
C
      RETURN
      END
