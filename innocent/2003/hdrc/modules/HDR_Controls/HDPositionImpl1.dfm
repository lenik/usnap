object HDPosition: THDPosition
  Left = 217
  Top = 451
  Width = 240
  Height = 144
  Hint = 'Hardware Position'
  AxBorderStyle = afbNone
  Caption = 'HDPosition'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 33
    Top = 29
    Width = 17
    Height = 13
    Caption = 'Cyl:'
  end
  object Label2: TLabel
    Left = 117
    Top = 29
    Width = 17
    Height = 13
    Caption = 'Hd:'
  end
  object Label3: TLabel
    Left = 173
    Top = 29
    Width = 22
    Height = 13
    Caption = 'Sec:'
  end
  object Label4: TLabel
    Left = 33
    Top = 69
    Width = 23
    Height = 13
    Caption = 'LBA:'
  end
  object Label5: TLabel
    Left = 8
    Top = 95
    Width = 60
    Height = 13
    Caption = 'Bytes Offset:'
  end
  object txtCylinder: TEdit
    Left = 53
    Top = 26
    Width = 57
    Height = 19
    Ctl3D = False
    ImeMode = imDisable
    MaxLength = 10
    ParentCtl3D = False
    TabOrder = 0
    Text = '0'
  end
  object optModeCHS: TRadioButton
    Left = 8
    Top = 8
    Width = 97
    Height = 17
    Hint = 'Cylinder/Head/Sector'
    Caption = 'CHS Mode'
    Checked = True
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 1
    TabStop = True
  end
  object optLBAMode: TRadioButton
    Left = 8
    Top = 50
    Width = 97
    Height = 17
    Hint = 'Large Block Address'
    Caption = 'LBA Mode'
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 2
  end
  object txtHead: TEdit
    Left = 136
    Top = 26
    Width = 30
    Height = 19
    Ctl3D = False
    ImeMode = imDisable
    MaxLength = 4
    ParentCtl3D = False
    TabOrder = 3
    Text = '0'
  end
  object txtSector: TEdit
    Left = 197
    Top = 26
    Width = 29
    Height = 19
    Ctl3D = False
    ImeMode = imDisable
    MaxLength = 4
    ParentCtl3D = False
    TabOrder = 4
    Text = '1'
  end
  object txtLBA: TEdit
    Left = 61
    Top = 67
    Width = 165
    Height = 19
    Ctl3D = False
    ImeMode = imDisable
    MaxLength = 20
    ParentCtl3D = False
    TabOrder = 5
    Text = '1'
  end
  object txtOffset: TEdit
    Left = 78
    Top = 93
    Width = 47
    Height = 19
    Ctl3D = False
    ImeMode = imDisable
    MaxLength = 20
    ParentCtl3D = False
    TabOrder = 6
    Text = '0'
  end
end
