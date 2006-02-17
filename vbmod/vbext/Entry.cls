VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Entry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Option Base 0

Private m_Key
Private m_Value

Public Property Get Key()
    LC.Assign Key, m_Key
End Property

Public Property Let Key(newKey)
    LC.Assign m_Key, newKey
End Property

Public Property Get Value()
    LC.Assign Value, m_Value
End Property

Public Property Let Value(newValue)
    LC.Assign m_Value, newValue
End Property
