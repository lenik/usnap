unit FontData;

interface

uses
        AEtype;

type
        FontHeader = Record
                dwMagic: longint;
                major: smallint;
                minor: smallint;
                szName: array[0..15] of char;
                szClass: array[0..15] of char;
                szFullname: array[0..63] of char;
                szAuthor: array[0..63] of char;
                szCompany: array[0..63] of char;
                szEmail: array[0..31] of char;
                szWeb: array[0..31] of char;
                dwCharSet: longint;
                dwLocale: longint;
                dwLanguage: longint;
                nBegin: longint;
                nEnd: longint;
                Flags: record
                        bColorized: int: 1;
                        bRasterized: int: 1;
                        end;
                Purpose: (
                        Normal = 0,
                        Fixed,
                        Variable,
                        Script,
                        Cartoon,
                        Arbitrary,
                        _Force_DWORD = $FFFFFFFF
                        );
                BasicShape: FontBasicShape;
                end;

        FontBasicShape = Record
                Height: longint;
                Width: longint;
                Escapement: longint;
                Orientation: longint;
                Weight: longint;
                end;

        FontRuntime = Record
                Weight: longint;
                Italic: longint;
                Underline: longint;
                StrikeOut: longint;
                MirrorV: longint;
                MirrorH: longint;
                InvertColor: longint;
                Smooth: longint;
                Outline: longint;
                MarginH: longint;
                MarginV: longint;
                ScaleH: longint;
                ScaleV: longint;
                dwEffectCode: longint;
                dwIndexOffset: longint;
                iUserTag: longint;
                pvUserTag: pointer;
                iSpecific: longint;
                pvSpecific: pointer;
        end;

        FontShape_Raster = Record
                cbSize: longint;
                Image: AEImage;
                dwReserved: longint;
                FeatherFactor: longint;
                ColorData_0: longint;
                end;

        FontShape_Vector = Record
                cbSize: longint;
                nShapes: longint;
                Shape_0: shape;
                end;

        FontShape_Vector_Specific = Record
                nInstances: longint;
                pCached: ^AEImage;
                end;


implementation

procedure abcdef();
begin

end;

end.
