C
C $Id: mlfnsp.f,v 1.4 2001-08-16 23:12:46 kennison Exp $
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
      REAL FUNCTION MLFNSP (E0,E1,E2,E3,PHI)
C
C This function computes the constant M.
C
      IMPLICIT REAL (A-Z)
      DATA TWO,FOUR,SIX /2.0E0,4.0E0,6.0E0/
C
      MLFNSP = E0 * PHI - E1 * SIN (TWO * PHI) + E2 * SIN (FOUR * PHI)
     * - E3 * SIN (SIX * PHI)
C
      RETURN
      END
