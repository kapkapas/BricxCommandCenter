object frmSimpleTerm: TfrmSimpleTerm
  Left = 324
  Top = 177
  Width = 478
  Height = 391
  Caption = 'Simple Terminal'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object mmoTerm: TMemo
    Left = 0
    Top = 0
    Width = 462
    Height = 353
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    WantTabs = True
    OnKeyPress = mmoTermKeyPress
  end
  object tmrPoll: TTimer
    Enabled = False
    Interval = 50
    OnTimer = tmrPollTimer
    Left = 40
    Top = 248
  end
  object alSimpleTerm: TActionList
    OnUpdate = alSimpleTermUpdate
    Left = 136
    Top = 88
    object act50ms: TAction
      Tag = 50
      Category = 'Refresh'
      Caption = '50 ms'
      GroupIndex = 2
      Hint = '50 ms'
      ShortCut = 16433
      OnExecute = actRefreshExecute
    end
    object act100ms: TAction
      Tag = 100
      Category = 'Refresh'
      Caption = '100 ms'
      GroupIndex = 2
      Hint = '100 ms'
      ShortCut = 16434
      OnExecute = actRefreshExecute
    end
    object act200ms: TAction
      Tag = 200
      Category = 'Refresh'
      Caption = '200 ms'
      GroupIndex = 2
      Hint = '200 ms'
      ShortCut = 16435
      OnExecute = actRefreshExecute
    end
    object act500ms: TAction
      Tag = 500
      Category = 'Refresh'
      Caption = '500 ms'
      GroupIndex = 2
      Hint = '500 ms'
      ShortCut = 16436
      OnExecute = actRefreshExecute
    end
    object act1sec: TAction
      Tag = 1000
      Category = 'Refresh'
      Caption = '1 sec'
      Checked = True
      GroupIndex = 2
      Hint = '1 sec'
      ShortCut = 16437
      OnExecute = actRefreshExecute
    end
    object act2sec: TAction
      Tag = 2000
      Category = 'Refresh'
      Caption = '2 sec'
      GroupIndex = 2
      Hint = '2 sec'
      ShortCut = 16438
      OnExecute = actRefreshExecute
    end
    object act5sec: TAction
      Tag = 5000
      Category = 'Refresh'
      Caption = '5 sec'
      GroupIndex = 2
      Hint = '5 sec'
      ShortCut = 16439
      OnExecute = actRefreshExecute
    end
    object act10sec: TAction
      Tag = 10000
      Category = 'Refresh'
      Caption = '10 sec'
      GroupIndex = 2
      Hint = '10 sec'
      ShortCut = 16440
      OnExecute = actRefreshExecute
    end
    object act20sec: TAction
      Tag = 20000
      Category = 'Refresh'
      Caption = '20 sec'
      GroupIndex = 2
      Hint = '20 sec'
      ShortCut = 16441
      OnExecute = actRefreshExecute
    end
    object act1min: TAction
      Tag = 60000
      Category = 'Refresh'
      Caption = '1 min'
      GroupIndex = 2
      Hint = '1 min'
      ShortCut = 16432
      OnExecute = actRefreshExecute
    end
    object actEditCut: TEditCut
      Category = 'Edit'
      Caption = 'Cu&t'
      Hint = 'Cut|Cuts the selection and puts it on the Clipboard'
      ImageIndex = 0
      ShortCut = 16472
    end
    object actEditCopy: TEditCopy
      Category = 'Edit'
      Caption = '&Copy'
      Hint = 'Copy|Copies the selection and puts it on the Clipboard'
      ImageIndex = 1
      ShortCut = 16451
    end
    object actEditPaste: TEditPaste
      Category = 'Edit'
      Caption = '&Paste'
      Hint = 'Paste|Inserts Clipboard contents'
      ImageIndex = 2
      ShortCut = 16470
    end
    object actEditDelete: TEditDelete
      Category = 'Edit'
      Caption = '&Delete'
      Hint = 'Delete|Erases the selection'
      ImageIndex = 5
      ShortCut = 46
    end
    object actEditSelectAll: TEditSelectAll
      Category = 'Edit'
      Caption = 'Select &All'
      Hint = 'Select All|Selects the entire document'
      ShortCut = 16449
    end
    object actPolling: TAction
      Category = 'Preferences'
      Caption = '&Polling'
      OnExecute = actPollingExecute
    end
    object actLabelLines: TAction
      Category = 'Preferences'
      Caption = '&Label Lines'
      OnExecute = actLabelLinesExecute
    end
    object actEchoSends: TAction
      Category = 'Preferences'
      Caption = '&Echo Sends'
      OnExecute = actEchoSendsExecute
    end
    object actNXTUseMailbox: TAction
      Category = 'Preferences'
      Caption = 'Use NXT Response Mailbox'
      OnExecute = actNXTUseMailboxExecute
    end
    object actMB1: TAction
      Category = 'MBNum'
      Caption = 'Mailbox1'
      GroupIndex = 2
      ShortCut = 16433
      OnExecute = actMBExecute
    end
    object actMB2: TAction
      Tag = 1
      Category = 'MBNum'
      Caption = 'Mailbox2'
      GroupIndex = 2
      ShortCut = 16434
      OnExecute = actMBExecute
    end
    object actMB3: TAction
      Tag = 2
      Category = 'MBNum'
      Caption = 'Mailbox3'
      GroupIndex = 2
      ShortCut = 16435
      OnExecute = actMBExecute
    end
    object actMB4: TAction
      Tag = 3
      Category = 'MBNum'
      Caption = 'Mailbox4'
      GroupIndex = 2
      ShortCut = 16436
      OnExecute = actMBExecute
    end
    object actMB5: TAction
      Tag = 4
      Category = 'MBNum'
      Caption = 'Mailbox5'
      GroupIndex = 2
      ShortCut = 16437
      OnExecute = actMBExecute
    end
    object actMB6: TAction
      Tag = 5
      Category = 'MBNum'
      Caption = 'Mailbox6'
      GroupIndex = 2
      ShortCut = 16438
      OnExecute = actMBExecute
    end
    object actMB7: TAction
      Tag = 6
      Category = 'MBNum'
      Caption = 'Mailbox7'
      GroupIndex = 2
      ShortCut = 16439
      OnExecute = actMBExecute
    end
    object actMB8: TAction
      Tag = 7
      Category = 'MBNum'
      Caption = 'Mailbox8'
      GroupIndex = 2
      ShortCut = 16440
      OnExecute = actMBExecute
    end
    object actMB9: TAction
      Tag = 8
      Category = 'MBNum'
      Caption = 'Mailbox9'
      GroupIndex = 2
      ShortCut = 16441
      OnExecute = actMBExecute
    end
    object actMB10: TAction
      Tag = 9
      Category = 'MBNum'
      Caption = 'Mailbox10'
      Checked = True
      GroupIndex = 2
      ShortCut = 16432
      OnExecute = actMBExecute
    end
    object actNXTNum4: TAction
      Category = 'Preferences'
      Caption = 'NXT 4 Byte Mailbox Msgs are Numeric'
      Checked = True
      OnExecute = actNXTNum4Execute
    end
    object actEditClear: TAction
      Category = 'Edit'
      Caption = 'Clear'
      OnExecute = actEditClearExecute
    end
    object actAppendLF: TAction
      Category = 'Preferences'
      Caption = 'Append LF to Each Message'
      OnExecute = actAppendLFExecute
    end
    object actFileSaveAs: TFileSaveAs
      Category = 'File'
      Caption = 'Save &As...'
      Dialog.DefaultExt = 'log'
      Dialog.Filter = 
        'Log Files (*.log)|*.log|Text Files (*.txt)|*.txt|All Files (*.*)' +
        '|*.*'
      Dialog.Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
      Hint = 'Save As|Saves the active file with a new name'
      ImageIndex = 30
      OnAccept = actFileSaveAsAccept
    end
  end
end
