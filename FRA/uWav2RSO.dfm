�
 TFRMWAVE2RSO 0u  TPF0TfrmWave2RSOfrmWave2RSOLeft� Top� BorderStylebsDialogCaptionWav 2 RSO 2 WavClientHeight�ClientWidth�Color	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OldCreateOrderShowHint	OnCreate
FormCreate
DesignSize�� PixelsPerInch`
TextHeight TLabellblMessagesLeft(TopAWidth3HeightCaption	Messages:  TButton
btnConvertLeftTopCWidthQHeightHintConvert selected filesCaptionConvertTabOrderOnClickbtnConvertClick  TMemommoMessagesLefthTop=WidthQHeightyHintMessagesReadOnly	
ScrollBarsssBothTabOrder  TButton	btnSelectLeftTop$WidthQHeightHintJSelect the files you wish to convert (either .wav -> .rso or .rso -> .wav)CaptionSelect Files...TabOrder OnClickbtnSelectClick  TListBoxlstWavFilesLefthTop"WidthQHeightHintWAV files to be converted
ItemHeightTabOrder  	TGroupBoxgrpResampleLeftTop_WidthQHeight� CaptionResampleTabOrder TLabellblRateLeftTop� WidthHeightCaptionRate:  TRadioButtonradSinc1LeftTopWidthDHeightHintXBand limited sinc interpolation, best quality, 97dB Signal to Noise Ratio, 96% BandwidthCaptionSinc 96%TabOrder   TRadioButtonradSinc2TagLeftTop!WidthDHeightHintZBand limited sinc interpolation, medium quality, 97dB Signal to Noise Ratio, 90% BandwidthCaptionSinc 90%TabOrder  TRadioButtonradSinc3TagLeftTop2WidthDHeightHintSBand limited sinc interpolation, fastest, 97dB Signal to Noise Ratio, 80% BandwidthCaptionSinc 80%TabOrder  TRadioButtonradZohTagLeftTopCWidth9HeightHint6Zero order hold interpolator, very fast, poor quality.CaptionZOHTabOrder  TRadioButton	radLinearTagLeftTopTWidth9HeightHint-Linear interpolator, very fast, poor quality.CaptionLinearTabOrder  TRadioButtonradNoneTagLeftTopfWidth9HeightHintNo resamplingCaptionNoneChecked	TabOrderTabStop	  	TSpinEditedtRateLeftTop� Width9HeightHintThe output sample rate	MaxLengthMaxValue�>MinValue�TabOrderValue@   TButtonbtnOKLeftTopfWidthQHeightHelpContext�CaptionOKDefault	ModalResultTabOrderOnClick
btnOKClick  TButton	btnCancelLeftTop�WidthQHeightHelpContext�Cancel	CaptionCancelModalResultTabOrderVisibleOnClickbtnCancelClick  TButtonbtnHelpLeftTop�WidthQHeightHelpContext�AnchorsakRightakBottom Caption&HelpTabOrderVisibleOnClickbtnHelpClick  	TCheckBoxchkUseCompressionLeftTopWidthQHeightHintCompress the .rso outputCaption
CompressedTabOrder  TDirectoryEditedtPathLefthTopWidthQHeightCursorcrNoHintThe specified output directoryAutoSizeReadOnly	TabOrder	OnChangeedtPathChangeSetHint  TOpenDialogdlgOpenFilterCWAV files (*.wav)|*.wav|RSO files (*.rso)|*.rso|All files (*.*)|*.*OptionsofHideReadOnlyofAllowMultiSelectofEnableSizingofDontAddToRecent Left� Top  
TPopupMenupumFilesLeft� Top�  	TMenuItemmniClearCaptionClearOnClickmniClearClick    