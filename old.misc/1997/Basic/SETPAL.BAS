SUB setpal (cn as integer, red as integer, green as integer, blue as integer)
PALETTE cn, 65536 * blue + 256 * green + red
END SUB
