Attribute VB_Name = "modObjects"
Option Explicit

Public parser As New OeSOLib.OeSOParser
Public compiler As New OeSOLib.OeSOCompiler
Public evaluator As New OeSOLib.OeSOEvaluator

Public app As New OeSOLib.OeSOApplication

Public atr As New OeSOLib.OeSOAttribute
Public atrc As New OeSOLib.OeSOAttributesCollection
Public cls As New OeSOLib.OeSOClass
Public clsc As New OeSOLib.OeSOClassesCollection
Public evt As New OeSOLib.OeSOEvent
Public evtc As New OeSOLib.OeSOEventsCollection
Public itf As New OeSOLib.OeSOInterface
Public itfc As New OeSOLib.OeSOInterfacesCollection
Public mtd As New OeSOLib.OeSOMethod
Public mtdc As New OeSOLib.OeSOMethodsCollection
Public obj As New OeSOLib.OeSOObject
Public objc As New OeSOLib.OeSOObjectsCollection
Public sts As New OeSOLib.OeSOStatus
Public stsc As New OeSOLib.OeSOStatusesCollection

Public ct As New CaComToolLib.CaCTools
