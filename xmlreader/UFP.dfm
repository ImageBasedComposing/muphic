object GLForm2D: TGLForm2D
  Left = 1014
  Top = 355
  Width = 429
  Height = 421
  Caption = 'Viewer'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 16
  object statusBar: TStatusBar
    Left = 0
    Top = 366
    Width = 413
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'test'
  end
end
