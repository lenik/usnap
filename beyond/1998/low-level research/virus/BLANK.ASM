.model small
.code

Start:
  push ds
  xor ax, ax
  push ax

  retf

  include Pad.t

end Start
