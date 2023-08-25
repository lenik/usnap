fs = import('fs')

sources = [
    'message.c',
    'power.c',
    'slap.c',
    'sleep.c',
    'sunit.c',
    'sysmon.c',
    'math/apn_neg.c',
    'math/apn_div4.c',
    'math/apn_mul8.c',
    'math/apn_add.c',
    'math/apn_str.c',
    'ui/crazykbd.c',
    'display/1602.c',
    'display/led8.c',
    'io/baud.c',
    'io/irda.c',
    'io/1wire.c',
    'io/crc8.c',
    'io/comm.c',
]

headers = [
    'slap.h',
    'sunit.h',
    'dalsemi/ds18b20.h',
    'sunit_stdio.h',
    'sysmon.h',
    'message.h',
    'types.h',
    'const.h',
    'math/apn.h',
    'bassert.h',
    'util.h',
    'ui/crazykbd.h',
    'ui/crazykbd_buf.h',
    '74xx/165.h',
    'power.h',
    'dk/skbd8.h',
    'dk/ps2kbd.h',
    'dk/hc6800.h',
    'display/led8.h',
    'display/1602.h',
    'io/comm.h',
    'io/baud.h',
    'io/crc8.h',
    'io/irda.h',
    'io/1wire.h',
    'sleep.h',
    'config.h',
]

install_headers(
    headers,
    preserve_path: true
    )

#FREEFLAGS = -DNDEBUG
#CHECKFLAGS = --debug

sdcc = find_program('sdcc', required : true)
#sdcc_args = [ '--Werror', '--std-c99']
sdcc_args = [ '--std-c99', '--debug' ]
sdcc_incs = [ '-I', meson.current_source_dir()  ]

sdccgen = generator(sdcc,
    output: '@BASENAME@.rel',
    arguments: sdcc_args + sdcc_incs + ['-c', '@INPUT@'] + ['-o', '@OUTPUT@'],
)

foreach src : sources
    base = fs.name(src)
    base = base.replace('.c', '')

    message('compile', src, 'to', base + '.rel')

    obj = sdccgen.process([ src ])

    hex = base + '.hex'
    custom_target(hex,
        input: obj,
        output: '@BASENAME@.hex',
        install: true,
        install_dir: 'firmware', 
        command: [ sdcc, sdcc_args, '-o', '@OUTPUT@', '@INPUT@' ],
        )
endforeach
