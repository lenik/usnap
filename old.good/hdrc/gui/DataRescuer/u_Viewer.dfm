object frmViewer: TfrmViewer
  Left = 258
  Top = 199
  Width = 577
  Height = 459
  Caption = #25159#21306#26597#30475#19982#32534#36753
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TabSet1: TTabSet
    Left = 24
    Top = 336
    Width = 465
    Height = 33
    BackgroundColor = clBackground
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    SelectedColor = clWhite
    Tabs.Strings = (
      #20108#36827#21046
      #25991#26412
      #20998#21306#34920
      #30446#24405#34920
      'FAT'
      #25991#20214#31995#32479#20449#24687)
    TabIndex = 0
    UnselectedColor = clMoneyGreen
    OnChange = TabSet1Change
  end
  object Notebook1: TNotebook
    Left = 24
    Top = 56
    Width = 465
    Height = 281
    TabOrder = 1
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10001
      Caption = 'Binary'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10006
      Caption = 'Text'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10002
      Caption = 'Partition'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10003
      Caption = 'Directory'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10004
      Caption = 'FAT'
    end
    object TPage
      Left = 0
      Top = 0
      HelpContext = 10005
      Caption = 'FileSystemInfo'
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 569
    Height = 40
    AutoSize = True
    ButtonHeight = 36
    ButtonWidth = 79
    Caption = 'ToolBar1'
    HotImages = ImageList1
    Images = ImageList1
    ShowCaptions = True
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 2
      Caption = 'CHS'#23450#20301
      ImageIndex = 0
    end
    object ToolButton2: TToolButton
      Left = 79
      Top = 2
      Caption = 'LBA'#23450#20301
      ImageIndex = 1
    end
    object ToolButton3: TToolButton
      Left = 158
      Top = 2
      Caption = #23548#20986#24403#21069#25159#21306
      ImageIndex = 2
    end
    object ToolButton4: TToolButton
      Left = 237
      Top = 2
      Caption = #23548#20837#24403#21069#25159#21306
      ImageIndex = 3
    end
    object ToolButton5: TToolButton
      Left = 316
      Top = 2
      Caption = #23548#20986#33539#22260
      ImageIndex = 4
    end
    object ToolButton6: TToolButton
      Left = 395
      Top = 2
      Caption = #23548#20837#33539#22260
      ImageIndex = 5
    end
  end
  object ImageList1: TImageList
    Left = 488
    Top = 8
  end
end
