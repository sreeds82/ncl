C
C	$Id: ngblda.f,v 1.1 1994-04-26 18:22:31 fred Exp $
C
      BLOCKDATA NGBLDA
C
C  Specify default values for escape functions.
C
      include 'ngcomn.h'
C
C  Workstation IDs initially undefined.
C
      DATA IWKID, IXPS/-1, -1/
C
C  No full background color by default.
C
      DATA IFULLB/0/
C
C  Maximum stack and path sizes.
C
      DATA ISTKMX, IPTHMX/ 200, 1300/
C
C  Line joins and caps are round.
C
      DATA ILJOIN, ILCAP/ 1, 1/ 
C
C  Page coordinates, in default PostScript coordinate system.
C
      DATA ILLX, ILLY, IURX, IURY/ 36, 126, 576, 666/      
C
C  Fill and hatch spacings.
C
      DATA FILSPC, HATSPC/0.0005, .01/
C
C  Miter limit.
C
      DATA RMITER/ 10./
C
C  Nominal linewidth scale.
C
      DATA RNLSCL/ 1./
C
C  Coordinate scale factor.
C
      DATA ICOSCL/25/
C
C  File name and picture name.
C
      DATA CFILNM,CPICNM/'DEFAULT',' '/
C
      END
