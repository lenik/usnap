
unit AEtype;

interface

const
        AEIMG_RGB32             = 0;
        AEIMG_RGB24             = 1;
        AEIMG_RGB32		= 0;
        AEIMG_RGB24		= 1;
        AEIMG_RGB16_565		= 2;
        AEIMG_SCALAR_I8		= 3;
        AEIMG_SCALAR_FLOAT	= 4;
        AEIMG_SCALAR_DOUBLE	= 5;
        AEIMG_NON_RASTERIZED	= $80000000;

type
        AEImage = Record
                pImage: pointer;
                Id: longint;
                ImageType: longint;
                Width: longint;
                Height: longint;
                Bits: longint;
                iTypeSpecific: longint;
                pvTypeSpecific: pointer;
                iUserTag: longint;
                pvUserTag: pointer;
                ColorKey: longint;
                Ex = Record
                        ValidBits: longint;
                        Pitch: longint;
                        BitsStorage: longint;
                        end;
                end;

        AEFont = Record
                Id: longint;
                Chars: longint;
                pShapes: ^AEImage;
                DefaultShape: AEFont_CharShape;
                end;

        AEFont_CharShape = Record
                logfont: LOGFONT;
                bColorized: longint;
                bVectorImage: longint;
                Reserved: longint;
                end;

implementation

end.
