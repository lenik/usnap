object frmProgress: TfrmProgress
  Left = 217
  Top = 260
  Width = 696
  Height = 396
  Caption = #27491#22312#20998#26512#20013'......'
  Color = clCaptionText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TabSet1: TTabSet
    Left = 96
    Top = 288
    Width = 369
    Height = 33
    BackgroundColor = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    SelectedColor = clBackground
    Tabs.Strings = (
      #25195#25551#36827#24230
      #37325#26500#30446#24405
      #20132#21449#21015#34920
      #20002#22833#31751#21015#34920)
    TabIndex = 0
    UnselectedColor = clMoneyGreen
    OnChange = TabSet1Change
  end
  object Notebook1: TNotebook
    Left = 96
    Top = 80
    Width = 369
    Height = 209
    TabOrder = 1
    OnClick = Notebook1Click
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10011
      Caption = 'Progress'
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 60
        Height = 13
        Caption = #27491#22312#25195#25551#65306
      end
      object Label2: TLabel
        Left = 62
        Top = 47
        Width = 24
        Height = 13
        Caption = #26609#38754
      end
      object Label3: TLabel
        Left = 134
        Top = 47
        Width = 24
        Height = 13
        Caption = #30913#22836
      end
      object Label4: TLabel
        Left = 206
        Top = 47
        Width = 24
        Height = 13
        Caption = #25159#21306
      end
      object lblCylinder: TLabel
        Left = 62
        Top = 63
        Width = 6
        Height = 13
        Caption = '0'
        Color = clCaptionText
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object lblHead: TLabel
        Left = 134
        Top = 63
        Width = 6
        Height = 13
        Caption = '0'
        Color = clCaptionText
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object lblSector: TLabel
        Left = 206
        Top = 63
        Width = 6
        Height = 13
        Caption = '1'
        Color = clCaptionText
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object lblStatus: TLabel
        Left = 64
        Top = 88
        Width = 257
        Height = 25
        AutoSize = False
        Caption = '[*] '#27491#22312#28155#21152#30446#24405#32467#26500
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10012
      Caption = 'Reconstruction'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10013
      Caption = 'Cross links'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10014
      Caption = 'Lost clusters'
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    Left = 40
    Top = 40
  end
end
